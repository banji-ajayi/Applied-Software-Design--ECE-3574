#ifndef STARRATING
#define STARRATING

#include <QMetaType>
#include <QPointF>
#include <QVector>
#include <QPolygonF>
#include <QPainter>

class StarRating {
public:
    enum EditMode { Editable, ReadOnly};

    StarRating(int starCount =1, int maxStarCount =5);
    void paint (QPainter* painter, const QRect& rect, const QPalette& palette, EditMode mode) const;
    QSize sizeHint() const;

    int starCount() const {return m_stars;}
    int maxStarCount() const { return m_maxStars; }
    void setStarCount(int stars) { m_stars = stars; }
    void setMaxStarCount(int max) { m_maxStars = max; }

private:
    QPolygonF m_starPolygon;
    QPolygonF m_diamondPolygon;
    int m_stars;
    int m_maxStars;
};

inline bool operator<(const StarRating& l, const StarRating& r) {
    return l.starCount() < r.starCount();
}

Q_DECLARE_METATYPE(StarRating);

#endif // STARRATING

