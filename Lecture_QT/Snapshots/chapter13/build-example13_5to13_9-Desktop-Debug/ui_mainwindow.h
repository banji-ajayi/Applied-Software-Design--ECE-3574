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
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "playlistsview.h"
#include "playlistview.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionQuit;
    QAction *actionCut;
    QAction *actionCopy;
    QAction *actionPaste;
    QAction *actionAbout;
    QAction *actionAboutQt;
    QAction *actionNew;
    QAction *actionClose;
    QAction *actionOpen;
    QAction *actionSaveAs;
    QAction *actionRemove;
    QAction *actionRefresh;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *lineEdit;
    QToolButton *clearFilterButton;
    PlayListView *playListView;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuHelp;
    QStatusBar *statusbar;
    QDockWidget *sourcesDock;
    QWidget *dockWidgetContents;
    QVBoxLayout *verticalLayout_2;
    PlaylistsView *sourceListView;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(772, 338);
        QIcon icon;
        icon.addFile(QStringLiteral(":/icons/collection.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QStringLiteral("actionQuit"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/icons/window-close.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionQuit->setIcon(icon1);
        actionCut = new QAction(MainWindow);
        actionCut->setObjectName(QStringLiteral("actionCut"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/icons/edit-cut.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCut->setIcon(icon2);
        actionCopy = new QAction(MainWindow);
        actionCopy->setObjectName(QStringLiteral("actionCopy"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/icons/edit-copy.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCopy->setIcon(icon3);
        actionPaste = new QAction(MainWindow);
        actionPaste->setObjectName(QStringLiteral("actionPaste"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/icons/edit-paste.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPaste->setIcon(icon4);
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/icons/help-about.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAbout->setIcon(icon5);
        actionAboutQt = new QAction(MainWindow);
        actionAboutQt->setObjectName(QStringLiteral("actionAboutQt"));
        actionAboutQt->setIcon(icon5);
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName(QStringLiteral("actionNew"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/icons/view-media-playlist.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionNew->setIcon(icon6);
        actionClose = new QAction(MainWindow);
        actionClose->setObjectName(QStringLiteral("actionClose"));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/icons/document-close.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionClose->setIcon(icon7);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/icons/document-open.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpen->setIcon(icon8);
        actionSaveAs = new QAction(MainWindow);
        actionSaveAs->setObjectName(QStringLiteral("actionSaveAs"));
        QIcon icon9;
        icon9.addFile(QStringLiteral(":/icons/document-save-as.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSaveAs->setIcon(icon9);
        actionRemove = new QAction(MainWindow);
        actionRemove->setObjectName(QStringLiteral("actionRemove"));
        QIcon icon10;
        icon10.addFile(QStringLiteral(":/icons/list-remove.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRemove->setIcon(icon10);
        actionRefresh = new QAction(MainWindow);
        actionRefresh->setObjectName(QStringLiteral("actionRefresh"));
        QIcon icon11;
        icon11.addFile(QStringLiteral(":/icons/refresh.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRefresh->setIcon(icon11);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout_2->addWidget(lineEdit);

        clearFilterButton = new QToolButton(centralwidget);
        clearFilterButton->setObjectName(QStringLiteral("clearFilterButton"));
        QIcon icon12;
        icon12.addFile(QStringLiteral(":/icons/edit-clear.png"), QSize(), QIcon::Normal, QIcon::Off);
        clearFilterButton->setIcon(icon12);

        horizontalLayout_2->addWidget(clearFilterButton);


        verticalLayout->addLayout(horizontalLayout_2);

        playListView = new PlayListView(centralwidget);
        playListView->setObjectName(QStringLiteral("playListView"));
        playListView->setMinimumSize(QSize(600, 0));
        playListView->setDragEnabled(true);
        playListView->setDragDropMode(QAbstractItemView::DragOnly);
        playListView->setAlternatingRowColors(true);
        playListView->setSelectionBehavior(QAbstractItemView::SelectRows);
        playListView->setShowGrid(false);
        playListView->setSortingEnabled(true);
        playListView->horizontalHeader()->setCascadingSectionResizes(true);
        playListView->horizontalHeader()->setStretchLastSection(true);
        playListView->verticalHeader()->setVisible(false);

        verticalLayout->addWidget(playListView);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 772, 25));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuEdit = new QMenu(menubar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);
        sourcesDock = new QDockWidget(MainWindow);
        sourcesDock->setObjectName(QStringLiteral("sourcesDock"));
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QStringLiteral("dockWidgetContents"));
        verticalLayout_2 = new QVBoxLayout(dockWidgetContents);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        sourceListView = new PlaylistsView(dockWidgetContents);
        sourceListView->setObjectName(QStringLiteral("sourceListView"));
        sourceListView->setMinimumSize(QSize(130, 0));
        sourceListView->setContextMenuPolicy(Qt::ActionsContextMenu);
        sourceListView->setAcceptDrops(true);
        sourceListView->setDragDropMode(QAbstractItemView::DropOnly);

        verticalLayout_2->addWidget(sourceListView);

        sourcesDock->setWidget(dockWidgetContents);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(1), sourcesDock);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuEdit->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionNew);
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionSaveAs);
        menuFile->addAction(actionClose);
        menuFile->addAction(actionQuit);
        menuFile->addAction(actionRefresh);
        menuEdit->addAction(actionCut);
        menuEdit->addAction(actionCopy);
        menuEdit->addAction(actionPaste);
        menuEdit->addAction(actionRemove);
        menuHelp->addAction(actionAbout);
        menuHelp->addAction(actionAboutQt);

        retranslateUi(MainWindow);
        QObject::connect(clearFilterButton, SIGNAL(clicked()), lineEdit, SLOT(clear()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "ModelView - Multiple Playlists", 0));
        actionQuit->setText(QApplication::translate("MainWindow", "&Quit", 0));
        actionQuit->setShortcut(QApplication::translate("MainWindow", "Ctrl+Q", 0));
        actionCut->setText(QApplication::translate("MainWindow", "Cut", 0));
        actionCut->setShortcut(QApplication::translate("MainWindow", "Ctrl+X", 0));
        actionCopy->setText(QApplication::translate("MainWindow", "Copy", 0));
        actionCopy->setShortcut(QApplication::translate("MainWindow", "Ctrl+C", 0));
        actionPaste->setText(QApplication::translate("MainWindow", "Paste", 0));
        actionPaste->setShortcut(QApplication::translate("MainWindow", "Ctrl+V", 0));
        actionAbout->setText(QApplication::translate("MainWindow", "About", 0));
        actionAboutQt->setText(QApplication::translate("MainWindow", "About Qt", 0));
        actionNew->setText(QApplication::translate("MainWindow", "New", 0));
        actionClose->setText(QApplication::translate("MainWindow", "Close", 0));
        actionOpen->setText(QApplication::translate("MainWindow", "Open", 0));
        actionSaveAs->setText(QApplication::translate("MainWindow", "Save As", 0));
        actionRemove->setText(QApplication::translate("MainWindow", "Remove", 0));
        actionRemove->setShortcut(QApplication::translate("MainWindow", "Del", 0));
        actionRefresh->setText(QApplication::translate("MainWindow", "&Refresh", 0));
        actionRefresh->setShortcut(QApplication::translate("MainWindow", "F5", 0));
#ifndef QT_NO_TOOLTIP
        lineEdit->setToolTip(QApplication::translate("MainWindow", "filter text", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        clearFilterButton->setToolTip(QApplication::translate("MainWindow", "clear filter", 0));
#endif // QT_NO_TOOLTIP
        clearFilterButton->setText(QApplication::translate("MainWindow", "...", 0));
        menuFile->setTitle(QApplication::translate("MainWindow", "&File", 0));
        menuEdit->setTitle(QApplication::translate("MainWindow", "&Edit", 0));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", 0));
        sourcesDock->setWindowTitle(QApplication::translate("MainWindow", "Playlists", 0));
#ifndef QT_NO_TOOLTIP
        sourceListView->setToolTip(QApplication::translate("MainWindow", "Click to select, Right-Click to add/remove", 0));
#endif // QT_NO_TOOLTIP
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
