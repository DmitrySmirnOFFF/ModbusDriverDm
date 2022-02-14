import QtQuick 2.12
import QtQuick.Controls 2.12

AbstractButton{
    id: root
    property int fontSize: 12
    property color colorNormal: "#c3c3c3"     //цвет по умолчанию
    readonly property color colorPressed:     Qt.darker( colorNormal,1.4) // цвет при нажатии
    text: ""
    implicitWidth:  120
    implicitHeight: 50

    background: Rectangle{
        id: background
        radius: 5
        color:  root.down ? root.colorPressed : root.colorNormal
        opacity: root.hovered ? 0.85 : 1
    }

    contentItem: Text{
        text: root.text
        font.bold: true
        font.pointSize: root.fontSize
        opacity: enabled ? 1.0 : 0.3
        color: root.down ? "white" : "black"
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        elide: Text.ElideRight
    }
}
