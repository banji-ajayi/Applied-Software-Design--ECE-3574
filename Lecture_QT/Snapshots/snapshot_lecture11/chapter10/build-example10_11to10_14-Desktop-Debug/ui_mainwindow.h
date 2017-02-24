/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionClose;
    QAction *actionQuit;
    QWidget *centralWidget;
    QPushButton *openButton;
    QPushButton *saveButton;
    QPushButton *pushButton_3;
    QPushButton *undoButton;
    QPushButton *redoButton;
    QPushButton *verticalMirrorButton;
    QPushButton *horizontalMirrorButton;
    QPushButton *adjustColorButton;
    QDoubleSpinBox *redSpin;
    QDoubleSpinBox *greenSpin;
    QDoubleSpinBox *blueSpin;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(854, 574);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        actionClose = new QAction(MainWindow);
        actionClose->setObjectName(QStringLiteral("actionClose"));
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QStringLiteral("actionQuit"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        openButton = new QPushButton(centralWidget);
        openButton->setObjectName(QStringLiteral("openButton"));
        openButton->setGeometry(QRect(740, 20, 99, 27));
        saveButton = new QPushButton(centralWidget);
        saveButton->setObjectName(QStringLiteral("saveButton"));
        saveButton->setGeometry(QRect(740, 60, 99, 27));
        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(740, 100, 99, 27));
        undoButton = new QPushButton(centralWidget);
        undoButton->setObjectName(QStringLiteral("undoButton"));
        undoButton->setGeometry(QRect(740, 170, 99, 27));
        redoButton = new QPushButton(centralWidget);
        redoButton->setObjectName(QStringLiteral("redoButton"));
        redoButton->setGeometry(QRect(740, 210, 99, 27));
        verticalMirrorButton = new QPushButton(centralWidget);
        verticalMirrorButton->setObjectName(QStringLiteral("verticalMirrorButton"));
        verticalMirrorButton->setGeometry(QRect(710, 290, 131, 27));
        horizontalMirrorButton = new QPushButton(centralWidget);
        horizontalMirrorButton->setObjectName(QStringLiteral("horizontalMirrorButton"));
        horizontalMirrorButton->setGeometry(QRect(710, 330, 131, 27));
        adjustColorButton = new QPushButton(centralWidget);
        adjustColorButton->setObjectName(QStringLiteral("adjustColorButton"));
        adjustColorButton->setGeometry(QRect(710, 390, 131, 27));
        redSpin = new QDoubleSpinBox(centralWidget);
        redSpin->setObjectName(QStringLiteral("redSpin"));
        redSpin->setGeometry(QRect(770, 420, 69, 27));
        greenSpin = new QDoubleSpinBox(centralWidget);
        greenSpin->setObjectName(QStringLiteral("greenSpin"));
        greenSpin->setGeometry(QRect(770, 450, 69, 27));
        blueSpin = new QDoubleSpinBox(centralWidget);
        blueSpin->setObjectName(QStringLiteral("blueSpin"));
        blueSpin->setGeometry(QRect(770, 480, 69, 27));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(700, 430, 67, 17));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(700, 450, 67, 17));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(700, 480, 67, 17));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 854, 25));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionSave);
        menuFile->addAction(actionClose);
        menuFile->addAction(actionQuit);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionOpen->setText(QApplication::translate("MainWindow", "Open", 0));
        actionSave->setText(QApplication::translate("MainWindow", "Save", 0));
        actionClose->setText(QApplication::translate("MainWindow", "Close", 0));
        actionQuit->setText(QApplication::translate("MainWindow", "Quit", 0));
        openButton->setText(QApplication::translate("MainWindow", "Open", 0));
        saveButton->setText(QApplication::translate("MainWindow", "Save", 0));
        pushButton_3->setText(QApplication::translate("MainWindow", "Quit", 0));
        undoButton->setText(QApplication::translate("MainWindow", "UNDO", 0));
        redoButton->setText(QApplication::translate("MainWindow", "REDO", 0));
        verticalMirrorButton->setText(QApplication::translate("MainWindow", "Vertical Mirror", 0));
        horizontalMirrorButton->setText(QApplication::translate("MainWindow", "Horizontal Mirror", 0));
        adjustColorButton->setText(QApplication::translate("MainWindow", "Adjust Color", 0));
        label->setText(QApplication::translate("MainWindow", "Red", 0));
        label_2->setText(QApplication::translate("MainWindow", "Green", 0));
        label_3->setText(QApplication::translate("MainWindow", "Blue", 0));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
