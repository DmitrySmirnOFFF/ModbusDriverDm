import QtQuick 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12


Item {
    id: item1
    implicitHeight: 600
    implicitWidth:  1080
    height: 600
    width: 1080



        property alias tag1inv1: gotovinvLamp1.state
        property alias tag2inv1: fail1Lamp1.state
        property alias tag3inv1: fail2Lamp1.state
        property alias tag4inv1: fail3Lamp1.state
        property alias tag5inv1: fail4Lamp1.state
        property alias tag6inv1: fail5Lamp1.state
        property alias tag1inv2: gotovinvLamp2.state
        property alias tag2inv2: fail1Lamp2.state
        property alias tag3inv2: fail2Lamp2.state
        property alias tag4inv2: fail3Lamp2.state
        property alias tag5inv2: fail4Lamp2.state
        property alias tag6inv2: fail5Lamp2.state

        Image {
            id: imgBg
            anchors.fill: parent
//            anchors.topMargin: 20
            source: "qrc:/img/grey.svg"
    //        anchors.rightMargin: 18
    //        anchors.bottomMargin: 20
    //        anchors.leftMargin: -18
    //        sourceSize: Qt.size(width,height)
            opacity: 0.7
        }
        Text {
        id: textLabel
        text: qsTr("Диагностика инверторов")
        anchors.top: parent.top
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.topMargin: 10
        font.pixelSize: 40
        font.bold: true
        }

        Item {
            id: stlamp1
            anchors.top: parent.top
            anchors.left: parent.left
            anchors.margins: 100
            anchors.leftMargin: 70
            width: 350
            Text {
                id: label
                text: qsTr("Инвертор 1")
                anchors.top: parent.top
                anchors.left: parent.left
                anchors.leftMargin: 100
                font.pixelSize: 30
                font.bold: true
            }

            Lamp{
                id:gotovinvLamp1
                anchors.top: parent.top
                anchors.left: parent.left
                anchors.margins: 60
                colorAlarmAck: "green"

            }
            Text {
                id: textgotovinv

                text: qsTr("Готовность инвертора ")
                font.pixelSize: 20
                font.bold: true
                anchors.left: gotovinvLamp1.right
                anchors.leftMargin:   45
                anchors.top: gotovinvLamp1.top
            }
            Lamp{
                id:fail1Lamp1
                anchors.top: gotovinvLamp1.top
                anchors.left: parent.left
                anchors.margins: 60
                colorAlarmAck: "red"

            }
            Text {
                id: textfail11

                text: qsTr("Ошибка Err DS инвертора 1 ")
                font.pixelSize: 20
                font.bold: true
                anchors.left: fail1Lamp1.right
                anchors.leftMargin:   45
                anchors.top: fail1Lamp1.top
            }
            Lamp{
                id:fail2Lamp1
                anchors.top: fail1Lamp1.top
                anchors.left: parent.left
                anchors.margins: 60
                colorAlarmAck: "red"

            }
            Text {
                id: textfail12

                text: qsTr("Ошибка Err I инвертора 1 ")
                font.pixelSize: 20
                font.bold: true
                anchors.left: fail2Lamp1.right
                anchors.leftMargin:   45
                anchors.top: fail2Lamp1.top
            }
            Lamp{
                id:fail3Lamp1
                anchors.top: fail2Lamp1.top
                anchors.left: parent.left
                anchors.margins: 60
                colorAlarmAck: "red"

            }
            Text {
                id: textfail13

                text: qsTr("Ошибка Err U инвертора 1")
                font.pixelSize: 20
                font.bold: true
                anchors.left: fail3Lamp1.right
                anchors.leftMargin:   45
                anchors.top: fail3Lamp1.top
            }
            Lamp{
                id:fail4Lamp1
                anchors.top: fail3Lamp1.top
                anchors.left: parent.left
                anchors.margins: 60
                colorAlarmAck: "red"

            }
            Text {
                id: textfail14

                text: qsTr("Ошибка Err T инвертора 1")
                font.pixelSize: 20
                font.bold: true
                anchors.left: fail4Lamp1.right
                anchors.leftMargin:   45
                anchors.top: fail4Lamp1.top
            }
            Lamp{
                id:fail5Lamp1
                anchors.top: fail4Lamp1.top
                anchors.left: parent.left
                anchors.margins: 60
                colorAlarmAck: "red"

            }
            Text {
                id: textfail15

                text: qsTr("Ошибка Err DC инвертора 1")
                font.pixelSize: 20
                font.bold: true
                anchors.left: fail5Lamp1.right
                anchors.leftMargin:   45
                anchors.top: fail5Lamp1.top
            }


//---------------------------------------------------------------------------------------------------------

        }

        Item {
            id: stlamp2
            anchors.top: parent.top
            anchors.left: stlamp1.right
            anchors.margins: 100
            Text {
                id: label2
                text: qsTr("Инвертор 2")
                anchors.top: parent.top
                anchors.left: parent.left
                anchors.leftMargin: 100
                font.pixelSize: 30
                font.bold: true
            }

            Lamp{
                id:gotovinvLamp2
                anchors.top: parent.top
                anchors.left: parent.left
                anchors.margins: 60
                colorAlarmAck: "green"

            }
            Text {
                id: textgotovinv2

                text: qsTr("Готовность инвертора ")
                font.pixelSize: 20
                font.bold: true
                anchors.left: gotovinvLamp2.right
                anchors.leftMargin:   45
                anchors.top: gotovinvLamp2.top
            }
            Lamp{
                id:fail1Lamp2
                anchors.top: gotovinvLamp2.top
                anchors.left: parent.left
                anchors.margins: 60
                colorAlarmAck: "red"

            }
            Text {
                id: textfail21

                text: qsTr("Ошибка Err DS инвертора 2 ")
                font.pixelSize: 20
                font.bold: true
                anchors.left: fail1Lamp2.right
                anchors.leftMargin:   45
                anchors.top: fail1Lamp2.top
            }
            Lamp{
                id:fail2Lamp2
                anchors.top: fail1Lamp2.top
                anchors.left: parent.left
                anchors.margins: 60
                colorAlarmAck: "red"

            }
            Text {
                id: textfail22

                text: qsTr("Ошибка Err I инвертора 2 ")
                font.pixelSize: 20
                font.bold: true
                anchors.left: fail2Lamp2.right
                anchors.leftMargin:   45
                anchors.top: fail2Lamp2.top
            }
            Lamp{
                id:fail3Lamp2
                anchors.top: fail2Lamp2.top
                anchors.left: parent.left
                anchors.margins: 60
                colorAlarmAck: "red"

            }
            Text {
                id: textfail23

                text: qsTr("Ошибка Err U инвертора 2")
                font.pixelSize: 20
                font.bold: true
                anchors.left: fail3Lamp2.right
                anchors.leftMargin:   45
                anchors.top: fail3Lamp2.top
            }
            Lamp{
                id:fail4Lamp2
                anchors.top: fail3Lamp2.top
                anchors.left: parent.left
                anchors.margins: 60
                colorAlarmAck: "red"

            }
            Text {
                id: textfail24

                text: qsTr("Ошибка Err T инвертора 2")
                font.pixelSize: 20
                font.bold: true
                anchors.left: fail4Lamp2.right
                anchors.leftMargin:   45
                anchors.top: fail4Lamp2.top
            }
            Lamp{
                id:fail5Lamp2
                anchors.top: fail4Lamp2.top
                anchors.left: parent.left
                anchors.margins: 60
                colorAlarmAck: "red"

            }
            Text {
                id: textfail25

                text: qsTr("Ошибка Err DC инвертора 2")
                font.pixelSize: 20
                font.bold: true
                anchors.left: fail5Lamp2.right
                anchors.leftMargin:   45
                anchors.top: fail5Lamp2.top
            }




        }



}

