import QtQuick 2.7
import QtQuick.Controls 2.1

import "../"

Popup{
    id:popup

    property alias text: label.text
    property int time: 3000
    property real fontPixelSize:global.em

    background: Rectangle{
        radius: 3
        color: "black"
        opacity: 0.8
    }

    onClosed: {
        label.text = ""
    }

    function show(){
        if(noteShow.running){
            noteShow.restart()
        }
        else{
            noteShow.start()
        }
    }


    contentItem: Text{
        id: label
        color:"white"
        width: parent.width
        font.pixelSize: fontPixelSize
        wrapMode: Text.WrapAtWordBoundaryOrAnywhere
    }

    SequentialAnimation
    {
        id:noteShow
        NumberAnimation
        {
            target: popup
            property: "opacity"
            from: 0
            to: 1
            duration: 1000
            easing.type:Easing.Linear
        }
        NumberAnimation
        {
            target: popup
            property: "opacity"
            from: 1
            to: 1
            duration: popup.time < 2000?0:popup.time - 2000
            easing.type:Easing.Linear
        }
        NumberAnimation
        {
            target: popup
            property: "opacity"
            from: 1
            to: 0
            duration: 1000
            easing.type:Easing.Linear
        }

        onRunningChanged: {
            if(running){
                popup.open()
            }
            else{
                popup.close()
            }
        }
    }
}
