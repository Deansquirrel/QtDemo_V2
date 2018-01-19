import QtQuick 2.7
import QtQuick.Controls 2.1

import "../"

Popup {
    id:popup

    property alias title: textTitle.text
    property alias text: label.text
    property real fontpixelSize:global.em

    property string textConfirmTitle: "确定"

    background: Rectangle{
        radius: 3
        color: "white"
        opacity: 1
    }

    closePolicy: Popup.NoAutoClose

    signal signalConfirmed()

    Column{
        anchors.fill: parent
        Item{
            width: parent.width
            height: global.em * 2
            Text{
                id:textTitle
                text:"提示"
                font.bold: true
                font.pixelSize: fontpixelSize
                anchors.centerIn: parent
            }
        }
        Item{
            width: parent.width
            height: global.em
        }
        Text {
            id:label
            width:parent.width
            font.pixelSize: fontpixelSize
            color: ui.fontColor
            wrapMode: Text.WrapAtWordBoundaryOrAnywhere
            horizontalAlignment: lineCount>1?Text.AlignLeft:Text.AlignHCenter
        }
        Item{
            width: parent.width
            height: global.em
        }

        Row{
            width: parent.width * 0.8
            height: global.em * 2
            anchors.horizontalCenter: parent.horizontalCenter
            layoutDirection: Qt.RightToLeft
            Item{
                width: parent.width * 0.5
                height: parent.height
                Text{
                    id:textConfirm
                    text:textConfirmTitle
                    color:ui.fontTipsColor
                    font.pixelSize: fontpixelSize
                    anchors.centerIn: parent
                }
                MouseArea{
                    anchors.fill: parent
                    onClicked: {
                        signalConfirmed()
                    }
                }
            }
        }
    }
}
