import QtQuick 2.0

import "../../../qml_com"

Rectangle{
    id:rootRect
    implicitHeight: global.defaultHeight
    implicitWidth: global.defaultWidth

    property alias text: text.text

    signal clicked();

    Text{
        id:text
        width: parent.width * 0.9
        wrapMode: Text.NoWrap
        elide: Text.ElideRight
        horizontalAlignment: Text.AlignHCenter
        text:modelData.showName
        anchors.centerIn: parent
    }

    MouseArea{
        anchors.fill: parent
        onClicked: {
            rootRect.clicked()
        }
    }
}
