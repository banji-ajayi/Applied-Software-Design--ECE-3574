#include "threads.h"
#include <ctime> //for srand

int Producer::insert_item(int item) {
    empty.acquire(); //producer takes 1 from the empty semaphore
    lock.lock();
    int* pEn = enqueue + head;
    *pEn = item;
    qDebug() << "Producer has written " << item << " into the buffer" << endl;
    lock.unlock();
    full.release();
    head = (head +1) %5;
    return 0;
}

void Producer::run() {
    int number;
    while(1) {
        number = rand() %101;
        sleep(5);
        insert_item(number);
    }
}

int Consumer::remove_item (int *item) {
    full.acquire(); //consumer takes 1 from the full semaphore
    lock.lock();
    int* pDe = dequeue+tail;
    *item = *pDe;
    qDebug() << "Consumer thread has read " << *item << " from the buffer" << endl;
    lock.unlock();
    empty.release();
    tail = (tail +1) %5;
    return 0;
}

void Consumer::run() {
    int number;
    while(1) {
        sleep(5);
        remove_item(&number);
    }
}
