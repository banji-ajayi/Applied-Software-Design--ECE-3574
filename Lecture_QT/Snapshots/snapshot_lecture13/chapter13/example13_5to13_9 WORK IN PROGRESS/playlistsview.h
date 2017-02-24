#ifndef PLAYLISTVIEW
#define PLAYLISTVIEW

#include <QListView>

class PlaylistsView : public QListView {
public:
    PlaylistsView(QWidget* parent =0)
        : QListView(parent)
    { }
    void dragEnterEvent(QDragEnterEvent* event);
    void dropEvent(QDropEvent* event);
    void dragMoveEvent(QDragEvent* event);
};

#endif // PLAYLISTVIEW

