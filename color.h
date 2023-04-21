#ifndef COLOR_H
#define COLOR_H
#include <QString>
#include <QTextBrowser>
//QTextBrowser text;

class color : public QTextBrowser{
    Q_OBJECT
    color(QWidget *parent = nullptr): QTextBrowser(parent ){};
public:

void appendGreen(const QString &text);
};

#endif // COLOR_H
