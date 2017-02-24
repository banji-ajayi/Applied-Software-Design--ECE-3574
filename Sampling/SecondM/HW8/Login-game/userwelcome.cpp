#include "userwelcome.h"
#include "ui_userwelcome.h"

UserWelcome::UserWelcome(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UserWelcome)
{
    ui->setupUi(this);
}

void UserWelcome::setUsername(QString name) {
    username = name;
    ui->message->setText("Welcome, " + username);
}

UserWelcome::~UserWelcome()
{
    delete ui;
}

void UserWelcome::on_changepassButton_clicked() {
    emit changePassword();
}

void UserWelcome::on_startButton_clicked() {
    emit startGame();
}

void UserWelcome::on_exitButton_clicked() {
    emit quitApplication();
}
