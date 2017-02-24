////////////////////////////////////////////////////////
// ECE 3574, Homework 6, Bowei Zhao
//// PID: 905789193
// email: bowei@vt.edu
// File name: matrix.cpp
// Description: secondary implementation file
// Date: 4/020/2016
//
// *-----------------------------------------------* //
#include "matrix.h"

QTextStream outM(stdout); // output stream for standard output
QTextStream inM(stdin); // input stream for standard input
QTextStream errM(stderr); // error stream for standard error exception	


int TotalMatrixCheck(defMat checkM1, defMat checkM2)
{
	int successRet = 1; // default to return for successful and good matrix arguments

	int tInt = 0; // not used for anything besides storing temporary integer for checking if valid
	bool okInt = false; // checks if input is valid for integer ONLY

	double tdouble = 0.0;
	bool okdouble = false;

	float tfloat = 0.f;
	bool okfloat = false;
	int i = 0;
	int j = 0;

	QString actQTStr; // stores what is ACTUALLY in the matrix before conversion
	string actStr;


	char buffer[100]; 

	//qDebug() << "\nFunction: TotalMatrixCheck \n| passed in "<< "\nM1: " << checkM1 << "\nM2: " << checkM2 << endl;
	try
	{
		int rowM1 = checkM1.length(); // M
		int colM1 = checkM1[0].length(); // N

		int rowM2 = checkM2.length(); // N
		int colM2 = checkM2[0].length(); // P

		//qDebug() << "TotalMatrixCheck -\nChecking dimension of row is non-zero." << endl;
		//outM << "length of M1 and M2 are: " << span1 << span2 << endl;
		//qDebug() << "sMatrix1.M_row is: " << sMatrix1.M_row << endl;
		if ((rowM1 == 0) || (rowM2 == 0) || (colM1 == 0) || (colM2 == 0))
		{
			 throw "One or both of the matrixes are of length 0.";
		}
		else if (colM1 != rowM2)
		{
			throw "The matrixes are not of correct dimensions for multiplication.";
		}

		//qDebug() << "TotalMatrixCheck -\nDone checking matrix non-zero.\nNow check all elements of Matrix 1 for integer" << endl;

		for(i = 0; i < rowM1; i++)
		{
			if (colM1 != checkM1[i].length())
			{
				throw "The rows in your first matrix input do not have corresponding column values." 
				"\nA key element(s) is missing";
			}

			for (j = 0; j < colM1; j++)
			{
				actQTStr = checkM1[i][j];
				actStr = checkM1[i][j].toStdString();
				tInt = checkM1[i][j].toInt(&okInt);
				tdouble = checkM1[i][j].toDouble(&okdouble);
				tfloat = checkM1[i][j].toFloat(&okfloat);

				//printf("TotalMatrixCheck -\ncheckM1 [%d][%d]: %d, %.2f, %.2f\n",i+1 , j+1, tInt, tdouble, tfloat);
				//qDebug() << "Flag M1 is : " << okInt << okdouble << okfloat << endl;

				if (okInt == false)
				{
					if ((okdouble == true) || (okfloat == true))
					{
						sprintf(buffer, "The input element at Matrix 1 [%dx%d] was not an integer.",i+1, j+1);
						throw buffer;
					}
					else
					{
						sprintf(buffer, "An element at Matrix 1 [%dx%d] was not an integer or number.",i+1, j+1);
						throw buffer;
					}


				}

			}
		}
		//qDebug() << "TotalMatrixCheck -\nDone checking Matrix 1 for int.\nNow check all elements of Matrix 2 for integer" << endl;

		tInt = 0;
		tdouble = 0.0;
		tfloat = 0.f;

		for(i = 0; i < rowM2; i++)
		{
			if (colM2 != checkM2[i].length())
			{
				throw "The rows in your second matrix input do not have corresponding column values." 
					 "\nA key element(s) is missing";
			}

			for (j = 0; j < colM2; j++)
			{
				tInt = checkM2[i][j].toInt(&okInt);
				tdouble = checkM2[i][j].toDouble(&okdouble);
				tfloat = checkM2[i][j].toFloat(&okfloat);

				//printf("TotalMatrixCheck -\ncheckM2 [%d][%d]: %d, %.2f, %.2f\n",i+1 , j+1, tInt, tdouble, tfloat);
				//qDebug() << "Flag M2 is : " << okInt << okdouble << okfloat << endl;

				// the lines of code below not used for anything. Just to surpress error
				//tfloat = tfloat + 0;
				//tInt = tInt + 0;
				//tdouble = tdouble + 0;

				if (okInt == false)
				{
					if ((okdouble == true) || (okfloat == true))
					{
						sprintf(buffer, "The input element at Matrix 2 [%dx%d] was not an integer.",i+1, j+1);
						throw buffer;
					}
					else
					{
						sprintf(buffer, "An element at Matrix 2 [%dx%d] was not an integer or number.",i+1, j+1);
						throw buffer;
					}
				}
			}
		}

		//qDebug() << "TotalMatrixCheck -\nDone checking Matrix 2 for int.\n" << endl;


	}
	catch (const char* msg)
	{
		successRet = 0;
		errM << "\n -- ERROR: " << msg << "\nPlease re-check your matrix data input\n" << endl;
		return successRet; // returns NOW, instead of later
	}
	//qDebug() << "TotalMatrixCheck -\nWill return successRet of: " << successRet << endl;
	return successRet;
}

int StartupErrorCheck(int &argc, QStringList arginput)
{	
	int successRun = 1;

	//qDebug() << "\nFunction: StartupErrorCheck \n| passed in " << argc << arginput << endl;

	try
	{
		if (argc != 4)
		{
			throw "Improper number of arguments provided. Please give terminal the 4 arguments of\n"
			"./matrix-multiply <Input Matrix 1> <Input Matrix 2> <Output Name>";			
		}
		//qDebug() << "Got past argc != 4" << endl;

		QString inName1 = arginput[1];
		inputFile1.setFileName(inName1);
		if (!inputFile1.open(QIODevice::ReadOnly | QIODevice::Text))
		{
			throw "The program could not create or open an input file.";
		}

		QString inName2 = arginput[2];
		inputFile2.setFileName(inName2);
		if (!inputFile2.open(QIODevice::ReadOnly | QIODevice::Text))
		{
			throw "The program could not create or open an input file.";
		}


		QString outName = arginput[3];
		outFile.setFileName(outName);
		if (!outFile.open(QIODevice::WriteOnly | QIODevice::Text))
		{
			throw "The program could not create or open an output file.";
		}

		QString tempName = "temp.txt";
		tempFiles.setFileName(tempName);
		if (!tempFiles.open(QIODevice::WriteOnly | QIODevice::Text))
		{
			throw "The program could not create or open an output temp.txt file.";
		}

	}
	catch (const char* msg)
	{
		successRun = 0;
		errM << "\n -- ERROR: " << msg << "\nPlease re-check your files and arguments\n" << endl;
	}

	return successRun;
}