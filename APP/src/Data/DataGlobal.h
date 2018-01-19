#ifndef DATAGLOBAL_H
#define DATAGLOBAL_H

#include <QObject>
#include <QDebug>

class DataGlobal : public QObject
{
    Q_OBJECT
public:
    explicit DataGlobal(QObject *parent = nullptr);

    Q_PROPERTY(bool isLoggerEnabled READ isLoggerEnabled CONSTANT)
    Q_PROPERTY(QString loggerLevel READ loggerLevel CONSTANT)

    void updateLoggerSettings(bool logenabled,QString loggerLevel);

    static bool isLoggerEnabled();
    static void setIsLoggerEnabled(bool isLoggerEnabled);

    static QString loggerLevel();
    static void setLoggerLevel(const QString &loggerLevel);

signals:

public slots:

private:
    //LoggerInfo
    //是否启用Logger
    static bool _isLoggerEnabled;
    //Logger Level
    static QString _loggerLevel;
};

#endif // DATAGLOBAL_H
