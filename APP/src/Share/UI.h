#ifndef UI_H
#define UI_H

#include <QObject>

class UI : public QObject
{
    Q_OBJECT
public:
    explicit UI(QObject *parent = nullptr);

    Q_PROPERTY(QString backColor READ backColor CONSTANT)
    Q_PROPERTY(QString winColor READ winColor CONSTANT)
    Q_PROPERTY(QString fontColor READ fontColor CONSTANT)
    Q_PROPERTY(QString fontLightColor READ fontLightColor CONSTANT)
    Q_PROPERTY(QString fontTipsColor READ fontTipsColor CONSTANT)
    Q_PROPERTY(QString themeColor READ themeColor CONSTANT)


    static QString backColor();
    static void setBackColor(const QString &backColor);

    static QString winColor();
    static void setWinColor(const QString &winColor);

    static QString fontColor();
    static void setFontColor(const QString &fontColor);

    static QString fontLightColor();
    static void setFontLightColor(const QString &fontLightColor);

    static QString fontTipsColor();
    static void setFontTipsColor(const QString &fontTipsColor);

    static QString themeColor();
    static void setThemeColor(const QString &themeColor);

signals:
    void uiConfigUpdated();
public slots:
    void updateUIConfig();

private:
    static QString _backColor;
    static QString _winColor;
    static QString _fontColor;
    static QString _fontLightColor;
    static QString _fontTipsColor;
    static QString _themeColor;
};

#endif // UI_H
