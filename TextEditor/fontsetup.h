#ifndef FONTSETUP_H
#define FONTSETUP_H

#include <QTextEdit>
#include <QColor>
#include <QPalette>

class FontSetup
{
public:
    FontSetup(QTextEdit* text);
    ~FontSetup();
    void setFontStyle(const QString fontStyle);
    void setFontColor(const QColor fontColor);
    void setFontSize(int size);
    void setBackgroundColor(const QColor backgroundColor);
    void setBackgroundTextColor(const QColor);

    QColor fontColor;
    QColor backgroundColor;
    QColor backgroundTextColor;
    QString fontStyle;
    int fontSize;
private:
    QTextEdit *setup;
};

#endif // FONTSETUP_H
