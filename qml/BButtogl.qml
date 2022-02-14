import QtQuick 2.12

BButbase{
    id: root
    property string textOn
    property string textOff
    property color colorOff: "red"
    property color colorOn: "lightgreen"
    colorNormal: checked ? colorOff : colorOn    //цвет по умолчанию
    checkable: true
    text: checked ? textOff : textOn
}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/
