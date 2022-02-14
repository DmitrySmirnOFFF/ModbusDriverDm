#ifndef MODBUSMASTER_H
#define MODBUSMASTER_H

#include <QObject>
#include <QModbusClient>
#include <QTimer>
#include <QQmlListProperty>

#include "ModbusRequest.h"

class ModbusMaster : public BaseObject
{
    Q_OBJECT
    Q_PROPERTY(QString port READ port WRITE setPort )
    Q_PROPERTY(int parity READ parity WRITE setParity )
    Q_PROPERTY(int baud READ baud WRITE setBaud )
    Q_PROPERTY(int dataBits READ dataBits WRITE setDataBits )
    Q_PROPERTY(int stopBits READ stopBits WRITE setStopBits )
    Q_PROPERTY(int responseTime READ responseTime WRITE setResponseTime )

public:
    explicit ModbusMaster(QObject *parent = nullptr);
    ~ModbusMaster();

    Q_INVOKABLE void start();
    Q_INVOKABLE void stop();

    Q_INVOKABLE QStringList getAvailablePorts();

    const QString &port() const;
    void setPort(const QString &newPort);

    int parity() const;
    void setParity(int newParity);

    int baud() const;
    void setBaud(int newBaud);

    int dataBits() const;
    void setDataBits(int newDataBits);

    int stopBits() const;
    void setStopBits(int newStopBits);

    int responseTime() const;
    void setResponseTime(int newResponseTime);

    QModbusClient *client() const;

private:
    QString m_port;
    int m_parity;
    int m_baud;
    int m_dataBits;
    int m_stopBits;
    int m_responseTime;
    int m_numberOfRetries;

    QTimer m_connectMonitorTim;
    bool   m_connectMonitorFlag=false;

    QModbusClient* m_client;

    //QVector<ModbusRequest*> m_requestList;
    QList<ModbusRequest*> m_requestList;

    void startRequests();
    void stopRequests();

    bool scanChildRequests();
    void setupChildRequests();


private slots:
    void slotClientErr(QModbusDevice::Error error);
    void slotStateChanged(QModbusDevice::State state);
    void slotConnectMonitorTim();

    // BaseObject interface
private:
    void qmlCompleteCallback() override;
};

#endif // MODBUSMASTER_H
