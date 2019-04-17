#include "fontsetup.h"



FontSetup::FontSetup(QTextEdit*text)
{
    setup = text;
    fontSize = defaultFontSize;
    backgroundColor = defaultBackgroundColor;
    fontColor = defaultColor;
}

FontSetup::~FontSetup()
{

}

void FontSetup::setFontStyle(const QFont inputfontStyle)
{
  this->fontStyle = inputfontStyle;
  setup->setFont(this->fontStyle);

}

void FontSetup::setFontColor(const QColor inputfontColor)
{
  this->fontColor = inputfontColor;
  setup->setTextColor(this->fontColor);
}

void FontSetup::setFontSize(int inputfontSize)
{
  this->fontSize = inputfontSize;
  setup->setFontPointSize(this->fontSize);

}

void FontSetup::setBackgroundColor(const QColor inputbackgroundColor)
{
  QPalette color = setup->palette();
  color.setColor(QPalette::Base,inputbackgroundColor);
  setup->setPalette(color);
}

void FontSetup::setBackgroundTextColor(const QColor inputbackgroundTextColor)
{
  this->backgroundTextColor = inputbackgroundTextColor;
  setup->setTextBackgroundColor(this->backgroundTextColor);
}

void FontSetup::setHighlightColor(const QColor highlightColor)
{
  QPalette p = setup->palette();
  p.setColor(QPalette::Highlight, QColor(highlightColor));
  p.setColor(QPalette::HighlightedText, QColor(defaultBackgroundColor));
  setup->setPalette(p);
}
