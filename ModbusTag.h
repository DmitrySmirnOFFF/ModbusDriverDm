#ifndef MODBUSTAG_H
#define MODBUSTAG_H

#include "BaseObject.h"
#include <QTime>
#include "ModbusRequest.h"

class ModbusTag : public BaseObject
{
    Q_OBJECT
    Q_PROPERTY(ModbusRequest *request READ request WRITE setRequest)
    Q_PROPERTY(uint value READ value WRITE setValue NOTIFY valueChanged)
    Q_PROPERTY(QString adress     READ adress       WRITE setAdress)
    Q_PROPERTY(QString adressHi   READ adressHi     WRITE setAdressHi)
    Q_PROPERTY(bool eventList READ eventList WRITE setEventList)
    Q_PROPERTY(int historyCount READ historyCount WRITE setHistoryCount)

public:
    explicit ModbusTag(QObject *parent = nullptr);

    uint value() const;
    void setValue(uint newValue);

    ModbusRequest *request() const;
    void setRequest(ModbusRequest *newRequest);

    const QString &adress() const;
    void setAdress(const QString &newAdress);

    const QString &adressHi() const;
    void setAdressHi(const QString &newAdressHi);

    bool eventList() const;
    void setEventList(bool newEventList);

    int historyCount() const;
    void setHistoryCount(int newHistoryCount);

private:
    ModbusRequest *m_request {nullptr};

    uint m_value;
    quint16 m_valueLow;
    quint16 m_valueHi;

    QString m_adress;
    int m_adressReg;
    int m_adressBit;

    QString m_adressHi;
    int m_adressRegHi;
    int m_adressBitHi;

    bool m_eventList;

    QVector<QPair<QTime,uint>> m_history;
    int m_historyCount;

    //func
    int readBit(const quint16 &word,const int &bit);
    bool writeBit(quint16 &word,const int &bit, int value);
    void sendBitTag();
    void sendWordTag();
    /* convert */
    int adressToReg(const QString &adress);
    int adressToBit(const QString &adress);

    /* check */
    bool isAdressRegSet();
    bool isBitTag();
    bool isBitLowSet();
    bool isBitHiSet();
    bool isBitEquals();
    bool isRegHiSet();
    bool isRegEquals();


signals:
    void valueChanged();
    void signalEventList();

private slots:
    void slotRequestComplete();
};

#endif // MODBUSTAG_H
