import QtQuick 2.7
import QtQuick.Controls 2.1

import "../"

Popup {
      id: popup
      implicitWidth: filickable.implicitWidth
      implicitHeight: filickable.implicitHeight

      height: lineHeight * Math.min(visibleItemCount,listData.length) + padding * 2

      closePolicy: Popup.NoAutoClose

      background: Rectangle{
          anchors.fill: parent
          radius: 3
          color: "white"
      }

      onOpened: {
          popup.init()
      }

      property int visibleItemCount: 5
      property real lineHeight: global.em * 2.5

      property string curr: ""
      property var listData: new Array(0)

      signal listSelected(var listValue)

      function init(){
          if(listData.length<1){
              sysBus.showSysNote("列表选择内容不能为空")
              popup.close()
              return
          }
          curr=listData[0]
          if(listData.length===1){
              popup.close()
              listSelected(curr)
              return
          }
      }

      Flickable{
          id:filickable
          width: parent.width
          height: lineHeight * visibleItemCount + 1
          contentHeight: columnList.implicitHeight
          flickableDirection: Flickable.AutoFlickIfNeeded
          ScrollIndicator.vertical: ScrollIndicator { }
          clip: true

          Column{
              id:columnList
              anchors.fill: parent
              Rectangle{
                  width: parent.width * 0.9
                  height: 1
                  anchors.horizontalCenter: parent.horizontalCenter
                  color:ui.fontLightColor
              }
              Repeater{
                  model:popup.listData.length
                  delegate: Item{
                      width: parent.width * 0.9
                      height: lineHeight
                      anchors.horizontalCenter: parent.horizontalCenter
                      Text {
                          text:listData[index]
                          anchors.left: parent.left
                          anchors.verticalCenter: parent.verticalCenter
                          leftPadding: global.em
                          width: parent.width
                          elide: Text.ElideRight
                          color:listData[index]===curr?ui.fontTipsColor:ui.fontColor
                      }
                      Rectangle{
                          width: parent.width
                          height: 1
                          anchors.bottom: parent.bottom
                          color:ui.fontLightColor
                      }
                      MouseArea{
                          anchors.fill: parent
                          onClicked: {
                              popup.close()
                              curr=listData[index]
                              listSelected(curr)
                          }
                      }
                  }
              }
          }
      }
}
