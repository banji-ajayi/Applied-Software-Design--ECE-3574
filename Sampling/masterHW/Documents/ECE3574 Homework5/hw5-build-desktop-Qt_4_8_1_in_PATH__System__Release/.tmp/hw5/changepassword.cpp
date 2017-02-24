#include "changepassword.h"
#include "ui_changepassword.h"
#include "classDefinitions.h"

extern QList<record> records;

ChangePassword::ChangePassword(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChangePassword)
{
    ui->setupUi(this);
    ui->oldPasswordEdit->setEchoMode(QLineEdit::Password);
    ui->passwordEdit->setEchoMode(QLineEdit::Password);
    ui->rPasswordEdit->setEchoMode(QLineEdit::Password);
}

ChangePassword::~ChangePassword()
{
    delete ui;
}

void ChangePassword::setName(QString name) {
    mName = name;
    ui->label->setText("Change password for user, " + name);
}

void ChangePassword::on_okButton_clicked()
{
    bool passCheck = false, oldPassCheck = false;
    QMessageBox *popUpBox =new QMessageBox(this);
    QByteArray hash, newPassHash;
    QCryptographicHash crypto(QCryptographicHash::Sha1);
    hash = crypto.hash(ui->oldPasswordEdit->text().toUtf8(), QCryptographicHash::Sha1);

    int i = 0;
    while (records.at(i).name != mName) //move i to correct record
        ++i;

    if (records.at(i).digest != hash) {
        popUpBox->setText("Old password does not match, please re-enter");
        popUpBox->exec();
        oldPassCheck = false;
    }
    else
        oldPassCheck = true;

    if (ui->passwordEdit->text() != ui->rPasswordEdit->text() && oldPassCheck) { //do not check until old password is correct
        popUpBox->setText("Passwords do not match, please re-enter");
        popUpBox->exec();
        passCheck = false;
    }
    else if (ui->passwordEdit->text().length() == 0 && oldPassCheck) {
        popUpBox->setText("Your password must be at least 1 character");
        popUpBox->exec();
        passCheck = false;
    }
    else
        passCheck = true;

    if (oldPassCheck && passCheck) {
        newPassHash = crypto.hash(ui->passwordEdit->text().toUtf8(), QCryptographicHash::Sha1);
        records[i].digest = newPassHash;
        records[i].color = ui->colorComboBox->currentText();
        on_cancelButton_clicked(); //use this slot to return to welcome screen
    }
}

void ChangePassword::on_cancelButton_clicked()
{
    ui->oldPasswordEdit->clear(); //clear out forms when exiting
    ui->passwordEdit->clear();
    ui->rPasswordEdit->clear();
    emit cancelSignal(mName);
}
