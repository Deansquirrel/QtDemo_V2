import QtQuick 2.0
import QtQuick.Controls 2.1

import com.bill.test 1.0

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
        title: "Test"
        onGoBack: {
            subBack()
        }
    }
    Item{
        width: parent.width
        height:parent.height - comTopLineBack.height
        anchors.top: comTopLineBack.bottom
        Button{
            text:"Test"
            width: global.em * 3
            height: global.em * 2
            anchors.centerIn: parent
            onClicked: {
                cTest.subTest()
            }
        }
    }

    CTest{
        id:cTest
    }
}
