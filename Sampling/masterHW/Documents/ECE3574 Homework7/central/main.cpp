///////////////////////////////
//Thomas Elliott
//905570602
//thomas7@vt.edu
//ECE 3574
//Homework 7
///////////////////////////////

#include <pthread.h>
#include <mqueue.h>
#include <errno.h>
#include <QString>
#include <QTextStream>
#include <QStringList>
#include <QDebug>
#include <QByteArray>

QTextStream cout(stdout);

int main(int argc, char* argv[]) {
    try {

        if (argc != 2)
            throw "The correct number of arguments were not passed";

        QString temp;
        QString extTemps;
        QString truncTemp;
        QStringList tempList;
        double tempSum = 0;
        bool stable = true, unstable = true;

        mqd_t mq70, mq71;

        mq70 = mq_open("/queue70", O_RDWR|O_CREAT|O_EXCL, 0664, NULL);
        mq71 = mq_open("/queue71", O_RDWR, NULL, NULL);        

        if (mq70 < 0)
            throw "This process is already running or something else went wrong";

        char* charTemp = new char[8193];
        char* charSend = new char();
        temp = "i";
        QByteArray baTemp = temp.toLocal8Bit();
        charSend = baTemp.data();
        mq_send(mq71, charSend, temp.length()+1, 1); //send initial message i
        temp = argv[1]; //initialize with starting temp

        while (unstable) {
            stable = true; //reset stable to true at the end of every pass
            mq_receive(mq70, charTemp, 8193, NULL);
            extTemps = QString::fromLocal8Bit(charTemp);
            tempList = extTemps.split(",", QString::SkipEmptyParts);

            for (int i=1; i<5;i++) {
                tempSum += tempList[i].toDouble(); //add up the temperatures of the 4 external processes
            }

            tempSum += temp.toDouble()*2;
            temp = QString::number(tempSum/6); //new central temp
            truncTemp = temp;
            truncTemp.truncate(temp.indexOf(".")+3); //cut off temp at 2nd decimal place to check for stabilization

            for (int i=1; i<5; i++) {
                QString checkTemp;
                checkTemp = tempList[i];
                checkTemp.truncate(tempList[i].indexOf(".")+3); //cut off temp at 2nd decimal place to check for stabilization
                if (truncTemp != checkTemp)
                    stable = false;
            }

            if (stable) {
                cout << "Central server has stabilized with temperature: " << temp << endl;
                temp = "s";
                baTemp = temp.toLocal8Bit();
                charSend = baTemp.data();
                tempSum = 0; //zero out sum for the random total to come
                mq_send(mq71, charSend, temp.length()+1, 1); //send stabilization message s

                for(int i=0; i<4; i++) {
                    mq_receive(mq70, charTemp, 8193, NULL);
                    temp = QString::fromLocal8Bit(charTemp);
                    tempSum += temp.toDouble();
                }
                cout << "Central server has calculated random sum: " << tempSum << ". The Central Server will now exit." << endl;
                unstable = false; //break out of while loop
            }

            else {
                baTemp = temp.toLocal8Bit();
                charSend = baTemp.data();
                cout << "Central Server has not stabilized. It is now sending temperature: " << temp << " to external process 1" << endl;
                mq_send(mq71, charSend, temp.length()+1, 1); //send new temps to processes if stabilization hasn't been reached
            }
            tempList.clear();
            tempSum = 0;
        }
    }

    catch (const char *err){
        qDebug() << err;
        exit(-1);
    }
    mq_unlink("/queue70");
    return 0;
}

