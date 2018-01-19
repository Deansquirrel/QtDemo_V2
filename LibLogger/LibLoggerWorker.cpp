#include "LibLoggerWorker.h"

bool LibLoggerWorker::_enabled = false;
QString LibLoggerWorker::_logPath = "";
QString LibLoggerWorker::_folder = "log";
QString LibLoggerWorker::_filePrefix = "";
QString LibLoggerWorker::_fileSuffix = "log";
LibLoggerWorker::LogLevel LibLoggerWorker::_level = LibLoggerWorker::LOGLEVEL_WARN;

LibLoggerWorker::LibLoggerWorker()
{

}

void LibLoggerWorker::init(QString logPath, QString folder, QString filePrefix, QString fileSuffix, LibLoggerWorker::LogLevel level)
{
    if(!logPath.endsWith("/")){
        logPath = logPath + "/";
    }
    if(logPath!="/"){
        _logPath = logPath;
    }
    _folder = folder;
    _filePrefix = filePrefix;
    _fileSuffix = fileSuffix;
    _level = level;
}

QString LibLoggerWorker::getLevel()
{
    switch (_level) {
    case LibLoggerWorker::LOGLEVEL_DEBUG:
        return "DEBUG";
    case LibLoggerWorker::LOGLEVEL_INFO:
        return "INFO";
    case LibLoggerWorker::LOGLEVEL_WARN:
        return "WARN";
    case LibLoggerWorker::LOGLEVEL_ERROR:
        return "ERROR";
    default:
        return "undefined";
    }
}

void LibLoggerWorker::outputMessage(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    LogLevel level;
    switch (type) {
    case QtDebugMsg:
        level = LibLoggerWorker::LOGLEVEL_DEBUG;
        break;
    case QtInfoMsg:
        level = LibLoggerWorker::LOGLEVEL_INFO;
        break;
    case QtWarningMsg:
        level = LibLoggerWorker::LOGLEVEL_WARN;
        break;
    case QtCriticalMsg:
        level = LibLoggerWorker::LOGLEVEL_ERROR;
        break;
    case QtFatalMsg:
        level = LibLoggerWorker::LOGLEVEL_ERROR;
        break;
    default:
        level = LibLoggerWorker::LOGLEVEL_DEBUG;
        break;
    }
    if(level>=this->_level){
        this->_writeLog(level,context,msg);
    }
}

bool LibLoggerWorker::getEnabled()
{
    return _enabled;
}

void LibLoggerWorker::setEnabled(bool enabled)
{
    _enabled = enabled;
}

void LibLoggerWorker::setLevel(const LogLevel &level)
{
    _level = level;
}

void LibLoggerWorker::_createFolder()
{
    QDir dir(_logPath);
    if(!dir.exists(_folder)){
        dir.mkdir(_folder);
    }
}

void LibLoggerWorker::_writeLog(LogLevel level, const QMessageLogContext &context, QString msg)
{
    static QMutex mutex;
    mutex.lock();

    QString text;
    switch (level) {
    case LibLoggerWorker::LOGLEVEL_DEBUG:
        text = "DEBUG";
        break;
    case LibLoggerWorker::LOGLEVEL_INFO:
        text = "INFO";
        break;
    case LibLoggerWorker::LOGLEVEL_WARN:
        text = "WARN";
        break;
    case LibLoggerWorker::LOGLEVEL_ERROR:
        text = "ERROR";
        break;
    default:
        text = "WARN";
        break;
    }
    QString context_info = QString("File:(%1) Line:(%2)").arg(QString(context.file)).arg(context.line);
    QString current_date_time = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss zzz");
    QString current_date = QDate::currentDate().toString("yyyyMMdd");
    QString message = QString("%1 %2 %3 %4").arg(current_date_time).arg(text).arg(context_info).arg(msg);

    this->_createFolder();
//    QString logPath = QStandardPaths::writableLocation((QStandardPaths::GenericDataLocation));

    QFile file(_logPath + this->_folder + "/" + this->_filePrefix + current_date + "." + this->_fileSuffix);

    file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text);
    QTextStream text_stream(&file);
    text_stream << message << endl;
    file.flush();
    file.close();
    mutex.unlock();
}
