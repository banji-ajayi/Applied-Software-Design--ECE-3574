/********************************************************************************
** Form generated from reading UI file 'datamemorycachegui.ui'
**
** Created: Sun Apr 7 23:50:31 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATAMEMORYCACHEGUI_H
#define UI_DATAMEMORYCACHEGUI_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTableView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DataMemoryCacheGui
{
public:
    QGridLayout *gridLayout_10;
    QGridLayout *gridLayout_5;
    QLabel *cacheSizeLabel;
    QGridLayout *gridLayout_7;
    QLabel *blockSizeLabel;
    QGridLayout *gridLayout_3;
    QLabel *cacheEfficiencyLabel;
    QGridLayout *gridLayout_6;
    QComboBox *cacheSize;
    QGridLayout *gridLayout_8;
    QComboBox *blockSize;
    QGridLayout *gridLayout_9;
    QPushButton *setCacheSize;
    QSpacerItem *horizontalSpacer;
    QGridLayout *gridLayout_4;
    QLineEdit *cacheEfficiency;
    QGridLayout *gridLayout;
    QLabel *cacheLabel;
    QGridLayout *gridLayout_2;
    QTableView *cacheTable;

    void setupUi(QWidget *DataMemoryCacheGui)
    {
        if (DataMemoryCacheGui->objectName().isEmpty())
            DataMemoryCacheGui->setObjectName(QString::fromUtf8("DataMemoryCacheGui"));
        DataMemoryCacheGui->resize(831, 380);
        gridLayout_10 = new QGridLayout(DataMemoryCacheGui);
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        gridLayout_5 = new QGridLayout();
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        cacheSizeLabel = new QLabel(DataMemoryCacheGui);
        cacheSizeLabel->setObjectName(QString::fromUtf8("cacheSizeLabel"));

        gridLayout_5->addWidget(cacheSizeLabel, 0, 0, 1, 1);


        gridLayout_10->addLayout(gridLayout_5, 0, 0, 1, 1);

        gridLayout_7 = new QGridLayout();
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        blockSizeLabel = new QLabel(DataMemoryCacheGui);
        blockSizeLabel->setObjectName(QString::fromUtf8("blockSizeLabel"));

        gridLayout_7->addWidget(blockSizeLabel, 0, 0, 1, 1);


        gridLayout_10->addLayout(gridLayout_7, 0, 1, 1, 1);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        cacheEfficiencyLabel = new QLabel(DataMemoryCacheGui);
        cacheEfficiencyLabel->setObjectName(QString::fromUtf8("cacheEfficiencyLabel"));

        gridLayout_3->addWidget(cacheEfficiencyLabel, 1, 0, 1, 1);


        gridLayout_10->addLayout(gridLayout_3, 0, 5, 1, 1);

        gridLayout_6 = new QGridLayout();
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        cacheSize = new QComboBox(DataMemoryCacheGui);
        cacheSize->setObjectName(QString::fromUtf8("cacheSize"));

        gridLayout_6->addWidget(cacheSize, 0, 0, 1, 1);


        gridLayout_10->addLayout(gridLayout_6, 1, 0, 1, 1);

        gridLayout_8 = new QGridLayout();
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        blockSize = new QComboBox(DataMemoryCacheGui);
        blockSize->setObjectName(QString::fromUtf8("blockSize"));

        gridLayout_8->addWidget(blockSize, 0, 0, 1, 1);


        gridLayout_10->addLayout(gridLayout_8, 1, 1, 1, 2);

        gridLayout_9 = new QGridLayout();
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        setCacheSize = new QPushButton(DataMemoryCacheGui);
        setCacheSize->setObjectName(QString::fromUtf8("setCacheSize"));

        gridLayout_9->addWidget(setCacheSize, 0, 0, 1, 1);


        gridLayout_10->addLayout(gridLayout_9, 1, 3, 1, 1);

        horizontalSpacer = new QSpacerItem(188, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_10->addItem(horizontalSpacer, 1, 4, 1, 1);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        cacheEfficiency = new QLineEdit(DataMemoryCacheGui);
        cacheEfficiency->setObjectName(QString::fromUtf8("cacheEfficiency"));

        gridLayout_4->addWidget(cacheEfficiency, 0, 0, 1, 1);


        gridLayout_10->addLayout(gridLayout_4, 1, 5, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        cacheLabel = new QLabel(DataMemoryCacheGui);
        cacheLabel->setObjectName(QString::fromUtf8("cacheLabel"));

        gridLayout->addWidget(cacheLabel, 0, 0, 1, 1);


        gridLayout_10->addLayout(gridLayout, 2, 2, 1, 2);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        cacheTable = new QTableView(DataMemoryCacheGui);
        cacheTable->setObjectName(QString::fromUtf8("cacheTable"));
        cacheTable->setEditTriggers(QAbstractItemView::NoEditTriggers);

        gridLayout_2->addWidget(cacheTable, 0, 0, 1, 1);


        gridLayout_10->addLayout(gridLayout_2, 3, 0, 1, 6);


        retranslateUi(DataMemoryCacheGui);

        QMetaObject::connectSlotsByName(DataMemoryCacheGui);
    } // setupUi

    void retranslateUi(QWidget *DataMemoryCacheGui)
    {
        DataMemoryCacheGui->setWindowTitle(QApplication::translate("DataMemoryCacheGui", "Form", 0, QApplication::UnicodeUTF8));
        cacheSizeLabel->setText(QApplication::translate("DataMemoryCacheGui", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt;\">Cache Size</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        blockSizeLabel->setText(QApplication::translate("DataMemoryCacheGui", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt;\">Block Size</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        cacheEfficiencyLabel->setText(QApplication::translate("DataMemoryCacheGui", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt;\">Cache Efficiency</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        cacheSize->clear();
        cacheSize->insertItems(0, QStringList()
         << QApplication::translate("DataMemoryCacheGui", "Select Cache Size", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DataMemoryCacheGui", "16", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DataMemoryCacheGui", "32", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DataMemoryCacheGui", "64", 0, QApplication::UnicodeUTF8)
        );
        blockSize->clear();
        blockSize->insertItems(0, QStringList()
         << QApplication::translate("DataMemoryCacheGui", "Select Block Size", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DataMemoryCacheGui", "2", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DataMemoryCacheGui", "4", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DataMemoryCacheGui", "8", 0, QApplication::UnicodeUTF8)
        );
        setCacheSize->setText(QApplication::translate("DataMemoryCacheGui", "Set Cache Size", 0, QApplication::UnicodeUTF8));
        cacheLabel->setText(QApplication::translate("DataMemoryCacheGui", "<html><head/><body><p align=\"center\"><span style=\" font-size:14pt;\">Cache Table</span></p></body></html>", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DataMemoryCacheGui: public Ui_DataMemoryCacheGui {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATAMEMORYCACHEGUI_H
