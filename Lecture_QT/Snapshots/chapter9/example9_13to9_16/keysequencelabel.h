#ifndef KEYSEQUENCELABEL_H
#define KEYSEQUENCELABEL_H

#include <QList>
#include <QPair>

#include <QMainWindow>

#include <QKeyEvent>
#include <QPaintEvent>
#include <QTimerEvent>

namespace Ui {
class KeySequenceLabel;
}

class KeySequenceLabel : public QMainWindow
{
    Q_OBJECT

public:
    explicit KeySequenceLabel(QWidget *parent = 0);
    ~KeySequenceLabel();

protected:
    void changeEvent(QEvent* e);
    void keyPressEvent(QKeyEvent* e);
    void leaveEvent(QEvent* e);
    void enterEvent(QEvent* e);
    void paintEvent(QPaintEvent* e);
    void timerEvent(QTimerEvent* e);
    void updateUi();

private slots:
    void on_pushButton_clicked();

private:
    Ui::KeySequenceLabel *ui;
    QList<QPair<int, int> > m_keys;
    int m_paints;
};

#endif // KEYSEQUENCELABEL_H
