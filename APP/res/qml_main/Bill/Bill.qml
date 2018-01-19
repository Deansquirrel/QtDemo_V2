import QtQuick 2.0
import QtQuick.Controls 2.1

import com.bill 1.0

import "../../qml_com"

Item {
    id:rootItem
    implicitHeight: global.defaultHeight
    implicitWidth: global.defaultWidth

    function loadBill(){
        cBill.pushQml("Menu")
    }

    StackView{
        id:rootStackView
        visible: rootStackView.depth > 0
        anchors.fill: parent
        focus: true
    }

    CBill{
        id:cBill
        onSignalPushQml: {
            rootStackView.push(url,initData)
        }
        onSignalPop: {
            if(rootStackView.depth > 1){
                rootStackView.pop()
            }
            else{
                rootStackView.clear()
                rootItem.loadBill()
            }
        }
        onSignalShowError: {
            sysBus.signalShowSysNote(msg)
        }
    }

    Component.onCompleted: {
        rootItem.loadBill()
    }
}
