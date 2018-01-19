#ifndef GLOBAL_H
#define GLOBAL_H

#include <QObject>

class Global : public QObject
{
    Q_OBJECT
public:
    explicit Global(QObject *parent = nullptr);

    Q_PROPERTY(int em READ em CONSTANT)
    Q_PROPERTY(int defaultHeight READ defaultHeight CONSTANT)
    Q_PROPERTY(int defaultWidth READ defaultWidth CONSTANT)
    Q_PROPERTY(QStringList fontFamily READ fontFamily CONSTANT)
    Q_PROPERTY(QString fontStr READ fontStr CONSTANT)
    Q_PROPERTY(QString PREFIX_MONEY READ getPREFIX_MONEY CONSTANT)

    static bool isAndroid();
    static void setIsAndroid(bool isAndroid);

    static bool isWindows();
    static void setIsWindows(bool isWindows);

    static int defaultWidth();
    static void setDefaultWidth(int defaultWidth);

    static int em();
    static void setEm(int em);

    static int defaultHeight();
    static void setDefaultHeight(int defaultHeight);

    static QStringList fontFamily();
    static void setFontFamily(const QStringList &fontFamily);

    static QString fontStr();
    static void setFontStr(const QString &fontStr);

    static QString getPREFIX_MONEY();

signals:

public slots:

private:
    //运行环境记录
    static bool _isAndroid;
    static bool _isWindows;

    //系统可用字体列表
    static QStringList _fontFamily;
    static QString _fontStr;

    //单位长度
    static int _em;
    //默认宽、高
    static int _defaultWidth;
    static int _defaultHeight;

    static QString _PREFIX_MONEY;
};

#endif // GLOBAL_H
