#include "color.h"
#include <QTextBrowser>

void color::appendGreen(const QString &text)
{
    QColor prev_color=textColor();
    setTextColor(Qt::green);
    append(text);
    setTextColor(prev_color);
}
