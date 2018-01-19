import QtQuick 2.7
import QtQuick.Controls 2.1

import "../../qml_com"

Popup {
    id:popup

    property alias text: label.text
    property real fontPixelSize:global.em

    closePolicy: Popup.NoAutoClose

    background: Rectangle{
        radius: 3
        color: " black"
        opacity: 0.8
    }

    contentItem: Text {
        id:label
        width:parent.width
        font.pixelSize: popup.fontPixelSize
        color: "white"
        wrapMode: Text.WrapAtWordBoundaryOrAnywhere
    }

    onOpened: {
        if(label.text === ""){
            label.text="正在处理，请稍后"
        }
    }

    onClosed: {
        label.text = ""
    }

}
