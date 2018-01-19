#ifndef LIBANDROID_GLOBAL_H
#define LIBANDROID_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(LIBANDROID_LIBRARY)
#  define LIBANDROIDSHARED_EXPORT Q_DECL_EXPORT
#else
#  define LIBANDROIDSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // LIBANDROID_GLOBAL_H
