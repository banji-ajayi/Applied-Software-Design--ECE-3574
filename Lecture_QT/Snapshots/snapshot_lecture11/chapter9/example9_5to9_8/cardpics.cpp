
#include <QObject>
#include <QMap>
#include <QtGui>
#include <QChar>
#include <QString>
#include <QImage>

#include "cardpics.h"

const QString CardPics::values="23456789tjqka";
const QString CardPics::suits="fphq";

CardPics::CardPics(QObject* parent)
    : QObject (parent) {
    foreach (QChar suit, suits) {
        foreach (QChar value, values) {
            QString card = QString("%1%2").arg(value).arg(suit);
            QImage image(fileName(card)); //loads the image here
            m_images[card] = image; //save it in the QMap
        }
    }
}

QString CardPics::fileName(QString card) {
    return QString(":/%1.png").arg(card); // Note that files should be prefixed by :/
}

QImage CardPics::get(QString card) const {
    return m_images.value(card.toLower(), QImage());
}

CardPics* CardPics::instance(QObject* parent) {
    static CardPics* inst = 0;
    if (inst == 0)
        inst = new CardPics(parent);
    return inst;
}

CardPics::~CardPics() {

}
