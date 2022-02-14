#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <QDebug>

#ifdef CONSOLE_TEST
#include "ModbusMaster.h"
#include "ModbusTag.h"
#else
#include "ModbusDriverQml.h"
#include "ModbusMaster.h"
#endif

//#define CONSOLE_TEST


int main(int argc, char *argv[])
{
    QGuiApplication a(argc, argv);

#ifdef CONSOLE_TEST
    ModbusMaster master;
    qDebug()<<master.getAvailablePorts();
    master.setPort("COM7");
    master.start();
    ModbusRequest req(&master);
    //req.setParent(&master);
    req.setReg(0);
    req.setQuantity(10);

    QObject group1(&req);

    ModbusTag tag1(&group1);
    tag1.setAdress("MW0");

    ModbusTag tag2;
    tag2.setParent(&group1);
    tag2.setAdress("MW1");

    QObject group2(&group1);

    ModbusTag tag3(&group2);
    tag3.setAdress("MW2");

    ModbusTag tag4;
    tag4.setParent(&group2);
    tag4.setAdress("MW3");


    master.start();
#else
    QQmlApplicationEngine engine;

    ModbusDriverQml::addToQml();

    //qmlRegisterType<ModbusMaster>("ModbusDriver", 1,0,   "ModbusMaster");

    //engine.addImportPath(":/qml");
    const QUrl url(QStringLiteral("qrc:/qml/MainWindow.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &a, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);
#endif

    return a.exec();
}
