#-------------------------------------------------
#
# Project created by QtCreator 2017-03-28T22:24:30
#
#-------------------------------------------------

QT       -= gui
QT      +=network

TARGET = LibCommon
TEMPLATE = lib

DEFINES += LIBCOMMON_LIBRARY

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

#Release模式下，日志输出文件及行号
DEFINES += QT_MESSAGELOGCONTEXT

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += LibCommon.cpp \
    FileOperation.cpp \
    Environmental.cpp \
    SubCommon.cpp

HEADERS += LibCommon.h\
        libcommon_global.h \
    FileOperation.h \
    Environmental.h \
    SubCommon.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
