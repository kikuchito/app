#include "customcolor.h"


void CustomColor::appendGreen(const QString &text)
{
    QColor prev_color=textColor();
    setTextColor(Qt::green);
    append(text);
    setTextColor(prev_color);
}
void CustomColor::appendPink(const QString &text)
{
    QColor prev_color=textColor();
    setTextColor(Qt::red);
    append(text);
    setTextColor(prev_color);
}
CustomColor* operator << (CustomColor* findresults, const QString &text)
{
    findresults->appendPink(text);
    return findresults;
}
