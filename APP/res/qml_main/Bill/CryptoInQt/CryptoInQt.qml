import QtQuick 2.0
import QtQuick.Controls 2.1

import com.bill.cryptoinqt 1.0

import "../../../qml_com"
import "../../../qml_com/ComTopLine"
import "../../../qml_com/ComInputLine"

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
        title: "校验码"
        onGoBack: {
            subBack()
        }
    }

    Column{
        width: parent.width
        height: parent.height - comTopLineBack.height
        anchors.top: comTopLineBack.bottom
        Rectangle{
            width: parent.width
            height: global.em * 4
            Row{
                width: parent.width * 0.9
                height: parent.height
                anchors.centerIn: parent
                ComInputLine{
                    id:comInputLineCode
                    width: parent.width * 0.7
                    height: global.em * 2
                    anchors.verticalCenter: parent.verticalCenter
                }

                Button{
                    text: "check"
                    width: global.em * 5
                    height: global.em * 1.5
                    anchors.verticalCenter: parent.verticalCenter
                    onClicked: {
                        var res = cCryptoInQt.checkCode(cCryptoInQt.sPlaintext(),comInputLineCode.text)
                        if(res === ""){
                            res = "校验通过";
                        }

                        sysBus.signalShowSysNote(res)
                    }
                }
            }
        }

        Rectangle{
            width: parent.width
            height: 1
            color:ui.fontLightColor
        }

        Rectangle{
            width: parent.width
            height: global.em * 3
            Text{
                id:textCode
                text:"Create Code"
                anchors.centerIn: parent
            }
            MouseArea{
                anchors.fill: parent
                onClicked: {
                    textCode.text = cCryptoInQt.createCode(cCryptoInQt.sPlaintext())
                }
            }
        }
    }

    CCryptoInQt{
        id:cCryptoInQt
    }

}
