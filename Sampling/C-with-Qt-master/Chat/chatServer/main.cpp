// Matt Luckam
// 905660738
// mcl209@vt.edu
// ECE 3574
// Homework 6
// 4/20/13

#include <QtGui/QApplication>

#include "chatserver.h"
#include "serverthread.h"
#include "../chatClient/message.h"

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ChatServer w;
    w.show();

    return a.exec();

}
