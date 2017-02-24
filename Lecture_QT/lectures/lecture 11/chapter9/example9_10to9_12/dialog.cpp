
#include <QDebug>

#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    update();
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::setModel(Product* model)
{
    m_model = model;
    update();
}

void Dialog::on_buttonBox_accepted()
{
    commit();
    QDialog::accept();
}
/* This has been created automatically with the Designer, see Section 9.7.1 */

void Dialog::commit() {
    if (m_model == 0)
        return;
    qDebug() << "commit()";
    m_model->m_name = ui->lineEdit->text();
    QTextDocument* doc = ui->textEdit->document();
    m_model->m_description = doc->toPlainText();
    m_model->m_price = ui->doubleSpinBox->value();
    m_model->m_dateValid = ui->dateEdit->date();
    qDebug() << m_model->m_price;
}
/* see example 9.12 */

void Dialog::update() {
    if (m_model == 0)
        return;
    qDebug() << "update()";
    ui->lineEdit->setText(m_model->m_name);
    ui->textEdit->setText(m_model->m_description);
    ui->doubleSpinBox->setValue(m_model->m_price);
    ui->dateEdit->setDate(m_model->m_dateValid);
}
/* see example 9.12 */
