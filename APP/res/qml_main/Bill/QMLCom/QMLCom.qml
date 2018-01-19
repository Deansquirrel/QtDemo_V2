import QtQuick 2.0
import QtQuick.Controls 2.1

import com.bill.qmlcom 1.0

import "../../../qml_com"
import "../../../qml_com/ComInputLine"
import "../../../qml_com/ComMessageBox"
import "../../../qml_com/ComNote"
import "../../../qml_com/ComNumpad"
import "../../../qml_com/ComSelectList"
import "../../../qml_com/ComTopLine"

Rectangle{
    id:rootItem

    implicitHeight: global.defaultHeight
    implicitWidth: global.defaultWidth
    color:ui.winColor

    StackView.onStatusChanged: {
        if(StackView.status==StackView.Active){
            rootItem.refresh()
        }
        if(StackView.status == StackView.Deactivating){

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
        comTopLineBack.forceActiveFocus()
    }

    function subKeyBack(){
        subBack()
    }

    function subBack(){
        cBill.popQml()
    }

    ComTopLineBack{
        id:comTopLineBack
        width: parent.width
        height: global.em * 3
        title: "QMLCom"
        onGoBack: {
            subBack()
        }
    }

    Column{
        width: parent.width
        height: parent.height - comTopLineBack.height
        anchors.top: comTopLineBack.bottom
    }

}
