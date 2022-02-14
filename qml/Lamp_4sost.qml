import QtQuick 2.11

Rectangle{
    id: root
    property color colorNormal: "grey"//"lightgreen"
    property color colorAlarmAck
    property color colorAlarm: "#f709ff"
    property int  state
    property int size: 30
    property alias period: anim.period //anim.duration
    implicitHeight: size
    implicitWidth:  size
    color: Qt.darker( rIns.color,1.2)
    radius: size/2

    Rectangle{
        id:rIns
        anchors.fill: parent
        anchors.margins: root.size*0.1
        color: root.colorNormal
        radius: root.size - anchors.margins

        SequentialAnimation on color {
            id: anim
            loops: Animation.Infinite
            running: false
            property int period: 300
            ColorAnimation { from: root.colorAlarmAck; to: root.colorAlarmAck; duration: period }
            ColorAnimation { from: root.colorAlarm; to: root.colorAlarm; duration: period }
//            ColorAnimation { from: root.colorAlarmAck; to: root.colorAlarm; duration: period }
//            ColorAnimation { from: root.colorAlarm; to: root.colorAlarmAck; duration: period }
        }
//        ColorAnimation on color {
//            id: anim
//            loops: Animation.Infinite
//            running: false
//            from: root.colorAlarm; to: root.colorAlarmAck; duration: 1000
//        }
        states: [
            State { name: "normal"; when: root.state==0
                PropertyChanges {
                    target: rIns
                    color:colorNormal
                }
            },
            State { name: "alarmAck"; when: root.state==1
                PropertyChanges {
                    target: rIns
                    color:colorAlarmAck
                }
                PropertyChanges {
                    target: anim
                    running: false
                }
            },
            State { name: "alarm"; when: root.state==2
                PropertyChanges {
                    target: anim
                    running: true
                }
            }
        ]
    }



}

/*##^##
Designer {
    D{i:0;formeditorZoom:4}
}
##^##*/
