import QtQuick 2.0
import QtQuick.Controls 2.1

import com.bill.androiddial 1.0

import "../../../qml_com"
import "../../../qml_com/ComTopLine"

Rectangle{
    id:rootRect
    implicitHeight: global.defaultHeight
    implicitWidth: global.defaultWidth
    color:ui.winColor

    StackView.onStatusChanged: {
        if(StackView.status == StackView.Active){
            rootRect.refresh()
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
        title: "安卓拨号"
        onGoBack: {
            subBack()
        }
    }
    ListView{
        width: parent.width
        height: parent.height - comTopLineBack.height
        anchors.top: comTopLineBack.bottom
        model:cAndroidDial.getPhoneList()
        clip: true
        delegate: PhoneDelegate{
            width: parent.width
            height: global.em * 5
            text:modelData
            Rectangle{
                width: parent.width
                height: 1
                anchors.top: parent.top
                color:ui.fontLightColor
                visible: index > 0
            }
            onClicked: {
                cAndroidDial.dialPhone(modelData)
            }
        }
    }

    CAndroidDial{
        id:cAndroidDial
        onSignalShowErr: {
            sysBus.signalShowSysNote(msg)
        }
    }

}
