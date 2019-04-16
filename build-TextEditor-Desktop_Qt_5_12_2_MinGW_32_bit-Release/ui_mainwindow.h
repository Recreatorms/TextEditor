/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *createFile;
    QAction *openFile;
    QAction *saveFile;
    QAction *changeFontSize;
    QAction *changeFontStyle;
    QAction *changeFontColor;
    QAction *changeBackgroundColor;
    QAction *changeBackgroundTextColor;
    QAction *saveNowFile;
    QAction *changeHighlight;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QTextEdit *textEdit;
    QMenuBar *menuBar;
    QMenu *Font;
    QMenu *File;
    QMenu *Compiler;
    QToolBar *mainToolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(888, 564);
        MainWindow->setTabShape(QTabWidget::Rounded);
        createFile = new QAction(MainWindow);
        createFile->setObjectName(QString::fromUtf8("createFile"));
        openFile = new QAction(MainWindow);
        openFile->setObjectName(QString::fromUtf8("openFile"));
        saveFile = new QAction(MainWindow);
        saveFile->setObjectName(QString::fromUtf8("saveFile"));
        changeFontSize = new QAction(MainWindow);
        changeFontSize->setObjectName(QString::fromUtf8("changeFontSize"));
        changeFontStyle = new QAction(MainWindow);
        changeFontStyle->setObjectName(QString::fromUtf8("changeFontStyle"));
        changeFontColor = new QAction(MainWindow);
        changeFontColor->setObjectName(QString::fromUtf8("changeFontColor"));
        changeBackgroundColor = new QAction(MainWindow);
        changeBackgroundColor->setObjectName(QString::fromUtf8("changeBackgroundColor"));
        changeBackgroundTextColor = new QAction(MainWindow);
        changeBackgroundTextColor->setObjectName(QString::fromUtf8("changeBackgroundTextColor"));
        saveNowFile = new QAction(MainWindow);
        saveNowFile->setObjectName(QString::fromUtf8("saveNowFile"));
        changeHighlight = new QAction(MainWindow);
        changeHighlight->setObjectName(QString::fromUtf8("changeHighlight"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        centralWidget->setMinimumSize(QSize(301, 198));
        centralWidget->setAutoFillBackground(true);
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(0);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(3, 0, 3, 3);
        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setAutoFillBackground(false);

        gridLayout->addWidget(textEdit, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 888, 20));
        Font = new QMenu(menuBar);
        Font->setObjectName(QString::fromUtf8("Font"));
        File = new QMenu(menuBar);
        File->setObjectName(QString::fromUtf8("File"));
        Compiler = new QMenu(menuBar);
        Compiler->setObjectName(QString::fromUtf8("Compiler"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        mainToolBar->setMovable(false);
        mainToolBar->setAllowedAreas(Qt::TopToolBarArea);
        mainToolBar->setToolButtonStyle(Qt::ToolButtonTextOnly);
        mainToolBar->setFloatable(true);
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);

        menuBar->addAction(File->menuAction());
        menuBar->addAction(Font->menuAction());
        menuBar->addAction(Compiler->menuAction());
        Font->addAction(changeFontSize);
        Font->addAction(changeFontStyle);
        Font->addSeparator();
        Font->addAction(changeFontColor);
        Font->addAction(changeBackgroundColor);
        Font->addAction(changeBackgroundTextColor);
        Font->addSeparator();
        Font->addAction(changeHighlight);
        File->addAction(createFile);
        File->addAction(openFile);
        File->addSeparator();
        File->addAction(saveFile);
        File->addAction(saveNowFile);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        createFile->setText(QApplication::translate("MainWindow", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214 \320\275\320\276\320\262\321\213\320\271", nullptr));
#ifndef QT_NO_SHORTCUT
        createFile->setShortcut(QApplication::translate("MainWindow", "Ctrl+N", nullptr));
#endif // QT_NO_SHORTCUT
        openFile->setText(QApplication::translate("MainWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214 \321\204\320\260\320\271\320\273", nullptr));
#ifndef QT_NO_SHORTCUT
        openFile->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", nullptr));
#endif // QT_NO_SHORTCUT
        saveFile->setText(QApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \320\272\320\260\320\272...", nullptr));
#ifndef QT_NO_SHORTCUT
        saveFile->setShortcut(QApplication::translate("MainWindow", "Ctrl+Shift+S", nullptr));
#endif // QT_NO_SHORTCUT
        changeFontSize->setText(QApplication::translate("MainWindow", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214 \321\200\320\260\320\267\320\274\320\265\321\200 \321\202\320\265\320\272\321\201\321\202\320\260", nullptr));
        changeFontStyle->setText(QApplication::translate("MainWindow", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214 \321\210\321\200\320\270\321\204\321\202", nullptr));
        changeFontColor->setText(QApplication::translate("MainWindow", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214 \321\206\320\262\320\265\321\202 \321\202\320\265\320\272\321\201\321\202\320\260", nullptr));
        changeBackgroundColor->setText(QApplication::translate("MainWindow", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214 \321\206\320\262\320\265\321\202 \321\204\320\276\320\275\320\260", nullptr));
        changeBackgroundTextColor->setText(QApplication::translate("MainWindow", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214 \321\206\320\262\320\265\321\202 \321\204\320\276\320\275\320\260 \321\202\320\265\320\272\321\201\321\202\320\260", nullptr));
        saveNowFile->setText(QApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
#ifndef QT_NO_SHORTCUT
        saveNowFile->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", nullptr));
#endif // QT_NO_SHORTCUT
        changeHighlight->setText(QApplication::translate("MainWindow", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214 \321\206\320\262\320\265\321\202 \320\262\321\213\320\264\320\265\320\273\320\265\320\275\320\270\321\217 \321\202\320\265\320\272\321\201\321\202\320\260", nullptr));
        Font->setTitle(QApplication::translate("MainWindow", "\320\250\321\200\320\270\321\204\321\202", nullptr));
        File->setTitle(QApplication::translate("MainWindow", "\320\244\320\260\320\271\320\273", nullptr));
        Compiler->setTitle(QApplication::translate("MainWindow", "\320\232\320\276\320\274\320\277\320\270\320\273\321\217\321\202\320\276\321\200", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
