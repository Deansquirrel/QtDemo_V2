#include "Boot.h"

Boot::Boot(QObject *parent) : QObject(parent)
{

}

void Boot::handleBoot()
{
    //注册QML可用CPP类型
    registerType();
    //------------------------------------------------------------------------------------------------------------------
    //LibLogger
#ifndef DISABLE_LOG_OUTPUT
    LibLogger libLogger;
    libLogger.setEnabled(true);
    QString logFolder = "";
    #ifdef Q_OS_ANDROID
        logFolder = QStandardPaths::writableLocation((QStandardPaths::GenericDataLocation));
    #endif
    libLogger.loggerInit(
                logFolder,
                "A_myLog",
                "",
                "log",
                LibLogger::LOGLEVEL_INFO);
#endif
    //------------------------------------------------------------------------------------------------------------------
    emit this->signalBootFinished();
}

void Boot::registerType()
{
    qmlRegisterType<Bill>("com.bill",1,0,"CBill");
    qmlRegisterType<Menu>("com.bill.menu",1,0,"CMenu");
    qmlRegisterType<AndroidDial>("com.bill.androiddial",1,0,"CAndroidDial");
    qmlRegisterType<AndroidMap>("com.bill.androidmap",1,0,"CAndroidMap");
    qmlRegisterType<CryptoInQt>("com.bill.cryptoinqt",1,0,"CCryptoInQt");
    qmlRegisterType<CryptoInQt>("com.bill.qmlcom",1,0,"CQMLCom");

    qmlRegisterType<Test>("com.bill.test",1,0,"CTest");
}
