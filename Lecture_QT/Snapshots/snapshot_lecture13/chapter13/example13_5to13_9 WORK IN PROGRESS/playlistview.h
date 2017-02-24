#ifndef PLAYLISTVIEW
#define PLAYLISTVIEW

#include <QTableView>

class PlayListView : public QTableView {
    Q_OBJECT
public:
    explicit PlayListView(QWidget* parent =0);
    virtual void dropEvent(QDropEvent *event);
    virtual void startDrag(Qt::DropActions supportedActions);
};

#endif // PLAYLISTVIEW

