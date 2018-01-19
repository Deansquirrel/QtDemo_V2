#ifndef LIBLOGGER_H
#define LIBLOGGER_H

#include "liblogger_global.h"
#include "LibLoggerWorker.h"

#include <QString>

class LIBLOGGERSHARED_EXPORT LibLogger
{

public:
    LibLogger();

    enum LogLevel {
        LOGLEVEL_DEBUG,
        LOGLEVEL_INFO,
        LOGLEVEL_WARN,
        LOGLEVEL_ERROR};

    void loggerInit(QString logPath,QString folder,QString filePrefix,QString fileSuffix,LogLevel level);
    QString getLoggerPath();
    QString getLoggerFolder();
    QString getLoggerLevel();
    void setLoggerLevel(const LogLevel &level);

    bool getEnabled();
    void setEnabled(bool enabled);

    void outputMessage(QtMsgType type, const QMessageLogContext &context, const QString &msg);

    QString logLevelToString(LibLogger::LogLevel level);
    LibLogger::LogLevel logLevelFromString(QString level);

private:
    LibLoggerWorker _libLoggerWorker;
    LibLoggerWorker::LogLevel _logLevelConvert(LogLevel level);
};

#endif // LIBLOGGER_H
