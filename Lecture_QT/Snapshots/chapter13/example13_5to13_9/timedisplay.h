#ifndef TIMEDISPLAY
#define TIMEDISPLAY

#include <QTimeEdit>

class TimeDisplay : public QTimeEdit {
    Q_OBJECT
public:
    TimeDisplay(QWidget* parent =0);
};

#endif // TIMEDISPLAY

