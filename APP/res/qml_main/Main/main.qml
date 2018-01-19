import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3

import com.main 1.0

import "../../qml_com"
import "../../qml_com/ComNote"

ApplicationWindow {
    visible: true
    width: global.defaultWidth
    height: global.defaultHeight
    title: qsTr("QtDemoV2")

    Loader{
        id:loader
        anchors.fill: parent
        focus: true
        onFocusChanged: {
            if(!focus){
                loader.focus = true
            }
        }
    }

    ComNote{
        id:comNote
        x:(parent.width - comNote.width) * 0.5
        y:(parent.height - comNote.height) * 0.5
        leftMargin: parent.width * 0.05
        rightMargin: parent.width * 0.05
    }

    BusyPage{
        id:busyPage
        x:(parent.width - busyPage.width) * 0.5
        y:(parent.height - busyPage.height) * 0.5
        leftMargin: parent.width * 0.05
        rightMargin: parent.width * 0.05

        modal: true
    }

    CMain{
        id:cMain
        onSignalLoadQml: {
            loader.setSource(billUrl,billData)
        }
        onSignalShowNote: {
            sysBus.signalShowSysNote(msg)
        }
    }

    Connections{
        target: sysBus

        onSignalShowSysNote: {
            comNote.text = msg
            comNote.time = time
            comNote.show()
        }

        onSignalLoadQml: {
            cMain.loadQml(billKey,initData)
        }

        onSignalLockScreen: {
            if(msg !== ""){
                busyPage.text = msg
            }
            busyPage.open()
        }

        onSignalUnlockScreen: {
            busyPage.close()
        }
    }

    Component.onCompleted: {
        cMain.loadQml("Boot")
    }
}
