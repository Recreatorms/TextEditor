#include "fontsetup.h"

const int defaultSize = 14;
const QColor defaultColor = Qt::black;
const QColor defaultBackgroundColor = Qt::white;
const QColor defaultHighlightColor = QColor::fromRgb(0, 120, 215, 255);

static QColor currentFontColor = defaultColor;
static QColor currentHighlightColor = defaultHighlightColor;
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
  currentFontColor = fontColor;
  setHighlightColor(currentHighlightColor);
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
  p.setColor(QPalette::HighlightedText, QColor(currentFontColor));
  setup->setPalette(p);
  currentHighlightColor = highlightColor;
}
