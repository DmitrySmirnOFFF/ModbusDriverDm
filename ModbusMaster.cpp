#include "ModbusMaster.h"

#include <QModbusRtuSerialMaster>  //требуют QT += serialbus
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QDebug>

//#define MODBUS_NASTER_DEBUG
//#define MODBUS_NASTER_CLIENT_OFF
#define   MODBUS_MASTER_AUTO_PORT
#define   MODBUS_NASTER_DEBUG_ERR

ModbusMaster::ModbusMaster(QObject *parent) : BaseObject(parent),
    m_port{""}, m_parity{QSerialPort::NoParity}, m_baud{QSerialPort::Baud115200},
    m_dataBits{QSerialPort::Data8},  m_stopBits{QSerialPort::OneStop},
    m_responseTime{1000}, m_numberOfRetries {3}
{
    m_client = new QModbusRtuSerialMaster(this);
    /* Проверяем как он поживает*/
    if (!m_client) {/* Если не создался*/
        qDebug()<<"[ModbusMaster Constructor] client create error, plc ["+objectName()+"]";
    }else{/* Если создался*/
        m_client->setConnectionParameter(QModbusDevice::SerialParityParameter, m_parity);
        m_client->setConnectionParameter(QModbusDevice::SerialBaudRateParameter, m_baud);
        m_client->setConnectionParameter(QModbusDevice::SerialDataBitsParameter, m_dataBits);
        m_client->setConnectionParameter(QModbusDevice::SerialStopBitsParameter, m_stopBits);
        m_client->setTimeout(m_responseTime);
        m_client->setNumberOfRetries(m_numberOfRetries);
        /* подключаем к событиям */
        connect(m_client, &QModbusClient::errorOccurred, this, &ModbusMaster::slotClientErr);     // Подключаем прием ошибок
        connect(m_client, &QModbusClient::stateChanged, this,  &ModbusMaster::slotStateChanged); // Подключаем прием состояний

        /*Таймер подключений*/
        /*Пытаемся подключиться раз в _connectMonitorTim.setInterval(1000) мс */
        m_connectMonitorTim.setInterval(5000);
        connect(&m_connectMonitorTim,&QTimer::timeout,this,&ModbusMaster::slotConnectMonitorTim);
    }
}

ModbusMaster::~ModbusMaster()
{
    if(m_client){
        m_connectMonitorFlag = false;
        m_client->disconnectDevice();
        m_client->disconnect(this);
        m_client->deleteLater();
    }
}

void ModbusMaster::start()
{
#ifdef MODBUS_NASTER_DEBUG
    qDebug()<<"[ModbusMaster start]";
#endif
    //qDebug()<<"[ModbusMaster qmlComplite] plc ["+objectName()+"] contains ["+QString::number(m_requestList.count())+"] requests";
    /* когда собрали все запросы, запускаем карусель */
#ifndef DEV_PLC_CLIENT_OFF

#ifdef MODBUS_MASTER_AUTO_PORT
    if(m_port==""){
        QStringList ports = getAvailablePorts();
        if(ports.count()){
            setPort(ports.at(0));
        }
    }
#endif
    if(!scanChildRequests()){
        qDebug()<<"[ModbusMaster start] in master [" +objectName()+ "] requests not found, please add child request";
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
    qDebug()<<"[ModbusMaster start] warring, using DEV_PLC_CLIENT_OFF";
#endif
}

void ModbusMaster::stop()
{
    m_connectMonitorFlag = false;
    /* выключаем m_client */
    if(m_client){
        m_client->disconnectDevice();
        qDebug()<<"[ModbusMaster stop] plc ["+objectName()+"] stopped";
    }
}

QStringList ModbusMaster::getAvailablePorts()
{
    const auto infos = QSerialPortInfo::availablePorts();
    QStringList list;
    for (const QSerialPortInfo &info : infos) {

        //        description = info.description();
        //        manufacturer = info.manufacturer();
        //        serialNumber = info.serialNumber();
        list << info.portName();
        //             << (!description.isEmpty() ? description : blankString)
        //             << (!manufacturer.isEmpty() ? manufacturer : blankString)
        //             << (!serialNumber.isEmpty() ? serialNumber : blankString)
        //             << info.systemLocation()
        //             << (info.vendorIdentifier() ? QString::number(info.vendorIdentifier(), 16) : blankString)
        //             << (info.productIdentifier() ? QString::number(info.productIdentifier(), 16) : blankString);
    }
    return list;
}

int ModbusMaster::parity() const
{
    return m_parity;
}

void ModbusMaster::setParity(int newParity)
{
    if (m_parity == newParity)
        return;
    m_parity = newParity;
    m_client->setConnectionParameter(QModbusDevice::SerialParityParameter, newParity);
}

int ModbusMaster::baud() const
{
    return m_baud;
}

void ModbusMaster::setBaud(int newBaud)
{
    if (m_baud == newBaud)
        return;
    m_baud = newBaud;
    m_client->setConnectionParameter(QModbusDevice::SerialBaudRateParameter, newBaud);
}

int ModbusMaster::dataBits() const
{
    return m_dataBits;
}

void ModbusMaster::setDataBits(int newDataBits)
{
    if (m_dataBits == newDataBits)
        return;
    m_dataBits = newDataBits;
    m_client->setConnectionParameter(QModbusDevice::SerialDataBitsParameter, m_dataBits);
}

int ModbusMaster::stopBits() const
{
    return m_stopBits;
}

void ModbusMaster::setStopBits(int newStopBits)
{
    if (m_stopBits == newStopBits)
        return;
    m_stopBits = newStopBits;
    m_client->setConnectionParameter(QModbusDevice::SerialStopBitsParameter, m_stopBits);
}

int ModbusMaster::responseTime() const
{
    return m_responseTime;
}

void ModbusMaster::setResponseTime(int newResponseTime)
{
    if (m_responseTime == newResponseTime)
        return;
    m_responseTime = newResponseTime;
    m_client->setTimeout(m_responseTime);
}

QModbusClient *ModbusMaster::client() const
{
    return m_client;
}

void ModbusMaster::startRequests()
{
    /* мы online включим запросы */
    if(m_client->state()==QModbusDevice::ConnectedState){ // если сокет !запущщен!, для каждого запроса...
        for(auto &element:m_requestList){
            if(!element->start()){// вызываем run (запускаем) для каждого
                qDebug()<<"[ModbusMaster startRequests] запрос [" +element->objectName()+"] не запустился";
            }
        }
    }
}

void ModbusMaster::stopRequests()
{
    for(auto &element:m_requestList){
        element->stop();
    }
}

bool ModbusMaster::scanChildRequests()
{
    m_requestList.clear();
    for(auto el : qAsConst(m_objects)){
        ModbusRequest *req = qobject_cast<ModbusRequest *>(el);
        if(req){//выюранный объект является запросом
#ifdef MODBUS_MASTER_DEBUG
            qDebug()<<"[ModbusClient scanChildRequests] find request ["<<req<<"]";
#endif
            m_requestList.append(req);//добавим в список запросов
        }
    }
    return m_requestList.count() ? true : false;
}

void ModbusMaster::setupChildRequests()
{
    for(auto el:qAsConst(m_requestList)){
        if(el){
            if(el->client()==nullptr) el->setClient(client());
        }
    }
}

const QString &ModbusMaster::port() const
{
    return m_port;
}

void ModbusMaster::setPort(const QString &newPort)
{
    if (m_port == newPort)
        return;
    m_port = newPort;
    m_client->setConnectionParameter(QModbusDevice::SerialPortNameParameter, m_port);
}

/* ------------------------       ------------------------- */
/* ------------------------ SLOTS ------------------------- */
/* ------------------------       ------------------------- */
void ModbusMaster::slotClientErr(QModbusDevice::Error error)
{
    Q_UNUSED(error);
    qDebug()<<"[ModbusMaster slotClientErr] plc ["+objectName()+"] error "+m_client->errorString();
    switch (error) {
    case QModbusDevice::Error::ConnectionError:{
        if(m_client->state()==QModbusDevice::ConnectedState){
            qDebug()<<"[ModbusMaster slotClientErr] plc ["+objectName()+"] connection lost, try reconnect";
            m_client->disconnectDevice();
        }
    }
        break;
    default:
        break;
    }
}

void ModbusMaster::slotStateChanged(QModbusDevice::State state)
{
    /* Изменился статус подключения клиента */
    QString answer = "[ModbusMaster slotStateChanged] plc ["+objectName()+"]";
    switch(state){
    case QModbusDevice::ConnectedState: /*мы подключились ура!!!*/
        qDebug()<<answer+" state: Connected";
        /*остановим таймер подключений*/
        m_connectMonitorTim.stop();
        /*запустим запросы*/
        startRequests();
        printf("\033[2J"); // Clear Screen
        break;
    case QModbusDevice::ConnectingState:
        qDebug()<<answer+" state: Connecting";
        break;
    case QModbusDevice::UnconnectedState: /*соединение порвалось как...*/
        qDebug()<<answer+" state: Unconnected";  /*или сам отключил*/
        /*остановим запросы*/
        stopRequests();
        /*попробуем подключиться заново*/
        /*запустим таймер подключений если надо*/
        if(m_connectMonitorFlag)
            m_connectMonitorTim.start();
        break;
    case QModbusDevice::ClosingState:
        qDebug()<<answer+" state: Closing";
        break;
    }
}

void ModbusMaster::slotConnectMonitorTim()
{
    /* таймер сработал, пытаемся подключиться к НАСТРОЕННОМУ m_client */
    QModbusDevice::Error err;
    if(!m_client->connectDevice()) {
        err = m_client->error();
        qDebug()<<"[ModbusMaster slotConnectMonitorTim] plc ["+objectName()+"] connect failed: ["+err+"] "+m_client->errorString();
    }
}


/* ------------------------       ------------------------- */
/* --------------------   SLOTS END   --------------------- */
/* ------------------------       ------------------------- */

void ModbusMaster::qmlCompleteCallback()
{
    start();
}
