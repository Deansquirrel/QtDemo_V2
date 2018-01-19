#include "FileOperation.h"

FileOperation::FileOperation()
{
    this->_codeFormat = "UTF-8";
}

QString FileOperation::readIniFile(QString file, QString group, QString key, QString defaultValue)
{
    QSettings* qSettings = new QSettings(file,QSettings::IniFormat);
//    qSettings->setIniCodec(QTextCodec::codecForName("GB18030"));
//    qSettings->setIniCodec(QTextCodec::codecForName("UTF-8"));
    qSettings->setIniCodec(QTextCodec::codecForName(this->_codeFormat));
    QString result = "";
    qSettings->beginGroup(group);
    result = qSettings->value(key,defaultValue).toString();
    qSettings->endGroup();
    delete qSettings;
    return result;
}

void FileOperation::writeIniFile(QString file, QString group, QString key, QString value)
{
    QSettings* qSettings = new QSettings(file,QSettings::IniFormat);
//    qSettings->setIniCodec(QTextCodec::codecForName("GB18030"));
//    qSettings->setIniCodec(QTextCodec::codecForName("UTF-8"));
    qSettings->setIniCodec(QTextCodec::codecForName(this->_codeFormat));
    qSettings->beginGroup(group);
    qSettings->setValue(key,value);
    qSettings->endGroup();
    qSettings->sync();
    delete qSettings;
}
