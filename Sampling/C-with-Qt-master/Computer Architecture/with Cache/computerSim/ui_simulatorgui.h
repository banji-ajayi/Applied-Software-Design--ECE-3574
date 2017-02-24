/********************************************************************************
** Form generated from reading UI file 'simulatorgui.ui'
**
** Created: Sun Apr 7 23:50:31 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIMULATORGUI_H
#define UI_SIMULATORGUI_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLCDNumber>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QStatusBar>
#include <QtGui/QTableView>
#include <QtGui/QTextBrowser>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SimulatorGui
{
public:
    QAction *actionOpen;
    QAction *actionExit;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_4;
    QPushButton *step;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label_2;
    QTableView *instructionMemory;
    QLabel *label_3;
    QPushButton *reset;
    QTextBrowser *accumulator;
    QTableView *dataMemory;
    QSpacerItem *verticalSpacer_2;
    QLabel *accumulatorOutputLabel;
    QPushButton *clear;
    QPushButton *run;
    QLabel *label;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *horizontalSpacer;
    QLCDNumber *programCounter;
    QTextBrowser *standardOutput;
    QSpacerItem *horizontalSpacer_7;
    QSpacerItem *horizontalSpacer_3;
    QLabel *errorOuputLabel;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *SimulatorGui)
    {
        if (SimulatorGui->objectName().isEmpty())
            SimulatorGui->setObjectName(QString::fromUtf8("SimulatorGui"));
        SimulatorGui->resize(750, 450);
        actionOpen = new QAction(SimulatorGui);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        actionExit = new QAction(SimulatorGui);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        centralWidget = new QWidget(SimulatorGui);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalSpacer_3 = new QSpacerItem(20, 26, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_3, 0, 6, 1, 2);

        horizontalSpacer_2 = new QSpacerItem(49, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 2, 8, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 53, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_4, 0, 4, 1, 1);

        step = new QPushButton(centralWidget);
        step->setObjectName(QString::fromUtf8("step"));

        gridLayout->addWidget(step, 8, 0, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(18, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 6, 9, 1, 1);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 0, 0, 1, 2);

        instructionMemory = new QTableView(centralWidget);
        instructionMemory->setObjectName(QString::fromUtf8("instructionMemory"));
        instructionMemory->setMinimumSize(QSize(0, 0));
        instructionMemory->setMaximumSize(QSize(16777215, 16777215));
        instructionMemory->setAutoScrollMargin(10);
        instructionMemory->setEditTriggers(QAbstractItemView::DoubleClicked);
        instructionMemory->setTabKeyNavigation(true);

        gridLayout->addWidget(instructionMemory, 1, 0, 7, 3);

        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 0, 10, 1, 2);

        reset = new QPushButton(centralWidget);
        reset->setObjectName(QString::fromUtf8("reset"));

        gridLayout->addWidget(reset, 8, 11, 1, 1);

        accumulator = new QTextBrowser(centralWidget);
        accumulator->setObjectName(QString::fromUtf8("accumulator"));
        accumulator->setMaximumSize(QSize(101, 31));

        gridLayout->addWidget(accumulator, 2, 5, 1, 2);

        dataMemory = new QTableView(centralWidget);
        dataMemory->setObjectName(QString::fromUtf8("dataMemory"));
        dataMemory->setEditTriggers(QAbstractItemView::DoubleClicked);

        gridLayout->addWidget(dataMemory, 1, 10, 7, 3);

        verticalSpacer_2 = new QSpacerItem(20, 77, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 7, 5, 1, 1);

        accumulatorOutputLabel = new QLabel(centralWidget);
        accumulatorOutputLabel->setObjectName(QString::fromUtf8("accumulatorOutputLabel"));

        gridLayout->addWidget(accumulatorOutputLabel, 1, 5, 1, 1);

        clear = new QPushButton(centralWidget);
        clear->setObjectName(QString::fromUtf8("clear"));

        gridLayout->addWidget(clear, 8, 12, 1, 1);

        run = new QPushButton(centralWidget);
        run->setObjectName(QString::fromUtf8("run"));

        gridLayout->addWidget(run, 8, 1, 1, 1);

        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 3, 5, 1, 2);

        horizontalSpacer_5 = new QSpacerItem(497, 24, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_5, 8, 2, 1, 9);

        horizontalSpacer_6 = new QSpacerItem(64, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_6, 4, 3, 1, 2);

        horizontalSpacer = new QSpacerItem(70, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 2, 3, 1, 2);

        programCounter = new QLCDNumber(centralWidget);
        programCounter->setObjectName(QString::fromUtf8("programCounter"));
        programCounter->setMinimumSize(QSize(71, 31));
        programCounter->setMaximumSize(QSize(71, 31));

        gridLayout->addWidget(programCounter, 4, 5, 1, 1);

        standardOutput = new QTextBrowser(centralWidget);
        standardOutput->setObjectName(QString::fromUtf8("standardOutput"));

        gridLayout->addWidget(standardOutput, 6, 4, 1, 5);

        horizontalSpacer_7 = new QSpacerItem(43, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_7, 4, 7, 1, 2);

        horizontalSpacer_3 = new QSpacerItem(18, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 6, 3, 1, 1);

        errorOuputLabel = new QLabel(centralWidget);
        errorOuputLabel->setObjectName(QString::fromUtf8("errorOuputLabel"));

        gridLayout->addWidget(errorOuputLabel, 5, 5, 1, 2);

        SimulatorGui->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(SimulatorGui);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 750, 25));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        SimulatorGui->setMenuBar(menuBar);
        mainToolBar = new QToolBar(SimulatorGui);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        SimulatorGui->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(SimulatorGui);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        SimulatorGui->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionExit);

        retranslateUi(SimulatorGui);

        QMetaObject::connectSlotsByName(SimulatorGui);
    } // setupUi

    void retranslateUi(QMainWindow *SimulatorGui)
    {
        SimulatorGui->setWindowTitle(QApplication::translate("SimulatorGui", "SimulatorGui", 0, QApplication::UnicodeUTF8));
        actionOpen->setText(QApplication::translate("SimulatorGui", "Open", 0, QApplication::UnicodeUTF8));
        actionOpen->setShortcut(QApplication::translate("SimulatorGui", "Ctrl+O", 0, QApplication::UnicodeUTF8));
        actionExit->setText(QApplication::translate("SimulatorGui", "Exit", 0, QApplication::UnicodeUTF8));
        actionExit->setShortcut(QApplication::translate("SimulatorGui", "Ctrl+W", 0, QApplication::UnicodeUTF8));
        step->setText(QApplication::translate("SimulatorGui", "Step", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("SimulatorGui", "Instruction Memory Table", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("SimulatorGui", "Data Memory Table", 0, QApplication::UnicodeUTF8));
        reset->setText(QApplication::translate("SimulatorGui", "Reset", 0, QApplication::UnicodeUTF8));
        accumulator->setHtml(QApplication::translate("SimulatorGui", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"right\" style=\"-qt-paragraph-type:empty; margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", 0, QApplication::UnicodeUTF8));
        accumulatorOutputLabel->setText(QApplication::translate("SimulatorGui", "Accumulator", 0, QApplication::UnicodeUTF8));
        clear->setText(QApplication::translate("SimulatorGui", "Clear", 0, QApplication::UnicodeUTF8));
        run->setText(QApplication::translate("SimulatorGui", "Run", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("SimulatorGui", "Program Counter", 0, QApplication::UnicodeUTF8));
        errorOuputLabel->setText(QApplication::translate("SimulatorGui", "Standard Output", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("SimulatorGui", "File", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SimulatorGui: public Ui_SimulatorGui {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIMULATORGUI_H
