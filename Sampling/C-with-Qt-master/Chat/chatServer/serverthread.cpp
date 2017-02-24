// Matt Luckam
// 905660738
// mcl209@vt.edu
// ECE 3574
// Homework 6
// 4/20/13

#include "serverthread.h"
#include <errno.h>

//Constuctor
ServerThread::ServerThread(QObject *parent) :
    QThread(parent)
{
}

//sets operation of thread
void ServerThread::run()
{

    //creates server mailbox and buffer
    mqd_t mq_serverBox;
    char buf[sizeof(newMessage)];

    // Set up the attributes for the server mailbox
    struct mq_attr attr;
    attr.mq_maxmsg = 2;
    attr.mq_msgsize = sizeof(newMessage);
    attr.mq_flags = 0;

    // Close the central mailbox to make sure it is unused, before creating it
    mq_unlink( SERVERBOX );
    mq_serverBox = mq_open( SERVERBOX, O_RDONLY | O_CREAT, S_IRWXU, &attr );

    int msgVal;

    while(1)
    {
        //waits for a message to be in server mailbox
        memset(buf, '\0', sizeof(newMessage)*sizeof(char));
        msgVal = mq_receive( mq_serverBox, buf, sizeof(buf), 0 );
        //checks for error with received message
        if ( msgVal != -1 )
        {
            struct newMessage receivedMessage;
            memcpy( &receivedMessage, buf, sizeof(newMessage) );

            int action( receivedMessage.action );

            QString name5 =  QString("/") + QString ( receivedMessage.UserName );
            QByteArray ba2 = name5.toLocal8Bit();
            char* mailboxName2 = ba2.data();

            //selects which action to perform
            switch (action)
            {
            case CLIENT_JOIN:
                emit clientJoin( receivedMessage.UserName );
                mailbox.append(mq_open(mailboxName2, O_WRONLY));
                break;

            case CLIENT_EXIT:
                emit clientLeave( receivedMessage.UserName );
                break;

            case CLIENT_PUBLIC_MESSAGE:
                clientMessage(receivedMessage);
                break;

            case CLIENT_PRIVATE_MESSAGE:
                clientMessage(receivedMessage);
                break;

            default:
                break;
            }
        }
    }

    //closes server mailbox
    mq_unlink(SERVERBOX);
    mq_close(mq_serverBox);
}

//tells server to send private message to client
void ServerThread::clientMessage(struct newMessage receivedMessage)
{
    // sends message to server gui
    QString sender ( receivedMessage.UserName );
    QString receiver ( receivedMessage.destinationName );
    QString message ( receivedMessage.message );

    if( receivedMessage.action == 5 )
    {
        emit privateMessage( sender, receiver, message );
    }

    if( receivedMessage.action == 4 )
    {
        emit publicMessage( sender, message );
    }


    //creates instance of client mailbox write only  and buffer
    char buf[sizeof(newMessage)];


    memcpy(&buf, &receivedMessage, sizeof(newMessage));

    //checks for error
    if(mailbox.at(0) != -1)
    {
        mq_send(mailbox.at(0), buf, sizeof(newMessage), 0);
    }
}

//sends signal that server has closed
void ServerThread::closeMailbox()
{
    newMessage end;

    QByteArray bab = QString( "closeTHISNOW!!" ).toLocal8Bit();
    char* mName = bab.data();

    strcpy(end.message, mName);
    char buf[sizeof(newMessage)];
    memcpy( &buf, &end , sizeof( newMessage ) );

    mq_send(mailbox.at(0), buf, sizeof(newMessage), 0);

    mq_unlink(SERVERBOX);
}
