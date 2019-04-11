#include "fontsetup.h"

const int defaultSize = 14;
const QColor defaultColor = Qt::black;
const QColor defaultBackgroundColor = Qt::white;

FontSetup::FontSetup(QTextEdit*text)
{
    setup = text;
    fontSize = defaultSize;
    backgroundColor = defaultBackgroundColor;
    fontColor = defaultColor;
}

FontSetup::~FontSetup()
{
  //обычный деструктор
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
