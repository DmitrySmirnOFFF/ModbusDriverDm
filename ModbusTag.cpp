#include "ModbusTag.h"
#include <QDebug>

#define MODBUS_TAG_DEBUG

ModbusTag::ModbusTag(QObject *parent) : BaseObject(parent),
    m_request{nullptr}, m_value{0}, m_valueLow{0}, m_valueHi{0},
    m_adress(""), m_adressReg{-1}, m_adressBit{-1},
    m_adressHi(""), m_adressRegHi{-1}, m_adressBitHi{-1},
    m_eventList{false},m_history(),m_historyCount{0}
{
#ifdef MODBUS_TAG_DEBUG
    connect(this,&ModbusTag::valueChanged,this,[=](){
        qDebug()<<  "[ModbusTag valueChanged] tag ["+objectName()+"] in group ["
                    +(this->parent() ? this->parent()->objectName():"no group") +
                    "] new value ["+QString::number(this->m_value)+"]";
    }
    );
#endif
}

uint ModbusTag::value() const
{
    return m_value;
}

void ModbusTag::setValue(uint newValue)
{
    if (m_value == newValue)
        return;
    if(isBitTag()){
        m_valueLow = newValue&0x01;
        m_valueHi = isBitHiSet() ? (newValue&0x02)>>1 : 0;
        m_value = m_valueLow | m_valueHi<<1;
        emit valueChanged();
        if(m_eventList) emit signalEventList(); //журнал событий
        sendBitTag();// отправляем
    }else if(isAdressRegSet()){/* установлен 1 регистр */
        m_valueLow = newValue&0xFFFF;
        m_valueHi = isRegHiSet() ? (newValue&0xFFFF0000)>>16 : 0;
        m_value = m_valueLow | m_valueHi<<16;
        emit valueChanged();
        sendWordTag();// отправляем
    }else {
        qDebug()<<"[ModbusTag setValue] error, please check adress in tag ["+objectName()+"]";
    }
}

ModbusRequest *ModbusTag::request() const
{
    return m_request;
}

void ModbusTag::setRequest(ModbusRequest *newRequest)
{
    if (newRequest == nullptr){
        qDebug()<<  "[ModbusTag setRequest] tag ["+objectName()+"] in group ["+
                    (parent() ? parent()->objectName():"no group") +"] set nullptr";
        return;
    }
    if (m_request == newRequest)
        return;
    m_request = newRequest;
#ifdef MODBUS_TAG_DEBUG
    qDebug()<<  "[ModbusTag setRequest] tag ["+objectName()+"] in group ["
                +(parent() ? parent()->objectName():"no group") +"] assign with request ["+
                m_request->objectName()+"]";
#endif
    connect(m_request, &ModbusRequest::requestReady, this,
            &ModbusTag::slotRequestComplete);
}

const QString &ModbusTag::adress() const
{
    return m_adress;
}

void ModbusTag::setAdress(const QString &newAdress)
{
    int reg = adressToReg(newAdress);
    if(reg>-1) m_adressReg = reg;
    int bit = adressToBit(newAdress);
    if(bit>-1) m_adressBit = bit;
    m_adress = newAdress;
}

const QString &ModbusTag::adressHi() const
{
    return m_adressHi;
}

void ModbusTag::setAdressHi(const QString &newAdressHi)
{
    int reg = adressToReg(newAdressHi);
    if(reg>-1) m_adressReg = reg;
    int bit = adressToBit(newAdressHi);
    if(bit>-1) m_adressBit = bit;
    m_adress = newAdressHi;
}

bool ModbusTag::eventList() const
{
    return m_eventList;
}

void ModbusTag::setEventList(bool newEventList)
{
    m_eventList = newEventList;
}

int ModbusTag::historyCount() const
{
    return m_historyCount;
}

void ModbusTag::setHistoryCount(int newHistoryCount)
{
    m_historyCount = newHistoryCount;
}

int ModbusTag::readBit(const quint16 &word, const int &bit)
{
    if((bit>=0)&&(bit<=15)){
        return word&(1<<bit) ? 1:0;
    }
    return -1;
}

bool ModbusTag::writeBit(quint16 &word, const int &bit, int value)
{
    if((bit>=0)&&(bit<=15)){
        if(value>0){
            word|=(1<<bit);
            return true;
        }else{
            word&=~(1<<bit);
            return true;
        }
    }
    return false;
}

void ModbusTag::sendBitTag()
{
    quint16 tmp;
    if(m_request==nullptr){
        return;
    }
    if(m_adressReg==m_adressRegHi){
        tmp = m_request->getRegData(m_adressReg);
        writeBit(tmp,m_adressBit,m_valueLow);
        if(isBitHiSet()) writeBit(tmp,m_adressBitHi,m_valueHi);
        m_request->setRegData(m_adressReg,tmp);
    }else{
        tmp = m_request->getRegData(m_adressReg);
        writeBit(tmp,m_adressBit,m_valueLow);
        m_request->setRegData(m_adressReg,tmp);
        if(isBitHiSet()){
            tmp = m_request->getRegData(m_adressRegHi);
            writeBit(tmp,m_adressBitHi,m_valueHi);
            m_request->setRegData(m_adressRegHi,tmp);
        }
    }
}

void ModbusTag::sendWordTag()
{
    /* тег не битовый */
    if(m_request==nullptr){
        return;
    }
    if(m_adressReg==m_adressRegHi){
        m_request->setRegData(m_adressReg,m_valueLow);
    }else{
        if(isAdressRegSet())   m_request->setRegData(m_adressReg,   m_valueLow);
        if(isRegHiSet())       m_request->setRegData(m_adressRegHi, m_valueHi);
    }

}
/* convert */
int ModbusTag::adressToReg(const QString &adress)
{
    bool flag;
    int  value;
    QString tmp;
    if(!adress.contains("MW")){
        qDebug()<<"[ModbusTag adressToReg] wrong adress: ["+adress +"] example-> <MW10>";
        return -1;
    }
    tmp = adress;
    tmp.remove("MW");
    value = tmp.split('.')[0].toInt(&flag); //попытаемся перевести в число
    if(!flag){//если не получилось
        qDebug()<<"[ModbusTag adressToReg] parsing error, adress ["+adress +"] example-> <MW10>";
        return -1;
    }
    if(value >= 0 && value <=1000){//проверка диапазона регистров
        return value;
    }
    qDebug()<<"[ModbusTag adressToReg] wrong register, adress ["+adress +"] register range-> <0..1000>";
    return -1;
}

int ModbusTag::adressToBit(const QString &adress)
{
    bool flag;
    int  value;
    QString tmp;
    if(!adress.contains("MW")){
        qDebug()<<"[ModbusTag adressToReg] wrong adress: ["+adress +"] example-> <MW10.2>";
        return -1;
    }
    tmp = adress;
    tmp.remove("MW");
    QStringList list = tmp.split('.');
    if(list.count()<=1){
       return -1;
    }
    value = tmp.split('.')[1].toInt(&flag); //попытаемся перевести в число
    if(!flag){//если не получилось
        qDebug()<<"[ModbusTag adressToReg] parsing error, adress ["+adress +"] example-> <MW10.2>";
        return -1;
    }
    if(value >= 0 && value <=15){//проверка диапазона битов
        return value;
    }
    qDebug()<<"[ModbusTag adressToReg] wrong bit, adress ["+adress +"] bit range-> <0..15>";
    return -1;
}

/* check */
bool ModbusTag::isBitTag()
{
    return isBitLowSet();
}

bool ModbusTag::isBitLowSet()
{
    return (m_adressBit>-1);
}

bool ModbusTag::isBitHiSet()
{
    return (m_adressBitHi>-1);
}

bool ModbusTag::isBitEquals()
{
    return m_adressBit==m_adressBitHi;
}

bool ModbusTag::isAdressRegSet()
{
    return (m_adressReg>-1);
}

bool ModbusTag::isRegHiSet()
{
    return (m_adressRegHi>-1);
}

bool ModbusTag::isRegEquals()
{
    return m_adressReg==m_adressRegHi;
}
/* check end */

/* ------------------------       ------------------------- */
/* ------------------------ SLOTS ------------------------- */
/* ------------------------       ------------------------- */

void ModbusTag::slotRequestComplete()
{
    if(m_request==nullptr){
        return;
    }
    if(!isAdressRegSet()){/* если адрес не установлен */
        return;
    }
    int newDataLow = 0;
    int newDataHi  = m_valueHi;
    uint newData = 0;
    newDataLow = m_request->getRegData(m_adressReg);
    if(isRegHiSet()) newDataHi  = m_request->getRegData(m_adressRegHi);
    if(isBitTag()){// если тэг битовый
        newDataLow = readBit(newDataLow,m_adressBit);
        if(isRegHiSet())  newDataHi =  readBit(newDataHi,m_adressBitHi);  // если старший регистр установлен, пробуем получить бит
        else newDataHi = -1;  // если не установлен, сделаем отрицательное значение
        newData =  newDataLow | (newDataHi>-1 ? 1<<1:0);
    }else{// если тэг не битовый
        newData = newDataLow | (isRegHiSet() ? newDataHi<<16 : 0);
    }

    if(m_value!=newData){// если данные обновились
        m_value = newData;
        m_valueLow = newDataLow;
        m_valueHi = newDataHi;
        emit valueChanged();
        if(m_eventList) emit signalEventList();
    }
}
/* ------------------------       ------------------------- */
/* --------------------   SLOTS END   --------------------- */
/* ------------------------       ------------------------- */
