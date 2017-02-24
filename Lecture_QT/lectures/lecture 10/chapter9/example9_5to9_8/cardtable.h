#ifndef CARDTABLE
#define CARDTABLE

class CardTable : public QWidget {
public:
    explicit CardTable(QWidget* parent=0);
private:
    CardPics m_deck;
};

class Card : public QLabel {
public:
    explicit Card(QString card, CardPics& ct, QWidget* parent=0)
        : QLabel(parent) {
        QImage img = ct.get(card);
        setPixmap(QPixmap::fromImage(img));
        show();
    }
};

#endif // CARDTABLE

