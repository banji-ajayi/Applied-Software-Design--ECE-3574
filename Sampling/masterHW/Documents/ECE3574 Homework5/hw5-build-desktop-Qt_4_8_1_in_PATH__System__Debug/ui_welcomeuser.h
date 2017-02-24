/********************************************************************************
** Form generated from reading UI file 'welcomeuser.ui'
**
** Created: Tue Oct 23 14:08:57 2012
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
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QLabel *label;

    void setupUi(QWidget *WelcomeUser)
    {
        if (WelcomeUser->objectName().isEmpty())
            WelcomeUser->setObjectName(QString::fromUtf8("WelcomeUser"));
        WelcomeUser->resize(582, 395);
        pushButton = new QPushButton(WelcomeUser);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(67, 230, 141, 27));
        pushButton_2 = new QPushButton(WelcomeUser);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(230, 230, 98, 27));
        pushButton_3 = new QPushButton(WelcomeUser);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(350, 230, 98, 27));
        label = new QLabel(WelcomeUser);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(160, 70, 211, 121));

        retranslateUi(WelcomeUser);

        QMetaObject::connectSlotsByName(WelcomeUser);
    } // setupUi

    void retranslateUi(QWidget *WelcomeUser)
    {
        WelcomeUser->setWindowTitle(QApplication::translate("WelcomeUser", "Form", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("WelcomeUser", "Change Password", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("WelcomeUser", "Start Game", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("WelcomeUser", "Exit", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("WelcomeUser", "TextLabel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class WelcomeUser: public Ui_WelcomeUser {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WELCOMEUSER_H
