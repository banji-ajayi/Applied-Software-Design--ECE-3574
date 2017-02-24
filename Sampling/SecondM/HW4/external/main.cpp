///////////////////////////////
// Jacob Melton
// 905698368
// jmelton1@vt.edu
// ECE 3574
// Homework 7
///////////////////////////////

#include <pthread.h>
#include <mqueue.h>
#include <errno.h>
#include <QString>
#include <QTextStream>
#include <QStringList>
#include <QDebug>
#include <QByteArray>

void usage(int err) {
    switch(err) {
    case 0:
        qDebug() << "The correct number of arguments was not passed. Follow usage instructions below." << endl;
        break;
    case 1:
        qDebug() << "The id number was not a valid integer. Follow usage instructions below." << endl;
        break;
    case 2:
        qDebug() << "The id was not between 0 and 6. Follow usage instructions below." << endl;
        break;
    case 3:
        qDebug() << "Creating the queue for the given ID failed. Remeber only instance of a process"
                 << " with a given ID can run at any time. Follow usage instructions below." << endl;
        break;
    case 4:
        qDebug() << "The provided temperature was not able to be converted to a double. Please only "
                 << "provide numbers for the temperature. Follow usage instructions below." << endl;
        break;
    }

    qDebug() << "Usage - external <id> <initial-temperature>" << endl
             << "<id> - any integer value from 0 to 6" << endl
             << "<initial-temperature> - any number";
    exit(-1);
}

QString decode(char* message) {
    return QString::fromLocal8Bit(message);
}

int main(int argc, char* argv[]) {
    QString message;
    QString start = "start", stable = "stable";
    char* recvMsg = new char[8192];
    char* sendMsg = new char();
    double currTemp, upTemp, downTemp, childATemp, childBTemp;
    mqd_t mq70, mq71, mq72, mq73, mq74, mq75, mq76;
    int myID;
    bool ok1, ok2, unstable = true, downToggle = true;

    // Grab some arguments
    myID = QString(argv[1]).toInt(&ok1); // get the ID value as an int
    currTemp = QString(argv[2]).toDouble(&ok2);  // Get the starting temperature as a string

    // Do some option checking
    if (argc != 3)
        usage(0);
    if (!ok1)
        usage(1);
    else if (myID != 0 && myID != 1 && myID != 2 && myID != 3 && myID != 4 && myID != 5 && myID != 6)
        usage(2);
    if (!ok2)
        usage(4);

    // Send startup messages if ID 0
    if (myID == 0) {
        mq70 = mq_open("/70", O_RDWR|O_CREAT|O_EXCL, 0664, NULL); // Open our queue so we can read it
        mq71 = mq_open("/71", O_RDWR, NULL, NULL); // Open child queues so we can write to them
        mq72 = mq_open("/72", O_RDWR, NULL, NULL); // same thing here

        sendMsg = start.toLocal8Bit().data();  // create our start message
        mq_send(mq71, sendMsg, 8192, 1); // send start to mq71
        mq_send(mq72, sendMsg, 8192, 1); // send start to mq72

        sendMsg = QString::number(currTemp).toLocal8Bit().data();
        mq_send(mq71, sendMsg, 8192, 1); // send current temp to mq71
        mq_send(mq72, sendMsg, 8192, 1); // send current temp to mq72
    }

    switch(myID) {
    case 0:
        mq70 = mq_open("/70", O_RDWR, 0664, NULL); // Open our queue so we can read it
        mq71 = mq_open("/71", O_RDWR, NULL, NULL); // Open child queues so we can write to them
        mq72 = mq_open("/72", O_RDWR, NULL, NULL); // same thing here
        if(mq70 == -1) { // Throw an error if we were unable to make our queue
            usage(3);
            mq_unlink("/70");
        }
        while(unstable) {
            mq_receive(mq70, recvMsg, 8192, NULL); // recieve messages from children
            message = decode(recvMsg);
            childATemp = message.toDouble();
            mq_receive(mq70, recvMsg, 8192, NULL);  // wait for second childs message
            message = decode(recvMsg);
            childBTemp = message.toDouble();


            upTemp = (currTemp + childATemp + childBTemp)/3.0; // calculate new temp
            downTemp = upTemp;

            if (qAbs(currTemp - upTemp) < 0.01) {
                currTemp = upTemp;
                unstable = false;

                qDebug() << "Process #" << myID << ": final temperature " << currTemp;
                sendMsg = stable.toLocal8Bit().data();
                mq_send(mq71, sendMsg, 8192, 1); // send stable to mq71
                mq_send(mq72, sendMsg, 8192, 1); // send stable to mq72
            }
            else {
                currTemp = upTemp;
                qDebug() << "Process #" << myID << ": current temperature " << currTemp;
                sendMsg = QString::number(currTemp).toLocal8Bit().data();
                mq_send(mq71, sendMsg, 8192, 1); // send new temp to mq71
                mq_send(mq72, sendMsg, 8192, 1); // send new temp to mq72
            }
        }
        break;
    case 1:
        mq71 = mq_open("/71", O_RDWR|O_CREAT|O_EXCL, 0664, NULL); // Open our queue for reading
        mq73 = mq_open("/73", O_RDWR, NULL, NULL); // Open our children so we can write to them
        mq74 = mq_open("/74", O_RDWR, NULL, NULL); // same thing here
        if(mq71 == -1) { // Throw an error if we were unable to make our queue
            usage(3);
            mq_unlink("/71");
        }
        while (unstable) {
            mq_receive(mq71, recvMsg, 8192, NULL); // recieve messages from parent or children
            message = decode(recvMsg);
            mq70 = mq_open("/70", O_WRONLY, NULL, NULL); // Open our parent so we can write to them
            if (message == "start") {   // Is this the start message?
                sendMsg = message.toLocal8Bit().data();  // create our start message
                mq_send(mq73, sendMsg, 8192, 1); // send start to mq73
                mq_send(mq74, sendMsg, 8192, 1); // send start to mq74
            }
            else if (message == "stable") {
                unstable = false;
                sendMsg = message.toLocal8Bit().data();  // create our start message
                mq_send(mq73, sendMsg, 8192, 1); // send stable to mq73
                mq_send(mq74, sendMsg, 8192, 1); // send stable to mq74
                qDebug() << "Process #" << myID << ": final temperature " << currTemp;
            }
            else if (downToggle) {  // getting the down temp and sending to children
                downTemp = (currTemp + message.toDouble())/2.0; // calculate down temp
                currTemp = downTemp;    // make our down temp our current temp
                downToggle = false;     // toggle so we wait for 2 messages from both children next

                sendMsg = QString::number(currTemp).toLocal8Bit().data();
                mq_send(mq73, sendMsg, 8192, 1); // send new temp to mq73
                mq_send(mq74, sendMsg, 8192, 1); // send new temp to mq74
            }
            else {  // getting the up tem and sending to parent
                childATemp = message.toDouble();
                mq_receive(mq71, recvMsg, 8192, NULL);  // wait for second childs message
                message = decode(recvMsg);
                childBTemp = message.toDouble();

                upTemp = (currTemp + childATemp + childBTemp)/3.0; // calculate new temp
                currTemp = upTemp;
                downToggle = true;

                qDebug() << "Process #" << myID << ": current temperature " << currTemp;
                sendMsg = QString::number(currTemp).toLocal8Bit().data();
                mq_send(mq70, sendMsg, 8192, 1); // send new temp to mq70
            }
        }
        break;
    case 2:
        mq72 = mq_open("/72", O_RDWR|O_CREAT|O_EXCL, 0664, NULL); // Open our queue for reading
        mq75 = mq_open("/75", O_RDWR, NULL, NULL); // Open our children so we can write to them
        mq76 = mq_open("/76", O_RDWR, NULL, NULL); // same thing here
        if(mq72 == -1) { // Throw an error if we were unable to make our queue
            usage(3);
            mq_unlink("/72");
        }
        while (unstable) {
            mq_receive(mq72, recvMsg, 8192, NULL); // recieve messages from parent or children
            message = decode(recvMsg);
            mq70 = mq_open("/70", O_WRONLY, NULL, NULL); // Open our parent so we can write to them
            if (message == "start") {   // Is this the start message?
                sendMsg = message.toLocal8Bit().data();  // create our start message
                mq_send(mq75, sendMsg, 8192, 1); // send start to mq71 and mq72
                mq_send(mq76, sendMsg, 8192, 1); // send start to mq71 and mq72
            }
            else if (message == "stable") {
                unstable = false;
                sendMsg = message.toLocal8Bit().data();  // create our start message
                mq_send(mq75, sendMsg, 8192, 1); // send stable to mq75
                mq_send(mq76, sendMsg, 8192, 1); // send stable to mq76
                qDebug() << "Process #" << myID << ": final temperature " << currTemp;
            }
            else if (downToggle) {  // getting the down temp and sending to children
                downTemp = (currTemp + message.toDouble())/2.0; // calculate down temp
                currTemp = downTemp;    // make our down temp our current temp
                downToggle = false;     // toggle so we wait for 2 messages from both children next

                sendMsg = QString::number(currTemp).toLocal8Bit().data();
                mq_send(mq75, sendMsg, 8192, 1); // send new temp to mq75
                mq_send(mq76, sendMsg, 8192, 1); // send new temp to mq76
            }
            else {  // getting the up tem and sending to parent
                childATemp = message.toDouble();
                mq_receive(mq72, recvMsg, 8192, NULL);  // wait for second childs message
                message = decode(recvMsg);
                childBTemp = message.toDouble();

                upTemp = (currTemp + childATemp + childBTemp)/3.0; // calculate new temp
                currTemp = upTemp;
                downToggle = true;

                qDebug() << "Process #" << myID << ": current temperature " << currTemp;
                sendMsg = QString::number(currTemp).toLocal8Bit().data();
                mq_send(mq70, sendMsg, 8192, 1); // send new temp to mq70
            }
        }
        break;
    case 3:
        mq73 = mq_open("/73", O_RDWR|O_CREAT|O_EXCL, 0664, NULL); // Open our queue for reading
        if(mq73 == -1) { // Throw an error if we were unable to make our queue
            usage(3);
            mq_unlink("/73");
        }
        while (unstable) {
            mq_receive(mq73, recvMsg, 8192, NULL); // recieve messages from parent
            message = decode(recvMsg);
            if (message == "start") { // is this the start message?
                mq71 = mq_open("/71", O_RDWR, NULL, NULL); // Open our parent so we can write to them
            }
            else if (message == "stable") {
                unstable = false;
                qDebug() << "Process #" << myID << ": final temperature " << currTemp;
            }
            else {
                downTemp = (currTemp + message.toDouble())/2.0; // calculate down temp
                currTemp = downTemp;    // make our down temp our current temp
                upTemp = downTemp;

                qDebug() << "Process #" << myID << ": current temperature " << currTemp;
                sendMsg = QString::number(currTemp).toLocal8Bit().data();
                mq_send(mq71, sendMsg, 8192, 1); // send new temp to mq71
            }
        }
        break;
    case 4:
        mq74 = mq_open("/74", O_RDWR|O_CREAT|O_EXCL, 0664, NULL); // Open our queue for reading
        if(mq74 == -1) { // Throw an error if we were unable to make our queue
            usage(3);
            mq_unlink("/74");
        }
        while (unstable) {
            mq_receive(mq74, recvMsg, 8192, NULL); // recieve messages from parent
            message = decode(recvMsg);
            if (message == "start") { // is this the start message?
                mq71 = mq_open("/71", O_RDWR, NULL, NULL); // Open our parent so we can write to them
            }
            else if (message == "stable") {
                unstable = false;
                qDebug() << "Process #" << myID << ": final temperature " << currTemp;
            }
            else {
                downTemp = (currTemp + message.toDouble())/2.0; // calculate down temp
                currTemp = downTemp;    // make our down temp our current temp
                upTemp = downTemp;

                qDebug() << "Process #" << myID << ": current temperature " << currTemp;
                sendMsg = QString::number(currTemp).toLocal8Bit().data();
                mq_send(mq71, sendMsg, 8192, 1); // send new temp to mq71
            }
        }
        break;
    case 5:
        mq75 = mq_open("/75", O_RDWR|O_CREAT|O_EXCL, 0664, NULL); // Open our queue for reading
        if(mq75 == -1) { // Throw an error if we were unable to make our queue
            usage(3);
            mq_unlink("/75");
        }
        while (unstable) {
            mq_receive(mq75, recvMsg, 8192, NULL); // recieve messages from parent
            message = decode(recvMsg);
            if (message == "start") { // is this the start message?
                mq72 = mq_open("/72", O_RDWR, NULL, NULL); // Open our parent so we can write to them
            }
            else if (message == "stable") {
                unstable = false;
                qDebug() << "Process #" << myID << ": final temperature " << currTemp;
            }
            else {
                downTemp = (currTemp + message.toDouble())/2.0; // calculate down temp
                currTemp = downTemp;    // make our down temp our current temp
                upTemp = downTemp;

                qDebug() << "Process #" << myID << ": current temperature " << currTemp;
                sendMsg = QString::number(currTemp).toLocal8Bit().data();
                mq_send(mq72, sendMsg, 8192, 1); // send new temp to mq72
            }
        }
        break;
    case 6:
        mq76 = mq_open("/76", O_RDWR|O_CREAT|O_EXCL, 0664, NULL); // Open our queue for reading
        if(mq76 == -1) { // Throw an error if we were unable to make our queue
            usage(3);
            mq_unlink("/76");
        }
        while (unstable) {
            mq_receive(mq76, recvMsg, 8192, NULL); // recieve messages from parent
            message = decode(recvMsg);
            if (message == "start") { // is this the start message?
                mq72 = mq_open("/72", O_RDWR, NULL, NULL); // Open our parent so we can write to them
            }
            else if (message == "stable") {
                unstable = false;
                qDebug() << "Process #" << myID << ": final temperature " << currTemp;
            }
            else {
                downTemp = (currTemp + message.toDouble())/2.0; // calculate down temp
                currTemp = downTemp;    // make our down temp our current temp
                upTemp = downTemp;

                qDebug() << "Process #" << myID << ": current temperature " << currTemp;
                sendMsg = QString::number(currTemp).toLocal8Bit().data();
                mq_send(mq72, sendMsg, 8192, 1); // send new temp to mq72
            }
        }
        break;
    }

    // Unlink everything just casuse
    mq_unlink("/70");
    mq_unlink("/71");
    mq_unlink("/72");
    mq_unlink("/73");
    mq_unlink("/74");
    mq_unlink("/75");
    mq_unlink("/76");

    return 0;
}


