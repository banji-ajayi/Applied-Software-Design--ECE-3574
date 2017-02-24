#include "mainlogin.h"
#include "ui_mainlogin.h"

QList<record> records;
QTextStream cout(stdout);

QDataStream& operator>>(QDataStream& s, record& r) {
    s >> r.name;
    s >> r.color;
    s >> r.digest;
    return s;
}

mainLogin::mainLogin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mainLogin)
{
    ui->setupUi(this);
    ui->passwordEdit->setEchoMode(QLineEdit::Password); //block password visibility in GUI
    readFile();
}

mainLogin::~mainLogin()
{
    delete ui;
}

void mainLogin::readFile() {
    QFile recordsFile("passwords.dat");
    QDataStream recordsStream(&recordsFile);
    recordsStream.setVersion(QDataStream::Qt_4_6);
    recordsFile.open(QIODevice::ReadOnly);
    recordsStream >> records;
}

void mainLogin::goodLoginSlot(QString name) {
    emit goodLogin(name);
}

void mainLogin::on_login_clicked()
{
    QString name, password;
    bool userCheck = false, passCheck = false, loginCheck = false;
    QByteArray hash;
    QCryptographicHash crypto(QCryptographicHash::Sha1);
    name = ui->nameEdit->text();
    password = ui->passwordEdit->text();
    hash = crypto.hash(password.toUtf8(), QCryptographicHash::Sha1);

    for (int i = 0; i < records.length(); i++) {
        if (records.at(i).name == name)
            userCheck = true;
        else
            userCheck = false;

        if (records.at(i).digest == hash)
            passCheck = true;
        else
            passCheck = false;

        if (userCheck && passCheck) {
            loginCheck = true;
            break;
        }
    }
    if (loginCheck)
        goodLoginSlot(name);
    else
        ui->prompt->setText("The user name or password is incorrect");
        ui->nameEdit->clear();
        ui->passwordEdit->clear();
}

void mainLogin::on_exit_clicked()
{
    emit exitSignal();
}
