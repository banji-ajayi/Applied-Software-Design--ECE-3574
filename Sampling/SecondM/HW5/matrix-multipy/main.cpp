//  Jacob Melton
//  905698368
//  jmelton1@vt.edu
//  ECE3574
//  HW5

/*
 * The usage of memory access synchronization didn't really come up as all of the
 * access to things like files is done individually or as read only. Examples of this
 * are when calculating the sum of the multiplication for a given element in C, two
 * threads might be reading from the same locations in A and B, but since read access
 * isn't an issue there isnt a need for locking or semaphores. in terms of syncing
 * though, the usage of pthread_join makes sure that we dont proceed in the main thread
 * until all the needed calculations of elements in C have been completed.
 */

#include <QCoreApplication>
#include <QTextStream>
#include <QStringList>
#include <pthread.h>
#include <QRegExp>
#include <QString>
#include <QDebug>
#include <QList>
#include <QFile>

typedef QList<QStringList> Matrix;

// Some global variables
Matrix A, B, C;
bool isInteger = false;
bool isDecimal = false;
bool inputFailure = false;
struct arg_struct {
    QFile mFile;
    int fileNum;
};

void *processFile(void *myArgs);
void *matrixMultiply(void *pos);
void checkRowLength(Matrix myMatrix);
void checkDimensions(Matrix matrix1, Matrix matrix2);
int checkMatrix(Matrix myMatrix);

// Process files given a struct of arguments
void *processFile (void *myArgs) {
    struct arg_struct *args = (struct arg_struct *)myArgs;
    QRegExp matchWS("\\s+");    // Match one or more occurences  of white space characters
    QString nextLine;

    // Attempt to open the file and return false if we fail to open the file
    // We exit with true because the join of processFile stores its return value
    // in the input failure boolean
    if (!args->mFile.open(QIODevice::ReadOnly)) {
        inputFailure = true;
        pthread_exit(0);
    }

    switch (args->fileNum) {
    case 1:
        while (!args->mFile.atEnd()) {
            nextLine = args->mFile.readLine();
            // Split the lines we get from the file by whitespace and append them to our matrix typedef
            A.append(nextLine.split(matchWS, QString::SkipEmptyParts));
        }
        break;
    case 2:
        while (!args->mFile.atEnd()) {
            nextLine = args->mFile.readLine();
            // Split the lines we get from the file by whitespace and append them to our matrix typedef
            B.append(nextLine.split(matchWS, QString::SkipEmptyParts));
        }
        break;
    }
    args->mFile.close();
    // return false if we succesfully processed the file
    pthread_exit(0);
}

// Execute single element matrix multiplication
void *matrixMultiply (void *pos) {
    QString *position = (QString *)pos;
    QStringList positions = position->split(QRegExp(","));
    int first = positions[0].toInt(), second = positions[1].toInt();
    int intSum = 0;
    double decSum = 0;

    for (int i = 0; i < A[0].length(); i++) {
        if (isInteger)
            intSum += A[first][i].toInt() * B[i][second].toInt();
        else
            decSum += A[first][i].toDouble() * B[i][second].toDouble();
    }

    if (isInteger)
        C[first][second] = QString::number(intSum);
    else
        C[first][second] = QString::number(decSum,'f',4);

    pthread_exit(0);
}

int checkMatrix(Matrix myMatrix) {
    checkRowLength(myMatrix); // Check for consistent column numbers;

    QRegExp decimalRegex("-?(0|[1-9][0-9]*)(.[0-9]{4})");
    QRegExp integerRegex("-?(0|[1-9][0-9]*)");
    bool typeConsistent;

    isInteger = integerRegex.exactMatch(myMatrix[0][0]);     // Figure out the first type we see
    isDecimal = decimalRegex.exactMatch(myMatrix[0][0]);    // That will be used to check consitency

    if (!isInteger && !isDecimal) {
        qDebug() << "Can't find a match for an integer or a decimal";
        exit(-1);
    }

    for(int i = 0; i < myMatrix.length(); i++) {
        for(int j = 0; j < myMatrix[i].length(); j++) {
            if (isInteger)
                typeConsistent = integerRegex.exactMatch(myMatrix[i][j]);
            if (isDecimal)
                typeConsistent = decimalRegex.exactMatch(myMatrix[i][j]);
            if (!typeConsistent) {
                qDebug() << "One of the elements of the array is of a different type than the first element. Please be consistent with the array contents.";
                exit(-1);
            }
        }
    }

    if (isInteger)
        return 0; // Type is integer
    else if (isDecimal)
        return 1; // Type is decimal

    return -1; // This shouldn't happen
}

void checkRowLength(Matrix myMatrix) {
    bool columnsEqual = true;
    int columns = myMatrix[0].length(); // Columns in row 1 set our default
    for(int i = 0; i < myMatrix.length(); i++) {
        if (columns != myMatrix[i].length()) //check each row to see if it has the correct number of columns
            columnsEqual = false;
    }

    if (!columnsEqual) {
        qDebug() << "Rows of the matrix have mismatching column counts. Please be consistent.";
        exit(-1);
    }
}

void checkDimensions(Matrix matrix1, Matrix matrix2) {
    // matrix1 should be the left operand and matrix 2 should be the right operand
    // for matrices [MxN] X [NxM], N must = N
    if (matrix1[0].length() != matrix2.length()) {
        qDebug() << "The matricies do not have dimensions suitible for multiplication.";
        exit(-1);
    }
    else
        return;
}

int main(int argc, char* argv[]) {
    QCoreApplication app(argc, argv);
    QStringList argList = app.arguments(); // argList holds all arguements from the command line
    QStringList positions;
    QFile output;
    struct arg_struct input1Args, input2Args;
    int matrixA_type = 0, matrixB_type = 0; // I arbitrailiy define 0 to be an int matrix and 1 to be a decimal matrix
    pthread_t inputThread1;
    pthread_t inputThread2;

    if (argc == 1) {
        qDebug() << "No parameteres given.";
        exit(-1);
    }

    // Attempt to create and open our output file
    output.setFileName(argList[3]);
    if (!output.open(QIODevice::WriteOnly)) {
        qDebug() << "Unable to open or create the output file. Please check file permissions.";
        exit(-1);
    }
    // Create our input files and set them in our arguments struct
    input1Args.mFile.setFileName(argList[1]);
    input1Args.fileNum = 1;
    input2Args.mFile.setFileName(argList[2]);
    input2Args.fileNum = 2;

    // Start the file processing threads
    pthread_create(&inputThread1, NULL, processFile, (void *)&input1Args);
    pthread_create(&inputThread2, NULL, processFile, (void *)&input2Args);
    // Wait for them both to complete
    pthread_join(inputThread1, NULL);
    pthread_join(inputThread2, NULL);

    // Catch bad input files and exit on them
    if(inputFailure) {
        qDebug() << "One or more of the given input files was unreadable or inaccessable. Please check they exist and their permissions.";
        exit(-1);
    }

    // Validate our matrix dimensions
    checkDimensions(A, B);

    // Determine the types of our matrixes
    matrixA_type = checkMatrix(A);
    matrixB_type = checkMatrix(B);

    if (matrixA_type != matrixB_type) {
        qDebug() << "The types of the two matricies don't match.";
        exit(-1);
    }

    // Populate matrix C with placeholders
    // And build our list of positions
    for (int i = 0; i < A.length(); i++) {
        QStringList rowOfC;
        for (int j = 0; j < B[0].length(); j++) {
            rowOfC.append("0");     // Adding columns
            positions.append(QString::number(i) + "," + QString::number(j));
        }
        C.append(rowOfC);       // Adding rows
    }

    // Make an array of pthreads for each element in our output
    // and spawn all the threads for calculating matrix values
    pthread_t myThreads[A.length() * B[0].length()];
    for (int i = 0; i < (A.length() * B[0].length()); i++) {
        pthread_create(&myThreads[i], NULL, matrixMultiply, (void *)&positions[i]);
    }
    for (int i = 0; i < (A.length() * B[0].length()); i++) {
        pthread_join(myThreads[i], NULL);
    }

    // Write our C matrix data type to the file with a textstream
    QTextStream outputStream(&output);
    if (isDecimal) {
        outputStream.setRealNumberPrecision(4);
        outputStream.setRealNumberNotation(QTextStream::FixedNotation);
    }
    for (int i = 0; i < C.length(); i++) {
        for (int j = 0; j < C[i].length(); j++) {
            outputStream << C[i][j] << " ";
        }
        outputStream << endl;
    }
    outputStream << endl;
    outputStream.flush();
    output.close();

    return 0;
