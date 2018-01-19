QT += qml quick gui core positioning multimedia

android {
    QT += androidextras
}

CONFIG += c++11

#-----------------------------------------------------------------------------------------
#是否为调试模式，正式编译时注释下面一行
DEFINES += DEBUG_MODE
#禁用日志输出，正式编译时注释下面一行
DEFINES += DISABLE_LOG_OUTPUT
#-----------------------------------------------------------------------------------------

#Release模式下，日志输出文件及行号
DEFINES += QT_MESSAGELOGCONTEXT

SOURCES += main.cpp \
    src/Share/Global.cpp \
    src/Share/UI.cpp \
    src/View/CMain.cpp \
    src/View/Boot/Boot.cpp \
    src/Bus/SysBus.cpp \
    src/Data/DataCache.cpp \
    src/Data/DataGlobal.cpp \
    src/Data/DataProvider.cpp \
    src/View/Bill/Bill.cpp \
    src/View/Bill/Menu/Menu.cpp \
    src/View/Bill/AndroidDial/AndroidDial.cpp \
    src/View/Bill/Test/Test.cpp \
    src/View/Bill/AndroidMap/AndroidMap.cpp \
    src/Share/QNativeMethods.cpp \
    src/Plugin/AMap/AMapLocation.cpp \
    src/Plugin/AMap/AMapLocationJavaHandle.cpp \
    src/View/Bill/CryptoInQt/CryptoInQt.cpp \
    src/Plugin/AMap/AMapPoiSearchJavaHandle.cpp \
    src/Plugin/AMap/AMapPoiSearch.cpp \
    src/Plugin/Tools/Tools.cpp \
    src/Plugin/Tools/ToolsJavaHandle.cpp \
    src/Plugin/AMap/AMapNaviJavaHandle.cpp \
    src/Plugin/AMap/AMapNavi.cpp \
    src/View/Bill/QMLCom/QMLCom.cpp

RESOURCES += res/qml_main.qrc \
    res/image.qrc \
    res/qml_com.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RC_FILE = ./myapp.rc

HEADERS += \
    src/Share/Global.h \
    src/Share/UI.h \
    src/View/CMain.h \
    src/View/Boot/Boot.h \
    src/Bus/SysBus.h \
    src/Data/DataCache.h \
    src/Data/DataGlobal.h \
    src/Data/DataProvider.h \
    src/View/Bill/Bill.h \
    src/View/Bill/Menu/Menu.h \
    src/View/Bill/AndroidDial/AndroidDial.h \
    src/View/Bill/Test/Test.h \
    src/View/Bill/AndroidMap/AndroidMap.h \
    src/Share/QNativeMethods.h \
    src/Plugin/AMap/AMapLocation.h \
    src/Plugin/AMap/AMapLocationJavaHandle.h \
    src/View/Bill/CryptoInQt/CryptoInQt.h \
    src/Plugin/AMap/AMapPoiSearchJavaHandle.h \
    src/Plugin/AMap/AMapPoiSearch.h \
    src/Plugin/Tools/Tools.h \
    src/Plugin/Tools/ToolsJavaHandle.h \
    src/Plugin/AMap/AMapNaviJavaHandle.h \
    src/Plugin/AMap/AMapNavi.h \
    src/View/Bill/QMLCom/QMLCom.h

DISTFILES += \
    android/AndroidManifest.xml \
    android/gradle/wrapper/gradle-wrapper.jar \
    android/gradlew \
    android/res/values/libs.xml \
    android/build.gradle \
    android/gradle/wrapper/gradle-wrapper.properties \
    android/gradlew.bat \
    androidLib/libcrypto.so \
    androidLib/libssl.so \
    android/AndroidManifest.xml \
    android/gradle/wrapper/gradle-wrapper.jar \
    android/gradlew \
    android/res/values/libs.xml \
    android/build.gradle \
    android/gradle/wrapper/gradle-wrapper.properties \
    android/gradlew.bat \
    android/res/values/color.xml \
    android/res/values/strings.xml \
    android/res/values/style.xml \
    android/res/values-zh-rCN/strings.xml \
    androidKeyStore/android_release.keystore \
    android/lib/AMap2DMap_5.2.0_AMapSearch_5.3.1_AMapLocation_3.5.0_20170817.jar \
    android/libs/AMap2DMap_5.2.0_AMapSearch_5.3.1_AMapLocation_3.5.0_20170817.jar \
    android/libs/AMap.jar \
    android/libs/armeabi/libGNaviData.so \
    android/libs/armeabi/libGNaviGuide.so \
    android/libs/armeabi/libGNaviMap.so \
    android/libs/armeabi/libGNaviMapex.so \
    android/libs/armeabi/libGNaviPos.so \
    android/libs/armeabi/libGNaviRoute.so \
    android/libs/armeabi/libGNaviSearch.so \
    android/libs/armeabi/libGNaviUtils.so \
    android/libs/armeabi/libRoadLineRebuildAPI.so \
    android/libs/armeabi/librtbt800.so \
    android/libs/armeabi/libwtbt800.so \
    android/libs/armeabi-v7a/libGNaviData.so \
    android/libs/armeabi-v7a/libGNaviGuide.so \
    android/libs/armeabi-v7a/libGNaviMap.so \
    android/libs/armeabi-v7a/libGNaviMapex.so \
    android/libs/armeabi-v7a/libGNaviPos.so \
    android/libs/armeabi-v7a/libGNaviRoute.so \
    android/libs/armeabi-v7a/libGNaviSearch.so \
    android/libs/armeabi-v7a/libGNaviUtils.so \
    android/libs/armeabi-v7a/libRoadLineRebuildAPI.so \
    android/libs/armeabi-v7a/librtbt800.so \
    android/libs/armeabi-v7a/libwtbt800.so \
    android/libs/Tools.jar \
    android/libs/AMap3DMap_5.3.0_AMapNavi_5.3.0_AMapSearch_5.3.1_AMapLocation_3.6.0_20170918.jar \
    android/libs/armeabi-v7a/libGNaviData.so \
    android/libs/armeabi-v7a/libGNaviGuide.so \
    android/libs/armeabi-v7a/libGNaviMap.so \
    android/libs/armeabi-v7a/libGNaviMapex.so \
    android/libs/armeabi-v7a/libGNaviPos.so \
    android/libs/armeabi-v7a/libGNaviRoute.so \
    android/libs/armeabi-v7a/libGNaviSearch.so \
    android/libs/armeabi-v7a/libGNaviUtils.so \
    android/libs/armeabi-v7a/libRoadLineRebuildAPI.so \
    android/libs/armeabi-v7a/librtbt800.so \
    android/libs/armeabi-v7a/libwtbt800.so

ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android

contains(ANDROID_TARGET_ARCH,armeabi-v7a) {
    ANDROID_EXTRA_LIBS = \
        $$PWD/androidLib/libcrypto.so \
        $$PWD/androidLib/libssl.so
}

#android
#{
#  ANDROID_EXTRA_LIBS += $$PWD/androidLib/libcrypto.so
#  ANDROID_EXTRA_LIBS += $$PWD/androidLib/libssl.so
#}

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../LibLogger/release/ -lLibLogger
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../LibLogger/debug/ -lLibLogger
else:unix: LIBS += -L$$OUT_PWD/../LibLogger/ -lLibLogger

INCLUDEPATH += $$PWD/../LibLogger
DEPENDPATH += $$PWD/../LibLogger

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../LibCommon/release/ -lLibCommon
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../LibCommon/debug/ -lLibCommon
else:unix: LIBS += -L$$OUT_PWD/../LibCommon/ -lLibCommon

INCLUDEPATH += $$PWD/../LibCommon
DEPENDPATH += $$PWD/../LibCommon

android{
    LIBS += -L$$OUT_PWD/../LibAndroid/ -lLibAndroid

    INCLUDEPATH += $$PWD/../LibAndroid
    DEPENDPATH += $$PWD/../LibAndroid
}
#unix:!macx: LIBS += -L$$OUT_PWD/../LibAndroid/ -lLibAndroid

#INCLUDEPATH += $$PWD/../LibAndroid
#DEPENDPATH += $$PWD/../LibAndroid

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../LibCryptoInQt/release/ -lLibCryptoInQt
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../LibCryptoInQt/debug/ -lLibCryptoInQt
else:unix: LIBS += -L$$OUT_PWD/../LibCryptoInQt/ -lLibCryptoInQt

INCLUDEPATH += $$PWD/../LibCryptoInQt
DEPENDPATH += $$PWD/../LibCryptoInQt
