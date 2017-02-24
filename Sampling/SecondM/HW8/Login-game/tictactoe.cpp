#include "tictactoe.h"
#include "ui_tictactoe.h"

TicTacToe::TicTacToe(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TicTacToe)
{
    ui->setupUi(this);

    // Set up all our icons
    blank.addFile("img/blank.png", QSize(50,50), QIcon::Normal, QIcon::Off);
    ro.addFile("img/ro.png", QSize(50, 50), QIcon::Normal, QIcon::Off);
    ro.addFile("img/ro.png", QSize(50, 50), QIcon::Disabled, QIcon::Off);
    rx.addFile("img/rx.png", QSize(50, 50), QIcon::Normal, QIcon::Off);
    rx.addFile("img/rx.png", QSize(50, 50), QIcon::Disabled, QIcon::Off);
    bo.addFile("img/bo.png", QSize(50, 50), QIcon::Normal, QIcon::Off);
    bo.addFile("img/bo.png", QSize(50, 50), QIcon::Disabled, QIcon::Off);
    bx.addFile("img/bx.png", QSize(50, 50), QIcon::Normal, QIcon::Off);
    bx.addFile("img/bx.png", QSize(50, 50), QIcon::Disabled, QIcon::Off);
    go.addFile("img/go.png", QSize(50, 50), QIcon::Normal, QIcon::Off);
    go.addFile("img/go.png", QSize(50, 50), QIcon::Disabled, QIcon::Off);
    gx.addFile("img/gx.png", QSize(50, 50), QIcon::Normal, QIcon::Off);
    gx.addFile("img/gx.png", QSize(50, 50), QIcon::Disabled, QIcon::Off);

    compScore = 0;
    userScore = 0;
    drawScore = 0;
    iconsPlaced = 0;
}

void TicTacToe::setUsername(QString name) {
    mName = name;
    ui->usernameLabel->setText(mName);
}
void TicTacToe::setColor(QString color) {
    mColor = color;
    if (mColor == "Red") {
        userIcon = rx;
        computerIcon = ro;
    }
    else if (mColor == "Blue") {
        userIcon = bx;
        computerIcon = bo;
    }
    else {
        userIcon = gx;
        computerIcon = go;
    }
}
void TicTacToe::resetIcons() {
    iconsPlaced = 0;
    ui->button11->setIcon(blank);
    ui->button12->setIcon(blank);
    ui->button13->setIcon(blank);
    ui->button21->setIcon(blank);
    ui->button22->setIcon(blank);
    ui->button23->setIcon(blank);
    ui->button31->setIcon(blank);
    ui->button32->setIcon(blank);
    ui->button33->setIcon(blank);
    ui->button11->setEnabled(true);
    ui->button12->setEnabled(true);
    ui->button13->setEnabled(true);
    ui->button21->setEnabled(true);
    ui->button22->setEnabled(true);
    ui->button23->setEnabled(true);
    ui->button31->setEnabled(true);
    ui->button32->setEnabled(true);
    ui->button33->setEnabled(true);
    ui->button11->setWhatsThis("");
    ui->button12->setWhatsThis("");
    ui->button13->setWhatsThis("");
    ui->button21->setWhatsThis("");
    ui->button22->setWhatsThis("");
    ui->button23->setWhatsThis("");
    ui->button31->setWhatsThis("");
    ui->button32->setWhatsThis("");
    ui->button33->setWhatsThis("");

}
void TicTacToe::resetScores() {
    compScore = 0;
    userScore = 0;
    drawScore = 0;

    ui->computerScore->setText(QString::number(compScore));
    ui->usernameScore->setText(QString::number(userScore));
    ui->drawScore->setText(QString::number(drawScore));
}
void TicTacToe::checkGameState() {
    if (isUserWin()) {
        userScore++;
        ui->usernameScore->setText(QString::number(userScore));
        gamePopUp.setText("Congratulations, you win");
        gamePopUp.exec();
        resetIcons();
        return;
    }
    if (isDraw()) {
        drawScore++;
        ui->drawScore->setText(QString::number(drawScore));
        gamePopUp.setText("Game drawn");
        gamePopUp.exec();
        resetIcons();
        return;
    }
    else {
        computerTurn();
        if (isComputerWin()) {
            compScore++;
            ui->computerScore->setText(QString::number(compScore));
            gamePopUp.setText("Sorry, you lost. Better luck next time");
            gamePopUp.exec();
            resetIcons();
            return;
        }
    }
}
void TicTacToe::computerTurn() {
    iconsPlaced++;
    if (ui->button11->whatsThis() == "") {
        ui->button11->setIcon(computerIcon);
        ui->button11->setDisabled(true);
        ui->button11->setWhatsThis("Comp");
    }
    else if (ui->button12->whatsThis() == "") {
        ui->button12->setIcon(computerIcon);
        ui->button12->setDisabled(true);
        ui->button12->setWhatsThis("Comp");
    }
    else if (ui->button13->whatsThis() == "") {
        ui->button13->setIcon(computerIcon);
        ui->button13->setDisabled(true);
        ui->button13->setWhatsThis("Comp");
    }
    else if (ui->button21->whatsThis() == "") {
        ui->button21->setIcon(computerIcon);
        ui->button21->setDisabled(true);
        ui->button21->setWhatsThis("Comp");
    }
    else if (ui->button22->whatsThis() == "") {
        ui->button22->setIcon(computerIcon);
        ui->button22->setDisabled(true);
        ui->button22->setWhatsThis("Comp");
    }
    else if (ui->button23->whatsThis() == "") {
        ui->button23->setIcon(computerIcon);
        ui->button23->setDisabled(true);
        ui->button23->setWhatsThis("Comp");
    }
    else if (ui->button31->whatsThis() == "") {
        ui->button31->setIcon(computerIcon);
        ui->button31->setDisabled(true);
        ui->button31->setWhatsThis("Comp");
    }
    else if (ui->button32->whatsThis() == "") {
        ui->button32->setIcon(computerIcon);
        ui->button32->setDisabled(true);
        ui->button32->setWhatsThis("Comp");
    }
    else if (ui->button33->whatsThis() == "") {
        ui->button33->setIcon(computerIcon);
        ui->button33->setDisabled(true);
        ui->button33->setWhatsThis("Comp");
    }
}
bool TicTacToe::isDraw() {
    if (iconsPlaced == 9 && !checkRows("User") && checkRows("Comp"))
        return true;
    else
        return false;
}
bool TicTacToe::isUserWin() {
    return checkRows("User");
}
bool TicTacToe::isComputerWin() {
    return checkRows("Comp");
}
bool TicTacToe::checkRows(QString player) {
    if (ui->button11->whatsThis() == player && ui->button12->whatsThis() == player && ui->button13->whatsThis() == player)
        return true;
    else if (ui->button21->whatsThis() == player && ui->button22->whatsThis() == player && ui->button23->whatsThis() == player)
        return true;
    else if (ui->button31->whatsThis() == player && ui->button32->whatsThis() == player && ui->button33->whatsThis() == player)
        return true;
    else if (ui->button11->whatsThis() == player && ui->button21->whatsThis() == player && ui->button31->whatsThis() == player)
        return true;
    else if (ui->button12->whatsThis() == player && ui->button22->whatsThis() == player && ui->button32->whatsThis() == player)
        return true;
    else if (ui->button13->whatsThis() == player && ui->button23->whatsThis() == player && ui->button33->whatsThis() == player)
        return true;
    else if (ui->button11->whatsThis() == player && ui->button22->whatsThis() == player && ui->button33->whatsThis() == player)
        return true;
    else if (ui->button31->whatsThis() == player && ui->button22->whatsThis() == player && ui->button13->whatsThis() == player)
        return true;
    else
        return false;
}

TicTacToe::~TicTacToe() {
    delete ui;
}

void TicTacToe::on_endButton_clicked() {
    resetIcons();
    resetScores();
    emit endGame(mName);
}
void TicTacToe::on_button11_clicked() {
    iconsPlaced++;
    ui->button11->setIcon(userIcon);
    ui->button11->setDisabled(true);
    ui->button11->setWhatsThis("User");
    checkGameState();
}
void TicTacToe::on_button12_clicked() {
    iconsPlaced++;
    ui->button12->setIcon(userIcon);
    ui->button12->setDisabled(true);
    ui->button12->setWhatsThis("User");
    checkGameState();
}
void TicTacToe::on_button13_clicked() {
    iconsPlaced++;
    ui->button13->setIcon(userIcon);
    ui->button13->setDisabled(true);
    ui->button13->setWhatsThis("User");
    checkGameState();
}
void TicTacToe::on_button21_clicked() {
    iconsPlaced++;
    ui->button21->setIcon(userIcon);
    ui->button21->setDisabled(true);
    ui->button21->setWhatsThis("User");
    checkGameState();
}
void TicTacToe::on_button22_clicked() {
    iconsPlaced++;
    ui->button22->setIcon(userIcon);
    ui->button22->setDisabled(true);
    ui->button22->setWhatsThis("User");
    checkGameState();
}
void TicTacToe::on_button23_clicked() {
    iconsPlaced++;
    ui->button23->setIcon(userIcon);
    ui->button23->setDisabled(true);
    ui->button23->setWhatsThis("User");
    checkGameState();
}
void TicTacToe::on_button31_clicked() {
    iconsPlaced++;
    ui->button31->setIcon(userIcon);
    ui->button31->setDisabled(true);
    ui->button31->setWhatsThis("User");
    checkGameState();
}
void TicTacToe::on_button32_clicked() {
    iconsPlaced++;
    ui->button32->setIcon(userIcon);
    ui->button32->setDisabled(true);
    ui->button32->setWhatsThis("User");
    checkGameState();
}
void TicTacToe::on_button33_clicked() {
    iconsPlaced++;
    ui->button33->setIcon(userIcon);
    ui->button33->setDisabled(true);
    ui->button33->setWhatsThis("User");
    checkGameState();
}
