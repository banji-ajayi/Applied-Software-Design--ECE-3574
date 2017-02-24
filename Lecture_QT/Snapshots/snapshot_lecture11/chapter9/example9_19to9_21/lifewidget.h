#ifndef LIFEWIDGET
#define LIFEWIDGET

#include <QWidget>
#include <QImage>

class LifeWidget : public QWidget
{
    Q_OBJECT

public:
    explicit LifeWidget(QWidget* parent=0);
    ~LifeWidget();
    QSize sizeHint() const;
    void paintEvent(QPaintEvent* evt); // Custom paint event

public slots:
    void setImage(const QImage& image);

private:
    QImage m_image;
    QSize m_size;
};

#endif // LIFEWIDGET

