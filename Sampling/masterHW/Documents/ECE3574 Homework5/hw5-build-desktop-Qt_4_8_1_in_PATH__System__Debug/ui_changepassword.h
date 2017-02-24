/********************************************************************************
** Form generated from reading UI file 'changepassword.ui'
**
** Created: Tue Oct 23 14:08:57 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANGEPASSWORD_H
#define UI_CHANGEPASSWORD_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QFormLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChangePassword
{
public:
    QPushButton *okButton;
    QPushButton *cancelButton;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *colorLabel;
    QComboBox *colorComboBox;
    QLabel *nameLabel;
    QLabel *passwordLabel;
    QLabel *rPasswordLabel;
    QLineEdit *nameEdit;
    QLineEdit *passwordEdit;
    QLineEdit *rPasswordEdit;
    QLabel *informDisplay;

    void setupUi(QWidget *ChangePassword)
    {
        if (ChangePassword->objectName().isEmpty())
            ChangePassword->setObjectName(QString::fromUtf8("ChangePassword"));
        ChangePassword->resize(475, 296);
        okButton = new QPushButton(ChangePassword);
        okButton->setObjectName(QString::fromUtf8("okButton"));
        okButton->setGeometry(QRect(220, 210, 91, 27));
        cancelButton = new QPushButton(ChangePassword);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        cancelButton->setGeometry(QRect(320, 210, 81, 27));
        formLayoutWidget = new QWidget(ChangePassword);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(60, 70, 311, 128));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        colorLabel = new QLabel(formLayoutWidget);
        colorLabel->setObjectName(QString::fromUtf8("colorLabel"));

        formLayout->setWidget(0, QFormLayout::LabelRole, colorLabel);

        colorComboBox = new QComboBox(formLayoutWidget);
        colorComboBox->setObjectName(QString::fromUtf8("colorComboBox"));

        formLayout->setWidget(0, QFormLayout::FieldRole, colorComboBox);

        nameLabel = new QLabel(formLayoutWidget);
        nameLabel->setObjectName(QString::fromUtf8("nameLabel"));

        formLayout->setWidget(1, QFormLayout::LabelRole, nameLabel);

        passwordLabel = new QLabel(formLayoutWidget);
        passwordLabel->setObjectName(QString::fromUtf8("passwordLabel"));

        formLayout->setWidget(2, QFormLayout::LabelRole, passwordLabel);

        rPasswordLabel = new QLabel(formLayoutWidget);
        rPasswordLabel->setObjectName(QString::fromUtf8("rPasswordLabel"));

        formLayout->setWidget(3, QFormLayout::LabelRole, rPasswordLabel);

        nameEdit = new QLineEdit(formLayoutWidget);
        nameEdit->setObjectName(QString::fromUtf8("nameEdit"));

        formLayout->setWidget(1, QFormLayout::FieldRole, nameEdit);

        passwordEdit = new QLineEdit(formLayoutWidget);
        passwordEdit->setObjectName(QString::fromUtf8("passwordEdit"));

        formLayout->setWidget(2, QFormLayout::FieldRole, passwordEdit);

        rPasswordEdit = new QLineEdit(formLayoutWidget);
        rPasswordEdit->setObjectName(QString::fromUtf8("rPasswordEdit"));

        formLayout->setWidget(3, QFormLayout::FieldRole, rPasswordEdit);

        informDisplay = new QLabel(ChangePassword);
        informDisplay->setObjectName(QString::fromUtf8("informDisplay"));
        informDisplay->setGeometry(QRect(110, 40, 211, 17));

        retranslateUi(ChangePassword);

        QMetaObject::connectSlotsByName(ChangePassword);
    } // setupUi

    void retranslateUi(QWidget *ChangePassword)
    {
        ChangePassword->setWindowTitle(QApplication::translate("ChangePassword", "Form", 0, QApplication::UnicodeUTF8));
        okButton->setText(QApplication::translate("ChangePassword", "Ok", 0, QApplication::UnicodeUTF8));
        cancelButton->setText(QApplication::translate("ChangePassword", "Cancel", 0, QApplication::UnicodeUTF8));
        colorLabel->setText(QApplication::translate("ChangePassword", "Color", 0, QApplication::UnicodeUTF8));
        colorComboBox->clear();
        colorComboBox->insertItems(0, QStringList()
         << QApplication::translate("ChangePassword", "Red", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ChangePassword", "Green", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ChangePassword", "Blue", 0, QApplication::UnicodeUTF8)
        );
        nameLabel->setText(QApplication::translate("ChangePassword", "User name", 0, QApplication::UnicodeUTF8));
        passwordLabel->setText(QApplication::translate("ChangePassword", "Password", 0, QApplication::UnicodeUTF8));
        rPasswordLabel->setText(QApplication::translate("ChangePassword", "Re-enter Password", 0, QApplication::UnicodeUTF8));
        informDisplay->setText(QApplication::translate("ChangePassword", "TextLabel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ChangePassword: public Ui_ChangePassword {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANGEPASSWORD_H
