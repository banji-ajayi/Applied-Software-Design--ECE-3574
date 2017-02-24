// Matt Luckam
// 905660738
// mcl209@vt.edu
// ECE 3574
// Homework 6
// 4/20/13

#include "chatserver.h"
#include "ui_chatserver.h"

//constructor
ChatServer::ChatServer(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ChatServer)
{
    ui->setupUi(this);

    //displays new client has joined the server
    connect( &thread, SIGNAL( clientJoin( char* ) ), this, SLOT( acceptClientJoin( char* ) ) );
    //disaplys client has left the server
    connect( &thread, SIGNAL( clientLeave(char* ) ), this, SLOT( acceptClientLeave( char* ) ) );
    //displas private message
    connect( &thread, SIGNAL( privateMessage( QString, QString, QString ) ) , this, SLOT( acceptPrivateMessage( QString, QString, QString ) ) );
    //displays public message
    connect( &thread, SIGNAL( publicMessage( QString, QString ) ), this, SLOT( acceptPublicMessage (QString, QString ) ) );

    //starts server thread
    thread.start();
}

//constructor
ChatServer::~ChatServer()
{
    delete ui;
}

//displays new client has joined the server
void ChatServer::acceptClientJoin( char* newUsername )
{
    QString username( newUsername );
    QString output = "client " + username + ": Has joined the chat session.";
    ui->serverWindow->append( output );
}

//disaplys client has left the server
void ChatServer::acceptClientLeave( char* newUsername )
{
    QString username( newUsername );
    QString output = "client " + username + ": Has exited the chat session.";
    ui->serverWindow->append( output );
}

//displays private message in server gui
void ChatServer::acceptPrivateMessage( QString sender, QString receiver, QString message )
{
    QString output = "client " + sender + " sent private chat to " + receiver +": " + message;
    ui->serverWindow->append( output );
}
//displays public message in server gui
void ChatServer::acceptPublicMessage( QString sender, QString message )
{
    QString output =  sender + ": " + message;
    ui->serverWindow->append( output );
}

//closes thread before closing server and closes open clients
void ChatServer::closeEvent( QCloseEvent *)
{
    //send signal to close clients
    thread.closeMailbox();
    thread.terminate();
}

