import QtQuick 2.0
import QtQuick.Controls 2.1

import "../"

Item {
    id:rootItem

    implicitHeight: global.em * 2.5
    implicitWidth: global.defaultWidth

    property alias text: textField.text
    property alias placeholderText: textField.placeholderText
    property alias pixelSize: textField.font.pixelSize
    property alias echoMode: textField.echoMode
    property alias underlineColor: rectUnderLine.color
    property alias fontColor: textField.color
    property alias horizontalAlignment: textField.horizontalAlignment

    onFocusChanged: {
        if(rootItem.focus){
            textField.focus = true
        }
    }

    TextField{
        id:textField
        text:""
        placeholderText: ""
        anchors.fill: parent
        font.pixelSize: global.em
        color:ui.fontColor
        width: parent.width * 0.9
        height: parent.height
        anchors.horizontalCenter: parent.horizontalCenter
        clip: true
        wrapMode: TextInput.NoWrap
        background: Rectangle{
            color:"transparent"
            anchors.fill: parent
        }
    }

    Rectangle{
        id:rectUnderLine
        height: 1
        width: parent.width
        color:ui.fontLightColor
        anchors.bottom: parent.bottom
    }
}
