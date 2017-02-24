#include "mainwindow.h"
#include "ui_mainwindow.h"


extern QTextStream cout;
QWidget* mainWidget;
ChangePassword *changePasswordWidget;
mainLogin *mainLoginWidget;
RegisterUser *registerUserWidget;
TicTacToe *ticTacToeWidget;
WelcomeUser *welcomeUserWidget;

QDataStream& operator<<(QDataStream& s, const record& r) {
    s << r.name;
    s << r.color;
    s << r.digest;
    return s;
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    mainWidget = new QWidget(this);
    changePasswordWidget = new ChangePassword(mainWidget);
    mainLoginWidget = new mainLogin(mainWidget);
    registerUserWidget = new RegisterUser(mainWidget);
    ticTacToeWidget = new TicTacToe(mainWidget);
    welcomeUserWidget = new WelcomeUser(mainWidget);
    ui->setupUi(this);
    this->setCentralWidget(mainWidget);
    displayMainLogin(); //default ui
    connect(mainLoginWidget, SIGNAL(goodLogin(QString)), this, SLOT(displayWelcome(QString)));
    connect(mainLoginWidget, SIGNAL(exitSignal()), this, SLOT(on_actionExit_triggered()));
    connect(registerUserWidget, SIGNAL(okSignal()), this, SLOT(displayMainLogin()));
    connect(welcomeUserWidget, SIGNAL(exitSignal()), this, SLOT(on_actionExit_triggered()));
    connect(welcomeUserWidget, SIGNAL(changePassSignal(QString)), this, SLOT(displayChangePassword(QString)));
    connect(welcomeUserWidget, SIGNAL(startGameSignal(QString)), this, SLOT(displayTicTacToe(QString)));
    connect(changePasswordWidget, SIGNAL(cancelSignal(QString)), this, SLOT(displayWelcome(QString)));
    connect(ticTacToeWidget, SIGNAL(returnToWelcomeSignal(QString)), this, SLOT(displayWelcome(QString)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::hideAllWidgets() {
    changePasswordWidget->hide();
    mainLoginWidget->hide();
    registerUserWidget->hide();
    ticTacToeWidget->hide();
    welcomeUserWidget->hide();
}

void MainWindow::displayWelcome(QString name) {
    hideAllWidgets();
    welcomeUserWidget->show();
    welcomeUserWidget->setName(name);
    mName = name; //give MainWindow current user
    ui->actionRegister_User->setEnabled(false);
    ui->actionLogout->setEnabled(true);
    ui->actionExit->setEnabled(true);
    ui->actionNew_game->setEnabled(true);
    ui->actionEnd_game->setEnabled(false);
    ui->actionChange_Password->setEnabled(true);
}

void MainWindow::displayMainLogin() {
    hideAllWidgets();
    mainLoginWidget->show();
    ticTacToeWidget->clearScores(); //clear out scores when a new user is going to login
    ui->actionRegister_User->setEnabled(true);
    ui->actionLogout->setEnabled(false);
    ui->actionExit->setEnabled(true);
    ui->actionNew_game->setEnabled(false);
    ui->actionEnd_game->setEnabled(false);
    ui->actionChange_Password->setEnabled(false);
}

void MainWindow::displayRegister() {
    hideAllWidgets();
    registerUserWidget->show();
    ui->actionRegister_User->setEnabled(false);
    ui->actionLogout->setEnabled(false);
    ui->actionExit->setEnabled(true);
    ui->actionNew_game->setEnabled(false);
    ui->actionEnd_game->setEnabled(false);
    ui->actionChange_Password->setEnabled(false);
}

void MainWindow::displayChangePassword(QString name) {
    hideAllWidgets();
    changePasswordWidget->show();
    changePasswordWidget->setName(name);
    ui->actionRegister_User->setEnabled(false);
    ui->actionLogout->setEnabled(true);
    ui->actionExit->setEnabled(true);
    ui->actionNew_game->setEnabled(false);
    ui->actionEnd_game->setEnabled(false);
    ui->actionChange_Password->setEnabled(false);
}

void MainWindow::displayTicTacToe(QString name) {
    hideAllWidgets();
    ticTacToeWidget->show();
    ticTacToeWidget->setName(name);
    for (int i = 0; i < records.length(); i++) {
        if (records[i].name == name)
            ticTacToeWidget->setColor(records[i].color);
    }
    ui->actionRegister_User->setEnabled(false);
    ui->actionLogout->setEnabled(true);
    ui->actionExit->setEnabled(true);
    ui->actionNew_game->setEnabled(false);
    ui->actionEnd_game->setEnabled(true);
    ui->actionChange_Password->setEnabled(false);
}

void MainWindow::on_actionRegister_User_triggered()
{
    displayRegister();
}

void MainWindow::on_actionLogout_triggered()
{
    displayMainLogin();
}

void MainWindow::on_actionExit_triggered()
{
    QFile recordsFile("passwords.dat");
    recordsFile.open(QIODevice::WriteOnly);
    QDataStream recordsStream(&recordsFile);
    recordsStream.setVersion(QDataStream::Qt_4_6);
    recordsStream << records;
    recordsFile.close();
    exit(1);
}

void MainWindow::on_actionNew_game_triggered()
{
    displayTicTacToe(mName);
}

void MainWindow::on_actionEnd_game_triggered()
{
    ticTacToeWidget->clearGrid();
    displayWelcome(mName);
}

void MainWindow::on_actionChange_Password_triggered()
{
    displayChangePassword(mName);
}
