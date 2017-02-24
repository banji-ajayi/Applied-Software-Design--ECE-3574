////////////////////////////////////////////////////////
// ECE 3574, Homework 4, Bowei Zhao
//// ID: 905789193
// email: bowei@vt.edu
// File name: main.cpp
// Description: main implementation file
// Date: 3/11/2016
//
// *-----------------------------------------------* //
#include "mainwindow.h"

// QApplication is a child of baseclass QCoreApplication which allows for extended
// functionality in dealing with widgets and GUI as opposed to QCoreApplication

int main(int argc, char *argv[])
{
	QApplication program(argc, argv); // give GUI Qapplication my input arguments
	mainwindow win; // make a variable of mainwindow class
	win.show(); // show the window
	return program.exec(); // goes into event loop
}