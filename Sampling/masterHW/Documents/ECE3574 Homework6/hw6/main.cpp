///////////////////////////////
//Thomas Elliott
//905570602
//thomas7@vt.edu
//ECE 3574
//Homework 6
///////////////////////////////

//////////////////////////Statement on Synchronization///////////////////////////
/*There really wasn't much need for using synchronization in this assignment
  considering that each thread never accesses the same memory location so there
  will never be any race conditions.  Each thread handles a different memory
  location in the resultant C matrix which means there is no need to lock down
  any memory location using something like mutexes.  The only thing really used
  in terms of synchronization is the pthread_join function which blocks the main
  thread until the thread that it is waiting on finishes.*/
/////////////////////////////////////////////////////////////////////////////////

#include <QStringList>
#include <QString>
#include <QList>
#include <QTextStream>
#include <QFile>
#include <QCoreApplication>
#include <QDebug>
#include <QRegExp>
#include <pthread.h>

void *readFile(void *fileNumber);
void *multiplyMatrices(void *pos);
pthread_t tid; // input file1 thread id
pthread_t tid2; // input file 2 thread id

QList<QStringList> A, B, C;
QStringList positions;
QFile inFile1, inFile2, outFile;
bool infile1Flag=false, infile2Flag=false;
QRegExp floatPattern("-?(0|[1-9][0-9]*)(.[0-9]{4})");
QRegExp intPattern("-?(0|[1-9][0-9]*)");
int typeIdA = 0, typeIdB = 0;
bool isInt, isFloat;

int checkValues(QList<QStringList>);
void checkRowLength(QList<QStringList>);
void checkDimensions(QList<QStringList>, QList<QStringList>);

QTextStream cout(stdout);

//overload << operator to write the matrices
QTextStream& operator<<(QTextStream& s, const QList<QStringList>& matrix) {
    for(int i = 0; i < matrix.length(); i++) {
        for(int j =0; j < matrix[0].length(); j++) {
            s << matrix[i][j] << " ";
        }
        s << "\n";
    }
    return s;
}

int main(int argc, char* argv[]) {
    try {
        /***************************Process Command line arguments********************************/
        QCoreApplication app(argc, argv);
        QStringList argList = app.arguments(); //argList holds all arguements from the command line
        /*****************************************************************************************/

        inFile1.setFileName(argList[1]);
        inFile2.setFileName(argList[2]);

        // Create the thread for the first input file
        pthread_create(&tid, NULL, readFile, (void*)"1");
        //Create the thread for the second input file
        pthread_create(&tid2, NULL, readFile, (void*)"2");

        //wait until the readFile threads finish before checking values in A and B
        pthread_join(tid, NULL);
        pthread_join(tid2, NULL);

        //handle file could not be opened case. Must be placed here since errors cannot be thrown
        //from the threads for whatever reason
        if(infile1Flag)
            throw "The first input file could not be opened. Check to make sure that it exists.";
        if(infile2Flag)
            throw "The second input file could not be opened. Check to make sure that it exists.";


        typeIdA = checkValues(A);
        typeIdB = checkValues(B);

        if (typeIdA != typeIdB)
            throw "Types for the two matrices do not match.";

        checkDimensions(A, B);

        //initialize correct size for C
        //create matrix of position numbers
        for (int i =0; i < A.length(); i++) {
            QStringList cTemp;
            for (int j=0; j< B[0].length(); j++) {
                cTemp.append("0");
                positions.append(QString::number(i)+ "," + QString::number(j));
            }
            C.append(cTemp);
        }

        pthread_t threads[A.length() * B[0].length()];

        for(int i=0; i < A.length()*B[0].length(); i++) {
            pthread_create(&threads[i], NULL, multiplyMatrices, (void*)&positions[i]);
        }

        for(int i=0; i < A.length()*B[0].length(); i++) {
            pthread_join(threads[i], NULL);
        }

        //Write the output matrix in C to the output file
        outFile.setFileName(argList[3]);
        QTextStream fileOutStream(&outFile);
        if (isFloat) {
            fileOutStream.setRealNumberPrecision(4);
            fileOutStream.setRealNumberNotation(QTextStream::FixedNotation);
        }

        //If it doesn't exist it will be created. not sure how this error will be thrown
        //but its here as a precaution
        if (!outFile.open(QIODevice::WriteOnly))
            throw "Something went wrong in trying to open the output file.";

        fileOutStream << C << endl;

    }
    catch (const char *err){
        qDebug() << err;
    }
    return 0;
}

void *readFile(void *fileNumber) {
    QString line;
    char* fNumber = (char*)fileNumber;

    //handle the first input file
    if (QString("1") == fNumber) {
        if (!inFile1.open(QIODevice::ReadOnly)){
            infile1Flag = true;
        }

        while (!inFile1.atEnd()) {
            line = inFile1.readLine();
            A.append(line.split(QRegExp("\\s+"), QString::SkipEmptyParts));
        }
    }

    //handle the second input file
    else {
        if (!inFile2.open(QIODevice::ReadOnly)){
            infile2Flag = true;
        }

        while (!inFile2.atEnd()) {
            line = inFile2.readLine();
            B.append(line.split(QRegExp("\\s+"), QString::SkipEmptyParts));
        }
    }

    pthread_exit(0);
}

void *multiplyMatrices(void *pos) {
    QString position = *((QString*)pos);
    QStringList positions = position.split(QRegExp(","));
    int iTemp =0;
    float fTemp =0;
    int pos0 = positions[0].toInt();
    int pos1 = positions[1].toInt();
    for (int i=0; i < A[0].length(); i++) {
        if (isInt)
            iTemp += A[pos0][i].toInt() * B[i][pos1].toInt();
        else
            fTemp += A[pos0][i].toFloat() * B[i][pos1].toFloat();
    }

    if (isInt)
        C[pos0][pos1] = QString::number(iTemp);
    else
        C[pos0][pos1] = QString::number(fTemp,'f',4);

    pthread_exit(0);
}

int checkValues(QList<QStringList> matrix) {
    checkRowLength(matrix); //make sure rows have matching number of columns
    bool typeCheck;
    isInt = intPattern.exactMatch(matrix[0][0]); //check first number for type
    isFloat = floatPattern.exactMatch(matrix[0][0]);

    if (!isInt && !isFloat)  //handle case where value isn't an int or float
        throw "The values used do not match the correct data type.";

    for(int i =0; i < matrix.length(); i++) {
        for(int j =0; j<matrix[0].length(); j++) {
            if (isInt)
                typeCheck = intPattern.exactMatch(matrix[i][j]);
            if (isFloat)
                typeCheck = floatPattern.exactMatch(matrix[i][j]);
            if (!typeCheck)
                throw "The values used do not match the correct data type.";
        }
    }
    if (isInt)
        return 1; //type is int
    else if (isFloat)
        return 2; //type is float
    else
        return -1; //something went wrong
}

void checkRowLength(QList<QStringList> matrix) {
    bool eqColumnCheck = true;
    int columns = matrix[0].length(); //initial number of columns
    for(int i =0; i < matrix.length(); i++) {
        if (columns != matrix[i].length()) //check each row to see if it has the correct number of columns
            eqColumnCheck = false;
    }

    if (!eqColumnCheck)
        throw "File formatted improperly, matrix rows have a different number of columns";
}

void checkDimensions(QList<QStringList> matrix1, QList<QStringList> matrix2) {
    //matrix1 should be the left operand and matrix 2 should be the right operand
    //for matrices [MxN] X [NxM], N must = N
    if (matrix1[0].length() != matrix2.length())
        throw "Matrice dimensions are not correct for multiplication.";
    else
        return;
}
