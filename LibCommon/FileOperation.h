#ifndef FILEOPERATION_H
#define FILEOPERATION_H

#include <QString>
#include <QSettings>
#include <QTextCodec>
#include <QByteArray>

class FileOperation
{
public:
    FileOperation();

    QString readIniFile(QString file,QString group,QString key,QString defaultValue);
    void writeIniFile(QString file,QString group,QString key,QString value);

private:
    QByteArray _codeFormat;
};

#endif // FILEOPERATION_H
