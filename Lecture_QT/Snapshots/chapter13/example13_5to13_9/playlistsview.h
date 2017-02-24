#ifndef PLAYLISTSVIEW
#define PLAYLISTSVIEW

#include <QListView>

class PlaylistsView : public QListView {
public:
    PlaylistsView(QWidget* parent =0)
        : QListView(parent)
    { }
    void dragEnterEvent(QDragEnterEvent* event);
    void dropEvent(QDropEvent* event);
    void dragMoveEvent(QDragMoveEvent* event);
};

#endif // PLAYLISTSVIEW

