#ifndef FONTSETUP_H
#define FONTSETUP_H

#include <QTextEdit>
#include <QColor>
#include <QPalette>
#include <QFontDialog>
#include <QFont>
class FontSetup
{
public:
    FontSetup(QTextEdit* text);
    ~FontSetup();
    void setFontStyle(const QFont fontStyle);
    void setFontColor(const QColor fontColor);
    void setFontSize(int size);
    void setBackgroundColor(const QColor backgroundColor);
    void setBackgroundTextColor(const QColor);
    void setHighlightColor(const QColor highlightColor);

    QColor fontColor;
    QColor backgroundColor;
    QColor backgroundTextColor;
    QFont fontStyle;
    int fontSize;
    QColor highlightColor;
private:
    QTextEdit *setup;
};

#endif // FONTSETUP_H
