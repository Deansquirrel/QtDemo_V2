#include "LibAndroid.h"


LibAndroid::LibAndroid()
{
}

void LibAndroid::dialPhone(QString phone, bool dial) throw(QString)
{
    LibAndroidDial libAndroidDial;
    try{
        libAndroidDial.handleDialPhone(phone,dial);
    }
    catch(QString msg){
        throw msg;
    }
}
