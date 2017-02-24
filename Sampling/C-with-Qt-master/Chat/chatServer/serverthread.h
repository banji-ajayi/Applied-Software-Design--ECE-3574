// Matt Luckam
// 905660738
// mcl209@vt.edu
// ECE 3574
// Homework 6
// 4/20/13

#ifndef SERVERTHREAD_H
#define SERVERTHREAD_H

#include <QThread>
#include <QtCore>
#include <QWidget>
#include <QtGui>
#include <iostream>
#include <string.h>
#include <mqueue.h>
#include <stdlib.h>
#include <stdio.h>
#include <string>

#include "../chatClient/message.h"

using namespace std;

class ServerThread : public QThread
{
    Q_OBJECT
public:
    //Constructor
    explicit ServerThread(QObject *parent = 0);
    //sends signal that server has closed
    void closeMailbox();
    
signals:
    //displays client has joined in server gui
    void clientJoin( char* newUsername );
    //displays client has left in server gui
    void clientLeave( char* newUsername );
    //displays private message in server gui
    void privateMessage( QString sender, QString receiver, QString message );
    //displays private public in server gui
    void publicMessage( QString sender, QString message );
    
public slots:

private:
    //sets operation of thread
    void run();
    //instance of client mailbox
    mqd_t mq_clientBox;
    //list of all mailboxes
    QList<mqd_t> mailbox;
    //tells server to send private message to client
    void clientMessage(struct newMessage receivedMessage);

    
};

#endif // SERVERTHREAD_H
