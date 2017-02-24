///////////////////////////////
//Thomas Elliott
//905570602
//thomas7@vt.edu
//ECE 3574
//Homework 3
///////////////////////////////

#include <QTextStream>
#include <QCoreApplication>
#include <QString>
#include <QStringList>
#include <QFile>
#include <QFileInfo>
#include <QDir>
#include <QDirIterator>
#include <QDebug>

int recurseCount;
int recurseDir(QFileInfo, int, bool);
int recurseOnceDir(QFileInfo, int, int& recurseCount);
QTextStream cout(stdout);
QString getCorrectSize(int, int);

int main(int argc, char* argv[]) {
    try {
        bool v=true, w=false, c=false, d=false, b=true, k=false, m=false;
        int optArgCount = 0;
        int byteSelector = 1;

        /***************************Process Command line arguments********************************/
        QCoreApplication app(argc, argv);
        QStringList argList = app.arguments(); //argList holds all arguements from the command line
        /*****************************************************************************************/

        /*********************Figure out which optional arguments were entered********************/
        if (argList[1][0] == '-') {
            ++optArgCount;
            if (argList[1][1] == 'v') {
                v = true;
            }
            else if (argList[1][1] == 'w') {
                w = true;
                v=false;
            }
            else if (argList[1][1] == 'c') {
                c = true;
                v=false;
            }
            else if (argList[1][1] == 'd') {
                d = true;
                v=false;
            }
            else if (argList[1][1] == 'b') {
                b = true;
            }
            else if (argList[1][1] == 'k') {
                k = true;
                b=false;
            }
            else if (argList[1][1] == 'm') {
                m = true;
                b=false;
            }
            else
                throw "The argument " + argList[1] + " was not recognized";
        }

        if (argc > 3 && argList[2][0] == '-') {
            ++optArgCount;
            if (argList[2][1] == 'b') {
                b = true;
            }
            else if (argList[2][1] == 'k') {
                k = true;
                b = false;
            }
            else if (argList[2][1] == 'm') {
                m = true;
                b = false;
            }
            else
                throw "The argument " + argList[2] + " was not recognized";
        }

        //the number of files/directories given on the command line = argc - optArgCount
        //the files/directories begin in argList[optArgCount+1]

        /*****************************************************************************************/
        QFileInfo file;

        if (k)
            byteSelector = 1024;
        if (m)
            byteSelector = 1024*1024;

        for (int i = optArgCount+1; i < argc; ++i) {
            //distinguish between directory and file given on the command line
            file =argList[i];

            if (file.isDir() && v)
                recurseDir(file, byteSelector, w);
            else if (w && file.isDir())
                recurseDir(file, byteSelector, w);
            else if (c && file.isDir()) {
                recurseCount =0;
                recurseOnceDir(file,byteSelector, recurseCount);
            }
            else if (d && file.isDir()) {
                recurseCount =1;
                recurseOnceDir(file,byteSelector, recurseCount);
            }
            else if ((w|c|d) && file.isFile())
                cout << file.absoluteFilePath() << "\t" << getCorrectSize(file.size(), byteSelector) << endl;
            cout << endl;
        }

    }
    catch (const char *err){
        qDebug() << err;
    }
    return 0;
}

int recurseDir(QFileInfo file, int byteSelector, bool wCase) {
    QDir dir(file.absoluteFilePath());
    int fileSize = 0;
    QFileInfoList entries = dir.entryInfoList(QDir::Files | QDir::Dirs | QDir::NoDot | QDir::NoDotDot, QDir::Name | QDir::DirsFirst);

    foreach (const QFileInfo &entry, entries) {
        if (entry.isDir()) {
            fileSize += recurseDir(entry, byteSelector, wCase);
        }
        else {
            if (wCase)
                cout << entry.absoluteFilePath() << "\t" << getCorrectSize(entry.size(), byteSelector) << endl;
            fileSize += entry.size();
        }
    }
    if (file.isDir()) {
        fileSize += file.size();
        cout << file.absoluteFilePath() << "\t";
        cout << getCorrectSize(fileSize, byteSelector) << endl;
    }
    return fileSize;
}

int recurseOnceDir(QFileInfo file, int byteSelector, int& recurseCount) {
    QDir dir(file.absoluteFilePath());
    int fileSize = 0;
    QFileInfoList entries = dir.entryInfoList(QDir::Files | QDir::Dirs | QDir::NoDot | QDir::NoDotDot, QDir::Name | QDir::DirsFirst);

    foreach (const QFileInfo &entry, entries) {
        if (entry.isDir()) {
            ++recurseCount;
            fileSize += recurseOnceDir(entry, byteSelector, recurseCount);
        }
        else {
            if (recurseCount <1)
                cout << entry.absoluteFilePath() << "\t" << getCorrectSize(entry.size(), byteSelector) << endl;
            fileSize += entry.size();
        }
    }
    if (file.isDir() && recurseCount < 2) {
        fileSize += file.size();
        cout << file.absoluteFilePath() << "\t";
        cout << getCorrectSize(fileSize, byteSelector) << endl;
    }
    if (file.isDir() && recurseCount >=2)
        fileSize += file.size();
        --recurseCount;
    return fileSize;
}

QString getCorrectSize (int fileSize, int byteSelector) {
    int newFileSize = 0;
    int r = fileSize % byteSelector;
    if (r!=0)
        newFileSize = fileSize/byteSelector +1;
    else
        newFileSize = fileSize/byteSelector;

    QString stringSize;
    stringSize.append(QString("%1").arg(newFileSize));
    if (byteSelector == 1024)
        return  stringSize + 'k';
    else if (byteSelector == 1024*1024)
        return stringSize + 'M';
    else
        return stringSize;
}
