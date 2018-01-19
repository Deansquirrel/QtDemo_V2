import QtQuick 2.0

Item {
    id:rootItem
    implicitHeight: global.defaultHeight
    implicitWidth: global.defaultWidth

    property alias text: textTitle.text
    property alias color: textTitle.color
    property alias font: textTitle.font

    enabled: true

    property color textEnabledColor: ui.fontColor
    property color textDisabledColor:ui.fontLightColor
    property color backEnabledColor:ui.backColor
    property color backDisabledColor:ui.winColor
    property color pressedBackColor:ui.fontLightColor

    signal clicked()

    Rectangle{
        id:rootRect
        anchors.fill: parent
        color:backEnabledColor
        Text{
            id:textTitle
            text:""
            font.pixelSize: global.em*1.5
            color:textEnabledColor
            anchors.centerIn: parent
        }
        MouseArea{
            id:mouseArea
            enabled: rootItem.enabled
            anchors.fill: parent
            onClicked: {
                if(enabled){
                    rootItem.clicked()
                }
            }
        }
    }

    states: [
        State {
          when:!rootItem.enabled
          PropertyChanges {
              target: rootRect
              color: backDisabledColor
          }
          PropertyChanges {
              target: textTitle
              color:textDisabledColor
          }
        },
        State {
          when:mouseArea.pressed
          PropertyChanges {
              target: rootRect
              color: pressedBackColor
          }
        }
    ]
}
