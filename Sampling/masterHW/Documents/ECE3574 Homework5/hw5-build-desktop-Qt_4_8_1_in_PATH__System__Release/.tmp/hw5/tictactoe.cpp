#include "tictactoe.h"
#include "ui_tictactoe.h"

TicTacToe::TicTacToe(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TicTacToe)
{
    ui->setupUi(this);
    ui->Grid1->hide();
    ui->Grid2->hide();
    ui->Grid3->hide();
    ui->Grid4->hide();
    ui->Grid5->hide();
    ui->Grid6->hide();
    ui->Grid7->hide();
    ui->Grid8->hide();
    ui->Grid9->hide();
    mComputerScore = 0;
    mUserScore = 0;
    mDrawCount = 0;
}

TicTacToe::~TicTacToe()
{
    delete ui;
}

void TicTacToe::setName(QString name) {
    mName = name;
    ui->userLabel->setText(mName);
}

void TicTacToe::setColor(QString color) {
    mColor = color;
    QPalette* palette = new QPalette();
    if (color == "Red")
        palette->setColor(QPalette::WindowText,Qt::red);
    else if (color == "Green")
        palette->setColor(QPalette::WindowText,Qt::green);
    else
        palette->setColor(QPalette::WindowText,Qt::blue);

    ui->Grid1->setPalette(*palette);
    ui->Grid2->setPalette(*palette);
    ui->Grid3->setPalette(*palette);
    ui->Grid4->setPalette(*palette);
    ui->Grid5->setPalette(*palette);
    ui->Grid6->setPalette(*palette);
    ui->Grid7->setPalette(*palette);
    ui->Grid8->setPalette(*palette);
    ui->Grid9->setPalette(*palette);
}

void TicTacToe::clearScores() {
    ui->computerScore->clear();
    ui->userScore->clear();
    ui->drawCount->clear();
}

bool TicTacToe::checkTwoInARow(int& block, QString var) {
    if (ui->Grid1->text() == var && ui->Grid2->text() == var && ui->Grid3->text() == "") {
        block = 3;
        return true;
    }
    else if (ui->Grid1->text() == var && ui->Grid4->text() == var && ui->Grid7->text() == "") {
        block = 7;
        return true;
    }
    else if (ui->Grid1->text() == var && ui->Grid5->text() == var && ui->Grid9->text() == "") {
        block = 9;
        return true;
    }
    else if (ui->Grid2->text() == var && ui->Grid5->text() == var && ui->Grid8->text() == "") {
        block = 8;
        return true;
    }
    else if (ui->Grid2->text() == var && ui->Grid3->text() == var && ui->Grid1->text() == "") {
        block = 1;
        return true;
    }
    else if (ui->Grid3->text() == var && ui->Grid5->text() == var  && ui->Grid7->text() == "") {
        block = 7;
        return true;
    }
    else if (ui->Grid3->text() == var && ui->Grid6->text() == var  && ui->Grid9->text() == "") {
        block = 9;
        return true;
    }
    else if (ui->Grid4->text() == var && ui->Grid5->text() == var && ui->Grid6->text() == "") {
        block = 6;
        return true;
    }
    else if (ui->Grid4->text() == var && ui->Grid7->text() == var && ui->Grid1->text() == "") {
        block = 1;
        return true;
    }
    else if (ui->Grid5->text() == var && ui->Grid7->text() == var  && ui->Grid3->text() == "") {
        block = 3;
        return true;
    }
    else if (ui->Grid5->text() == var && ui->Grid6->text() == var && ui->Grid4->text() == "") {
        block = 4;
        return true;
    }
    else if (ui->Grid5->text() == var && ui->Grid8->text() == var && ui->Grid2->text() == "") {
        block = 2;
        return true;
    }
    else if (ui->Grid5->text() == var && ui->Grid9->text() == var && ui->Grid1->text() == "") {
        block = 1;
        return true;
    }
    else if (ui->Grid6->text() == var && ui->Grid9->text() == var && ui->Grid3->text() == "") {
        block = 3;
        return true;
    }
    else if (ui->Grid7->text() == var && ui->Grid8->text() == var  && ui->Grid9->text() == "") {
        block = 9;
        return true;
    }
    else if (ui->Grid8->text() == var && ui->Grid9->text() == var && ui->Grid7->text() == "") {
        block = 7;
        return true;
    }
    else if (ui->Grid1->text() == var && ui->Grid3->text() == var && ui->Grid2->text() == "") {
        block = 2;
        return true;
    }
    else if (ui->Grid1->text() == var && ui->Grid7->text() == var && ui->Grid4->text() == "") {
        block = 4;
        return true;
    }
    else if (ui->Grid1->text() == var && ui->Grid9->text() == var && ui->Grid5->text() == "") {
        block = 5;
        return true;
    }
    else if (ui->Grid2->text() == var && ui->Grid8->text() == var && ui->Grid5->text() == "") {
        block = 5;
        return true;
    }
    else if (ui->Grid3->text() == var && ui->Grid7->text() == var && ui->Grid5->text() == "") {
        block = 5;
        return true;
    }
    else if (ui->Grid3->text() == var && ui->Grid9->text() == var && ui->Grid6->text() == "") {
        block = 6;
        return true;
    }
    else if (ui->Grid4->text() == var && ui->Grid6->text() == var && ui->Grid5->text() == "") {
        block = 5;
        return true;
    }
    else if (ui->Grid7->text() == var && ui->Grid9->text() == var && ui->Grid8->text() == "") {
        block = 8;
        return true;
    }
    else {
        block = 0;
        return false;
    }
}

bool TicTacToe::checkThreeInARow(QString var) {
    if (ui->Grid1->text() == var && ui->Grid2->text() == var && ui->Grid3->text() == var)
        return true;
    else if (ui->Grid4->text() == var && ui->Grid5->text() == var && ui->Grid6->text() == var)
        return true;
    else if (ui->Grid7->text() == var && ui->Grid8->text() == var && ui->Grid9->text() == var)
        return true;
    else if (ui->Grid1->text() == var && ui->Grid4->text() == var && ui->Grid7->text() == var)
        return true;
    else if (ui->Grid2->text() == var && ui->Grid5->text() == var && ui->Grid8->text() == var)
        return true;
    else if (ui->Grid3->text() == var && ui->Grid6->text() == var && ui->Grid9->text() == var)
        return true;
    else if (ui->Grid1->text() == var && ui->Grid4->text() == var && ui->Grid7->text() == var)
        return true;
    else if (ui->Grid1->text() == var && ui->Grid5->text() == var && ui->Grid9->text() == var)
        return true;
    else if (ui->Grid3->text() == var && ui->Grid5->text() == var && ui->Grid7->text() == var)
        return true;
    else
        return false;
}

bool TicTacToe::checkComputerWin() {
    if (checkThreeInARow("O")) {
        QMessageBox *popUpBox =new QMessageBox(this);
        popUpBox->setText("Sorry, you lost. Better luck next time");
        popUpBox->exec();
        return true;
    }
    else
        return false;
}

bool TicTacToe::checkUserWin() {
    if (checkThreeInARow("X")) {
        QMessageBox *popUpBox =new QMessageBox(this);
        popUpBox->setText("Congratulations, you win");
        popUpBox->exec();
        return true;
    }
    else
        return false;
}

void TicTacToe::clearGrid() {
    ui->Grid1->clear();
    ui->Grid2->clear();
    ui->Grid3->clear();
    ui->Grid4->clear();
    ui->Grid5->clear();
    ui->Grid6->clear();
    ui->Grid7->clear();
    ui->Grid8->clear();
    ui->Grid9->clear();
    ui->Grid1->hide();
    ui->Grid2->hide();
    ui->Grid3->hide();
    ui->Grid4->hide();
    ui->Grid5->hide();
    ui->Grid6->hide();
    ui->Grid7->hide();
    ui->Grid8->hide();
    ui->Grid9->hide();
    ui->Grid1Button->show();
    ui->Grid2Button->show();
    ui->Grid3Button->show();
    ui->Grid4Button->show();
    ui->Grid5Button->show();
    ui->Grid6Button->show();
    ui->Grid7Button->show();
    ui->Grid8Button->show();
    ui->Grid9Button->show();
}

void TicTacToe::computerPlay() {
    int block;
    if (checkTwoInARow(block, "O")) {
        blockEndGame(block); //play the place where computer can win first
    }

    else if (checkTwoInARow(block, "X")) {
        blockEndGame(block); //block place where user can win
    }

    else {
        if(ui->Grid1->text() == "X" && ui->Grid5->text().isEmpty()) {
            ui->Grid5Button->hide();
            ui->Grid5->show();
            ui->Grid5->setText("O");
        }
        else if(ui->Grid2->text() == "X" && ui->Grid5->text().isEmpty()) {
            ui->Grid5Button->hide();
            ui->Grid5->show();
            ui->Grid5->setText("O");
        }
        else if(ui->Grid3->text() == "X" && ui->Grid5->text().isEmpty()) {
            ui->Grid5Button->hide();
            ui->Grid5->show();
            ui->Grid5->setText("O");
        }
        else if(ui->Grid4->text() == "X" && ui->Grid5->text().isEmpty()) {
            ui->Grid5Button->hide();
            ui->Grid5->show();
            ui->Grid5->setText("O");
        }
        else if(ui->Grid5->text() == "X" && ui->Grid1->text().isEmpty()) {
            ui->Grid1Button->hide();
            ui->Grid1->show();
            ui->Grid1->setText("O");
        }
        else if(ui->Grid6->text() == "X" && ui->Grid5->text().isEmpty()) {
            ui->Grid5Button->hide();
            ui->Grid5->show();
            ui->Grid5->setText("O");
        }
        else if(ui->Grid7->text() == "X" && ui->Grid5->text().isEmpty()) {
            ui->Grid5Button->hide();
            ui->Grid5->show();
            ui->Grid5->setText("O");
        }
        else if(ui->Grid8->text() == "X" && ui->Grid5->text().isEmpty()) {
            ui->Grid5Button->hide();
            ui->Grid5->show();
            ui->Grid5->setText("O");
        }
        else if(ui->Grid9->text() == "X" && ui->Grid5->text().isEmpty()) {
            ui->Grid5Button->hide();
            ui->Grid5->show();
            ui->Grid5->setText("O");
        }
        else if(ui->Grid8->text() == "X" && ui->Grid7->text().isEmpty()) {
            ui->Grid7Button->hide();
            ui->Grid7->show();
            ui->Grid7->setText("O");
        }
        else if(ui->Grid7->text() == "X" && ui->Grid8->text().isEmpty()) {
            ui->Grid8Button->hide();
            ui->Grid8->show();
            ui->Grid8->setText("O");
        }
        else {
            int empty = findEmptyGrid(); //if credentials above aren't met place random O
            blockEndGame(empty); //places based on grid number passed from finding an empty grid
        }
    }
}

bool TicTacToe::checkDraw() {
    bool draw = false;
    if (checkThreeInARow("X"))
        draw = false;
    if (checkThreeInARow("O"))
        draw = false;
    if (ui->Grid1->text() == "X" | ui->Grid1->text() == "O"){
        if (ui->Grid2->text() == "X" | ui->Grid2->text() == "O") {
            if (ui->Grid3->text() == "X" | ui->Grid3->text() == "O") {
                if (ui->Grid4->text() == "X" | ui->Grid4->text() == "O") {
                    if (ui->Grid5->text() == "X" | ui->Grid5->text() == "O") {
                        if (ui->Grid6->text() == "X" | ui->Grid6->text() == "O") {
                            if (ui->Grid7->text() == "X" | ui->Grid7->text() == "O") {
                                if (ui->Grid8->text() == "X" | ui->Grid8->text() == "O") {
                                    if (ui->Grid9->text() == "X" | ui->Grid9->text() == "O")
                                        draw = true;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if (draw) {
        QMessageBox *popUpBox =new QMessageBox(this);
        popUpBox->setText("game drawn");
        popUpBox->exec();
        return true;
    }
    else
        return false;
}

void TicTacToe::checkGameCondition() {
    if (checkDraw()) {
        ++mDrawCount;
        ui->drawCount->setText(QString("%1").arg(mDrawCount));
        clearGrid();
    }

    else if (checkUserWin()) {
        ++mUserScore;
        ui->userScore->setText(QString("%1").arg(mUserScore));
        clearGrid();
    }

    else {
        computerPlay();
        if(checkComputerWin()) {
            ++mComputerScore;
            ui->computerScore->setText(QString("%1").arg(mComputerScore));
            clearGrid();
        }
    }
}

int TicTacToe::findEmptyGrid() {
    if (ui->Grid1->text() == "")
        return 1;
    else if (ui->Grid2->text() == "")
        return 2;
    else if (ui->Grid3->text() == "")
        return 3;
    else if (ui->Grid4->text() == "")
        return 4;
    else if (ui->Grid5->text() == "")
        return 5;
    else if (ui->Grid6->text() == "")
        return 6;
    else if (ui->Grid7->text() == "")
        return 7;
    else if (ui->Grid8->text() == "")
        return 8;
    else if (ui->Grid9->text() == "")
        return 9;
}

void TicTacToe::blockEndGame(int block) {
    if(block == 1) {
        ui->Grid1Button->hide();
        ui->Grid1->show();
        ui->Grid1->setText("O");
    }
    else if (block == 2) {
        ui->Grid2Button->hide();
        ui->Grid2->show();
        ui->Grid2->setText("O");
    }
    else if (block == 3) {
        ui->Grid3Button->hide();
        ui->Grid3->show();
        ui->Grid3->setText("O");
    }
    else if (block == 4) {
        ui->Grid4Button->hide();
        ui->Grid4->show();
        ui->Grid4->setText("O");
    }
    else if (block == 5) {
        ui->Grid5Button->hide();
        ui->Grid5->show();
        ui->Grid5->setText("O");
    }
    else if (block == 6) {
        ui->Grid6Button->hide();
        ui->Grid6->show();
        ui->Grid6->setText("O");
    }
    else if (block == 7) {
        ui->Grid7Button->hide();
        ui->Grid7->show();
        ui->Grid7->setText("O");
    }
    else if (block == 8) {
        ui->Grid8Button->hide();
        ui->Grid8->show();
        ui->Grid8->setText("O");
    }
    else if (block == 9) {
        ui->Grid9Button->hide();
        ui->Grid9->show();
        ui->Grid9->setText("O");
    }
    else
        return;
}

void TicTacToe::on_endGameButton_clicked()
{
    clearGrid();
    emit returnToWelcomeSignal(mName);
}

void TicTacToe::on_Grid1Button_clicked()
{
    ui->Grid1Button->hide();
    ui->Grid1->show();
    ui->Grid1->setText("X");
    checkGameCondition();
}

void TicTacToe::on_Grid2Button_clicked()
{
    ui->Grid2Button->hide();
    ui->Grid2->show();
    ui->Grid2->setText("X");
    checkGameCondition();
}

void TicTacToe::on_Grid3Button_clicked()
{
    ui->Grid3Button->hide();
    ui->Grid3->show();
    ui->Grid3->setText("X");
    checkGameCondition();
}

void TicTacToe::on_Grid4Button_clicked()
{
    ui->Grid4Button->hide();
    ui->Grid4->show();
    ui->Grid4->setText("X");
    checkGameCondition();
}

void TicTacToe::on_Grid5Button_clicked()
{
    ui->Grid5Button->hide();
    ui->Grid5->show();
    ui->Grid5->setText("X");
    checkGameCondition();
}

void TicTacToe::on_Grid6Button_clicked()
{
    ui->Grid6Button->hide();
    ui->Grid6->show();
    ui->Grid6->setText("X");
    checkGameCondition();
}

void TicTacToe::on_Grid7Button_clicked()
{
    ui->Grid7Button->hide();
    ui->Grid7->show();
    ui->Grid7->setText("X");
    checkGameCondition();
}

void TicTacToe::on_Grid8Button_clicked()
{
    ui->Grid8Button->hide();
    ui->Grid8->show();
    ui->Grid8->setText("X");
    checkGameCondition();
}

void TicTacToe::on_Grid9Button_clicked()
{
    ui->Grid9Button->hide();
    ui->Grid9->show();
    ui->Grid9->setText("X");
    checkGameCondition();
}
