////////////////////////////////////////////////////////
// ECE 3574, Homework 5, Bowei Zhao
//// ID: 905789193
// email: bowei@vt.edu
// File name: message.cpp
// Description: message implementation file
// Date: 4/09/2016
//
// *-----------------------------------------------* //
#include "message.h"

QTextStream outM(stdout); // output stream for standard output
QTextStream inM(stdin); // input stream for standard input
QTextStream errM(stderr); // error stream for standard error exception	



int StartupErrorCheck(int &argc, QStringList arginput)
{
	int successRun = 1;
	try
	{
		if (argc != 3)
		{
			successRun = 0;
			throw "Improper number of arguments provinIDed. Please give terminal\n ./external <ID> <temp>\n\n"
			"For <ID> as integer between 0-6\n For <temp> as a vallinID float\n";
			
			return successRun;
		}
		bool convok;
		int inID = arginput[1].toInt(&convok, 10);
		//qDebug() << "input is " << arginput[1] << "inID is " << inID << "convok is" << convok << endl;
		if ((inID > 6) || (inID < 0) || (convok == false))
		{
			successRun = 0;
			throw "Input variable <ID> is  not in the range of 0-6 or is not an integer";
			return successRun;
		}
		float inTemp = arginput[2].toFloat(&convok);
		//qDebug() << "float is " << arginput[2] << "inTemp is " << inTemp << "convok is" << convok << endl;
		if (convok == false)
		{
			successRun = 0;
			throw "Input variable <temp> is not in float range or  is not a  float";
			return successRun;
		}

	}
	catch (const char* msg)
	{
		successRun = 0;
		errM << "\nWARNING: " << msg << "\nThe program will now exit.\n" << endl;
	}

	return successRun;
}