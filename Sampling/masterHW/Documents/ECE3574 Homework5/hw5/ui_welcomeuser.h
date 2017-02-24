/********************************************************************************
** Form generated from reading UI file 'welcomeuser.ui'
**
** Created: Thu Nov 1 14:01:35 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WELCOMEUSER_H
#define UI_WELCOMEUSER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WelcomeUser
{
public:
    QPushButton *changePassButton;
    QPushButton *startButton;
    QPushButton *exitButton;
    QLabel *label;

    void setupUi(QWidget *WelcomeUser)
    {
        if (WelcomeUser->objectName().isEmpty())
            WelcomeUser->setObjectName(QString::fromUtf8("WelcomeUser"));
        WelcomeUser->resize(582, 395);
        changePassButton = new QPushButton(WelcomeUser);
        changePassButton->setObjectName(QString::fromUtf8("changePassButton"));
        changePassButton->setGeometry(QRect(67, 230, 141, 27));
        startButton = new QPushButton(WelcomeUser);
        startButton->setObjectName(QString::fromUtf8("startButton"));
        startButton->setGeometry(QRect(230, 230, 98, 27));
        exitButton = new QPushButton(WelcomeUser);
        exitButton->setObjectName(QString::fromUtf8("exitButton"));
        exitButton->setGeometry(QRect(350, 230, 98, 27));
        label = new QLabel(WelcomeUser);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(110, 70, 311, 121));
        label->setMinimumSize(QSize(0, 121));
        QFont font;
        font.setPointSize(28);
        font.setBold(true);
        font.setItalic(true);
        font.setWeight(75);
        label->setFont(font);

        retranslateUi(WelcomeUser);

        QMetaObject::connectSlotsByName(WelcomeUser);
    } // setupUi

    void retranslateUi(QWidget *WelcomeUser)
    {
        WelcomeUser->setWindowTitle(QApplication::translate("WelcomeUser", "Form", 0, QApplication::UnicodeUTF8));
        changePassButton->setText(QApplication::translate("WelcomeUser", "Change Password", 0, QApplication::UnicodeUTF8));
        startButton->setText(QApplication::translate("WelcomeUser", "Start Game", 0, QApplication::UnicodeUTF8));
        exitButton->setText(QApplication::translate("WelcomeUser", "Exit", 0, QApplication::UnicodeUTF8));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class WelcomeUser: public Ui_WelcomeUser {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WELCOMEUSER_H
