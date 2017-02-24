/********************************************************************************
** Form generated from reading UI file 'test.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEST_H
#define UI_TEST_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QDial>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Test
{
public:
    QHBoxLayout *hboxLayout;
    QVBoxLayout *vboxLayout;
    QHBoxLayout *hboxLayout1;
    QComboBox *comboBox;
    QSpinBox *spinBox;
    QDoubleSpinBox *doubleSpinBox;
    QHBoxLayout *hboxLayout2;
    QLineEdit *lineEdit;
    QLCDNumber *lcdNumber;
    QProgressBar *progressBar;
    QHBoxLayout *hboxLayout3;
    QTimeEdit *timeEdit_2;
    QDateEdit *dateEdit_2;
    QDateTimeEdit *dateTimeEdit_2;
    QSlider *horizontalSlider;
    QHBoxLayout *hboxLayout4;
    QRadioButton *radioButton_2;
    QCheckBox *checkBox_2;
    QPushButton *pushButton_2;
    QHBoxLayout *hboxLayout5;
    QTextEdit *textEdit_2_2;
    QDial *dial_2_2;
    QSlider *verticalSlider;

    void setupUi(QDialog *Test)
    {
        if (Test->objectName().isEmpty())
            Test->setObjectName(QStringLiteral("Test"));
        Test->resize(660, 640);
        hboxLayout = new QHBoxLayout(Test);
#ifndef Q_OS_MAC
        hboxLayout->setSpacing(6);
#endif
        hboxLayout->setContentsMargins(8, 8, 8, 8);
        hboxLayout->setObjectName(QStringLiteral("hboxLayout"));
        vboxLayout = new QVBoxLayout();
#ifndef Q_OS_MAC
        vboxLayout->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        vboxLayout->setContentsMargins(0, 0, 0, 0);
#endif
        vboxLayout->setObjectName(QStringLiteral("vboxLayout"));
        hboxLayout1 = new QHBoxLayout();
#ifndef Q_OS_MAC
        hboxLayout1->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        hboxLayout1->setContentsMargins(0, 0, 0, 0);
#endif
        hboxLayout1->setObjectName(QStringLiteral("hboxLayout1"));
        comboBox = new QComboBox(Test);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        hboxLayout1->addWidget(comboBox);

        spinBox = new QSpinBox(Test);
        spinBox->setObjectName(QStringLiteral("spinBox"));

        hboxLayout1->addWidget(spinBox);

        doubleSpinBox = new QDoubleSpinBox(Test);
        doubleSpinBox->setObjectName(QStringLiteral("doubleSpinBox"));

        hboxLayout1->addWidget(doubleSpinBox);


        vboxLayout->addLayout(hboxLayout1);

        hboxLayout2 = new QHBoxLayout();
#ifndef Q_OS_MAC
        hboxLayout2->setSpacing(6);
#endif
        hboxLayout2->setContentsMargins(0, 0, 0, 0);
        hboxLayout2->setObjectName(QStringLiteral("hboxLayout2"));
        lineEdit = new QLineEdit(Test);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        hboxLayout2->addWidget(lineEdit);

        lcdNumber = new QLCDNumber(Test);
        lcdNumber->setObjectName(QStringLiteral("lcdNumber"));

        hboxLayout2->addWidget(lcdNumber);

        progressBar = new QProgressBar(Test);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setValue(24);

        hboxLayout2->addWidget(progressBar);


        vboxLayout->addLayout(hboxLayout2);

        hboxLayout3 = new QHBoxLayout();
#ifndef Q_OS_MAC
        hboxLayout3->setSpacing(6);
#endif
        hboxLayout3->setContentsMargins(0, 0, 0, 0);
        hboxLayout3->setObjectName(QStringLiteral("hboxLayout3"));
        timeEdit_2 = new QTimeEdit(Test);
        timeEdit_2->setObjectName(QStringLiteral("timeEdit_2"));

        hboxLayout3->addWidget(timeEdit_2);

        dateEdit_2 = new QDateEdit(Test);
        dateEdit_2->setObjectName(QStringLiteral("dateEdit_2"));

        hboxLayout3->addWidget(dateEdit_2);

        dateTimeEdit_2 = new QDateTimeEdit(Test);
        dateTimeEdit_2->setObjectName(QStringLiteral("dateTimeEdit_2"));

        hboxLayout3->addWidget(dateTimeEdit_2);


        vboxLayout->addLayout(hboxLayout3);

        horizontalSlider = new QSlider(Test);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setOrientation(Qt::Horizontal);

        vboxLayout->addWidget(horizontalSlider);

        hboxLayout4 = new QHBoxLayout();
#ifndef Q_OS_MAC
        hboxLayout4->setSpacing(6);
#endif
        hboxLayout4->setContentsMargins(0, 0, 0, 0);
        hboxLayout4->setObjectName(QStringLiteral("hboxLayout4"));
        radioButton_2 = new QRadioButton(Test);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));

        hboxLayout4->addWidget(radioButton_2);

        checkBox_2 = new QCheckBox(Test);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));

        hboxLayout4->addWidget(checkBox_2);

        pushButton_2 = new QPushButton(Test);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        hboxLayout4->addWidget(pushButton_2);


        vboxLayout->addLayout(hboxLayout4);

        hboxLayout5 = new QHBoxLayout();
#ifndef Q_OS_MAC
        hboxLayout5->setSpacing(6);
#endif
        hboxLayout5->setContentsMargins(0, 0, 0, 0);
        hboxLayout5->setObjectName(QStringLiteral("hboxLayout5"));
        textEdit_2_2 = new QTextEdit(Test);
        textEdit_2_2->setObjectName(QStringLiteral("textEdit_2_2"));

        hboxLayout5->addWidget(textEdit_2_2);

        dial_2_2 = new QDial(Test);
        dial_2_2->setObjectName(QStringLiteral("dial_2_2"));
        dial_2_2->setOrientation(Qt::Horizontal);

        hboxLayout5->addWidget(dial_2_2);


        vboxLayout->addLayout(hboxLayout5);


        hboxLayout->addLayout(vboxLayout);

        verticalSlider = new QSlider(Test);
        verticalSlider->setObjectName(QStringLiteral("verticalSlider"));
        verticalSlider->setOrientation(Qt::Vertical);

        hboxLayout->addWidget(verticalSlider);


        retranslateUi(Test);

        QMetaObject::connectSlotsByName(Test);
    } // setupUi

    void retranslateUi(QDialog *Test)
    {
        Test->setWindowTitle(QApplication::translate("Test", "Dialog", 0));
        radioButton_2->setText(QApplication::translate("Test", "RadioButton", 0));
        checkBox_2->setText(QApplication::translate("Test", "CheckBox", 0));
        pushButton_2->setText(QApplication::translate("Test", "PushButton", 0));
    } // retranslateUi

};

namespace Ui {
    class Test: public Ui_Test {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEST_H
