import QtQuick 2.7
import QtQuick.Controls 2.2
import QtQuick.Window 2.2

import com.boot 1.0

import "../../qml_com"

Item {
    id:rootItem
    implicitHeight: global.defaultHeight
    implicitWidth: global.defaultWidth

    property alias textMsg: textMsg.text

    Rectangle{
        anchors.fill: parent
        color:ui.backColor
        Text{
            id:textMsg
            text: String("系统正在初始化")
            anchors.centerIn: parent
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: global.em
            width: parent.width * 0.8
            wrapMode: Text.WrapAtWordBoundaryOrAnywhere
        }

        Rectangle{
            id:rectQuit
            width: parent.width
            height: global.em * 3
            color:ui.themeColor
            visible: false
            anchors.bottom: parent.bottom
            Text{
                text:"退    出"
                color:"white"
            }
            MouseArea{
                anchors.fill: parent
                onClicked: {
                    Qt.quit()
                }
            }
        }
    }

    CBoot{
        id:cBoot

        onSignalBootFinished: {
            if(msg !== ""){
                sysBus.signalShowSysNote(msg)
            }
            cMain.loadQml("Bill")
        }
        onSignalBootErr: {
            textMsg.text = msg
            rectQuit.visible = true
            rectQuit.visible = true
        }
    }

    Component.onCompleted: {
        cBoot.handleBoot()
    }
}
