import QtQuick 2.12
import QtQuick.Controls 2.12

Rectangle{
    id: rControl
//    property int state: rb1.checked ? 0 : rb2.checked ? 1 : rb3.checked ? 2 : 0
    color: "#75f3bfbf"
//    height: 600
//    width: 1080

//    Text {
//        text: "Выбор состояния ->"
//        anchors.verticalCenter: parent.verticalCenter
//        anchors.right: rb1.left
//        anchors.rightMargin: 10
//    }

//    RadioButton{
//        id:rb1
//        x: 248
//        anchors.verticalCenter: parent.verticalCenter
//        text: "<--"
//    }
//    RadioButton{
//        id:rb2
//        anchors.verticalCenter: parent.verticalCenter
//        anchors.left: rb1.right
//        anchors.leftMargin: -2
//        text: "-->"
//    }
//    RadioButton{
//        id:rb3
//        anchors.verticalCenter: parent.verticalCenter
//        anchors.left: rb2.right
//        anchors.leftMargin: -3
//        text: "3"
//    }



    RadioButton{
        id:tbScreen1
        text: "Экран 1"
//        anchors.verticalCenter: parent.verticalCenter
        anchors.left: parent.left
        anchors.margins: 10
        onClicked: {
        loader.sourceComponent = compScreenContent1
        }
    }
    RadioButton{
        id:tbScreen2
        text: "Экран 2"
        anchors.right:  parent.right
        anchors.margins: 10
        onClicked: {
        loader.sourceComponent = compScreenContent2
        }
    }
//    RadioButton{
//        id:tbScreen3
//        text: "Экран 3"
//        anchors.verticalCenter: parent.verticalCenter
//        anchors.right: parent.right
//        anchors.rightMargin: 5
//        onClicked: {
//        loader.sourceComponent = compScreenContent3
//        }
//    }
}
