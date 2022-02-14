QT += quick

#CONFIG += c++11 console


#-------------------    Import   -------------------
QT += serialbus serialport

#-------------------  Import End -------------------

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        BaseObject.cpp \
        EventList/EventList.cpp \
        ModbusClient.cpp \
        ModbusDriverQml.cpp \
        ModbusMaster.cpp \
        ModbusRequest.cpp \
        ModbusTag.cpp \
        ModbusTagGroup.cpp \
        main.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target



HEADERS += \
    BaseObject.h \
    EventList/EventList.h \
    ModbusClient.h \
    ModbusDriverQml.h \
    ModbusMaster.h \
    ModbusRequest.h \
    ModbusTag.h \
    ModbusTagGroup.h

QML_IMPORT_PATH =

#DISTFILES += \
#   qml/QmlAddressing.qml

RESOURCES += \
    qmlQrc.qrc

