#ifndef MODBUSCLIENT_H
#define MODBUSCLIENT_H

#include "BaseObject.h"
#include <QModbusClient>
#include <QTimer>
#include <QUrl>
#include <QQmlListProperty>
#include "ModbusRequest.h"

class ModbusClient : public BaseObject
{
    Q_OBJECT
    Q_PROPERTY(QString socket   READ socket       WRITE setSocket)
    Q_PROPERTY(int responseTime READ responseTime WRITE setResponseTime)

public:
    explicit ModbusClient(QObject *parent = nullptr);
    ~ModbusClient();

    Q_INVOKABLE void start();
    Q_INVOKABLE void stop();

    int responseTime() const;
    void setResponseTime(int newResponseTime);

    QModbusClient *client() const;

    QString socket() const;
    void setSocket(const QString &newSocket);

private:
    QUrl m_socket; //ip:port
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

    const QString getLocalIp();

private slots:
    void slotClientErr(QModbusDevice::Error error);
    void slotStateChanged(QModbusDevice::State state);
    void slotConnectMonitorTim();

    // BaseObject interface
private:
    void qmlCompleteCallback() override;
};

#endif // ModbusClient_H
