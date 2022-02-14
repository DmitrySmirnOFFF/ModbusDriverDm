//import QtQuick 2.12
//import QtQuick.Window 2.12


//Window {
//    title: "Modbus Driver qml test"
//    height: 600
//    width: 1080
//    visible: true
//    //visibility: "Fullscreen"


//    TestForm{
////        anchors.fill: parent
////        tagIa: setup.gFC400.ia.value/10.0
////        tagIb: setup.gFC400.ib.value
////        tagIc: setup.gFC400.ic.value
////        tagUa: setup.gFC400.ua.value
////        tagUb: setup.gFC400.ub.value
////        tagUc: setup.gFC400.uc.value
////        tagState: setup.gFC400.ready.value
////        tagWork: setup.gFC400.work.value
////        tagFault: setup.gFC400.fault.value
////        onTagStartChanged: setup.gFC400.start.value = tagStart
//    }


//    ModbusDriverSetup{
//    id:setup
//    }
//}

import QtQuick 2.12
import QtQml 2.12
import QtQuick.Window 2.12


Window {
    id: window
    height: 600
    width: 1080
    visible: true
    title: "Modbus Driver qml test"
    //visibility: "FullScreen"

    Rcontrol{
        id: rControl
        //anchors.fill: parent
        height: 0
//        width: 1080
        anchors.left: parent.left
        anchors.right: parent.right
//        anchors.bottom: parent.bottom
        anchors.top: parent.top
//        height: 50
//        width: 100
    }


    Loader{
    id:loader
    anchors.left: parent.left
    anchors.right: parent.right
    anchors.top: rControl.bottom
    anchors.bottom: parent.bottom
//    anchors.rightMargin: -140
//    anchors.bottomMargin: -120
    sourceComponent: compScreenContent1
    }


        Component{
            id:compScreenContent1
           T1{
               anchors.fill: parent
               tagIa: setup.gFC400.ia.value/10.0
               tagIb: setup.gFC400.ib.value
               tagIc: setup.gFC400.ic.value
               tagUa: setup.gFC400.ua.value
               tagUb: setup.gFC400.ub.value
               tagUc: setup.gFC400.uc.value
               tagState: setup.gFC400.ready.value
               tagWork: setup.gFC400.work.value
               tagFault: setup.gFC400.fault.value
               onTagStartChanged: setup.gFC400.start.value = tagStart

               tagTinv1:setup.gFC400.tinv1.value
               tagTinv2:setup.gFC400.tinv2.value


            }
        }
     Component{
            id:compScreenContent2
            T2 {
                anchors.fill: parent
                tag1inv1: setup.gFC400.g1.value
                tag2inv1: setup.gFC400.f11.valu
                tag3inv1: setup.gFC400.f12.value
                tag4inv1: setup.gFC400.f13.value
                tag5inv1: setup.gFC400.f14.value
                tag6inv1: setup.gFC400.f15.value

                tag1inv2: setup.gFC400.g2.value
                tag2inv2: setup.gFC400.f21.valu
                tag3inv2: setup.gFC400.f22.value
                tag4inv2: setup.gFC400.f23.value
                tag5inv2: setup.gFC400.f24.value
                tag6inv2: setup.gFC400.f25.value

            }
        }
         ModbusDriverSetup{
         id:setup
         }

    }





/*##^##
Designer {
    D{i:0;formeditorZoom:0.9;height:480;width:640}D{i:1}D{i:2}
}
##^##*/
