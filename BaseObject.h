#ifndef BASEOBJECT_H
#define BASEOBJECT_H

#include <QObject>
#include <QQmlListProperty>

class BaseObject : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QQmlListProperty<BaseObject> objects READ objects CONSTANT)
    Q_CLASSINFO("DefaultProperty","objects")
public:
    explicit BaseObject(QObject *parent = nullptr);

    QQmlListProperty<BaseObject> objects();
    Q_INVOKABLE void qmlComplete();
private:
    virtual void qmlCompleteCallback();
protected:
    QList<BaseObject*> m_objects;
};

#endif // BASEOBJECT_H
