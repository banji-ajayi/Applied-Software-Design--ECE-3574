
#include <QObject>
#include <QMap>
#include <QtGui>
#include <QChar>
#include <QString>
#include <QImage>
#include <QLabel>
#include <QPixmap>
#include <QWidget>

#include <QHBoxLayout>
#include <QVBoxLayout>

#include <QPushButton>

#include "cardpics.h"
#include "cardtable.h"

//#define EXAMPLE9_9
#ifndef EXAMPLE9_9
CardTable::CardTable(QWidget *parent)
    : QWidget(parent) {
    QHBoxLayout *row;
    QVBoxLayout* rows = new QVBoxLayout();
    QVBoxLayout* buttons = new QVBoxLayout();

    row = new QHBoxLayout();
    row->addWidget(new Card(QString("ah"), m_deck, this));
    row->addWidget(new Card(QString("qq"), m_deck, this));
    row->addWidget(new Card(QString("kp"), m_deck, this));
    row->addWidget(new Card(QString("8f"), m_deck, this));
    rows->addLayout(row);

    row = new QHBoxLayout();
    row->addWidget(new Card(QString("qp"), m_deck, this));
    row->addWidget(new Card(QString("jp"), m_deck, this));
    row->addWidget(new Card(QString("td"), m_deck, this));
    rows->addLayout(row);

    buttons->addWidget(new QPushButton("Deal"));
    buttons->addWidget(new QPushButton("Shuffle"));

    QHBoxLayout* cols = new QHBoxLayout();
    setLayout(cols);
    cols->addLayout(rows);
    cols->addLayout(buttons);

    m_deck.setParent(this);
}
#else
CardTable::CardTable(QWidget *parent)
    : QWidget(parent) {
    QHBoxLayout *row;
    QVBoxLayout* rows = new QVBoxLayout();
    QVBoxLayout* buttons = new QVBoxLayout();

    row = new QHBoxLayout();
    row->addWidget(new Card(QString("ah"), m_deck, this));
    row->addWidget(new Card(QString("qq"), m_deck, this));
    row->addWidget(new Card(QString("kp"), m_deck, this));
    row->addWidget(new Card(QString("8f"), m_deck, this));
    rows->addLayout(row);
    //rows->addStretch(1); //try to uncomment

    row = new QHBoxLayout();
    row->addWidget(new Card(QString("qp"), m_deck, this));
    row->addWidget(new Card(QString("jp"), m_deck, this));
    row->addWidget(new Card(QString("td"), m_deck, this));
    rows->addLayout(row);
    rows->addStretch(1); //example 9_9

    buttons->addStretch(1); //example 9_9
    buttons->addWidget(new QPushButton("Deal"));
    buttons->addWidget(new QPushButton("Shuffle"));
    buttons->addSpacing(20); //example 9_9

    QHBoxLayout* cols = new QHBoxLayout();
    setLayout(cols);
    cols->addLayout(rows);
    //cols->addStretch(1); //try to uncomment
    cols->addLayout(buttons);
    cols->addStretch(0); //example 9_9

    m_deck.setParent(this);
}
#endif
