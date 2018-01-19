#ifndef TOOLSJAVAHANDLE_H
#define TOOLSJAVAHANDLE_H

#include <QObject>

class ToolsJavaHandle : public QObject
{
    Q_OBJECT
public:
    explicit ToolsJavaHandle(QObject *parent = nullptr);

#ifdef Q_OS_ANDROID
    //消息提示
    void showMessage(QString msg) throw(QString);
#endif

#ifdef Q_OS_ANDROID
    //Native方法注册
    void registerNativeMethods() throw(QString);
#endif

signals:

public slots:

private:
    const char* JAR_TOOLS_TOOLS = "com/yuansong/tools/Tools";
    const char* JAR_TOOLS_TOOLS_SHOWMESSAGE = "showMessage";
};

#endif // TOOLSJAVAHANDLE_H
