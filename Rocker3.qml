import QtQuick 2.0
import QtQml 2.0
import QtQuick.Controls 2.12

AbstractButton{
    id: root
    property real  scale: 1.0
    implicitHeight: 84*scale
    implicitWidth:  84*scale

//    property string imgOn: "file:LibBitMaps/Selector Switches/Rocker3On.png"
//    property string imgOnLight: "file:LibBitMaps/Selector Switches/Rocker3OnLight.png"
//    property string imgOff: "file:LibBitMaps/Selector Switches/Rocker3Off.png"
//    property string imgOffLight: "file:LibBitMaps/Selector Switches/Rocker3OffLight.png"

    property string imgOn: "/SelectorSwitchesImg/Rocker3On.png"
    property string imgOnLight: "/SelectorSwitchesImg/Rocker3OnLight.png"
    property string imgOff: "/SelectorSwitchesImg/Rocker3Off.png"
    property string imgOffLight: "/SelectorSwitchesImg/Rocker3OffLight.png"
    checkable: true

    contentItem:Image {
        id:img
        source: root.checked ? imgOff : imgOn
        sourceSize: Qt.size(width, height)
        Image {
            anchors.fill: parent
            opacity: 0.5
            source: root.checked ? imgOffLight : imgOnLight
            sourceSize: Qt.size(width, height)
        }
    }
}
