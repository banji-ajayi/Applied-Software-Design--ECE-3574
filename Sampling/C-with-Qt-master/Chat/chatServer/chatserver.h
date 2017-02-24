// Matt Luckam
// 905660738
// mcl209@vt.edu
// ECE 3574
// Homework 6
// 4/20/13

#ifndef CHATSERVER_H
#define CHATSERVER_H

#include <QMainWindow>

#include "../chatClient/message.h"
#include "serverthread.h"


namespace Ui {
class ChatServer;
}

class ChatServer : public QMainWindow
{
    Q_OBJECT
    
public:
    //Constructor
    explicit ChatServer(QWidget *parent = 0);
    //Destructor
    ~ChatServer();

public slots:
    //displays new client has joined the server
    void acceptClientJoin( char* newUsername );
    //disaplys client has left the server
    void acceptClientLeave( char* newUsername );
    //displays private message in server gui
    void acceptPrivateMessage( QString sender, QString receiver, QString message );
    //displays public message in server gui
    void acceptPublicMessage( QString sender, QString message );
    
private:
    Ui::ChatServer *ui;
    //instance of thread
    ServerThread thread;
    //overloads close event
    void closeEvent( QCloseEvent * );
};

#endif // CHATSERVER_H
