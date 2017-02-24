#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <QWidget>
#include <classDefinitions.h>
#include <QMessageBox>

extern QList<record> records;

namespace Ui {
class TicTacToe;
}

class TicTacToe : public QWidget
{
    Q_OBJECT
    
public:
    QString mName;
    QString mColor;
    explicit TicTacToe(QWidget *parent = 0);
    ~TicTacToe();
    void setName(QString);
    void setColor(QString);
    void clearScores();
    bool checkTwoInARow(int&, QString);
    bool checkThreeInARow(QString);
    bool checkComputerWin();
    bool checkUserWin();
    void clearGrid();
    void computerPlay();
    bool checkDraw();
    void checkGameCondition();
    int findEmptyGrid();
    void blockEndGame(int);
    
signals:
    void returnToWelcomeSignal(QString);

private slots:
    void on_endGameButton_clicked();

    void on_Grid1Button_clicked();

    void on_Grid2Button_clicked();

    void on_Grid3Button_clicked();

    void on_Grid4Button_clicked();

    void on_Grid5Button_clicked();

    void on_Grid6Button_clicked();

    void on_Grid7Button_clicked();

    void on_Grid8Button_clicked();

    void on_Grid9Button_clicked();

private:
    Ui::TicTacToe *ui;
    int mUserScore;
    int mComputerScore;
    int mDrawCount;
};

#endif // TICTACTOE_H
