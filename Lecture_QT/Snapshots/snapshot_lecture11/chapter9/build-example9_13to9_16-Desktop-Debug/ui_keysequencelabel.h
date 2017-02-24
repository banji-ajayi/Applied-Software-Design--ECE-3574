/********************************************************************************
** Form generated from reading UI file 'keysequencelabel.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KEYSEQUENCELABEL_H
#define UI_KEYSEQUENCELABEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_KeySequenceLabel
{
public:
    QWidget *centralWidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLCDNumber *lcdNumber;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton;
    QLabel *label_2;
    QMenuBar *menuBar;
    QMenu *menuEvent_Loop_Deom;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *KeySequenceLabel)
    {
        if (KeySequenceLabel->objectName().isEmpty())
            KeySequenceLabel->setObjectName(QStringLiteral("KeySequenceLabel"));
        KeySequenceLabel->resize(400, 300);
        centralWidget = new QWidget(KeySequenceLabel);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayoutWidget = new QWidget(centralWidget);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 0, 381, 121));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(horizontalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        lcdNumber = new QLCDNumber(horizontalLayoutWidget);
        lcdNumber->setObjectName(QStringLiteral("lcdNumber"));

        horizontalLayout->addWidget(lcdNumber);

        horizontalLayoutWidget_2 = new QWidget(centralWidget);
        horizontalLayoutWidget_2->setObjectName(QStringLiteral("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(10, 130, 381, 111));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(horizontalLayoutWidget_2);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout_2->addWidget(pushButton);

        label_2 = new QLabel(horizontalLayoutWidget_2);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        KeySequenceLabel->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(KeySequenceLabel);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 25));
        menuEvent_Loop_Deom = new QMenu(menuBar);
        menuEvent_Loop_Deom->setObjectName(QStringLiteral("menuEvent_Loop_Deom"));
        KeySequenceLabel->setMenuBar(menuBar);
        mainToolBar = new QToolBar(KeySequenceLabel);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        KeySequenceLabel->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(KeySequenceLabel);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        KeySequenceLabel->setStatusBar(statusBar);

        menuBar->addAction(menuEvent_Loop_Deom->menuAction());

        retranslateUi(KeySequenceLabel);

        QMetaObject::connectSlotsByName(KeySequenceLabel);
    } // setupUi

    void retranslateUi(QMainWindow *KeySequenceLabel)
    {
        KeySequenceLabel->setWindowTitle(QApplication::translate("KeySequenceLabel", "KeySequenceLabel", 0));
        label->setText(QApplication::translate("KeySequenceLabel", "Number of paintEvents()", 0));
        pushButton->setText(QApplication::translate("KeySequenceLabel", "Clear", 0));
        label_2->setText(QApplication::translate("KeySequenceLabel", "QKeySequence", 0));
        menuEvent_Loop_Deom->setTitle(QApplication::translate("KeySequenceLabel", "Event Loop Demo", 0));
    } // retranslateUi

};

namespace Ui {
    class KeySequenceLabel: public Ui_KeySequenceLabel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KEYSEQUENCELABEL_H
