/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionStart;
    QAction *actionStop;
    QAction *actionExit;
    QWidget *centralWidget;
    QWidget *layoutWidget;
    QVBoxLayout *mainLayout;
    QLabel *titleLabel;
    QHBoxLayout *dataSources;
    QLabel *toLabel;
    QLineEdit *fromFIeld;
    QLabel *fromLabel;
    QLineEdit *toField;
    QListView *primeResults;
    QProgressBar *progressBar;
    QHBoxLayout *primeCounter;
    QLabel *primeCountLabel;
    QLineEdit *primeCountField;
    QHBoxLayout *controlButtons;
    QPushButton *startButton;
    QPushButton *stopButton;
    QPushButton *exitButton;
    QMenuBar *menuBar;
    QMenu *menuFile;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(470, 492);
        actionStart = new QAction(MainWindow);
        actionStart->setObjectName(QStringLiteral("actionStart"));
        actionStop = new QAction(MainWindow);
        actionStop->setObjectName(QStringLiteral("actionStop"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(11, 11, 447, 431));
        mainLayout = new QVBoxLayout(layoutWidget);
        mainLayout->setSpacing(6);
        mainLayout->setContentsMargins(11, 11, 11, 11);
        mainLayout->setObjectName(QStringLiteral("mainLayout"));
        mainLayout->setContentsMargins(10, 10, 10, 10);
        titleLabel = new QLabel(layoutWidget);
        titleLabel->setObjectName(QStringLiteral("titleLabel"));
        QFont font;
        font.setPointSize(12);
        titleLabel->setFont(font);

        mainLayout->addWidget(titleLabel);

        dataSources = new QHBoxLayout();
        dataSources->setSpacing(6);
        dataSources->setObjectName(QStringLiteral("dataSources"));
        toLabel = new QLabel(layoutWidget);
        toLabel->setObjectName(QStringLiteral("toLabel"));

        dataSources->addWidget(toLabel);

        fromFIeld = new QLineEdit(layoutWidget);
        fromFIeld->setObjectName(QStringLiteral("fromFIeld"));

        dataSources->addWidget(fromFIeld);

        fromLabel = new QLabel(layoutWidget);
        fromLabel->setObjectName(QStringLiteral("fromLabel"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(fromLabel->sizePolicy().hasHeightForWidth());
        fromLabel->setSizePolicy(sizePolicy);
        fromLabel->setMinimumSize(QSize(31, 22));
        fromLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        dataSources->addWidget(fromLabel);

        toField = new QLineEdit(layoutWidget);
        toField->setObjectName(QStringLiteral("toField"));

        dataSources->addWidget(toField);


        mainLayout->addLayout(dataSources);

        primeResults = new QListView(layoutWidget);
        primeResults->setObjectName(QStringLiteral("primeResults"));
        primeResults->setEnabled(true);
        primeResults->setAutoFillBackground(false);

        mainLayout->addWidget(primeResults);

        progressBar = new QProgressBar(layoutWidget);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(progressBar->sizePolicy().hasHeightForWidth());
        progressBar->setSizePolicy(sizePolicy1);
        progressBar->setMinimumSize(QSize(400, 0));
        progressBar->setLayoutDirection(Qt::LeftToRight);
        progressBar->setValue(24);
        progressBar->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        progressBar->setOrientation(Qt::Horizontal);

        mainLayout->addWidget(progressBar);

        primeCounter = new QHBoxLayout();
        primeCounter->setSpacing(6);
        primeCounter->setObjectName(QStringLiteral("primeCounter"));
        primeCounter->setContentsMargins(3, 3, 3, 3);
        primeCountLabel = new QLabel(layoutWidget);
        primeCountLabel->setObjectName(QStringLiteral("primeCountLabel"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(primeCountLabel->sizePolicy().hasHeightForWidth());
        primeCountLabel->setSizePolicy(sizePolicy2);
        primeCountLabel->setMinimumSize(QSize(0, 0));

        primeCounter->addWidget(primeCountLabel);

        primeCountField = new QLineEdit(layoutWidget);
        primeCountField->setObjectName(QStringLiteral("primeCountField"));
        QSizePolicy sizePolicy3(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(primeCountField->sizePolicy().hasHeightForWidth());
        primeCountField->setSizePolicy(sizePolicy3);
        primeCountField->setMinimumSize(QSize(0, 0));
        primeCountField->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);
        primeCountField->setReadOnly(true);

        primeCounter->addWidget(primeCountField);


        mainLayout->addLayout(primeCounter);

        controlButtons = new QHBoxLayout();
        controlButtons->setSpacing(6);
        controlButtons->setObjectName(QStringLiteral("controlButtons"));
        controlButtons->setContentsMargins(5, 5, 5, 5);
        startButton = new QPushButton(layoutWidget);
        startButton->setObjectName(QStringLiteral("startButton"));
        sizePolicy1.setHeightForWidth(startButton->sizePolicy().hasHeightForWidth());
        startButton->setSizePolicy(sizePolicy1);
        startButton->setMinimumSize(QSize(135, 30));
        startButton->setAcceptDrops(false);

        controlButtons->addWidget(startButton);

        stopButton = new QPushButton(layoutWidget);
        stopButton->setObjectName(QStringLiteral("stopButton"));
        QSizePolicy sizePolicy4(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(stopButton->sizePolicy().hasHeightForWidth());
        stopButton->setSizePolicy(sizePolicy4);
        stopButton->setMinimumSize(QSize(135, 30));
        stopButton->setAcceptDrops(false);

        controlButtons->addWidget(stopButton);

        exitButton = new QPushButton(layoutWidget);
        exitButton->setObjectName(QStringLiteral("exitButton"));
        sizePolicy3.setHeightForWidth(exitButton->sizePolicy().hasHeightForWidth());
        exitButton->setSizePolicy(sizePolicy3);
        exitButton->setMinimumSize(QSize(135, 30));
        exitButton->setAcceptDrops(false);

        controlButtons->addWidget(exitButton);


        mainLayout->addLayout(controlButtons);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 470, 19));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addAction(actionStart);
        menuFile->addAction(actionStop);
        menuFile->addAction(actionExit);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionStart->setText(QApplication::translate("MainWindow", "Start", 0));
        actionStop->setText(QApplication::translate("MainWindow", "Stop", 0));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", 0));
        titleLabel->setText(QApplication::translate("MainWindow", "How many prime numbers are there?", 0));
        toLabel->setText(QApplication::translate("MainWindow", "From", 0));
        fromLabel->setText(QApplication::translate("MainWindow", "To", 0));
        primeCountLabel->setText(QApplication::translate("MainWindow", " Primes Found:", 0));
        startButton->setText(QApplication::translate("MainWindow", "Start", 0));
        stopButton->setText(QApplication::translate("MainWindow", "Stop", 0));
        exitButton->setText(QApplication::translate("MainWindow", "Exit", 0));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
