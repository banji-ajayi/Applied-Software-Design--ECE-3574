#include "mainwindow.h"
#include "ui_mainwindow.h"

QDataStream& operator<<(QDataStream& s, const Record& r) {
    s << r.username;
    s << r.color;
    s << r.digest;
    return s;
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    // Create our main window and all the panels from their respective classes
    ui->setupUi(this);
    gameDialog = new TicTacToe(this);
    loginDialog = new UserLogin(this);
    welcomeDialog = new UserWelcome(this);
    registerDialog = new UserRegister(this);
    passwordDialog = new ChangePassword(this);

    // Connect the signals from all child forms to the mainwindow
    connect(loginDialog, SIGNAL(loginComplete(QString)), this, SLOT(displayWelcome(QString)));
    connect(loginDialog, SIGNAL(quitApplication()), this, SLOT(quitApplication()));
    connect(registerDialog, SIGNAL(registerComplete()), this, SLOT(displayLogin()));
    connect(welcomeDialog, SIGNAL(changePassword()), this, SLOT(displayPassword()));
    connect(welcomeDialog, SIGNAL(startGame()), this, SLOT(displayGame()));
    connect(welcomeDialog, SIGNAL(quitApplication()), this, SLOT(quitApplication()));
    connect(passwordDialog, SIGNAL(changePassComplete(QString)), this, SLOT(displayWelcome(QString)));
    connect(gameDialog, SIGNAL(endGame(QString)), this, SLOT(displayWelcome(QString)));

    // Then start by showing the main login panel
    displayLogin();
}

void MainWindow::clearForms() {
    gameDialog->hide();
    loginDialog->hide();
    welcomeDialog->hide();
    registerDialog->hide();
    passwordDialog->hide();
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::displayLogin() {
    clearForms();
    loginDialog->show();
    gameDialog->resetScores();

    ui->actionRegister_User->setEnabled(true);
    ui->actionLogout_User->setEnabled(false);
    ui->actionExit->setEnabled(true);
    ui->actionNew_Game->setEnabled(false);
    ui->actionEnd_Game->setEnabled(false);
    ui->actionChange_Password->setEnabled(false);
}

void MainWindow::displayRegister() {
    clearForms();
    registerDialog->show();

    ui->actionRegister_User->setEnabled(false);
    ui->actionLogout_User->setEnabled(false);
    ui->actionExit->setEnabled(true);
    ui->actionNew_Game->setEnabled(false);
    ui->actionEnd_Game->setEnabled(false);
    ui->actionChange_Password->setEnabled(false);
}

void MainWindow::displayGame() {
    clearForms();
    gameDialog->show();
    gameDialog->setUsername(username);
    for (int i = 0; i < myRecords.length(); i++) {
        if (myRecords[i].username == username)
            gameDialog->setColor(myRecords[i].color);
    }

    ui->actionRegister_User->setEnabled(false);
    ui->actionLogout_User->setEnabled(true);
    ui->actionExit->setEnabled(true);
    ui->actionNew_Game->setEnabled(false);
    ui->actionEnd_Game->setEnabled(true);
    ui->actionChange_Password->setEnabled(false);
}

void MainWindow::displayWelcome(QString name) {
    username = name;
    clearForms();
    welcomeDialog->show();
    welcomeDialog->setUsername(name);

    ui->actionRegister_User->setEnabled(false);
    ui->actionLogout_User->setEnabled(true);
    ui->actionExit->setEnabled(true);
    ui->actionNew_Game->setEnabled(true);
    ui->actionEnd_Game->setEnabled(false);
    ui->actionChange_Password->setEnabled(true);
}

void MainWindow::displayPassword() {
    clearForms();
    passwordDialog->show();
    passwordDialog->setUsername(username);

    ui->actionRegister_User->setEnabled(false);
    ui->actionLogout_User->setEnabled(true);
    ui->actionExit->setEnabled(true);
    ui->actionNew_Game->setEnabled(false);
    ui->actionEnd_Game->setEnabled(false);
    ui->actionChange_Password->setEnabled(false);
}

void MainWindow::quitApplication() {
    QFile inFile("passwords.dat");
    inFile.open(QIODevice::WriteOnly);
    QDataStream inStream(&inFile);
    inStream.setVersion(QDataStream::Qt_4_6);
    inStream << myRecords;
    inFile.close();

    QApplication::quit();
}


void MainWindow::on_actionRegister_User_triggered() {
    displayRegister();
}

void MainWindow::on_actionLogout_User_triggered() {
    username = "";
    displayLogin();
}

void MainWindow::on_actionExit_triggered() {
    quitApplication();
}

void MainWindow::on_actionNew_Game_triggered() {
    displayGame();
}

void MainWindow::on_actionEnd_Game_triggered() {
    displayWelcome(username);
}

void MainWindow::on_actionChange_Password_triggered() {
    displayPassword();
}
