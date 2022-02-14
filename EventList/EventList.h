#ifndef EVENTLIST_H
#define EVENTLIST_H

#include <QObject>

class EventList : public QObject
{
    Q_OBJECT
public:
    explicit EventList(QObject *parent = nullptr);

signals:

};

#endif // EVENTLIST_H
