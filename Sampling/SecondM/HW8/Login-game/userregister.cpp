#include "userregister.h"
#include "ui_userregister.h"

UserRegister::UserRegister(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UserRegister)
{
    ui->setupUi(this);
}

UserRegister::~UserRegister()
{
    delete ui;
}

void UserRegister::on_okButton_clicked() {
    bool fieldError = false;
    QMessageBox errorPopUp(this);

    for(int i = 0; i < myRecords.length(); i++) {
        if(ui->usernameLineEdit->text() == myRecords.at(i).username) {
            errorPopUp.setText("User name already exists, please pick another");
            errorPopUp.exec();
            fieldError = true;
            break;
        }
    }
    if (ui->passwordLineEdit->text() != ui->passwordAgainLineEdit->text() && !fieldError) {
        errorPopUp.setText("Passwords do not match, please re-enter");
        errorPopUp.exec();
        fieldError = true;
    }

    if (!fieldError) {
        QCryptographicHash sha1(QCryptographicHash::Sha1);
        QByteArray pwHash;
        pwHash = sha1.hash(ui->passwordLineEdit->text().toUtf8(), QCryptographicHash::Sha1);
        Record newUser;
        newUser.username = ui->usernameLineEdit->text();
        newUser.color = ui->playerColorComboBox->currentText();
        newUser.digest = pwHash;
        myRecords.append(newUser);

        ui->usernameLineEdit->clear();
        ui->passwordLineEdit->clear();
        ui->passwordAgainLineEdit->clear();
        emit registerComplete();
    }
}

void UserRegister::on_cancelButton_clicked() {
    ui->usernameLineEdit->clear();
    ui->passwordLineEdit->clear();
    ui->passwordAgainLineEdit->clear();
    emit registerComplete();
}
