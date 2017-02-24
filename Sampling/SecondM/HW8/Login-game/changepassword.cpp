#include "changepassword.h"
#include "ui_changepassword.h"

ChangePassword::ChangePassword(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChangePassword)
{
    ui->setupUi(this);
}

void ChangePassword::setUsername(QString name) {
    username = name;
}

ChangePassword::~ChangePassword() {
    delete ui;
}

void ChangePassword::on_okButton_clicked() {
    int targetIndex = 0;
    QMessageBox errorPopUp(this);
    QByteArray oldHash, newHash;
    QCryptographicHash sha1(QCryptographicHash::Sha1);

    oldHash = sha1.hash(ui->passwordOldLineEdit->text().toUtf8(), QCryptographicHash::Sha1);

    for (int i = 0; i < myRecords.length(); i++) {
        if (myRecords.at(i).username == username) {
            targetIndex = i;
            break;
        }
    }

    if (myRecords.at(targetIndex).digest != oldHash) {
        errorPopUp.setWindowTitle("Invalid Old Password");
        errorPopUp.setText("Old password does not match, please re-enter");
        errorPopUp.setIcon(QMessageBox::Warning);
        errorPopUp.exec();
    }
    else if (ui->passwordLineEdit->text() != ui->passwordAgainLineEdit->text()) {
        errorPopUp.setWindowTitle("Password Do Not Match");
        errorPopUp.setText("The passwords do not match, please re-enter");
        errorPopUp.setIcon(QMessageBox::Warning);
        errorPopUp.exec();
    }
    else {
        newHash = sha1.hash(ui->passwordLineEdit->text().toUtf8(), QCryptographicHash::Sha1);
        myRecords[targetIndex].digest = newHash;
        myRecords[targetIndex].color = ui->playerColorComboBox->currentText();
        emit changePassComplete(username);
    }
}

void ChangePassword::on_cancelButton_clicked() {
    ui->passwordOldLineEdit->clear();
    ui->passwordLineEdit->clear();
    ui->passwordAgainLineEdit->clear();
    emit changePassComplete(username);
}
