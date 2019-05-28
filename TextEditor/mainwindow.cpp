#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <qstring.h>
#include <QContextMenuEvent>
#include <qfiledialog.h>
#include <QColorDialog>
#include <QInputDialog>
#include <QTextCodec>

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
  ui->setupUi(this);
  pFileManager = new FileManager();
  pFontSetup = new FontSetup(ui->textEdit);
  pCompiler = new Compiler();

  connect(ui->createFile, &QAction::triggered, this, &MainWindow::createFileSlot);
  connect(ui->openFile, &QAction::triggered, this, &MainWindow::openFileSlot);
  connect(ui->saveFile, &QAction::triggered, this, &MainWindow::saveFileSlot);
  connect(ui->saveNowFile, &QAction::triggered, this, &MainWindow::saveNowFileSlot);

  connect(ui->changeFontSize, &QAction::triggered, this, &MainWindow::changeFontSizeSlot);
  connect(ui->changeFontStyle, &QAction::triggered, this, &MainWindow::changeFontStyleSlot);
  connect(ui->changeFontColor, &QAction::triggered, this, &MainWindow::changeFontColorSlot);
  connect(ui->changeBackgroundColor, &QAction::triggered, this, &MainWindow::changeBackgroundColorSlot);
  connect(ui->changeBackgroundTextColor, &QAction::triggered, this, &MainWindow::changeBackgroundTextColorSlot);

  connect(ui->changeSelect, &QAction::triggered, this, &MainWindow::changeSelectSlot);

  connect(ui->run,&QAction::triggered, this, &MainWindow::runSlot);
  connect(ui->highlight, &QAction::toggled, this, &MainWindow::HighlightSlot);

  connect(ui->action_UTF_8, &QAction::triggered, this, &MainWindow::codecUTF8Slot);
  connect(ui->action_KOI8_R, &QAction::triggered, this, &MainWindow::codecKOI8Slot);
  connect(ui->action_Windows_1251, &QAction::triggered, this, &MainWindow::codecWindows1251Slot);
  pFontSetup->setFontStyle(defaultFontStyle);
  pFontSetup->setFontSize(defaultFontSize);
  pFontSetup->setSelectColor(defaultSelectColor, defaultBackgroundColor);
}

MainWindow::~MainWindow()
{
  delete ui;
  delete pFileManager;
  delete pFontSetup;
  delete pCompiler;
}

void MainWindow::openFileSlot()
{
    QString path = QFileDialog::getOpenFileName(this, "Открыть файл", pFileManager->fileName, "*.txt *.cpp *.c *.h");
    pFileManager->currentPath = path;
    if(path != "")
    {
       QString text = pFileManager->openFile(path);
       ui->textEdit->setPlainText(text);
    }
}

void MainWindow::createFileSlot()
{
  QString path = QFileDialog::getSaveFileName(this, "Создать новый файл", "sampleText");
  pFileManager->currentPath = path;
  pFileManager->createFile(path);
}

void MainWindow::saveNowFileSlot() {
  if(pFileManager->currentPath != "")
  {
      QString text = ui->textEdit->toPlainText();
      pFileManager->saveFile(pFileManager->currentPath,text);
  }
}

void MainWindow::saveFileSlot()
{
    QString path = QFileDialog::getSaveFileName(this, "Сохранить файл", pFileManager->fileName, "*.txt  *.cpp *.c *.h");
    if(path != "")
    {
        QString text = ui->textEdit->toPlainText();
        pFileManager->saveFile(path,text);
    }
}

void MainWindow::changeFontSizeSlot()
{
    pFontSetup->setFontSize(QInputDialog::getInt(this, "Изменить размер текста","Давай меняй, чего ждёшь", pFontSetup->fontSize, 1, 100));
}

void MainWindow::changeFontColorSlot()
{
    pFontSetup->setFontColor(QColorDialog::getColor(pFontSetup->fontColor,this));
}

void MainWindow::changeFontStyleSlot()
{
    pFontSetup->setFontStyle(QFontDialog::getFont(nullptr, pFontSetup->fontStyle, this));
}

void MainWindow::changeBackgroundColorSlot()
{
    pFontSetup->setBackgroundColor(QColorDialog::getColor(pFontSetup->backgroundColor,this));
}

void MainWindow::changeBackgroundTextColorSlot()
{
    pFontSetup->setBackgroundTextColor(QColorDialog::getColor(pFontSetup->backgroundTextColor,this));
}


void MainWindow::changeSelectSlot()
{
    pFontSetup->setSelectColor(QColorDialog::getColor(pFontSetup->selectColor,this), defaultBackgroundColor);
}

void MainWindow::runSlot()
{
    ui->textEdit->setPlainText("Не работает (пока что). и не будет. я не знаю, не умею, нехочу не будуотстаньте");
    pCompiler->runTest(pFileManager->fileName);
}

void MainWindow::HighlightSlot()
{
  if (ui->highlight->isChecked() == true){
     pHighlighter = new Highlighter(pFontSetup->setup->document());
     pFontSetup->setFontStyle(QFont("Courier New", 15, 75, false));
     pFontSetup->setFontSize(20);
     pFontSetup->setBackgroundColor(Qt::black);
     pFontSetup->setFontColor(Qt::white);
     pFontSetup->setSelectColor(Qt::white, Qt::black);

  } else {
      delete pHighlighter;
      pFontSetup->setFontColor(Qt::black);
      pFontSetup->setFontStyle(QFont("Comic Sans MS", 0, 75, false));
      pFontSetup->setBackgroundColor(Qt::white);
      pFontSetup->setFontSize(defaultFontSize);
      pFontSetup->setSelectColor(defaultSelectColor, Qt::white);
  }
}

void MainWindow::codecUTF8Slot()
{/*
  QString text = ui->textEdit->toPlainText();
  QByteArray byteArray;
  QDataStream out(&byteArray, QIODevice::WriteOnly);
  out << text;
  QTextCodec *codec = QTextCodec::codecForName("UTF-8");
  text = codec->toUnicode(byteArray);
  ui->textEdit->setPlainText(text);*/
  QString text = ui->textEdit->toPlainText();
  QTextCodec *codec = QTextCodec::codecForName("UTF-8");
  QByteArray byteArray;
  QDataStream in(&byteArray, QIODevice::ReadOnly);
  in >> byteArray;
  byteArray = codec->fromUnicode(text);
  text = byteArray;
  ui->textEdit->setPlainText(text);
}

void MainWindow::codecKOI8Slot()
{
  QString text = ui->textEdit->toPlainText();
  QTextCodec *codec = QTextCodec::codecForName("KOI8-R");
  QByteArray byteArray;
  QDataStream in(&byteArray, QIODevice::ReadOnly);
  in >> byteArray;
  byteArray = codec->fromUnicode(text);
  text = byteArray;
  ui->textEdit->setPlainText(text);
}

void MainWindow::codecWindows1251Slot()
{
  QString text = ui->textEdit->toPlainText();
  QTextCodec *codec = QTextCodec::codecForName("Windows-1251");
  QByteArray byteArray;
  QDataStream in(&byteArray, QIODevice::ReadOnly);
  in >> byteArray;
  byteArray = codec->fromUnicode(text);
  text = byteArray;
  ui->textEdit->setPlainText(text);
}
