import QtQuick 2.6
import QtQuick.Controls 2.1

RadioButton {
  id: control
  text: qsTr("RadioButton")

  font.family: Qt.application.font

  property real indicatorPer: 0.5

  indicator: Item{
      width: parent.height
      height: parent.height
//      color:"green"
      Rectangle{
          width: parent.width * indicatorPer
          height: parent.height * indicatorPer
          color:"transparent"
          anchors.centerIn: parent
          radius: height * 0.5
          border.color: control.checked ? ui.fontTipsColor : ui.fontColor
      }
      Rectangle{
          width: parent.width * indicatorPer / 2 //+ 1
          height: parent.width * indicatorPer / 2 //+ 1
          color:control.checked ? ui.fontTipsColor : ui.fontColor
          anchors.centerIn: parent
          radius: height * 0.5
          visible: control.checked
      }
  }


//      Rectangle {
//      id:rectBack
//      implicitWidth: parent.height * indicatorPer
//      implicitHeight: parent.height * indicatorPer
//      x: control.leftPadding
//      y: parent.height / 2 - height / 2
//      radius: height / 2
//      border.color: control.checked ? ui.fontTipsColor : ui.fontColor

//      Rectangle {
//          id:rectRound
//          width: rectBack.height / 2
//          height: rectBack.height / 2
//          x: control.leftPadding
//          y: parent.height / 2 - height / 2
//          radius: height / 2
//          color: control.checked ? ui.fontTipsColor : ui.fontColor
//          visible: control.checked
//      }
//  }

  contentItem: Text {
      text: control.text
      font: control.font
      opacity: enabled ? 1.0 : 0.3
      color: control.checked ? ui.fontTipsColor : ui.fontColor
      horizontalAlignment: Text.AlignLeft
      verticalAlignment: Text.AlignVCenter
      width: parent.width
      wrapMode: Text.NoWrap
      elide: Text.ElideRight
      leftPadding: control.indicator.width
  }
}
