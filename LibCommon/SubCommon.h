#ifndef SUBCOMMON_H
#define SUBCOMMON_H

#include <QString>
#include <QByteArray>
#include <QCryptographicHash>

class SubCommon
{
public:
    SubCommon();

    QString getMD5(QString data);
};

#endif // SUBCOMMON_H
