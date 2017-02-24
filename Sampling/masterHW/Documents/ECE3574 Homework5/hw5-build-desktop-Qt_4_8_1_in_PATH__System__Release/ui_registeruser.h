/********************************************************************************
** Form generated from reading UI file 'registeruser.ui'
**
** Created: Sun Oct 21 22:20:44 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTERUSER_H
#define UI_REGISTERUSER_H

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

class Ui_RegisterUser
{
public:
    QPushButton *cancelButton;
    QPushButton *okButton;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *nameLabel;
    QLabel *passwordLabel;
    QLabel *rPasswordLabel;
    QLabel *colorLabel;
    QComboBox *colorComboBox;
    QLineEdit *passwordEdit;
    QLineEdit *rPasswordEdit;
    QLineEdit *nameEdit;

    void setupUi(QWidget *RegisterUser)
    {
        if (RegisterUser->objectName().isEmpty())
            RegisterUser->setObjectName(QString::fromUtf8("RegisterUser"));
        RegisterUser->resize(528, 333);
        cancelButton = new QPushButton(RegisterUser);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        cancelButton->setGeometry(QRect(350, 210, 81, 27));
        okButton = new QPushButton(RegisterUser);
        okButton->setObjectName(QString::fromUtf8("okButton"));
        okButton->setGeometry(QRect(250, 210, 91, 27));
        formLayoutWidget = new QWidget(RegisterUser);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(70, 40, 321, 128));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        formLayout->setContentsMargins(0, 0, 0, 0);
        nameLabel = new QLabel(formLayoutWidget);
        nameLabel->setObjectName(QString::fromUtf8("nameLabel"));

        formLayout->setWidget(0, QFormLayout::LabelRole, nameLabel);

        passwordLabel = new QLabel(formLayoutWidget);
        passwordLabel->setObjectName(QString::fromUtf8("passwordLabel"));

        formLayout->setWidget(1, QFormLayout::LabelRole, passwordLabel);

        rPasswordLabel = new QLabel(formLayoutWidget);
        rPasswordLabel->setObjectName(QString::fromUtf8("rPasswordLabel"));

        formLayout->setWidget(2, QFormLayout::LabelRole, rPasswordLabel);

        colorLabel = new QLabel(formLayoutWidget);
        colorLabel->setObjectName(QString::fromUtf8("colorLabel"));

        formLayout->setWidget(3, QFormLayout::LabelRole, colorLabel);

        colorComboBox = new QComboBox(formLayoutWidget);
        colorComboBox->setObjectName(QString::fromUtf8("colorComboBox"));

        formLayout->setWidget(3, QFormLayout::FieldRole, colorComboBox);

        passwordEdit = new QLineEdit(formLayoutWidget);
        passwordEdit->setObjectName(QString::fromUtf8("passwordEdit"));

        formLayout->setWidget(1, QFormLayout::FieldRole, passwordEdit);

        rPasswordEdit = new QLineEdit(formLayoutWidget);
        rPasswordEdit->setObjectName(QString::fromUtf8("rPasswordEdit"));

        formLayout->setWidget(2, QFormLayout::FieldRole, rPasswordEdit);

        nameEdit = new QLineEdit(formLayoutWidget);
        nameEdit->setObjectName(QString::fromUtf8("nameEdit"));

        formLayout->setWidget(0, QFormLayout::FieldRole, nameEdit);


        retranslateUi(RegisterUser);

        QMetaObject::connectSlotsByName(RegisterUser);
    } // setupUi

    void retranslateUi(QWidget *RegisterUser)
    {
        RegisterUser->setWindowTitle(QApplication::translate("RegisterUser", "Form", 0, QApplication::UnicodeUTF8));
        cancelButton->setText(QApplication::translate("RegisterUser", "Cancel", 0, QApplication::UnicodeUTF8));
        okButton->setText(QApplication::translate("RegisterUser", "Ok", 0, QApplication::UnicodeUTF8));
        nameLabel->setText(QApplication::translate("RegisterUser", "User name", 0, QApplication::UnicodeUTF8));
        passwordLabel->setText(QApplication::translate("RegisterUser", "Password", 0, QApplication::UnicodeUTF8));
        rPasswordLabel->setText(QApplication::translate("RegisterUser", "Re-enter Password", 0, QApplication::UnicodeUTF8));
        colorLabel->setText(QApplication::translate("RegisterUser", "Color", 0, QApplication::UnicodeUTF8));
        colorComboBox->clear();
        colorComboBox->insertItems(0, QStringList()
         << QApplication::translate("RegisterUser", "Red", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("RegisterUser", "Green", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("RegisterUser", "Blue", 0, QApplication::UnicodeUTF8)
        );
    } // retranslateUi

};

namespace Ui {
    class RegisterUser: public Ui_RegisterUser {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERUSER_H
