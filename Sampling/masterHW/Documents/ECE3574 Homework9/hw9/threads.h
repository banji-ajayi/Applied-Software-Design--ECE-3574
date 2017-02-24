#include <QString>
#include <QSemaphore>
#include <QMutex>
#include <QThread>
#include <QTextStream>
#include <QDebug>

extern int buffer[];
extern QMutex lock;
extern QSemaphore full, empty;
extern int *enqueue, *dequeue;
extern int head, tail;

class Producer : public QThread
{
    public:
        int insert_item(int item);
        void run();
};

class Consumer : public QThread
{
    public:
        int remove_item (int *item);
        void run();
};
