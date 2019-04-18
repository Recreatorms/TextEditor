#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "filemanager.h"
#include "fontsetup.h"
#include "compiler.h"
#include "codec.h"

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

  void changeSelectSlot();

  void runSlot();

  void HighlightSlot();

  void codecUTFSlot();
  void codecANSISlot();
  void codecKOI8Slot();
  void codecMacintoshSlot();
  void codecWindows1251Slot();

private:
  Ui::MainWindow *ui;
  FileManager* pFileManager;
  FontSetup* pFontSetup;
  Compiler* pCompiler;
  Codec* pCodec;
};

#endif // MAINWINDOW_H
