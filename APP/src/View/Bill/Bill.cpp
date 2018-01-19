#include "Bill.h"

Bill::Bill(QObject *parent) : QObject(parent)
{
    _billUrlData.insert("Menu","qrc:/qml_main/Bill/Menu/Menu.qml");
    _billUrlData.insert("AndroidDial","qrc:/qml_main/Bill/AndroidDial/AndroidDial.qml");
    _billUrlData.insert("AndroidMap","qrc:/qml_main/Bill/AndiroidMap/AndroidMap.qml");
    _billUrlData.insert("CryptoInQt","qrc:/qml_main/Bill/CryptoInQt/CryptoInQt.qml");
    _billUrlData.insert("QMLCom","qrc:/qml_main/Bill/QMLCom/QMLCom.qml");

    _billUrlData.insert("Test","qrc:/qml_main/Bill/Test/Test.qml");

#ifdef Q_OS_ANDROID

#endif
}

void Bill::pushQml(QString billKey, QJsonObject initData)
{
    if(!_billUrlData.keys().contains(billKey)){
        QString msg = "billKey - [" + billKey + "]不存在对应的QML";
        qWarning()<<msg;
        emit this->signalShowError(msg);
        return;
    }
    emit this->signalPushQml(_billUrlData.value(billKey),initData);
}

void Bill::popQml()
{
    emit this->signalPop();
}
