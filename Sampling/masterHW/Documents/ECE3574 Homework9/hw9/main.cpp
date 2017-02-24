#include "threads.h"

/* the buffer */
#define MAX_BUFFER_SIZE 5
int buffer [MAX_BUFFER_SIZE];
QMutex lock;
QSemaphore full, empty(MAX_BUFFER_SIZE);
int *enqueue = buffer;
int *dequeue = buffer;
int head =0, tail =0;

int main() {
    srand(time(NULL)); //create seed for rand function
    Producer p1, p2, p3, p4, p5;
    Consumer c1, c2;
    p1.start();
    p2.start();
    p3.start();
    p4.start();
    p5.start();
    c1.start();
    c2.start();

    sleep(300); //sleep for 5 minutes
    p1.quit();
    p2.quit();
    p3.quit();
    p4.quit();
    p5.quit();
    c1.quit();
    c2.quit();
    exit(1);

    lock.lock(); //obtain the lock then unlock it before the mutex is destroyed
    lock.unlock();
    return 0;
}
