/********************************************************************************
** Form generated from reading UI file 'tictactoe.ui'
**
** Created: Thu Nov 1 14:01:35 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TICTACTOE_H
#define UI_TICTACTOE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFormLayout>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TicTacToe
{
public:
    QFrame *line;
    QFrame *line_2;
    QFrame *line_3;
    QFrame *line_4;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *computerLabel;
    QLabel *drawLabel;
    QLabel *userLabel;
    QLabel *computerScore;
    QLabel *drawCount;
    QLabel *userScore;
    QLabel *label;
    QPushButton *endGameButton;
    QLabel *Grid1;
    QPushButton *Grid1Button;
    QPushButton *Grid2Button;
    QPushButton *Grid3Button;
    QPushButton *Grid4Button;
    QPushButton *Grid5Button;
    QPushButton *Grid6Button;
    QPushButton *Grid7Button;
    QPushButton *Grid8Button;
    QPushButton *Grid9Button;
    QLabel *Grid2;
    QLabel *Grid3;
    QLabel *Grid4;
    QLabel *Grid5;
    QLabel *Grid6;
    QLabel *Grid7;
    QLabel *Grid8;
    QLabel *Grid9;

    void setupUi(QWidget *TicTacToe)
    {
        if (TicTacToe->objectName().isEmpty())
            TicTacToe->setObjectName(QString::fromUtf8("TicTacToe"));
        TicTacToe->resize(576, 300);
        line = new QFrame(TicTacToe);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(110, 20, 20, 241));
        QFont font;
        font.setPointSize(30);
        line->setFont(font);
        line->setAutoFillBackground(false);
        line->setFrameShadow(QFrame::Plain);
        line->setLineWidth(3);
        line->setFrameShape(QFrame::VLine);
        line_2 = new QFrame(TicTacToe);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(200, 20, 20, 241));
        line_2->setFont(font);
        line_2->setAutoFillBackground(false);
        line_2->setFrameShadow(QFrame::Plain);
        line_2->setLineWidth(3);
        line_2->setFrameShape(QFrame::VLine);
        line_3 = new QFrame(TicTacToe);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setGeometry(QRect(30, 90, 271, 20));
        line_3->setFont(font);
        line_3->setAutoFillBackground(false);
        line_3->setFrameShadow(QFrame::Plain);
        line_3->setLineWidth(3);
        line_3->setFrameShape(QFrame::HLine);
        line_4 = new QFrame(TicTacToe);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setGeometry(QRect(30, 170, 271, 20));
        line_4->setFont(font);
        line_4->setAutoFillBackground(false);
        line_4->setFrameShadow(QFrame::Plain);
        line_4->setLineWidth(3);
        line_4->setFrameShape(QFrame::HLine);
        formLayoutWidget = new QWidget(TicTacToe);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(380, 60, 160, 91));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        computerLabel = new QLabel(formLayoutWidget);
        computerLabel->setObjectName(QString::fromUtf8("computerLabel"));

        formLayout->setWidget(0, QFormLayout::LabelRole, computerLabel);

        drawLabel = new QLabel(formLayoutWidget);
        drawLabel->setObjectName(QString::fromUtf8("drawLabel"));

        formLayout->setWidget(2, QFormLayout::LabelRole, drawLabel);

        userLabel = new QLabel(formLayoutWidget);
        userLabel->setObjectName(QString::fromUtf8("userLabel"));

        formLayout->setWidget(1, QFormLayout::LabelRole, userLabel);

        computerScore = new QLabel(formLayoutWidget);
        computerScore->setObjectName(QString::fromUtf8("computerScore"));

        formLayout->setWidget(0, QFormLayout::FieldRole, computerScore);

        drawCount = new QLabel(formLayoutWidget);
        drawCount->setObjectName(QString::fromUtf8("drawCount"));

        formLayout->setWidget(2, QFormLayout::FieldRole, drawCount);

        userScore = new QLabel(formLayoutWidget);
        userScore->setObjectName(QString::fromUtf8("userScore"));

        formLayout->setWidget(1, QFormLayout::FieldRole, userScore);

        label = new QLabel(TicTacToe);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(420, 40, 66, 17));
        endGameButton = new QPushButton(TicTacToe);
        endGameButton->setObjectName(QString::fromUtf8("endGameButton"));
        endGameButton->setGeometry(QRect(410, 210, 98, 27));
        endGameButton->setFlat(false);
        Grid1 = new QLabel(TicTacToe);
        Grid1->setObjectName(QString::fromUtf8("Grid1"));
        Grid1->setGeometry(QRect(30, 20, 91, 81));
        QFont font1;
        font1.setPointSize(70);
        Grid1->setFont(font1);
        Grid1->setAlignment(Qt::AlignCenter);
        Grid1Button = new QPushButton(TicTacToe);
        Grid1Button->setObjectName(QString::fromUtf8("Grid1Button"));
        Grid1Button->setGeometry(QRect(30, 20, 89, 79));
        Grid1Button->setFocusPolicy(Qt::NoFocus);
        Grid1Button->setFlat(true);
        Grid2Button = new QPushButton(TicTacToe);
        Grid2Button->setObjectName(QString::fromUtf8("Grid2Button"));
        Grid2Button->setGeometry(QRect(120, 20, 89, 79));
        Grid2Button->setFocusPolicy(Qt::NoFocus);
        Grid2Button->setFlat(true);
        Grid3Button = new QPushButton(TicTacToe);
        Grid3Button->setObjectName(QString::fromUtf8("Grid3Button"));
        Grid3Button->setGeometry(QRect(210, 20, 89, 79));
        Grid3Button->setFocusPolicy(Qt::NoFocus);
        Grid3Button->setFlat(true);
        Grid4Button = new QPushButton(TicTacToe);
        Grid4Button->setObjectName(QString::fromUtf8("Grid4Button"));
        Grid4Button->setGeometry(QRect(30, 100, 89, 79));
        Grid4Button->setFocusPolicy(Qt::NoFocus);
        Grid4Button->setFlat(true);
        Grid5Button = new QPushButton(TicTacToe);
        Grid5Button->setObjectName(QString::fromUtf8("Grid5Button"));
        Grid5Button->setGeometry(QRect(120, 100, 89, 79));
        Grid5Button->setFocusPolicy(Qt::NoFocus);
        Grid5Button->setFlat(true);
        Grid6Button = new QPushButton(TicTacToe);
        Grid6Button->setObjectName(QString::fromUtf8("Grid6Button"));
        Grid6Button->setGeometry(QRect(210, 100, 89, 79));
        Grid6Button->setFocusPolicy(Qt::NoFocus);
        Grid6Button->setFlat(true);
        Grid7Button = new QPushButton(TicTacToe);
        Grid7Button->setObjectName(QString::fromUtf8("Grid7Button"));
        Grid7Button->setGeometry(QRect(30, 180, 89, 79));
        Grid7Button->setFocusPolicy(Qt::NoFocus);
        Grid7Button->setFlat(true);
        Grid8Button = new QPushButton(TicTacToe);
        Grid8Button->setObjectName(QString::fromUtf8("Grid8Button"));
        Grid8Button->setGeometry(QRect(120, 180, 89, 79));
        Grid8Button->setFocusPolicy(Qt::NoFocus);
        Grid8Button->setFlat(true);
        Grid9Button = new QPushButton(TicTacToe);
        Grid9Button->setObjectName(QString::fromUtf8("Grid9Button"));
        Grid9Button->setGeometry(QRect(210, 180, 89, 79));
        QFont font2;
        font2.setKerning(true);
        Grid9Button->setFont(font2);
        Grid9Button->setFocusPolicy(Qt::NoFocus);
        Grid9Button->setCheckable(false);
        Grid9Button->setAutoDefault(false);
        Grid9Button->setDefault(false);
        Grid9Button->setFlat(true);
        Grid2 = new QLabel(TicTacToe);
        Grid2->setObjectName(QString::fromUtf8("Grid2"));
        Grid2->setGeometry(QRect(120, 20, 91, 81));
        Grid2->setFont(font1);
        Grid2->setAlignment(Qt::AlignCenter);
        Grid3 = new QLabel(TicTacToe);
        Grid3->setObjectName(QString::fromUtf8("Grid3"));
        Grid3->setGeometry(QRect(210, 20, 91, 81));
        Grid3->setFont(font1);
        Grid3->setAlignment(Qt::AlignCenter);
        Grid4 = new QLabel(TicTacToe);
        Grid4->setObjectName(QString::fromUtf8("Grid4"));
        Grid4->setGeometry(QRect(30, 100, 91, 81));
        Grid4->setFont(font1);
        Grid4->setAlignment(Qt::AlignCenter);
        Grid5 = new QLabel(TicTacToe);
        Grid5->setObjectName(QString::fromUtf8("Grid5"));
        Grid5->setGeometry(QRect(120, 100, 91, 81));
        Grid5->setFont(font1);
        Grid5->setAlignment(Qt::AlignCenter);
        Grid6 = new QLabel(TicTacToe);
        Grid6->setObjectName(QString::fromUtf8("Grid6"));
        Grid6->setGeometry(QRect(210, 100, 91, 81));
        Grid6->setFont(font1);
        Grid6->setAlignment(Qt::AlignCenter);
        Grid7 = new QLabel(TicTacToe);
        Grid7->setObjectName(QString::fromUtf8("Grid7"));
        Grid7->setGeometry(QRect(30, 180, 91, 81));
        Grid7->setFont(font1);
        Grid7->setAlignment(Qt::AlignCenter);
        Grid8 = new QLabel(TicTacToe);
        Grid8->setObjectName(QString::fromUtf8("Grid8"));
        Grid8->setGeometry(QRect(120, 180, 91, 81));
        Grid8->setFont(font1);
        Grid8->setAlignment(Qt::AlignCenter);
        Grid9 = new QLabel(TicTacToe);
        Grid9->setObjectName(QString::fromUtf8("Grid9"));
        Grid9->setEnabled(true);
        Grid9->setGeometry(QRect(210, 180, 91, 81));
        QFont font3;
        font3.setPointSize(70);
        font3.setKerning(false);
        Grid9->setFont(font3);
        Grid9->setAlignment(Qt::AlignCenter);

        retranslateUi(TicTacToe);

        QMetaObject::connectSlotsByName(TicTacToe);
    } // setupUi

    void retranslateUi(QWidget *TicTacToe)
    {
        TicTacToe->setWindowTitle(QApplication::translate("TicTacToe", "Form", 0, QApplication::UnicodeUTF8));
        computerLabel->setText(QApplication::translate("TicTacToe", "Computer", 0, QApplication::UnicodeUTF8));
        drawLabel->setText(QApplication::translate("TicTacToe", "Draw", 0, QApplication::UnicodeUTF8));
        userLabel->setText(QString());
        computerScore->setText(QApplication::translate("TicTacToe", "0", 0, QApplication::UnicodeUTF8));
        drawCount->setText(QApplication::translate("TicTacToe", "0", 0, QApplication::UnicodeUTF8));
        userScore->setText(QApplication::translate("TicTacToe", "0", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("TicTacToe", "Score", 0, QApplication::UnicodeUTF8));
        endGameButton->setText(QApplication::translate("TicTacToe", "End Game", 0, QApplication::UnicodeUTF8));
        Grid1->setText(QString());
        Grid2->setText(QString());
        Grid3->setText(QString());
        Grid4->setText(QString());
        Grid5->setText(QString());
        Grid6->setText(QString());
        Grid7->setText(QString());
        Grid8->setText(QString());
        Grid9->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class TicTacToe: public Ui_TicTacToe {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TICTACTOE_H
