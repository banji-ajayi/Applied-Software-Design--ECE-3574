///////////////////////////////
//Thomas Elliott
//905570602
//thomas7@vt.edu
//ECE 3574
//Homework 7
///////////////////////////////

#include <pthread.h>
#include <mqueue.h>
#include <ctime>
#include <errno.h>
#include <QString>
#include <QTextStream>
#include <QCoreApplication>
#include <QStringList>
#include <QDebug>
#include <QByteArray>

QTextStream cout(stdout);

int main(int argc, char* argv[]) {
    try {
        srand (time(NULL)); //create seed for rand function
        mqd_t mq70, mq71, mq72, mq73, mq74;

        /***************************Process Command line arguments********************************/
        QCoreApplication app(argc, argv);
        QStringList argList = app.arguments(); //argList holds all arguements from the command line
        /*****************************************************************************************/

        //some error checking...
        if (argc != 3)
            throw "You do not have the correct number of arguments.";
        if (argList[2] != "1" && argList[2] != "2" && argList[2] != "3" && argList[2] != "4")
            throw "Your id should be between 1 and 4";

        QString temperature = argv[1], tempSum, prevTemp, message;
        QByteArray baTemp;
        char* charTemp = new char[8193];
        char* charSend = new char();
        QStringList tempList;
        bool unstable = true;

        //this is first process connected to message queue 71
        if (argList[2] == "1") {
            tempSum = "i," + temperature; //initialize the sum on process 1
            mq71 = mq_open("/queue71", O_RDWR|O_CREAT|O_EXCL, 0664, NULL);
            mq72 = mq_open("/queue72", O_RDWR, NULL, NULL);

            if (mq71 < 0)
                throw "This process is already running or something else went wrong";

            while (unstable) {
                mq_receive(mq71, charTemp, 8193, NULL); //receive message from central server
                message = QString::fromLocal8Bit(charTemp);

                if (message == "i") { //first initiation
                    baTemp = tempSum.toLocal8Bit();
                    charSend = baTemp.data();
                    mq_send(mq72, charSend, tempSum.length()+1, 1); //send the temp to message queue 72
                    cout << "External process id #" << argv[2] << " Sending temperature: " << temperature << " to central server" << endl;
                }

                else if (message == "s") { //central server has stabilized
                    cout << "External process id #" << argv[2] << " Stabilized with temperature: " << prevTemp << endl;
                    mq_send(mq72, charTemp, message.length()+1, 1); //send stabilized message to next process
                    temperature = QString::number(rand() %101); //send random number to central server
                    baTemp = temperature.toLocal8Bit();
                    charSend = baTemp.data();
                    mq70 = mq_open("/queue70", O_RDWR, NULL, NULL);
                    mq_send(mq70, charSend, temperature.length()+1, 1);
                    cout << "External process id #" << argv[2] << " Generated random number: " << temperature << endl;
                    unstable = false; //break out of while loop
                }

                else {
                    tempSum = message; //central temp
                    temperature = QString::number((prevTemp.toDouble()*3 + tempSum.toDouble()*2)/5);
                    tempSum.append("," + temperature); //new temp calculation
                    baTemp = tempSum.toLocal8Bit();
                    charSend = baTemp.data();
                    mq_send(mq72, charSend, tempSum.length()+1, 1); //send the temp to message queue 72
                    cout << "External process id #" << argv[2] << " Sending temperature: " << temperature << " to central server" << endl;
                }
                prevTemp = temperature;
                tempSum.clear();
                temperature.clear();
            }
            mq_unlink("/queue71");
        }

        //this is second process connected to message queue 72
        else if (argList[2] == "2") {
            mq72 = mq_open("/queue72", O_RDWR|O_CREAT|O_EXCL, 0664, NULL);
            mq73 = mq_open("/queue73", O_RDWR, NULL, NULL);

            if (mq72 < 0)
                throw "This process is already running or something else went wrong";

            while(unstable) {
                mq_receive(mq72, charTemp, 8193, NULL); //receive message from ex1 sent to mq72
                tempSum = QString::fromLocal8Bit(charTemp);

                if (tempSum.startsWith("i")) { //first initiation
                    tempSum.append("," + temperature);
                    baTemp = tempSum.toLocal8Bit();
                    charSend = baTemp.data();
                    mq_send(mq73, charSend, tempSum.length()+1, 1); //send the temp to message queue 73
                    cout << "External process id #" << argv[2] << " Sending temperature: " << temperature << " to central server" << endl;
                }

                else if (tempSum == "s") { //central server has stabilized
                    cout << "External process id #" << argv[2] << " Stabilized with temperature: " << prevTemp << endl;
                    mq70 = mq_open("/queue70", O_RDWR, NULL, NULL); //open central server before sending it random number
                    mq_send(mq73, charTemp, tempSum.length()+1, 1); //send stabilized message to next process
                    temperature = QString::number(rand() %101); //send random number to central server
                    baTemp = temperature.toLocal8Bit();
                    charSend = baTemp.data();
                    mq_send(mq70, charSend, temperature.length()+1, 1);
                    cout << "External process id #" << argv[2] << " Generated random number: " << temperature << endl;
                    unstable = false; //break out of while loop
                }

                else {
                    tempList = tempSum.split(",", QString::SkipEmptyParts);
                    temperature = QString::number((prevTemp.toDouble()*3 + tempList[0].toDouble()*2)/5); //new temp calculation
                    tempSum.append("," + temperature);
                    baTemp = tempSum.toLocal8Bit();
                    charSend = baTemp.data();
                    mq_send(mq73, charSend, tempSum.length()+1, 1); //send the temp to mq73
                    cout << "External process id #" << argv[2] << " Sending temperature: " << temperature << " to central server" << endl;
                }
                prevTemp = temperature;
                tempSum.clear();
                temperature.clear();
                tempList.clear();
            }
            mq_unlink("/queue72");
        }

        //this is third process connected to message queue 73
        else if (argList[2] == "3") {
            mq73 = mq_open("/queue73", O_RDWR|O_CREAT|O_EXCL, 0664, NULL);
            mq74 = mq_open("/queue74", O_RDWR, NULL, NULL);

            if (mq73 < 0)
                throw "This process is already running or something else went wrong";

            while(unstable) {
                mq_receive(mq73, charTemp, 8193, NULL); //receive message from ex2 sent to mq73
                tempSum = QString::fromLocal8Bit(charTemp);

                if (tempSum.startsWith("i")) { //first initiation
                    tempSum.append("," + temperature);
                    baTemp = tempSum.toLocal8Bit();
                    charSend = baTemp.data();
                    mq_send(mq74, charSend, tempSum.length()+1, 1); //send the temp to message queue 74
                    cout << "External process id #" << argv[2] << " Sending temperature: " << temperature << " to central server" << endl;
                }

                else if (tempSum == "s") { //central server has stabilized
                    cout << "External process id #" << argv[2] << " Stabilized with temperature: " << prevTemp << endl;
                    mq70 = mq_open("/queue70", O_RDWR, NULL, NULL); //open central server before sending it random number
                    mq_send(mq74, charTemp, tempSum.length()+1, 1); //send stabilized message to next process
                    temperature = QString::number(rand() %101); //send random number to central server
                    baTemp = temperature.toLocal8Bit();
                    charSend = baTemp.data();
                    mq_send(mq70, charSend, temperature.length()+1, 1);
                    cout << "External process id #" << argv[2] << " Generated random number: " << temperature << endl;
                    unstable = false; //break out of while loop
                }

                else {
                    tempList = tempSum.split(",", QString::SkipEmptyParts);
                    temperature = QString::number((prevTemp.toDouble()*3 + tempList[0].toDouble()*2)/5); //new temp calculation
                    tempSum.append("," + temperature);
                    baTemp = tempSum.toLocal8Bit();
                    charSend = baTemp.data();
                    mq_send(mq74, charSend, tempSum.length()+1, 1); //send the temp to mq74
                    cout << "External process id #" << argv[2] << " Sending temperature: " << temperature << " to central server" << endl;
                }
                prevTemp = temperature;
                tempSum.clear();
                temperature.clear();
                tempList.clear();
            }
            mq_unlink("/queue73");
        }

        //this is fourth process connected to message queue 74
        else {
            mq74 = mq_open("/queue74", O_RDWR|O_CREAT|O_EXCL, 0664, NULL);

            if (mq74 < 0)
                throw "This process is already running or something else went wrong";

            while (unstable) {
                mq_receive(mq74, charTemp, 8193, NULL); //receive message from ex3 sent to mq74
                mq70 = mq_open("/queue70", O_RDWR, NULL, NULL); //since this process runs first and mq70 hasn't been created until this point LEAVE HERE
                tempSum = QString::fromLocal8Bit(charTemp);

                if (tempSum.startsWith("i")) { //first initiation
                    tempSum.append("," + temperature);
                    baTemp = tempSum.toLocal8Bit();
                    charSend = baTemp.data();
                    cout << "mq74 is sending " << charSend << " to the central process" << endl;
                    mq_send(mq70, charSend, tempSum.length()+1, 1); //send the temp to the central server mq70
                    cout << "External process id #" << argv[2] << " Sending temperature: " << temperature << " to central server" << endl;
                }

                else if (tempSum == "s") { //central server has stabilized
                    cout << "External process id #" << argv[2] << " Stabilized with temperature: " << prevTemp << endl;
                    temperature = QString::number(rand() %101); //send random number to central server
                    baTemp = temperature.toLocal8Bit();
                    charSend = baTemp.data();
                    mq_send(mq70, charSend, temperature.length()+1, 1);
                    cout << "External process id #" << argv[2] << " Generated random number: " << temperature << endl;
                    unstable = false; //break out of while loop
                }

                else {
                    tempList = tempSum.split(",", QString::SkipEmptyParts);
                    temperature = QString::number((prevTemp.toDouble()*3 + tempList[0].toDouble()*2)/5); //new temp calculation
                    tempSum.append("," + temperature);
                    baTemp = tempSum.toLocal8Bit();
                    charSend = baTemp.data();
                    mq_send(mq70, charSend, tempSum.length()+1, 1); //send the temp to the central process message queue 70
                    cout << "External process id #" << argv[2] << " Sending temperature: " << temperature << " to central server" << endl;
                }
                prevTemp = temperature;
                tempSum.clear();
                temperature.clear();
                tempList.clear();
            }
            mq_unlink("/queue74");
        }
    }

    catch (const char *err){
        qDebug() << err;
        exit(-1);
    }
    return 0;
}


