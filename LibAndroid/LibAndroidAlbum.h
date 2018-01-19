#ifndef LIBANDROIDALBUM_H
#define LIBANDROIDALBUM_H

#include <QObject>
#ifdef Q_OS_ANDROID
#include <QAndroidJniObject>
#include <QAndroidJniEnvironment>
#endif

class LibAndroidAlbum : public QObject
{
    Q_OBJECT
public:
    explicit LibAndroidAlbum(QObject *parent = nullptr);

    void getPicPath();

signals:

public slots:
};

#endif // LIBANDROIDALBUM_H
