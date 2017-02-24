/********************************************************************************
** Form generated from reading UI file 'chatserver.ui'
**
** Created: Sat Apr 20 01:24:18 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATSERVER_H
#define UI_CHATSERVER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QTextEdit>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChatServer
{
public:
    QWidget *centralWidget;
    QTextEdit *serverWindow;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *ChatServer)
    {
        if (ChatServer->objectName().isEmpty())
            ChatServer->setObjectName(QString::fromUtf8("ChatServer"));
        ChatServer->resize(400, 300);
        centralWidget = new QWidget(ChatServer);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        serverWindow = new QTextEdit(centralWidget);
        serverWindow->setObjectName(QString::fromUtf8("serverWindow"));
        serverWindow->setGeometry(QRect(10, 10, 382, 211));
        serverWindow->setReadOnly(true);
        ChatServer->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(ChatServer);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 25));
        ChatServer->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ChatServer);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        ChatServer->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(ChatServer);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        ChatServer->setStatusBar(statusBar);
        toolBar = new QToolBar(ChatServer);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        ChatServer->addToolBar(Qt::TopToolBarArea, toolBar);

        retranslateUi(ChatServer);

        QMetaObject::connectSlotsByName(ChatServer);
    } // setupUi

    void retranslateUi(QMainWindow *ChatServer)
    {
        ChatServer->setWindowTitle(QApplication::translate("ChatServer", "ChatServer", 0, QApplication::UnicodeUTF8));
        toolBar->setWindowTitle(QApplication::translate("ChatServer", "toolBar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ChatServer: public Ui_ChatServer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATSERVER_H
