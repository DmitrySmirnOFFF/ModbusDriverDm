#include "BaseObject.h"
#include <QDebug>

BaseObject::BaseObject(QObject *parent)
    : QObject{parent}
{

}

QQmlListProperty<BaseObject> BaseObject::objects()
{
    return QQmlListProperty<BaseObject>(this,m_objects);
}

void BaseObject::qmlComplete()
{
    for (auto  const &el : qAsConst(m_objects)){
        el->qmlComplete();
    }
    this->qmlCompleteCallback();
}

void BaseObject::qmlCompleteCallback()
{
    qDebug()<<"[BaseObject qmlCompleteCallback] c++ qml setup complete: "+objectName();
}
