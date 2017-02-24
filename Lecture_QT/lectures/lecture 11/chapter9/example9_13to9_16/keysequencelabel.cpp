#include "keysequencelabel.h"
#include "ui_keysequencelabel.h"

KeySequenceLabel::KeySequenceLabel(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::KeySequenceLabel)
{
    ui->setupUi(this);
    startTimer(2000);
    m_paints=0;
}

KeySequenceLabel::~KeySequenceLabel()
{
    delete ui;
}

void KeySequenceLabel::changeEvent(QEvent* e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        //retranslateUi(this);
        break;
    default:
        break;
    }
}

void KeySequenceLabel::keyPressEvent(QKeyEvent* e)
{
    bool doNothing=false;

    if (e->key() == 0)
        doNothing = true;
    if (m_keys.size() > 3)
        doNothing = true;
    if (doNothing) {
        QMainWindow::keyPressEvent(e);
        return;
    }
    QPair<int, int> pair = QPair<int, int>(e->modifiers(), e->key());
    m_keys << pair;
    e->accept();
    updateUi();
}

void KeySequenceLabel::updateUi()
{
    if(!m_keys.isEmpty()) {
        int keys[4] = {0,0,0,0};
        for (int i=0; i<m_keys.size(); ++i) {
            QPair<int, int> pair = m_keys[i];
            keys[i] = pair.first | pair.second;
        }
        QKeySequence seq = QKeySequence(keys[0], keys[1], keys[2], keys[3]);
        ui->label_2->setText(seq.toString());
    }
    else
        ui->label_2->clear();
}

void KeySequenceLabel::leaveEvent(QEvent* e)
{
    statusBar()->showMessage(tr("Mouse has left the building"));
    e->accept();
}

void KeySequenceLabel::enterEvent(QEvent* e)
{
    statusBar()->showMessage(tr("Mouse is in da house"));
    e->accept();
}

void KeySequenceLabel::paintEvent(QPaintEvent* e)
{
    ++m_paints;
    QMainWindow::paintEvent(e);
}

void KeySequenceLabel::timerEvent(QTimerEvent* e)
{
    ui->lcdNumber->display(m_paints);
}

void KeySequenceLabel::on_pushButton_clicked()
{
    m_keys.clear();
    updateUi();
}
