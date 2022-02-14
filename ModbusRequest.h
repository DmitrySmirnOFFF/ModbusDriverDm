#ifndef MODBUSREQUEST_H
#define MODBUSREQUEST_H

#include "BaseObject.h"
#include <QModbusClient>
#include <QModbusDataUnit>
#include <QQmlListProperty>
#include <QTimer>

class ModbusRequest : public BaseObject
{
    Q_OBJECT
    Q_PROPERTY(int reg READ reg WRITE setReg NOTIFY regChanged)
    Q_PROPERTY(int quantity READ quantity WRITE setQuantity NOTIFY quantityChanged)
    Q_PROPERTY(int slave READ slave WRITE setSlave NOTIFY slaveChanged)
    Q_PROPERTY(int periodRx READ periodRx WRITE setPeriodRx NOTIFY periodRxChanged)
    Q_PROPERTY(int periodTx READ periodTx WRITE setPeriodTx NOTIFY periodTxChanged)

public:
    explicit ModbusRequest(QObject *parent = nullptr);
    ~ModbusRequest();

    /*func*/
    quint16 getRegData(int reg) const;
    void setRegData(int reg, const quint16 &data);
    bool start();
    void stop();

    /* property */
    int reg() const;
    void setReg(int newReg);

    int quantity() const;
    void setQuantity(int newQuantity);

    int slave() const;
    void setSlave(int newSlave);

    int periodRx() const;
    void setPeriodRx(int newPeriodRx);

    int periodTx() const;
    void setPeriodTx(int newPeriodTx);

    QModbusClient *client() const;
    void setClient(QModbusClient *newClient);

private:
    /*func*/
    void read();
    void write(const QModbusDataUnit &dataUnit);
    QVector<quint16> getRawResult(const QModbusResponse& rawResult, int quantity);
    void setupChildTags(QObject* parent);
    /* property */
    int m_reg;
    int m_quantity;
    int m_slave;
    int m_periodRx;
    int m_periodTx;
    QModbusDataUnit::RegisterType m_regType;
    /* main obj */
    QModbusClient* m_client {nullptr};
    QModbusDataUnit m_dataUnitRx;
    QVector<quint16> m_dataStoreRX;
    QVector<QModbusDataUnit> m_dataUnitTxVector;
    QTimer m_requestRxTim;
    QTimer m_requestTxTim;

    /*func check*/
    bool regInRange(int reg) const;
    bool checkReg(int reg);
    bool checkQuantity(int quantity);
    bool checkPeriod(int period);
    bool checkSlave(int slave);
private slots:
    void slotRequestRxTim();
    void slotRequestTxTim();
    void slotRequestRxReady();
    void slotRequestTxReady();

signals:
    void requestReady();
    void regChanged();
    void quantityChanged();
    void slaveChanged();
    void periodRxChanged();
    void periodTxChanged();
};

#endif // MODBUSREQUEST_H
