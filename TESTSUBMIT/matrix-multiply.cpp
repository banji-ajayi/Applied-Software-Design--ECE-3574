////////////////////////////////////////////////////////
// ECE 3574, Homework 6, Bowei Zhao
//// PID: 905789193
// email: bowei@vt.edu
// File name: matrix-multiply.cpp
// Description: main implementation file
// Date: 4/020/2016
//

/*
	Comment:
	I used pthreads create mechanisms to create my threads and waited for their completion with Join.
	Due to this nature of waiting. I did not use mutexes or semaphores as they would not have
	overly benefited the project but rather complicated it.  The synhronization provided by 
	the pthread_create and pthread_join were enough to complete the project as is and allowed for good
	coding techniques

*/
// *-----------------------------------------------* //
#include "matrix.h"

QTextStream outS(stdout); // output stream for standard output
QTextStream inS(stdin); // input stream for standard input
QTextStream errS(stderr); // error stream for standard error exception

QFile inputFile1, inputFile2, outFile, tempFiles;
//QFile tempFiles("temp.txt");


bool FlagDimension = false;
bool FlagMultiply = false;

struct Mat_Struct sMatrix1, sMatrix2, sMatrix3;

defMat matrix1, matrix2, matrix3;

pthread_t Thread_m1;
pthread_t Thread_m2;



void *InitFileManip(void *IVar)
{
	char* IDNumMatch = (char*)IVar;
	QStringList seperate;
	QString lineIn;


	int rowSize = 0; // will later store size of the matrix. Universal for Matrix 1 and 2
	int colSize = 0;

	//qDebug() << "\nFunction: InitFileManip \n| passed in " << IDNumMatch << endl;

	if (IDNumMatch == QString("1"))
	{
		//qDebug() << "IDNumMatch 1" << endl;
		//qDebug() << "sMatrix1.M_row is: " << sMatrix1.M_row << endl;
		while (!inputFile1.atEnd())
		{
			lineIn = inputFile1.readLine();
			seperate = lineIn.split(QRegularExpression("\\s+"), QString::SkipEmptyParts);
			matrix1.append(seperate);
		}
		rowSize = matrix1.length();
		colSize = matrix1[0].length();
		//qDebug() << "InitFileManip -\nPrinting matrix1 " << matrix1 << "\n rowSize: " << rowSize << " colSize: " << colSize << endl;
		sMatrix1.M_row = rowSize;
		sMatrix1.M_col = colSize;

	}
	else if (IDNumMatch == QString("2"))
	{
		//qDebug() << "IDNumMatch 2" << endl;
		//qDebug() << "sMatrix2.M_row is: " << sMatrix2.M_row << endl;
		while (!inputFile2.atEnd())
		{
			lineIn = inputFile2.readLine();
			seperate = lineIn.split(QRegularExpression("\\s+"), QString::SkipEmptyParts);
			matrix2.append(seperate);
		}
		rowSize = matrix2.length();
		colSize = matrix2[0].length();
		//qDebug() << "InitFileManip -\nPrinting matrix2 " << matrix2 << "\n rowSize: " << rowSize << " colSize: " << colSize << endl;
		sMatrix2.M_row = rowSize;
		sMatrix2.M_col = colSize;
	}
	else
	{
		//qDebug() << "Else ran" << endl;
	}

	if ((rowSize == 0) || (colSize == 0))
	{
		//qDebug() << "InitFileManip -\nFlagDimension became true" << endl;
		FlagDimension = true;
	}
	//qDebug() << "InitFileManip -\nBefore InitFileManip exits" << endl;
	pthread_exit(0);
}

void *MatrixMultiplication(void *ElmPos)
{
	QStringList ListofIndex;
	int X = 0;
	int Y = 0;
	int i = 0;
	bool ConvOkX = true;
	bool ConvOkY = true;
	int Valin1 = 0;
	int Valin2 = 0;
	int SumMat = 0;
	int tempMult = 0;

	QString Indexpos = *((QString*)ElmPos);
	//qDebug() << "Thread " << ElmPos << Indexpos << endl;

	ListofIndex = Indexpos.split(",");
	//qDebug() << "Thread QStringList " << ListofIndex << endl;

	X = ListofIndex[0].toInt(&ConvOkX);
	Y = ListofIndex[1].toInt(&ConvOkY);
	if ((ConvOkX == false) || (ConvOkY == false))
	{
		//qDebug() << "MatrixMultiplication -\nConversion failed at " << X << Y << endl;
		FlagMultiply = true;
	}

	for (i = 0; i < sMatrix1.M_col; i++)
	{
		Valin1 = matrix1[X][i].toInt(&ConvOkX);
		Valin2 = matrix2[i][Y].toInt(&ConvOkY);
		if ((ConvOkX == false) || (ConvOkY == false))
		{
			//qDebug() << "MatrixMultiplication -\nConversion failed at " << X << Y << endl;
			FlagMultiply = true;
		}
		else
		{
			tempMult = Valin1 * Valin2;
			SumMat = SumMat + tempMult;
			//printf("\nMult for Valin1= %d, Valin2= %d, tempMult= %d, SumMat= %d \n",Valin1, Valin2, tempMult, SumMat);

		}

	}
	QString outMatrixStr;
	//tempFiles.open(QIODevice::ReadWrite);
	//QTextStream tOUT(&tempFiles);

	outMatrixStr = QString::number(SumMat);
	matrix3[X][Y] = outMatrixStr;
	//qDebug() << "\n\n ** ** Final out at [" << X+1 << " x " << Y+1 << "] is = " << matrix3[X][Y] << endl;
	//tOUT << "C" << X+1 << "," << Y+1 << "=" << matrix3[X][Y] << endl;

	pthread_exit(0);
}

int main(int argc, char *argv[])
{
	QCoreApplication app(argc, argv); // used to create a seperate instance for error checking. 
    QStringList arginput = app.arguments();
	int initialSuccess = StartupErrorCheck(argc, arginput); // sneds to other function to check if valid
	outS << "\n"; 
	//qDebug() << "\nSuccess reach with output StartupErrorCheck =" << initialSuccess << endl;
	if (initialSuccess == 0) // if not successful. Program ends. 
	{
		errS << "\n -- Program input conditions not met. Terminating now" << endl;
		return 0;
	}
	else
	{
		int i = 0; // initializing later use looping elements of i and j
		int j = 0;
		QStringList TempList;
		QStringList PosList;
		QString Str_i;
		QString Str_j;

		sMatrix1.M_FileName = arginput[1];
		sMatrix1.M_ID = "1";
		//sMatrix1.M_row = 5;

		sMatrix2.M_FileName = arginput[2];
		sMatrix2.M_ID = "2";
		//sMatrix2.M_row = 10;


		pthread_create(&Thread_m1, NULL, InitFileManip, (void *)"1");
		pthread_create(&Thread_m2, NULL, InitFileManip, (void *)"2");
		//qDebug() << "main -\nPassed Pthread Creation. Next is join" << endl;

		if (FlagDimension == true)
		{
			errS << " -- ERROR: The data format of the matrices diagree!" <<
			"\nThey are only allowed to be integers with no decimal places." << endl;
			return 0;
		}

		pthread_join(Thread_m1, NULL);
		pthread_join(Thread_m2, NULL);
		//qDebug() << "main -\nPassed Pthread Joining. Next is TotalMatrixCheck" << endl;

		int sucessMat = TotalMatrixCheck(matrix1, matrix2);

		if (sucessMat == 0)
		{
			errS << "\n -- Matrix conditions not met. Terminating now" << endl;
			return 0;
		}
		//outS << "main -\nCurrent status of sMatrix1: " << sMatrix1.M_ID << sMatrix1.M_row << sMatrix1.M_col << endl;
		/*
		printf("main -\n sMatrix1:  ID=%d , row=%d , col=%d"
				"\n sMatrix2:  ID=%d , row=%d , col=%d", 1, sMatrix1.M_row, sMatrix1.M_col,
					2, sMatrix2.M_row, sMatrix2.M_col);
		*/
		for (i = 0; i < sMatrix1.M_row; i++)
		{
			for (j = 0; j < sMatrix2.M_col; j++)
			{
				Str_i = QString::number(i, 10);
				Str_j = QString::number(j, 10);
				TempList.append("0");
				PosList.append(Str_i + "," + Str_j);
			}
			matrix3.append(TempList);
		}

		for (i = 0; i < sMatrix1.M_row; i++)
		{
			for (j = 0; j < sMatrix2.M_col; j++)
			{
				//qDebug() << "main -\n matrix3 at: "<< i+1 << " x " << j+1 << " is " << matrix3[i][j] << endl;

			}
		}
		int elementCount = sMatrix1.M_row * sMatrix2.M_col;

		pthread_t MultThreads[elementCount];

		for (i = 0; i < elementCount; i++)
		{
			pthread_create(&MultThreads[i], NULL, MatrixMultiplication, (void *)&PosList[i]);
		}
		for (j = 0; j < elementCount; j++)
		{
			pthread_join(MultThreads[j], NULL);
		}

		if (FlagMultiply == true)
		{
			errS << " -- ERROR: What was passed in for matrix multiplication could not be multiplied." << endl;
			return 0;
		}
		sMatrix3.M_row = matrix3.length();
		sMatrix3.M_col = matrix3[0].length();
		//qDebug() << "Matrix 3 has row col of " << sMatrix3.M_row << sMatrix3.M_col << endl;

		//outFile.open(QIODevice::ReadWrite | QIODevice::Text);
		QTextStream FinalOUT(&outFile);
		QTextStream tOUT(&tempFiles);

		for (i = 0; i < sMatrix3.M_row; i++)
		{
			for (j = 0; j < sMatrix3.M_col; j++)
			{
				FinalOUT << matrix3[i][j] << " ";
				tOUT << "C" << i+1 << "," << j+1 << "=" << matrix3[i][j] << endl;
			}
			FinalOUT << endl;
		}
		FinalOUT << "\n";
		tOUT.flush();
		FinalOUT.flush();

	}

	tempFiles.close();
	outFile.close();
	inputFile1.close();
	inputFile2.close();
	outS << " ** Program Finished ** " << endl;
	return 0;
}