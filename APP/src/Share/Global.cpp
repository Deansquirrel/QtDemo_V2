#include "Global.h"

bool Global::_isAndroid = false;
bool Global::_isWindows = false;
QStringList Global::_fontFamily;
QString Global::_fontStr = "";
int Global::_em = 0;
int Global::_defaultWidth = 0;
int Global::_defaultHeight = 0;
QString Global::_PREFIX_MONEY = "¥";

Global::Global(QObject *parent) : QObject(parent)
{

}

bool Global::isAndroid()
{
    return _isAndroid;
}

void Global::setIsAndroid(bool isAndroid)
{
    _isAndroid = isAndroid;
}

bool Global::isWindows()
{
    return _isWindows;
}

void Global::setIsWindows(bool isWindows)
{
    _isWindows = isWindows;
}

int Global::defaultWidth()
{
    return _defaultWidth;
}

void Global::setDefaultWidth(int defaultWidth)
{
    _defaultWidth = defaultWidth;
}

int Global::defaultHeight()
{
    return _defaultHeight;
}

void Global::setDefaultHeight(int defaultHeight)
{
    _defaultHeight = defaultHeight;
}

QStringList Global::fontFamily()
{
    return _fontFamily;
}

void Global::setFontFamily(const QStringList &fontFamily)
{
    _fontFamily = fontFamily;
}

QString Global::fontStr()
{
    return _fontStr;
}

void Global::setFontStr(const QString &fontStr)
{
    _fontStr = fontStr;
}

QString Global::getPREFIX_MONEY()
{
    return _PREFIX_MONEY;
}

int Global::em()
{
    return _em;
}

void Global::setEm(int em)
{
    _em = em;
}
