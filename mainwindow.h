#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "filemanager.h"
#include "fontsetup.h"

static QString currentPath;
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

private:
  Ui::MainWindow *ui;
  FileManager* pFileManager;
  FontSetup* pFontSetup;
};

#endif // MAINWINDOW_H
