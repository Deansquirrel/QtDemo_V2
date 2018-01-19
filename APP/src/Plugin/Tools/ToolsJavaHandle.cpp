#include "ToolsJavaHandle.h"

ToolsJavaHandle::ToolsJavaHandle(QObject *parent) : QObject(parent)
{

}

#ifdef Q_OS_ANDROID
void ToolsJavaHandle::showMessage(QString msg) throw(QString)
{

}
#endif

#ifdef Q_OS_ANDROID
void ToolsJavaHandle::registerNativeMethods() throw(QString)
{

}
#endif
