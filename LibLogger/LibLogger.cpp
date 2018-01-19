#include "LibLogger.h"

LibLogger::LibLogger()
{
}

void LibLogger::loggerInit(QString logPath,QString folder, QString filePrefix, QString fileSuffix, LogLevel level)
{
    _libLoggerWorker.init(logPath,folder,filePrefix,fileSuffix,this->_logLevelConvert(level));
}

QString LibLogger::getLoggerPath()
{
    return _libLoggerWorker.getPath();
}

QString LibLogger::getLoggerFolder()
{
    return _libLoggerWorker.getFolder();
}

QString LibLogger::getLoggerLevel()
{
    return _libLoggerWorker.getLevel();
}

void LibLogger::setLoggerLevel(const LogLevel &level)
{
    _libLoggerWorker.setLevel(this->_logLevelConvert(level));
}

bool LibLogger::getEnabled()
{
    return _libLoggerWorker.getEnabled();
}

void LibLogger::setEnabled(bool enabled)
{
    _libLoggerWorker.setEnabled(enabled);
}

void LibLogger::outputMessage(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    if(getEnabled()){
        _libLoggerWorker.outputMessage(type,context,msg);
    }
}

QString LibLogger::logLevelToString(LibLogger::LogLevel level)
{
    QString strLogLevel = "";
    switch (level) {
    case LibLogger::LOGLEVEL_DEBUG:
        strLogLevel = "DEBUG";
        break;
    case LibLogger::LOGLEVEL_INFO:
        strLogLevel = "INFO";
        break;
    case LibLogger::LOGLEVEL_WARN:
        strLogLevel = "WARN";
        break;
    case LibLogger::LOGLEVEL_ERROR:
        strLogLevel = "ERROR";
        break;
    default:
        strLogLevel = "WARN";
        break;
    }
    return strLogLevel;
}

LibLogger::LogLevel LibLogger::logLevelFromString(QString level)
{
    LibLogger::LogLevel logLevel = LibLogger::LOGLEVEL_WARN;
    if(level == "DEBUG") logLevel = LibLogger::LOGLEVEL_DEBUG;
    if(level == "INFO") logLevel = LibLogger::LOGLEVEL_INFO;
    if(level == "WARN") logLevel = LibLogger::LOGLEVEL_WARN;
    if(level == "ERROR") logLevel = LibLogger::LOGLEVEL_ERROR;
    return logLevel;
}

LibLoggerWorker::LogLevel LibLogger::_logLevelConvert(LibLogger::LogLevel level)
{
    LibLoggerWorker::LogLevel logLevel;
    switch (level) {
    case LibLogger::LOGLEVEL_DEBUG:
        logLevel=LibLoggerWorker::LOGLEVEL_DEBUG;
        break;
    case LibLogger::LOGLEVEL_INFO:
        logLevel=LibLoggerWorker::LOGLEVEL_INFO;
        break;
    case LibLogger::LOGLEVEL_WARN:
        logLevel=LibLoggerWorker::LOGLEVEL_WARN;
        break;
    case LibLogger::LOGLEVEL_ERROR:
        logLevel=LibLoggerWorker::LOGLEVEL_ERROR;
        break;
    default:
        logLevel=LibLoggerWorker::LOGLEVEL_WARN;
        break;
    }
    return logLevel;
}
