#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "fontsetup.h"

#include <qstring.h>
#include <QContextMenuEvent>
#include <qfiledialog.h>
#include <QColorDialog>
#include <QInputDialog>

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
  ui->setupUi(this);
  pFileManager = new FileManager();
  pFontSetup = new FontSetup(ui->textEdit);

  connect(ui->createFile, &QAction::triggered, this, &MainWindow::createFileSlot);
  connect(ui->openFile, &QAction::triggered, this, &MainWindow::openFileSlot);
  connect(ui->saveFile, &QAction::triggered, this, &MainWindow::saveFileSlot);
  connect(ui->saveNowFile, &QAction::triggered, this, &MainWindow::saveNowFileSlot);

  connect(ui->changeFontSize, &QAction::triggered, this, &MainWindow::changeFontSizeSlot);
  connect(ui->changeFontStyle, &QAction::triggered, this, &MainWindow::changeFontStyleSlot);
  connect(ui->changeFontColor, &QAction::triggered, this, &MainWindow::changeFontColorSlot);
  connect(ui->changeBackgroundColor, &QAction::triggered, this, &MainWindow::changeBackgroundColorSlot);
  connect(ui->changeBackgroundTextColor, &QAction::triggered, this, &MainWindow::changeBackgroundTextColorSlot);

  connect(ui->changeHighlight, &QAction::triggered, this, &MainWindow::changeHighlightSlot);
}

MainWindow::~MainWindow()
{
  delete ui;
  delete pFileManager;
  delete pFontSetup;
}

void MainWindow::openFileSlot()
{
    QString path = QFileDialog::getOpenFileName(this, tr("Открыть файл"), "", "*.txt *.docx *.cpp *.c *.h");
    currentPath = path;
    if(path != "")
    {
       QString text = pFileManager->openFile(path);
       ui->textEdit->setPlainText(text);
    }
}

void MainWindow::createFileSlot()
{
  QString path = QFileDialog::getSaveFileName(this, tr("Создать файл"), "sampleText");
  currentPath = path;
  pFileManager->createFile(path);
}

void MainWindow::saveNowFileSlot() {
  if(currentPath != "")
  {
      QString text = ui->textEdit->toPlainText();
      pFileManager->saveFile(currentPath,text);
  }
}

void MainWindow::saveFileSlot()
{
    QString path = QFileDialog::getSaveFileName(this, tr("Сохранить файл"), "sampleText", "*.txt *.docx *.cpp *.c *.h");
    if(path != "")
    {
        QString text = ui->textEdit->toPlainText();
        pFileManager->saveFile(path,text);
    }
}

void MainWindow::changeFontSizeSlot()
{
    pFontSetup->setFontSize(QInputDialog::getInt(this, "Размер шрифта", "Укажите размер", 14, 1, 100));
}

void MainWindow::changeFontColorSlot()
{
    pFontSetup->setFontColor(QColorDialog::getColor(pFontSetup->fontColor,this));
}

void MainWindow::changeFontStyleSlot()
{
    pFontSetup->setFontStyle(QFontDialog::getFont(nullptr,this));
}

void MainWindow::changeBackgroundColorSlot()
{
    pFontSetup->setBackgroundColor(QColorDialog::getColor(pFontSetup->backgroundColor,this));
}

void MainWindow::changeBackgroundTextColorSlot()
{
    pFontSetup->setBackgroundTextColor(QColorDialog::getColor(pFontSetup->backgroundTextColor,this));
}


void MainWindow::changeHighlightSlot()
{
  pFontSetup->setHighlightColor(QColorDialog::getColor(pFontSetup->highlightColor,this));
}
