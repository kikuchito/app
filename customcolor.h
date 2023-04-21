#ifndef CUSTOMCOLOR_H
#define CUSTOMCOLOR_H

#include <QTextBrowser>
#include <QObject>

class CustomColor : public QTextBrowser
{
    Q_OBJECT
public:
    CustomColor(QWidget *parent = nullptr): QTextBrowser(parent ){};

    void appendGreen(const QString &text);
    void appendPink(const QString &text);
};
CustomColor* operator << (CustomColor* findresults, const QString &text);
#endif // CUSTOMCOLOR_H
