#ifndef LIBCRYPTOINQT_GLOBAL_H
#define LIBCRYPTOINQT_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(LIBCRYPTOINQT_LIBRARY)
#  define LIBCRYPTOINQTSHARED_EXPORT Q_DECL_EXPORT
#else
#  define LIBCRYPTOINQTSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // LIBCRYPTOINQT_GLOBAL_H