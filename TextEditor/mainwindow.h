#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "filemanager.h"
#include "fontsetup.h"
#include "compiler.h"


namespace Ui {
  class MainWindow;
}

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

private slots:
  void createFileSlot();
  void openFileSlot();
  void saveFileSlot();
  void saveNowFileSlot();

  void changeFontStyleSlot();
  void changeFontColorSlot();
  void changeFontSizeSlot();
  void changeBackgroundColorSlot();
  void changeBackgroundTextColorSlot();

  void changeHighlightSlot();

  void runSlot();

private:
  Ui::MainWindow *ui;
  FileManager* pFileManager;
  FontSetup* pFontSetup;
  Compiler* pCompiler;
};

#endif // MAINWINDOW_H
