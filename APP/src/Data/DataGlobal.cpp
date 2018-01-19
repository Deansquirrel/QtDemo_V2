#include "DataGlobal.h"

bool DataGlobal::_isLoggerEnabled = false;
QString DataGlobal::_loggerLevel = "";

DataGlobal::DataGlobal(QObject *parent) : QObject(parent)
{

}

void DataGlobal::updateLoggerSettings(bool logenabled, QString loggerLevel)
{
    _isLoggerEnabled = logenabled;
    _loggerLevel = loggerLevel;
}

bool DataGlobal::isLoggerEnabled()
{
    return _isLoggerEnabled;
}

void DataGlobal::setIsLoggerEnabled(bool isLoggerEnabled)
{
    _isLoggerEnabled = isLoggerEnabled;
}

QString DataGlobal::loggerLevel()
{
    return _loggerLevel;
}

void DataGlobal::setLoggerLevel(const QString &loggerLevel)
{
    _loggerLevel = loggerLevel;
}
