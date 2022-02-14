#include "ModbusClient.h"

#include <QModbusTcpClient>  //требуют QT += quick serialbus

#include <QHostAddress>
#include <QNetworkInterface>
#include <QDebug>

//#define MODBUS_CLIENT_DEBUG
//#define MODBUS_CLIENT_DEBUG_CLIENT_OFF
#define   MODBUS_CLIENT_AUTO_PORT
#define   MODBUS_CLIENT_DEBUG_ERR

ModbusClient::ModbusClient(QObject *parent) : BaseObject(parent),
    m_socket(QUrl::fromUserInput(getLocalIp()+":502")),
    m_responseTime{1000}, m_numberOfRetries {3}
{
    m_client = new QModbusTcpClient(this);
    /* Проверяем как он поживает*/
    if (!m_client) {/* Если не создался*/
        qDebug()<<"[ModbusClient Constructor] client create error, plc ["+objectName()+"]";
    }else{/* Если создался*/
        m_client->setTimeout(m_responseTime);
        m_client->setNumberOfRetries(m_numberOfRetries);
        /* подключаем к событиям */
        connect(m_client, &QModbusClient::errorOccurred, this, &ModbusClient::slotClientErr);     // Подключаем прием ошибок
        connect(m_client, &QModbusClient::stateChanged, this,  &ModbusClient::slotStateChanged); // Подключаем прием состояний

        /*Таймер подключений*/
        /*Пытаемся подключиться раз в _connectMonitorTim.setInterval(1000) мс */
        m_connectMonitorTim.setInterval(5000);
        connect(&m_connectMonitorTim,&QTimer::timeout,this,&ModbusClient::slotConnectMonitorTim);
    }
}

ModbusClient::~ModbusClient()
{
    if(m_client){
        m_connectMonitorFlag = false;
        m_client->disconnectDevice();
        m_client->disconnect(this);
        m_client->deleteLater();
    }
}

void ModbusClient::start()
{
#ifdef MODBUS_CLIENT_DEBUG
    qDebug()<<"[ModbusClient start]";
#endif
    //qDebug()<<"[ModbusClient qmlComplite] plc ["+objectName()+"] contains ["+QString::number(m_requestList.count())+"] requests";
#ifndef MODBUS_CLIENT_DEBUG_CLIENT_OFF
    if(!scanChildRequests()){ // если запросы не установлены явно, выполним поиск в дочерних элементах
        qDebug()<<"[ModbusClient start] requests not find, please add child request";
        return;
    }
    setupChildRequests();
    /* Устанавливаем факт запуска */
    m_connectMonitorFlag = true;
    /* Запускаем таймер попыток подключения */
    m_connectMonitorTim.start();
    slotConnectMonitorTim();
    /* ждем пока он сработает */
#else
    qDebug()<<"[ModbusClient start] warring, using DEV_PLC_CLIENT_OFF";
#endif
}

void ModbusClient::stop()
{
    m_connectMonitorFlag = false;
    /* выключаем m_client */
    if(m_client){
        m_client->disconnectDevice();
        qDebug()<<"[ModbusClient stop] plc ["+objectName()+"] stopped";
    }
}

int ModbusClient::responseTime() const
{
    return m_responseTime;
}

void ModbusClient::setResponseTime(int newResponseTime)
{
    if (m_responseTime == newResponseTime)
        return;
    m_responseTime = newResponseTime;
    m_client->setTimeout(m_responseTime);
}

QModbusClient *ModbusClient::client() const
{
    return m_client;
}

void ModbusClient::startRequests()
{
    /* мы online включим запросы */
    if(m_client->state()==QModbusDevice::ConnectedState){ // если сокет !запущщен!, для каждого запроса...
        for(auto &element:m_requestList){
            if(!element->start()){// вызываем run (запускаем) для каждого
                qDebug()<<"[ModbusClient startRequests] запрос [" +element->objectName()+"] не запустился";
            }
        }
    }
}

void ModbusClient::stopRequests()
{
    for(auto &element:m_requestList){
        element->stop();
    }
}

bool ModbusClient::scanChildRequests()
{
    m_requestList.clear();
    for(auto el:qAsConst(m_objects)){
        ModbusRequest *req = qobject_cast<ModbusRequest *>(el);
        if(req){//выюранный объект является запросом
#ifdef MODBUS_CLIENT_DEBUG
            qDebug()<<"[ModbusClient scanChildRequests] find request ["<<req<<"]";
#endif
            m_requestList.append(req);//добавим в список запросов
        }
    }
    return m_requestList.count() ? true : false;
}

void ModbusClient::setupChildRequests()
{
    for(auto el:qAsConst(m_requestList)){
        if(el){
            if(el->client()==nullptr) el->setClient(client());
        }
    }
}

QString ModbusClient::socket() const
{
    return m_socket.toString();
}

void ModbusClient::setSocket(const QString &newSocket)
{
    if(m_client==nullptr){
        return;
    }
    QUrl tmp = QUrl::fromUserInput(newSocket);
    if(!tmp.isValid()){
        qDebug()<<"[ModbusClient setSocket] socket ["+newSocket+"] invalid, plc ["+objectName()+"]";
        return;
    }
    m_client->setConnectionParameter(QModbusDevice::NetworkPortParameter, m_socket.port());
    m_client->setConnectionParameter(QModbusDevice::NetworkAddressParameter, m_socket.host());
}

const QString ModbusClient::getLocalIp()
{
    const QHostAddress &localhost = QHostAddress(QHostAddress::LocalHost);
    for (auto address: QNetworkInterface::allAddresses()) {
        if ((address.protocol() == QAbstractSocket::IPv4Protocol) && (address != localhost)){
            //qDebug() << address.toString();
            return address.toString();
        }
    }
    return "undefined";
}

/* ------------------------       ------------------------- */
/* ------------------------ SLOTS ------------------------- */
/* ------------------------       ------------------------- */
void ModbusClient::slotClientErr(QModbusDevice::Error error)
{
    Q_UNUSED(error);
    qDebug()<<"[ModbusClient slotClientErr] plc ["+objectName()+"] error "+m_client->errorString();
    switch (error) {
    case QModbusDevice::Error::ConnectionError:{
        if(m_client->state()==QModbusDevice::ConnectedState){
            qDebug()<<"[ModbusClient slotClientErr] plc ["+objectName()+"] connection lost, try reconnect";
            m_client->disconnectDevice();
        }
    }
        break;
    default:
        break;
    }
}

void ModbusClient::slotStateChanged(QModbusDevice::State state)
{
    /* Изменился статус подключения клиента */
    QString answer = "[ModbusClient slotStateChanged] plc ["+objectName()+"]";
    switch(state){
    case QModbusDevice::ConnectedState: {/*мы подключились ура!!!*/
        qDebug()<<answer+" state: Connected";
        /*остановим таймер подключений*/
        m_connectMonitorTim.stop();
        /*запустим запросы*/
        startRequests();
        printf("\033[2J"); // Clear Screen
    }
        break;
    case QModbusDevice::ConnectingState:{
        qDebug()<<answer+" state: Connecting";
    }
        break;
    case QModbusDevice::UnconnectedState:{ /*соединение порвалось как...*/
        qDebug()<<answer+" state: Unconnected";  /*или сам отключил*/
        /*остановим запросы*/
        stopRequests();
        /*попробуем подключиться заново*/
        /*запустим таймер подключений если надо*/
        if(m_connectMonitorFlag) m_connectMonitorTim.start();
    }
        break;
    case QModbusDevice::ClosingState:{
        qDebug()<<answer+" state: Closing";
    }
        break;
    }
}

void ModbusClient::slotConnectMonitorTim()
{
    /* таймер сработал, пытаемся подключиться к НАСТРОЕННОМУ m_client */
    QModbusDevice::Error err;
    if(!m_client->connectDevice()) {
        err = m_client->error();
        qDebug()<<"[ModbusClient slotConnectMonitorTim] plc ["+objectName()+"] connect failed: ["+err+"] "+m_client->errorString();
    }
}

/* ------------------------       ------------------------- */
/* --------------------   SLOTS END   --------------------- */
/* ------------------------       ------------------------- */

void ModbusClient::qmlCompleteCallback()
{
    start();
}
