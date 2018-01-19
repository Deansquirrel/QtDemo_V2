import QtQuick 2.0
import QtQuick.Controls 2.1

import com.bill.menu 1.0

import "../../../qml_com"

Rectangle {
    id:rootItem
    implicitHeight: global.defaultHeight
    implicitWidth: global.defaultWidth
    color:ui.winColor

    StackView.onStatusChanged: {
        if(StackView.status==StackView.Active){
            rootItem.refresh()
        }
    }

    Keys.enabled: true

    Keys.onReleased: {
        if(event.key===Qt.Key_Back){
            event.accepted = true
            subKeyBack()
        }
    }

    function refresh(){
        rectTitle.forceActiveFocus()
    }

    function subKeyBack(){
        subBack()
    }

    function subBack(){
        Qt.quit()
    }

    Rectangle{
        id:rectTitle
        width: parent.width
        height: global.em * 3
        color:ui.backColor
        Text{
            width: parent.width * 0.9
            anchors.centerIn: parent
            wrapMode: Text.NoWrap
            text:"列表"
        }
        Rectangle{
            width: parent.width
            height: 1
            color:ui.fontLightColor
            anchors.bottom: parent.bottom
        }
        Button{
            id:btnQuit
            text:"退出"
            width: global.em * 3
            anchors.right: parent.right
            anchors.rightMargin: global.em
            anchors.verticalCenter: parent.verticalCenter
            onClicked: {
                subBack()
            }
        }
    }
    ListView{
        width: parent.width
        height: parent.height - rectTitle.height
        anchors.top: rectTitle.bottom
        model: cMenu.getMenuModel()
        clip:true
        delegate: MenuDelegate{
            width: parent.width
            height: global.em * 5
            color:ui.backColor
            text:modelData.showName
            billKey: modelData.billKey
            Rectangle{
                width: parent.width
                height: 1
                anchors.top: parent.top
                color:ui.fontLightColor
                visible: index > 0
            }
        }
    }
    CMenu{
        id:cMenu
    }
}
