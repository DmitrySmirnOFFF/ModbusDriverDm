#include "ModbusRequest.h"

#include "ModbusTag.h"
#include <QDebug>

#define MODBUS_REQUEST_ONLY_HOLDING
#define MODBUS_REQUEST_DEBUG
//#define MODBUS_REQUEST_ENABLE_RX_LOG

ModbusRequest::ModbusRequest(QObject *parent) : BaseObject(parent),
    m_reg {-1}, m_quantity {-1}, m_slave {1},
    m_periodRx {500}, m_periodTx {50},
    m_regType {QModbusDataUnit::RegisterType::HoldingRegisters}
{
    m_requestRxTim.setInterval(m_periodRx);
    connect(&m_requestRxTim,&QTimer::timeout,this,&ModbusRequest::slotRequestRxTim);
    m_requestTxTim.setInterval(m_periodTx);
    connect(&m_requestTxTim,&QTimer::timeout,this,&ModbusRequest::slotRequestTxTim);
    m_dataUnitRx.setRegisterType(QModbusDataUnit::RegisterType::HoldingRegisters);
}

ModbusRequest::~ModbusRequest()
{
#ifdef MODBUS_REQUEST_DEBUG
    qDebug()<<"[ModbusRequest destructor] requst ["+objectName()+"] says: Goodbye :)";
#endif
}

quint16 ModbusRequest::getRegData(int reg) const
{
    if(regInRange(reg)){
        /* проверим есть, ли данные в очередь на отправку*/
        if(!m_dataUnitTxVector.isEmpty()){//если очеред на отправку не пуста
            for(auto &element:m_dataUnitTxVector){ /**/
                /* если в очереди на отправку есть данный регистр, то
                    актуальные данные в нём */
                if(element.startAddress()==reg) return element.value(0);
            }
        }
        return m_dataStoreRX.value(reg - m_reg);//заполняем ответ
    }
    qDebug()<<"[ModbusRequest  getRegisterData] register [MW" +
              QString::number(reg)+"] in request ["+objectName()+"] out of range,"
                                                                 " ["+QString::number(m_reg)+".."+QString::number(m_reg+m_quantity)+"]";
    return 0;
}

void ModbusRequest::setRegData(int reg, const quint16 &data)
{
    if(m_dataUnitTxVector.count()>1){//если в контейнере есть хотябы 2 элемента
        //проверяем, последний (он же первый в векторе) запрос на отправку содержит тот же регистр?
        if(m_dataUnitTxVector.first().startAddress()==reg){
            /* модифицируем элемемент в очереди на отправку */
            m_dataUnitTxVector.first().setValue(0,data);
            return;
        }
    }
    /* в очереди 0..1 элемент и последний элемент с регистром не равным reg*/
#ifdef MODBUS_REQUEST_DEBUG
    qDebug()<<  "[ModbusRequest setRegData] requset [" +objectName()+"], register ["+QString::number(reg)+"], data ["+QString::number(data)+"]";
#endif
    QModbusDataUnit dataUnit(m_regType,reg,1);
    dataUnit.setValue(0,data);
    /* засунем запрос в начало вектора */
    m_dataUnitTxVector.prepend(dataUnit);
    m_requestTxTim.start();
}


/*func*/
bool ModbusRequest::start()
{
    /* пройдём валидацию */
    if(!checkReg(m_reg)){
        qDebug()<<"[ModbusRequest start] failed start requsest ["+objectName()+"], check reg, current value is "+QString::number(m_reg);
        return false;
    }
    if(!checkQuantity(m_quantity)){
        qDebug()<<"[ModbusRequest start] failed start requsest ["+objectName()+"], check quantity, current value is "+QString::number(m_quantity);
        return false;
    }
    if(!checkSlave(m_slave)){
        qDebug()<<"[ModbusRequest start] failed start requsest ["+objectName()+"], check slave, current value is "+QString::number(m_slave);
        return false;
    }
    if(!checkPeriod(m_periodRx)){
        qDebug()<<"[ModbusRequest start] failed start requsest ["+objectName()+"], check period, current value is "+QString::number(m_periodRx);
        return false;
    }

    setupChildTags(this);

    if(m_client){// если клиент установлен
        /* запускаем таймер чтения */
        m_requestRxTim.start();
        /* дальше работаем со слотом таймера чтения */
        return true;
    }

    qDebug()<<"[ModbusRequest start] failed start requsest ["+objectName()+"], client not set";
    return false;
}

void ModbusRequest::stop()
{
    m_requestRxTim.stop();
}

void ModbusRequest::read()
{
    if (m_client==nullptr){
        qDebug()<<"[ModbusRequest read] request :"+ objectName() +" error [m_client = nullptr]";
        return;//Если modbusDevice NullPtr то слив
    }
    if (m_client->state()!=QModbusDevice::ConnectedState){
        qDebug()<<"[ModbusRequest read] request :"+ objectName() +" error [client disconnect]";
        return;//Если мы не подключены то слив
    }
    QModbusReply* m_replyRx =  m_client->sendReadRequest(m_dataUnitRx,m_slave);
    if (m_replyRx){
        if (!m_replyRx->isFinished()) connect(m_replyRx, &QModbusReply::finished,
                                              this, &ModbusRequest::slotRequestRxReady);
        else
            delete m_replyRx; // broadcast replies return immediately
    } else
        qDebug()<<"[ModbusRequest read] request :"+ objectName() +" error " + m_client->errorString();

}

void ModbusRequest::write(const QModbusDataUnit &dataUnit)
{
    if (m_client==nullptr){
#ifndef MODBUS_REQUEST_DISABLE_ERROR
        qDebug()<<"[ModbusRequest write] request :"+ objectName() +" error [m_client = nullptr]";
#endif
        return;//Если modbusDevice NullPtr то слив
    }
    if (m_client->state()!=QModbusDevice::ConnectedState){
        qDebug()<<"[ModbusRequest write] request :"+ objectName() +" error [client disconnect]";
        return;//Если мы не подключены то слив
    }
    QModbusReply* m_replyTx =  m_client->sendWriteRequest(dataUnit,m_slave);
    if (m_replyTx){
        if (!m_replyTx->isFinished())
            connect(m_replyTx, &QModbusReply::finished,
                    this, &ModbusRequest::slotRequestTxReady);
        else
            delete m_replyTx; // broadcast replies return immediately
    } else
        qDebug()<<"[ModbusRequest read] request :"+ objectName() +" error " + m_client->errorString();
}

QVector<quint16> ModbusRequest::getRawResult(const QModbusResponse &rawResult, int quantity)
{
    QByteArray rawData = rawResult.data();
    QVector<quint16> data;
    for(int i=0;i<quantity;i++){
        data.append((rawData.at(i/8+1)>>(i-8*(i/8)))&0x01);
    }
    return data;
}

void ModbusRequest::setupChildTags(QObject* parent)
{
    static int nestingLevel=0; // уровень вложенности
    static int tagNum = 0;
    if(parent==nullptr){
        return;
    }
    QObjectList child = parent->children();
    for(auto el:child){// по всем дочерним элементам
        ModbusTag *tag = qobject_cast<ModbusTag *>(el);  //пробуем преобразовать
        if(tag){//если это тэг
            tagNum++;
            if(tag->request()==nullptr) tag->setRequest(this);
        }else if(nestingLevel++<10){//если это не тэг
            //qDebug()<<"[ModbusRequest setupChildTags] request ["+objectName()+"],  nesting level is ["+QString::number(nestingLevel) + "]";
            setupChildTags(el);
        }else{
            qDebug()<<"[ModbusRequest setupChildTags] nesting level ["+QString::number(nestingLevel) + "] > 10, error";
            nestingLevel=0;
            return;
        }
    }
#ifdef MODBUS_REQUEST_DEBUG
    qDebug()<<"[ModbusRequest setupChildTags] request ["+objectName()+"] contains ["+QString::number(tagNum)+"] tags";
#endif
    tagNum=0;
    nestingLevel=0;
}

/* ------------------------       ------------------------- */
/* ------------------------ SLOTS ------------------------- */
/* ------------------------       ------------------------- */

void ModbusRequest::slotRequestRxTim()
{
    /* отправляем запрос чтения */
    read();
}

void ModbusRequest::slotRequestTxTim()
{
    if(!m_dataUnitTxVector.isEmpty()){
        //stopRead();
        /* отправим последний элемент */
        write(m_dataUnitTxVector.last());
        //удалим последний элемент
        m_dataUnitTxVector.removeLast();
    }else{
        m_requestTxTim.stop();
    }
}

void ModbusRequest::slotRequestRxReady()
{
    QModbusReply* m_replyRx = qobject_cast<QModbusReply *>(sender());
    if (!m_replyRx)
        return;
    switch (m_replyRx->error()) {
    case QModbusDevice::NoError:
    {
#ifndef MODBUS_REQUEST_ONLY_HOLDING
        if(m_replyRx->result().registerType()<=QModbusDataUnit::Coils){
            m_dataStoreRX = getRawResult(m_replyRx->rawResult(),m_replyRx->result().valueCount());
        }
        else
#endif
            m_dataStoreRX = m_replyRx->result().values();
#ifdef MODBUS_REQUEST_ENABLE_RX_LOG
        qDebug()<<"[DevRequest slotRequestRxReady] request = ["+objectName()+"] complited !";
        qDebug()<<m_dataStoreRX;
#endif
        /* пока не завершили отправку - не сигналим */
        if(m_dataUnitTxVector.isEmpty()){
            emit requestReady(); //Данные готовы забирайте плиз
        }
        break;
    }
    default:
        qDebug()<<"[ModbusRequest slotRequestRxReady] request = ["+objectName()+"] replyRx Error: {"+
                  m_replyRx->error()+"} "+ m_replyRx->errorString();
#ifdef MODBUS_REQUEST_DEBUG
        qDebug()<<m_replyRx->rawResult();
#endif
    }
    m_replyRx->deleteLater();
}

void ModbusRequest::slotRequestTxReady()
{
    QModbusReply* m_replyTx = qobject_cast<QModbusReply *>(sender());
    if (!m_replyTx)
        return;
    switch (m_replyTx->error()) {
    case QModbusDevice::NoError:
#ifdef MODBUS_REQUEST_DEBUG
        qDebug()<<"[ModbusRequest slotRequestTxReady] Client/Master= ["+parent()->objectName() +
                  "] request= ["+objectName()+"] replyTx complited ! - " << m_replyTx->result().values();
#endif
        break;
    default:
        qDebug()<<"[ModbusRequest slotRequestTxReady] request = ["+objectName()+"] replyTx Error: {"+ m_replyTx->error()+"} "+m_replyTx->errorString();
    }
    delete m_replyTx;
}
/* ------------------------       ------------------------- */
/* --------------------   SLOTS END   --------------------- */
/* ------------------------       ------------------------- */

/* property */
int ModbusRequest::reg() const
{
    return m_reg;
}

void ModbusRequest::setReg(int newReg)
{
    if(!checkReg(newReg)){
        qDebug()<<"[ModbusRequest setReg] wrong register, request ["+objectName()+"]";
        return;
    }
    if (m_reg == newReg)
        return;
    m_reg = newReg;
    m_dataUnitRx.setStartAddress(newReg);
    emit regChanged();
}

int ModbusRequest::quantity() const
{
    return m_quantity;
}

void ModbusRequest::setQuantity(int newQuantity)
{
    if(!checkQuantity(newQuantity)){
        qDebug()<<"[ModbusRequest setQuantity] wrong quantity, request ["+objectName()+"]";
        return;
    }
    if (m_quantity == newQuantity)
        return;
    m_quantity = newQuantity;
    m_dataUnitRx.setValueCount(m_quantity);
    emit quantityChanged();
}

int ModbusRequest::slave() const
{
    return m_slave;
}

void ModbusRequest::setSlave(int newSlave)
{
    if(!checkSlave(newSlave)){
        qDebug()<<"[DevRequest setSlave] wrong slave, request ["+objectName()+"]";
        return;
    }
    if (m_slave == newSlave)
        return;
    m_slave = newSlave;
    emit slaveChanged();
}

int ModbusRequest::periodRx() const
{
    return m_periodRx;
}

void ModbusRequest::setPeriodRx(int newPeriodRx)
{
    if(!checkPeriod(newPeriodRx)){
        qDebug()<<"[DevRequest setPeriodRx] wrong period, request ["+objectName()+"]";
        return;
    }
    if (m_periodRx == newPeriodRx)
        return;
    m_periodRx = newPeriodRx;
    m_requestRxTim.setInterval(newPeriodRx); //ms rx queue
    emit periodRxChanged();
}

int ModbusRequest::periodTx() const
{
    return m_periodTx;
}

void ModbusRequest::setPeriodTx(int newPeriodTx)
{
    if(!checkPeriod(newPeriodTx)){
        qDebug()<<"[ModbusRequest setPeriodTx] wrong period, request ["+objectName()+"]";
        return;
    }
    if (m_periodTx == newPeriodTx)
        return;
    m_periodTx = newPeriodTx;
    m_requestTxTim.setInterval(newPeriodTx); //ms tx queue
    emit periodTxChanged();
}

QModbusClient *ModbusRequest::client() const
{
    return m_client;
}

void ModbusRequest::setClient(QModbusClient *newClient)
{
    if( (newClient!=nullptr) && (newClient!=m_client)){
        if(m_client!=nullptr){
            m_client->disconnect(this);
        }
        m_client = newClient;
    }
}

/* check */
bool ModbusRequest::regInRange(int reg) const
{
    return ((reg>=m_reg) && (reg<=(m_reg+m_quantity-1)));
}

bool ModbusRequest::checkReg(int reg)
{
    return (reg>=0)&&(reg<=1000);
}

bool ModbusRequest::checkQuantity(int quantity)
{
    return (quantity>=1)&&(quantity<=100);
}

bool ModbusRequest::checkPeriod(int period)
{
    return (period>=50)&&(period<=10000);
}

bool ModbusRequest::checkSlave(int slave)
{
    return (slave>=1)&&(slave<=100);
}
