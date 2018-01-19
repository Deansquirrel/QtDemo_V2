#ifndef LIBANDROID_H
#define LIBANDROID_H

#include "libandroid_global.h"

#include "LibAndroidDial.h"

class LIBANDROIDSHARED_EXPORT LibAndroid
{

public:
    LibAndroid();

    QString getAndroidPicture();

    void dialPhone(QString phone, bool dial = false) throw(QString);
};

#endif // LIBANDROID_H
