#include "UI.h"

QString UI::_backColor = "white";
QString UI::_winColor = "#F2F2F2";
//QString UI::_winColor = "#EBEBEB";
QString UI::_fontColor = "#333333";
QString UI::_fontLightColor = "#CCCCCC";
QString UI::_fontTipsColor = "#3955A3";
QString UI::_themeColor = "#F02E50";


UI::UI(QObject *parent) : QObject(parent)
{

}

QString UI::backColor()
{
    return _backColor;
}

void UI::setBackColor(const QString &backColor)
{
    _backColor = backColor;
}

QString UI::winColor()
{
    return _winColor;
}

void UI::setWinColor(const QString &winColor)
{
    _winColor = winColor;
}

QString UI::fontColor()
{
    return _fontColor;
}

void UI::setFontColor(const QString &fontColor)
{
    _fontColor = fontColor;
}

QString UI::fontLightColor()
{
    return _fontLightColor;
}

void UI::setFontLightColor(const QString &fontLightColor)
{
    _fontLightColor = fontLightColor;
}

QString UI::fontTipsColor()
{
    return _fontTipsColor;
}

void UI::setFontTipsColor(const QString &fontTipsColor)
{
    _fontTipsColor = fontTipsColor;
}

QString UI::themeColor()
{
    return _themeColor;
}

void UI::setThemeColor(const QString &themeColor)
{
    _themeColor = themeColor;
}

void UI::updateUIConfig()
{
    emit this->uiConfigUpdated();
}
