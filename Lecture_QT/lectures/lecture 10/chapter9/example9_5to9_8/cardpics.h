#ifndef CARDPICS
#define CARDPICS

class CardPics : public QObject {
public:
    explicit CardPics(QObject* parent =0);
    ~CardPics();

    static CardPics* instance(QObject* parent);

    QString fileName(QString card);
    QImage get(QString card) const;

private:
    QMap<QString,QImage> m_images;

    static const QString values;
    static const QString suits;
};

#endif // CARDPICS

