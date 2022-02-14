#include "ModbusDriverQml.h"
#include <QQmlApplicationEngine>
/* imports */


void ModbusDriverQml::addToQml()
{
    qmlRegisterType<BaseObject>    ("ModbusDriver", 1,0,   "BaseObject");
    qmlRegisterType<ModbusMaster>  ("ModbusDriver", 1,0,   "ModbusMaster");
    qmlRegisterType<ModbusClient>  ("ModbusDriver", 1,0,   "ModbusClient");
    qmlRegisterType<ModbusRequest> ("ModbusDriver", 1,0,   "ModbusRequest");
    qmlRegisterType<ModbusTagGroup>("ModbusDriver", 1,0,   "ModbusTagGroup");
    qmlRegisterType<ModbusTag>     ("ModbusDriver", 1,0,   "ModbusTag");
}
