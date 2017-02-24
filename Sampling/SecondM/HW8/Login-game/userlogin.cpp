#include "userlogin.h"
#include "ui_userlogin.h"

QList<Record> myRecords;

QDataStream& operator>>(QDataStream& s, Record& r) {
    s >> r.username;
    s >> r.color;
    s >> r.digest;

    return s;
}

UserLogin::UserLogin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UserLogin)
{
    ui->setupUi(this);
    ui->passwordLineEdit->setEchoMode(QLineEdit::Password);

    // Read in the records and populate the myRecords QList so that all the other windows can use it
    QFile inFile("passwords.dat");
    QDataStream inStream(&inFile);
    inStream.setVersion(QDataStream::Qt_4_6);
    inFile.open(QIODevice::ReadOnly);
    inStream >> myRecords;
}

bool UserLogin::checkCredentials() {
    QByteArray pwHash;
    QCryptographicHash sha1(QCryptographicHash::Sha1);

    pwHash = sha1.hash(password.toUtf8(), QCryptographicHash::Sha1);

    for (int i = 0; i < myRecords.length(); i++) {
        Record tempRecord = myRecords.at(i);
        if((tempRecord.username == username) && (tempRecord.digest == pwHash))
            return true;
    }
    return false;
}

UserLogin::~UserLogin()
{
    delete ui;
}

void UserLogin::on_exitButton_clicked() {
    emit quitApplication();
}

void UserLogin::on_loginButton_clicked() {
    username = ui->usernameLineEdit->text();
    password = ui->passwordLineEdit->text();

    if (checkCredentials())
        emit loginComplete(username);
    else {
        QMessageBox invalidLogin(this);
        invalidLogin.setWindowTitle("Invalid Login");
        invalidLogin.setText("The user/password combination does not match an existing user/password combination.");
        invalidLogin.setIcon(QMessageBox::Warning);
        invalidLogin.exec();
        ui->usernameLineEdit->clear();
        ui->passwordLineEdit->clear();
    }
}
