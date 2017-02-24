/********************************************************************************
** Form generated from reading UI file 'lifemainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LIFEMAINWINDOW_H
#define UI_LIFEMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LifeMainWindow
{
public:
    QAction *actionPopulate_Randomly;
    QAction *actionStart_Stop;
    QAction *actionClear;
    QAction *actionQuit;
    QAction *actionAbout;
    QAction *actionAbout_Qt;
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *menuGame_of_Life;
    QMenu *menuHelp;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *LifeMainWindow)
    {
        if (LifeMainWindow->objectName().isEmpty())
            LifeMainWindow->setObjectName(QStringLiteral("LifeMainWindow"));
        LifeMainWindow->resize(400, 300);
        actionPopulate_Randomly = new QAction(LifeMainWindow);
        actionPopulate_Randomly->setObjectName(QStringLiteral("actionPopulate_Randomly"));
        actionStart_Stop = new QAction(LifeMainWindow);
        actionStart_Stop->setObjectName(QStringLiteral("actionStart_Stop"));
        actionStart_Stop->setCheckable(true);
        actionClear = new QAction(LifeMainWindow);
        actionClear->setObjectName(QStringLiteral("actionClear"));
        actionQuit = new QAction(LifeMainWindow);
        actionQuit->setObjectName(QStringLiteral("actionQuit"));
        actionAbout = new QAction(LifeMainWindow);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        actionAbout_Qt = new QAction(LifeMainWindow);
        actionAbout_Qt->setObjectName(QStringLiteral("actionAbout_Qt"));
        centralWidget = new QWidget(LifeMainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        LifeMainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(LifeMainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 25));
        menuGame_of_Life = new QMenu(menuBar);
        menuGame_of_Life->setObjectName(QStringLiteral("menuGame_of_Life"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        LifeMainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(LifeMainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        LifeMainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(LifeMainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        LifeMainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuGame_of_Life->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuGame_of_Life->addAction(actionPopulate_Randomly);
        menuGame_of_Life->addAction(actionStart_Stop);
        menuGame_of_Life->addAction(actionClear);
        menuGame_of_Life->addAction(actionQuit);
        menuHelp->addAction(actionAbout);
        menuHelp->addAction(actionAbout_Qt);

        retranslateUi(LifeMainWindow);

        QMetaObject::connectSlotsByName(LifeMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *LifeMainWindow)
    {
        LifeMainWindow->setWindowTitle(QApplication::translate("LifeMainWindow", "LifeMainWindow", 0));
        actionPopulate_Randomly->setText(QApplication::translate("LifeMainWindow", "Populate Randomly", 0));
        actionPopulate_Randomly->setShortcut(QApplication::translate("LifeMainWindow", "R", 0));
        actionStart_Stop->setText(QApplication::translate("LifeMainWindow", "Start/Stop", 0));
        actionStart_Stop->setShortcut(QApplication::translate("LifeMainWindow", "Space", 0));
        actionClear->setText(QApplication::translate("LifeMainWindow", "Clear", 0));
        actionClear->setShortcut(QApplication::translate("LifeMainWindow", "Del", 0));
        actionQuit->setText(QApplication::translate("LifeMainWindow", "Quit", 0));
        actionQuit->setShortcut(QApplication::translate("LifeMainWindow", "Ctrl+Q", 0));
        actionAbout->setText(QApplication::translate("LifeMainWindow", "About", 0));
        actionAbout_Qt->setText(QApplication::translate("LifeMainWindow", "About Qt", 0));
        menuGame_of_Life->setTitle(QApplication::translate("LifeMainWindow", "Game", 0));
        menuHelp->setTitle(QApplication::translate("LifeMainWindow", "Help", 0));
    } // retranslateUi

};

namespace Ui {
    class LifeMainWindow: public Ui_LifeMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LIFEMAINWINDOW_H
