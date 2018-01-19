import QtQuick 2.0

import "../"

Item {
    id:rootItem
    implicitHeight: global.defaultHeight
    implicitWidth: global.defaultWidth

    property alias title: textTitle.text
    property alias leftImageSource: imageLeft.source
    property alias rightImageSource: imageRight.source

    property bool showRight: false


    signal titleClicked()
    signal goBack()
    signal rightClicked()

    Rectangle{
        id:recctTitle
        width: parent.width
        height: parent.height
        anchors.horizontalCenter: parent.horizontalCenter
        color:"white"
        Row{
            width: parent.width * 0.9
            height: parent.height
            anchors.horizontalCenter: parent.horizontalCenter
            Item{
                id:itemLeft
                width: global.em * 2
                height: global.em * 2
                anchors.verticalCenter: parent.verticalCenter
                Image {
                    id:imageLeft
                    source: "qrc:/image/backBlack.png"
                    width: global.em
                    height: global.em
                    anchors.left: parent.left
                    anchors.verticalCenter: parent.verticalCenter
                }
                MouseArea{
                    anchors.fill: parent
                    onClicked: {
                        rootItem.goBack()
                    }
                }
            }
            Text {
                id:textTitle
                width: parent.width - itemLeft.width - itemRight.width
                wrapMode: Text.NoWrap
                elide: Text.ElideRight
                anchors.verticalCenter: parent.verticalCenter
                MouseArea{
                    anchors.fill: parent
                    onClicked: {
                        rootItem.titleClicked()
                    }
                }
            }
            Item{
                id:itemRight
                width: global.em * 2
                height: global.em * 2
                anchors.verticalCenter: parent.verticalCenter

                visible: rootItem.showRight

                Image {
                    id:imageRight
                    source: "qrc:/image/saveBlack.png"
                    width: global.em
                    height: global.em
                    anchors.right: parent.right
                    anchors.verticalCenter: parent.verticalCenter
                }
                MouseArea{
                    anchors.fill: parent
                    onClicked: {
                        if(rootItem.showRight){
                            rootItem.rightClicked()
                        }
                    }
                }
            }
        }

        Rectangle{
            width: parent.width
            height: 1
            color:ui.fontLightColor
            anchors.bottom: parent.bottom
        }
    }
}
