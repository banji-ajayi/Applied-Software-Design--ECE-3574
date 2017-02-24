#include "registeruser.h"
#include "ui_registeruser.h"

RegisterUser::RegisterUser(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RegisterUser)
{
    ui->setupUi(this);
    ui->passwordEdit->setEchoMode(QLineEdit::Password);
    ui->rPasswordEdit->setEchoMode(QLineEdit::Password);
}

RegisterUser::~RegisterUser()
{
    delete ui;
}

void RegisterUser::on_okButton_clicked()
{
    bool errorCheck = true;
    QMessageBox *popUpBox =new QMessageBox(this); 

    for (int i = 0; i < records.length(); i++) {
        if (ui->nameEdit->text() == records.at(i).name && errorCheck) {
            popUpBox->setText("User name already exists, please pick another.");
            popUpBox->exec();
            errorCheck = false;
            break;
        }
    }
    if (ui->passwordEdit->text().length() == 0 && errorCheck) {
        popUpBox->setText("Your password must be at least 1 character");
        popUpBox->exec();
        errorCheck = false;
    }

    else if (ui->passwordEdit->text() != ui->rPasswordEdit->text() && errorCheck) { //only display if username doesn't already exist
        popUpBox->setText("Passwords do not match, please re-enter");
        popUpBox->exec();
        errorCheck = false;
    }

    if(errorCheck) {
        QCryptographicHash crypto(QCryptographicHash::Sha1);
        QByteArray hash;
        hash = crypto.hash(ui->passwordEdit->text().toUtf8(), QCryptographicHash::Sha1);
        record tempRecord;
        tempRecord.name = ui->nameEdit->text();
        tempRecord.color = ui->colorComboBox->currentText();
        tempRecord.digest = hash;
        records.append(tempRecord);
        returnToMainLogin();
    }
}

void RegisterUser::returnToMainLogin() {
    ui->nameEdit->clear(); //clear out forms upon exit
    ui->passwordEdit->clear();
    ui->rPasswordEdit->clear();
    emit okSignal();
}

void RegisterUser::on_cancelButton_clicked()
{
    returnToMainLogin();
}
