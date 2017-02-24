/********************************************************************************
** Form generated from reading UI file 'changepassword.ui'
**
** Created: Thu Nov 1 14:01:35 2012
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
    QLabel *oldPasswordLabel;
    QLabel *passwordLabel;
    QLabel *rPasswordLabel;
    QLineEdit *oldPasswordEdit;
    QLineEdit *passwordEdit;
    QLineEdit *rPasswordEdit;
    QLabel *label;

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

        oldPasswordLabel = new QLabel(formLayoutWidget);
        oldPasswordLabel->setObjectName(QString::fromUtf8("oldPasswordLabel"));

        formLayout->setWidget(1, QFormLayout::LabelRole, oldPasswordLabel);

        passwordLabel = new QLabel(formLayoutWidget);
        passwordLabel->setObjectName(QString::fromUtf8("passwordLabel"));

        formLayout->setWidget(2, QFormLayout::LabelRole, passwordLabel);

        rPasswordLabel = new QLabel(formLayoutWidget);
        rPasswordLabel->setObjectName(QString::fromUtf8("rPasswordLabel"));

        formLayout->setWidget(3, QFormLayout::LabelRole, rPasswordLabel);

        oldPasswordEdit = new QLineEdit(formLayoutWidget);
        oldPasswordEdit->setObjectName(QString::fromUtf8("oldPasswordEdit"));

        formLayout->setWidget(1, QFormLayout::FieldRole, oldPasswordEdit);

        passwordEdit = new QLineEdit(formLayoutWidget);
        passwordEdit->setObjectName(QString::fromUtf8("passwordEdit"));

        formLayout->setWidget(2, QFormLayout::FieldRole, passwordEdit);

        rPasswordEdit = new QLineEdit(formLayoutWidget);
        rPasswordEdit->setObjectName(QString::fromUtf8("rPasswordEdit"));

        formLayout->setWidget(3, QFormLayout::FieldRole, rPasswordEdit);

        label = new QLabel(ChangePassword);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(80, 40, 281, 20));

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
        oldPasswordLabel->setText(QApplication::translate("ChangePassword", "Password (old)", 0, QApplication::UnicodeUTF8));
        passwordLabel->setText(QApplication::translate("ChangePassword", "Password (new)", 0, QApplication::UnicodeUTF8));
        rPasswordLabel->setText(QApplication::translate("ChangePassword", "Re-enter Password", 0, QApplication::UnicodeUTF8));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ChangePassword: public Ui_ChangePassword {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANGEPASSWORD_H
