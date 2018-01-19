#ifndef LIBCOMMON_H
#define LIBCOMMON_H

#include "libcommon_global.h"
#include "FileOperation.h"
#include "Environmental.h"
#include "SubCommon.h"

class LIBCOMMONSHARED_EXPORT LibCommon
{

public:
    LibCommon();

    //FileOperation
    QString readIniFile(QString file,QString group,QString key,QString defaultValue);
    void writeIniFile(QString file,QString group,QString key,QString value);

    //Environmental
    QString getLocalMac();
    QString getLocalHostName();
    QString getLocalIP();

    //SubCommon
    QString getMD5(QString data);

private:
    FileOperation _fileOperation;
};

#endif // LIBCOMMON_H
