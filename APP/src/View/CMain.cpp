#include "CMain.h"

CMain::CMain(QObject *parent) : QObject(parent)
{
    _billUrlData.insert("Boot","qrc:/qml_main/Boot/Boot.qml");
    _billUrlData.insert("Bill","qrc:/qml_main/Bill/Bill.qml");
}

void CMain::loadQml(QString billKey, QJsonObject initData)
{
    if(!_billUrlData.keys().contains(billKey)){
        qWarning()<<"billKey - [" + billKey + "]不存在对应的QML";
        //billKey不存在时，加载 BOOT
        billKey = "Boot";
    }
    emit this->signalLoadQml(_billUrlData.value(billKey),initData);
}
