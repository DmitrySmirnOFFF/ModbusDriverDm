import QtQuick 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12


Item {
    id: item1
    implicitHeight: 600
    implicitWidth:  1080



    property alias tagIa: textIa.text
    property alias tagIb: textIb.text
    property alias tagIc: textIc.text
    property alias tagUa: textUa.text
    property alias tagUb: textUb.text
    property alias tagUc: textUc.text
    property alias tagState: rReady.state
    property alias tagWork: rWork.state
    property alias tagFault: rFault.state
    property bool tagStart
    property alias tagTinv1: textTinv1.text
    property alias tagTinv2: textTinv2.text



    Image {
        id: imgBg
        anchors.fill: parent

        source: "qrc:/img/grey.svg"

        opacity: 0.7
    }
    Text {
        id: textLabel
        text: qsTr("Диагностика работы ПЧ")
        anchors.top: parent.top
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.topMargin: 10
        font.pixelSize: 40
        font.bold: true
    }

//    Button{
//        property color color: "red"
//        id:btStart
//        x: 67
//        y: 101
//        anchors.margins: 20
//        //        textOn: "Пуск"
//        //        textOff: "Cтоп"
//        //checkable: btStart.start
//        text: "Пуск"

//        onClicked: {
//            tagStart = true
//        }
//    }
//    RoundButton{
//        id:btStop
//        x: 248
//        y: 101

//        text: "Стоп"
//        onClicked: {
//            tagStart = false
//        }

//    }
    AbstractButton{
        id: stop
        x:250
        y:80

        property int size: 100
        property color colorNormal:  "#9c2727"    //цвет по умолчанию
        readonly property color colorPressed:     "#c3c3c3"

        text: "Стоп"
        implicitWidth:  size
        implicitHeight: size
        background: Rectangle{
            id: background
            radius: 50
            color:  stop.down ? stop.colorPressed : stop.colorNormal


        }
        contentItem: Text{
            text: stop.text
            font.bold: true
            font.pointSize: 20
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
        }
        onClicked: {
            tagStart = false
        }

    }
    AbstractButton{
        id: start
        x:40
        y:80

        property int size: 100
        property color colorNormal: "#317512"  //цвет по умолчанию
        readonly property color colorPressed:    "#c3c3c3"
        text: "Старт"
        implicitWidth:  size
        implicitHeight: size
        background: Rectangle{
            id: background2
            radius: 50
            color:  start.down ? start.colorPressed : start.colorNormal


        }
        contentItem: Text{
            text: start.text
            font.bold: true
            font.pointSize: 20
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
        }
        onClicked: {
            tagStart = true
        }

    }
    //        Lamp{
    //        id:st
    //        anchors.top: parent.top
    //        anchors.left: ss.right
    //        anchors.margins: 100
    //        anchors.topMargin: 150
    //        colorAlarmAck: "green"

    //        }
    //        Text {
    //            id: textssName
    //            color: "#808000"
    //            text: qsTr("Старт/Стоп ")
    //            y:200
    //            anchors.left:  ss.left
    //            font.pixelSize: 20
    ////                anchors.leftMargin: -477
    //            font.bold: true
    //        }
    //        BButtogl{
    //            id:st
    //        anchors.top: parent.top
    //        anchors.left: ss.right
    //        anchors.margins: 100
    //        anchors.topMargin: 150
    //        textOn: "Готов"
    //        textOff: "Работа"
    //                }
    //        Text {
    //            id: textstName
    //            color: "#808000"
    //            text: qsTr("Состояние ")
    //            y:200
    //            anchors.left:  st.left
    //            font.pixelSize: 20
    ////                anchors.leftMargin: -477
    //            font.bold: true
    //        }
    //        RoundButton{
    //            id: rReady
    //            x: 138
    //            y: 140
    //            text: "+"
    //            checkable: true
    //            property int state: {
    //                    if(rReady.checked==true){
    //                        state = 1
    //                    }else if(rReady.checked==false){
    //                        state = 0
    //                    }
    //                }

    //        }
    //        implicitWidth:  1080//640 : rb2.checked ? 1 : rb3.checked ? 2 : 0
    //property int state: swtch.checked ? 1 : 0
    //    property int state: {
    //        if(swtch.checked==true){
    //            state = 1
    //        }else if(swtch.checked==false){
    //            state = 0
    //        }
    //    //    }
    //        Button {
    //            id: swtch
    //            x: 138
    //            y: 140
    //            text: "+"
    //            checkable: true
    //        onCheckedChanged: {
    //        console.log("switch changed")
    //            lamp.state = checked
    //            state = checked
    //        }
    //        onClicked: {
    //            console.log("switch click")

    //        }
    //        Lamp{
    //            id:lamp
    //            state: swtch.checked

    //        }

//    BButtogl {
//        id: ss1
//        x: 189
//        y: 137
//        text: "Стоп"
//        anchors.margins: 20
//        textOff: "Cтоп"
//        textOn: "Пуск"
//        checkable: btStart.start
//    }

    Item{
        id:strI
        anchors.left:parent.left
        anchors.leftMargin:20
        y:200
        width: 20
        height: 20
        Text {
            id: textIaName
            //                color: "#ff0000"
            text: qsTr("Ia`: ")
            anchors.left: parent.left
            anchors.top: parent.top
            font.pixelSize: 30
            anchors.leftMargin: 0
            anchors.topMargin: 0
            //                anchors.leftMargin: -477
            font.bold: true
        }
        Text {
            id: textIa
            font.bold: true

            color: "#ff0000"
            x: 0
            y: 50
            font.pixelSize: 30
        }
        /* -------------- */
        Text {
            id: textIbName
            x: 135
            //                color: "#ff0000"
            text: qsTr("Ib`:  ")
            font.pixelSize: 30
            anchors.topMargin: 0
            font.bold: true
//            anchors.left: textIaName.right
//            anchors.leftMargin: 45
            anchors.top: parent.top
        }

        Text {
            id: textIb
            font.bold: true

            color: "#0000ff"
            x: 150
            y: 50
            font.pixelSize: 30
        }

        /* -------------- */
        Text {
            id: textIcName
            //                color: "#ff0000"
            text: qsTr("Ic`:  ")
            font.pixelSize: 30

            font.bold: true
            anchors.left: textIbName.right
            anchors.leftMargin: 66
            anchors.top: parent.top
        }


    Text {
        id: textIc

        font.bold: true

        color: "#008000"
        x: 300
        y: 50
        font.pixelSize: 30


    }
    }


    Item{
        id:strU
        anchors.left:parent.left
        anchors.bottom: strI.top
        anchors.bottomMargin: -120
        anchors.leftMargin: 20
        Text {
            id: textUaName
            //                    color: "#ff0000"
            text: qsTr("Ua`: ")
            anchors.left: parent.left
            anchors.top: parent.top
            font.pixelSize: 30
            //                anchors.leftMargin: -477
            font.bold: true
        }
        Text {
            id: textUa
            font.bold: true
            color: "#ff0000"
            x: 0
            y: 50
            font.pixelSize: 30

        }
        /* -------------- */
        Text {
            id: textUbName
            x: 135
            //                    color: "#ff0000"
            text: qsTr("Ub`:  ")
            font.pixelSize: 30
            anchors.topMargin: 0
            font.bold: true
//            anchors.left:  textUaName.right
            anchors.top: parent.top
//            anchors.leftMargin: 40
        }

        Text {
            id: textUb
            font.bold: true
            color: "#0000ff"
            x: 150
            y: 50
            font.pixelSize: 30

        }

        /* -------------- */
        Text {
            id: textUcName
            //                    color: "#ff0000"
            text: qsTr("Uc`:  ")
            font.pixelSize: 30
            anchors.topMargin: 0
            font.bold: true
            anchors.left:   textUbName.right
            anchors.top: parent.top
            anchors.leftMargin: 54
        }

        Text {
            id: textUc
            font.bold: true
            color: "#008000"
            x: 300
            y: 50
            font.pixelSize: 30

        }

    }

    Item{
        id:blokslov
        anchors.top: item1.top
        anchors.right: item1.right
        anchors.rightMargin:  100
        anchors.topMargin: 150
        height:400
        width:500


        Lamp{
            id:rReady
            anchors.top: textrReady.top
            //                    anchors.left: ss.right
            //                    anchors.margins: 100
            //                    anchors.topMargin: 100
            colorAlarmAck: "green"

        }
        Text {
            id: textrReady
            //                color: "#ff0000"
            text: qsTr("Готовность преобразователя")
            font.pixelSize: 20
            font.bold: true
            //                anchors.left: textUbName.right
            //                anchors.leftMargin: 20
//            anchors.top: textTinv2.bottom
//            anchors.topMargin: 100
            anchors.left:rReady.right
            anchors.leftMargin: 50
        }
        Lamp{
            id:rWork
            anchors.top: textrWork.top
            //                    anchors.left: ss.right
            //                    anchors.margins: 100
            //                    anchors.topMargin: 100
            colorAlarmAck: "green"

        }
        Text {
            id: textrWork
            //                color: "#ff0000"
            text: qsTr("Работа преобразователя")
            font.pixelSize: 20
            font.bold: true
            //                anchors.left: textUbName.right
            //                anchors.leftMargin: 20
            anchors.top: textrReady.bottom
            anchors.topMargin: 100
            anchors.left:rWork.right
            anchors.leftMargin: 50
        }
        Lamp{
            id:rFault
            anchors.top: textrFault.top
            //                    anchors.left: ss.right
            //                    anchors.margins: 100
            //                    anchors.topMargin: 100
            colorAlarmAck: "green"

        }
        Text {
            id: textrFault
            //                color: "#ff0000"
            text: qsTr("Неисправность преобразователя")
            font.pixelSize: 20
            font.bold: true
            //                anchors.left: textUbName.right
            //                anchors.leftMargin: 20
            anchors.top: textrWork.bottom
            anchors.topMargin: 100
            anchors.left:rWork.right
            anchors.leftMargin: 50
        }








    }
    Text {
        id: textTinv1Name
        x: 20
        y: 435
        //                color: "#ff0000"
        text: qsTr("Tinv1:  ")
        font.pixelSize: 30

        font.bold: true

    }

    Text {
        id: textTinv1
        x: 50
        y: 480
//        color: "#ff0000"
        font.pixelSize: 30
        font.bold: true

    }

    Text {
        id: textTinv2Name
        x: 270
        y: 435
        text: qsTr("Tinv2:  ")
        font.pixelSize: 30
        font.bold: true

    }

    Text {
        id: textTinv2
        x: 300
        y: 480
//        color: "#ff0000"
        font.pixelSize: 30
        font.bold: true
    }




}
