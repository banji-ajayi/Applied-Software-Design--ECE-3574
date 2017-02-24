#include "welcomeuser.h"
#include "ui_welcomeuser.h"

WelcomeUser::WelcomeUser(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WelcomeUser)
{
    ui->setupUi(this);
}

WelcomeUser::~WelcomeUser()
{
    delete ui;
}

void WelcomeUser::setName(QString name) {
    mName = name;
    ui->label->setText("Welcome, " + name);
}

void WelcomeUser::on_changePassButton_clicked()
{
    emit changePassSignal(mName);
}

void WelcomeUser::on_startButton_clicked()
{
    emit startGameSignal(mName);
}

void WelcomeUser::on_exitButton_clicked()
{
    emit exitSignal();
}
