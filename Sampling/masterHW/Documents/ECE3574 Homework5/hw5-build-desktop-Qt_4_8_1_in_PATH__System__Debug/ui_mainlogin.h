/********************************************************************************
** Form generated from reading UI file 'mainlogin.ui'
**
** Created: Tue Oct 23 14:08:57 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINLOGIN_H
#define UI_MAINLOGIN_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mainLogin
{
public:
    QLabel *nameLabel;
    QLabel *passwordLabel;
    QPushButton *login;
    QPushButton *exit;
    QLineEdit *nameEdit;
    QLineEdit *passwordEdit;

    void setupUi(QWidget *mainLogin)
    {
        if (mainLogin->objectName().isEmpty())
            mainLogin->setObjectName(QString::fromUtf8("mainLogin"));
        mainLogin->resize(492, 300);
        nameLabel = new QLabel(mainLogin);
        nameLabel->setObjectName(QString::fromUtf8("nameLabel"));
        nameLabel->setGeometry(QRect(80, 80, 81, 17));
        passwordLabel = new QLabel(mainLogin);
        passwordLabel->setObjectName(QString::fromUtf8("passwordLabel"));
        passwordLabel->setGeometry(QRect(80, 130, 66, 17));
        login = new QPushButton(mainLogin);
        login->setObjectName(QString::fromUtf8("login"));
        login->setGeometry(QRect(190, 220, 91, 27));
        exit = new QPushButton(mainLogin);
        exit->setObjectName(QString::fromUtf8("exit"));
        exit->setGeometry(QRect(290, 220, 81, 27));
        nameEdit = new QLineEdit(mainLogin);
        nameEdit->setObjectName(QString::fromUtf8("nameEdit"));
        nameEdit->setGeometry(QRect(180, 70, 171, 27));
        passwordEdit = new QLineEdit(mainLogin);
        passwordEdit->setObjectName(QString::fromUtf8("passwordEdit"));
        passwordEdit->setGeometry(QRect(180, 120, 171, 27));

        retranslateUi(mainLogin);

        QMetaObject::connectSlotsByName(mainLogin);
    } // setupUi

    void retranslateUi(QWidget *mainLogin)
    {
        mainLogin->setWindowTitle(QApplication::translate("mainLogin", "Form", 0, QApplication::UnicodeUTF8));
        nameLabel->setText(QApplication::translate("mainLogin", "User name", 0, QApplication::UnicodeUTF8));
        passwordLabel->setText(QApplication::translate("mainLogin", "Password", 0, QApplication::UnicodeUTF8));
        login->setText(QApplication::translate("mainLogin", "Login", 0, QApplication::UnicodeUTF8));
        exit->setText(QApplication::translate("mainLogin", "Exit", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class mainLogin: public Ui_mainLogin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINLOGIN_H
