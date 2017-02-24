#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <QDialog>
#include <QIcon>
#include <QMessageBox>

namespace Ui {
class TicTacToe;
}

class TicTacToe : public QDialog
{
    Q_OBJECT

public:
    QString mName, mColor;
    QMessageBox gamePopUp;

    explicit TicTacToe(QWidget *parent = 0);
    void setUsername(QString name);
    void setColor(QString color);
    void resetIcons();
    void resetScores();
    ~TicTacToe();

signals:
    void endGame(QString name);

private slots:
    void on_endButton_clicked();
    void on_button11_clicked();
    void on_button12_clicked();
    void on_button13_clicked();
    void on_button21_clicked();
    void on_button22_clicked();
    void on_button23_clicked();
    void on_button31_clicked();
    void on_button32_clicked();
    void on_button33_clicked();

private:
    void computerTurn();
    void checkGameState();
    bool isDraw();
    bool isUserWin();
    bool isComputerWin();
    bool checkRows(QString player);
    QIcon ro, rx, bo, bx, go, gx, blank;
    QIcon userIcon, computerIcon;
    int compScore, userScore, drawScore, iconsPlaced;
    Ui::TicTacToe *ui;
};

#endif // TICTACTOE_H
