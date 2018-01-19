import QtQuick 2.7
import QtQuick.Controls 2.1

import "../"
import "../ComInputLine"

Popup {
    id:popup

    property alias text: inputLineText.text
    property real fontpixelSize:global.em

    background: Rectangle{
        radius: 3
        color: "white"
        opacity: 1
    }

    closePolicy: Popup.NoAutoClose

    signal signalConfirmed(var data)
    signal signalCanceled()

    onOpened: {
        inputLineText.forceActiveFocus()
    }

    Column{
        anchors.fill: parent
        Item{
            width: parent.width
            height: global.em * 0.5
        }
        Item{
            width: parent.width
            height: global.em * 2.5
            clip: true
            ComInputLine{
                id:inputLineText
                width: parent.width * 0.9
                height: parent.height
                anchors.centerIn: parent
                underlineColor: ui.fontLightColor
                fontColor: ui.fontColor
                pixelSize: global.em
                placeholderText: "请录入"
            }
        }
        Item{
            width: parent.width
            height: global.em * 0.5
        }

        Row{
            width: parent.width * 0.8
            height: global.em * 2
            anchors.horizontalCenter: parent.horizontalCenter
            Item{
                width: parent.width * 0.5
                height: parent.height
                Text{
                    id:textCancel
                    text:"取消"
                    color:ui.fontTipsColor
                    font.pixelSize: fontpixelSize
                    anchors.centerIn: parent
                }
                MouseArea{
                    anchors.fill: parent
                    onClicked: {
                        signalCanceled()
                    }
                }
            }
            Item{
                width: parent.width * 0.5
                height: parent.height
                Text{
                    id:textConfirm
                    text:"确定"
                    color:ui.fontTipsColor
                    font.pixelSize: fontpixelSize
                    anchors.centerIn: parent
                }
                MouseArea{
                    anchors.fill: parent
                    onClicked: {
                        if(inputLineText.text===""){
                            sysBus.showSysNote("未录入任何内容")
                            inputLineText.focus = true
                        }
                        else{
                            signalConfirmed(inputLineText.text)
                        }
                    }
                }
            }
        }
    }
}
