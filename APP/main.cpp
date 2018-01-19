#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <QDebug>
#include <QFontDatabase>
#include <QQmlContext>
#include <QTextCodec>
#include <QFont>

#include "src/Share/Global.h"
#include "src/Share/UI.h"

#include "src/Bus/SysBus.h"

#include "src/Data/DataGlobal.h"
#include "src/Data/DataCache.h"

#include "src/View/CMain.h"
#include "src/View/Boot/Boot.h"

#include "LibLogger.h"

#ifndef  DISABLE_LOG_OUTPUT
void myMessageOutput(QtMsgType type,const QMessageLogContext &context,const QString &msg){
    LibLogger libLogger;
    libLogger.outputMessage(type,context,msg);
}
#endif

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QCoreApplication::setAttribute(Qt::AA_UseSoftwareOpenGL);

    QGuiApplication app(argc, argv);
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
    QQmlApplicationEngine engine;

#ifndef  DISABLE_LOG_OUTPUT
    qInstallMessageHandler(myMessageOutput);
#endif

    //--------------------------------------------------------------------------------
    //解析启动参数
//    QStringList arg =  app.arguments();
//    qInfo()<<"启动参数 - " << arg;
    //--------------------------------------------------------------------------------

    //--------------------------------------------------------------------------------
    //环境定义
#ifdef Q_OS_ANDROID
    Global::setIsAndroid(true);
#endif
#ifdef Q_OS_WIN
    Global::setIsWindows(true);
#endif
    //--------------------------------------------------------------------------------
    //注册启动前QML必用CPP类
    qmlRegisterType<CMain>("com.main",1,0,"CMain");
    qmlRegisterType<Boot>("com.boot",1,0,"CBoot");
    //--------------------------------------------------------------------------------
    //注册QML全局对象
    Global global;
    engine.rootContext()->setContextProperty("global",&global);
    DataGlobal dataGlobal;
    engine.rootContext()->setContextProperty("dataGlobal",&dataGlobal);
    DataCache dataCache;
    engine.rootContext()->setContextProperty("dataCache",&dataCache);
    UI ui;
    engine.rootContext()->setContextProperty("ui",&ui);
    //--------------------------------------------------------------------------------
    //注册全局BUS
    SysBus sysBus;
    engine.rootContext()->setContextProperty("sysBus",&sysBus);
    //--------------------------------------------------------------------------------
    //界面元素初始化
    Global::setEm(16);


    //--------------------------------------------------------------------------------
    //字体定义
    QFontDatabase fontDatabase;

    QStringList fontList=fontDatabase.families(QFontDatabase::Any);
    Global::setFontFamily(fontList);

    QString fontName="";

#ifdef Q_OS_ANDROID
    //定义安卓下默认字体
    if(fontList.contains("Roboto")){
        fontName="Roboto";
    }
    if(fontList.contains("Noto Sans SC")){
        fontName="Noto Sans SC";
    }
#endif
#ifdef Q_OS_WIN
    //定义Windows下默认字体
    if(fontList.contains("黑体")){
        fontName="黑体";
    }
    if(fontList.contains("微软雅黑")){
        fontName="微软雅黑";
    }
    if(fontList.contains("Microsoft YaHei UI")){
        fontName="Microsoft YaHei UI";
    }
#endif
    QFont qFont = app.font();
    qFont.setPixelSize(global.em());
    if(fontName!=""){
        qFont.setFamily(fontName);
    }
    Global::setFontStr(fontName);
    QGuiApplication::setFont(qFont);

    //--------------------------------------------------------------------------------

#ifdef Q_OS_ANDROID
    Global::setDefaultHeight(618);
    Global::setDefaultWidth(360);
#endif
#ifdef Q_OS_WIN
    Global::setDefaultHeight(480);
    Global::setDefaultWidth(640);

    Global::setDefaultHeight(640);
    Global::setDefaultWidth(360);

#endif

    //--------------------------------------------------------------------------------
    //注册Native方法
//    AMap aMap;
//    try{
//        aMap.startLocation();
//    }catch(QString errMsg){
//        qWarning()<<errMsg;
//    }
    //--------------------------------------------------------------------------------


    engine.load(QUrl(QLatin1String("qrc:/qml_main/Main/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
