import QtQuick 2.6
import QtQuick.Controls 2.1

Button {
      id: control
      text: qsTr("Button")

      implicitHeight: textItem.implicitHeight * 1.2
      implicitWidth: textItem.implicitWidth + textItem.implicitHeight * 0.5

      property alias backColor:rectBack.color
//      property alias borderColor: rectBack.border.color
      property color borderColor: ui.themeColor
//      property alias borderWidth: rectBack.border.width
      property int borderWidth: 0
      property alias fontColor: textItem.color

      font.pixelSize: global.em
      font.family: global.fontStr

      contentItem: Text {
          id:textItem
          text: control.text
          font: control.font
          opacity: control.enabled ? 1.0 : 0.3
          color:"white"
          horizontalAlignment: Text.AlignHCenter
          verticalAlignment: Text.AlignVCenter
          elide: Text.ElideRight
      }

      background: Rectangle {
          id:rectBack
          radius: 3
          color:ui.themeColor
          implicitWidth: 100
          implicitHeight: 40
          opacity: control.enabled ? 1 : 0.3
          border.color: control.borderColor
          border.width: control.borderWidth
      }
  }
