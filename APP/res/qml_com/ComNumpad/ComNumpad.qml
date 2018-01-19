import QtQuick 2.0

Item {
    id:rootItem
    implicitHeight: global.defaultHeight
    implicitWidth: global.defaultWidth

    visible: false

    property bool isBorderVisible: true
    property alias borderColor: rootRect.color
    property alias titleDone:btnDone.text
    property alias titleBack: btnBack.text

    property real fontPixelSize: global.em * 1.5

    property bool btnEnabled: true

    enabled: true

    //打开键盘
    signal opened()
    //关闭键盘
    signal closed()
    //键盘点击
    signal clicked(var msg)
    //点击完成
    signal clickDone()
    //点击退格
    signal clickBack()

    function open(){
        rootItem.visible=true
    }

    function close(){
        rootItem.visible=false
    }

    onVisibleChanged: {
        if(visible){
            opened()
        }
        else{
            closed()
        }
    }

    function subNumPressed(msg){
        if(enabled){
            rootItem.clicked(msg)
        }
    }

    Rectangle{
        id:rootRect
        anchors.fill: parent
        color:ui.fontLightColor
        anchors.topMargin: rootItem.isBorderVisible?1:0
        Row{
            width: parent.width
            height: parent.height-parent.anchors.topMargin
            anchors.bottom: parent.bottom
            spacing: parent.anchors.topMargin
            Column{
                width: (parent.width-parent.spacing*3)/4
                height: parent.height-spacing*3
                spacing: parent.spacing
                DeleteBtn{
                    width: parent.width
                    height: parent.height/4
                    text:"1"
                    font.pixelSize: rootItem.fontPixelSize
                    enabled: rootItem.btnEnabled
                    onClicked: {
                        subNumPressed(text)
                    }
                }
                DeleteBtn{
                    width: parent.width
                    height: parent.height/4
                    enabled: rootItem.btnEnabled
                    text:"4"
                    font.pixelSize: rootItem.fontPixelSize
                    onClicked: {
                        subNumPressed(text)
                    }
                }
                DeleteBtn{
                    width: parent.width
                    height: parent.height/4
                    enabled: rootItem.btnEnabled
                    text:"7"
                    font.pixelSize: rootItem.fontPixelSize
                    onClicked: {
                        subNumPressed(text)
                    }
                }
                DeleteBtn{
                    id:btnBack
                    width: parent.width
                    height: parent.height/4
                    text:"返回"
                    font.pixelSize: rootItem.fontPixelSize
                    onClicked: {
                        rootItem.close()
                    }
                }
            }
            Column{
                width: (parent.width-parent.spacing*3)/4
                height: parent.height-spacing*3
                spacing: parent.spacing
                DeleteBtn{
                    width: parent.width
                    height: parent.height/4
                    enabled: rootItem.btnEnabled
                    text:"2"
                    font.pixelSize: rootItem.fontPixelSize
                    onClicked: {
                        subNumPressed(text)
                    }
                }
                DeleteBtn{
                    width: parent.width
                    height: parent.height/4
                    enabled: rootItem.btnEnabled
                    text:"5"
                    font.pixelSize: rootItem.fontPixelSize
                    onClicked: {
                        subNumPressed(text)
                    }
                }
                DeleteBtn{
                    width: parent.width
                    height: parent.height/4
                    enabled: rootItem.btnEnabled
                    text:"8"
                    font.pixelSize: rootItem.fontPixelSize
                    onClicked: {
                        subNumPressed(text)
                    }
                }
                DeleteBtn{
                    width: parent.width
                    height: parent.height/4
                    enabled: rootItem.btnEnabled
                    text:"0"
                    font.pixelSize: rootItem.fontPixelSize
                    onClicked: {
                        subNumPressed(text)
                    }
                }
            }
            Column{
                width: (parent.width-parent.spacing*3)/4
                height: parent.height-spacing*3
                spacing: parent.spacing
                DeleteBtn{
                    width: parent.width
                    height: parent.height/4
                    enabled: rootItem.btnEnabled
                    text:"3"
                    font.pixelSize: rootItem.fontPixelSize
                    onClicked: {
                        subNumPressed(text)
                    }
                }
                DeleteBtn{
                    width: parent.width
                    height: parent.height/4
                    enabled: rootItem.btnEnabled
                    text:"6"
                    font.pixelSize: rootItem.fontPixelSize
                    onClicked: {
                        subNumPressed(text)
                    }
                }
                DeleteBtn{
                    width: parent.width
                    height: parent.height/4
                    enabled: rootItem.btnEnabled
                    text:"9"
                    font.pixelSize: rootItem.fontPixelSize
                    onClicked: {
                        subNumPressed(text)
                    }
                }
                DeleteBtn{
                    width: parent.width
                    height: parent.height/4
                    enabled: rootItem.btnEnabled
                    text:"."
                    font.pixelSize: rootItem.fontPixelSize
                    onClicked: {
                        subNumPressed(text)
                    }
                }
            }
            Column{
                width: (parent.width-parent.spacing*3)/4
                height: parent.height-spacing*1
                spacing: parent.spacing
                DeleteBtn{
                    width: parent.width
                    height: parent.height/2
//                    text:"Back"
                    font.pixelSize: rootItem.fontPixelSize
                    enabled: rootItem.btnEnabled
                    onClicked: {
                        clickBack()
                    }
                    Image{
                        source: parent.enabled?"back.png":"backDisenabled.png"
                        width: rootItem.fontPixelSize * 1.5
                        height: rootItem.fontPixelSize * 1.5
                        anchors.centerIn: parent
                    }
                }
                DeleteBtn{
                    id:btnDone
                    width: parent.width
                    height: parent.height/2
                    enabled: rootItem.btnEnabled
                    text:"完成"
                    font.pixelSize: rootItem.fontPixelSize
                    onClicked: {
                        clickDone()
                    }
                }
            }
        }
    }
}
