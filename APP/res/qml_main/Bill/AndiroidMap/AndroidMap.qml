import QtQuick 2.0
import QtQuick.Controls 2.1

import com.bill.androidmap 1.0

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
        title: "安卓地图（高德）"
        onGoBack: {
            subBack()
        }
    }

    Item{
        width: parent.width
        height: parent.height - comTopLineBack.height
        anchors.top: comTopLineBack.bottom
        Column{
//            anchors.centerIn: parent
            width: parent.width
            spacing: global.em

            //定位
            Item{
                width: parent.width * 0.9
                height: global.em * 4
                anchors.horizontalCenter: parent.horizontalCenter
                Button{
                    id:btnLocation
                    text:"Location"
                    anchors.centerIn: parent
                    width: global.em * 8
                    height: global.em * 2

                    onClicked: {
                        cAndroidMap.location()
                    }
                }
            }
            //导航
            Item{
                width: parent.width * 0.9
                height: global.em * 5
                anchors.horizontalCenter: parent.horizontalCenter
                Column{
                    anchors.fill: parent
                    Item{
                        width: parent.width
                        height: global.em * 2
                    }
                    ComInputLine{
                        id:comInputLineAddress
                        width: parent.width
                        height: global.em * 2
                        placeholderText:"地址"
                    }
                    Row{
                        width: parent.width
                        height: global.em * 3
                        Item{
                            width: parent.width * 0.5
                            height: global.em * 3
                            Button{
                                id:btnGetPoi
                                text:"GetPoi"
                                width: global.em * 8
                                height: global.em * 2
                                anchors.centerIn: parent
                                onClicked: {
                                    if(comInputLineAddress.text.trim() === ""){
                                        sysBus.signalShowSysNote("地址不能为空")
                                        comInputLineAddress.text = ""
                                        comInputLineAddress.forceActiveFocus()
                                        return
                                    }
                                    cAndroidMap.getPoiInfo(comInputLineAddress.text.trim())
                                }
                            }
                        }
                        Item{
                            width: parent.width * 0.5
                            height: global.em * 3
                            Button{
                                id:btnStartNaviPage
                                text:"StartNaviPage"
                                width: global.em * 8
                                height: global.em * 2
                                anchors.centerIn: parent
                                onClicked: {
                                    if(comInputLineAddress.text.trim() === ""){
                                        sysBus.signalShowSysNote("地址不能为空")
                                        comInputLineAddress.text = ""
                                        comInputLineAddress.forceActiveFocus()
                                        return
                                    }
                                    cAndroidMap.startNaviPage(comInputLineAddress.text.trim())
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    CAndroidMap{
        id:cAndroidMap

        onSignalShowNote: {
            sysBus.signalShowSysNote(msg)
        }
    }

}
