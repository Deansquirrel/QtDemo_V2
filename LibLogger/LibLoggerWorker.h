#ifndef LIBLOGGERWORKER_H
#define LIBLOGGERWORKER_H

#include <QString>
#include <QDir>
#include <QStandardPaths>
#include <QFile>

#include <QMessageLogContext>
#include <QDateTime>
#include <QTextStream>
#include <QMutex>
#include <QDebug>

class LibLoggerWorker
{
public:
    explicit LibLoggerWorker();

    enum LogLevel {
        LOGLEVEL_DEBUG,
        LOGLEVEL_INFO,
        LOGLEVEL_WARN,
        LOGLEVEL_ERROR};

    static void init(QString logPath,QString folder,QString filePrefix,QString fileSuffix,LogLevel level);

    static QString getPath(){ return _logPath;}
    static QString getFolder(){return _folder;}
    static QString getLevel();
    static void setLevel(const LogLevel &level);

    void outputMessage(QtMsgType type, const QMessageLogContext &context, const QString &msg);

    static bool getEnabled();
    static void setEnabled(bool enabled);

signals:

private:
    static bool _enabled;

    static QString _logPath;
    static QString _folder;
    static QString _filePrefix;
    static QString _fileSuffix;
    static LogLevel _level;

    void _createFolder();
    void _writeLog(LogLevel level,const QMessageLogContext &context,QString msg);
};

#endif // LIBLOGGERWORKER_H
