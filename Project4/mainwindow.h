////////////////////////////////////////////////////////
// ECE 3574, Homework 4, Bowei Zhao
//// ID: 905789193
// email: bowei@vt.edu
// File name: mainwindow.h
// Description: mainwindow header file
// Date: 3/11/2016

/*
QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
*/
//
// *-----------------------------------------------* //

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui>
#include <QWidget>
#include <QApplication>
#include <QMainWindow>
#include <QCoreApplication>
#include <QTextEdit>
#include <QPushButton>
#include <QBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QScrollArea>
#include <QScrollBar>
#include <QMessageBox>
#include <QCheckBox>
#include <QAbstractButton>

#include <QTextStream>
#include <QDate>
#include <QDateTime>
#include <QFile>
#include <QString>
#include <QStringList>
#include <QList>
#include <QDebug>
#include <QVector>

#include <iostream>
#include <fstream>
#include <string>
#include <exception>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
// Makes a class mainwindow that inherits from public of QMainWindow which
// is a QWidget and so it also has public of QWidget
class mainwindow : public QMainWindow 
{
	Q_OBJECT // required to make MOC files and tells it is a GUI program
			// that uses Widget and Objects

	public:
    	explicit mainwindow();
    	int giveRandom(int sel); // generates a random value
    	void initializeDat(); // initializing function to take in .dat function input
    	QString generateDateTime(); // generates fictitious time for Reminder outputs as required

    // Declares the slots in the class that will be used
    // these are used to be tied to QPushButton signals generated
    // which will then cause an action thanks to that signal
    public slots: 
    	void QuitSlot(); // if Quit button is pressed, Slot activates
    	void AdviceSlot(); // if Advice button is pressed, Slot activates
    	void WeatherSlot(); // if Weather button is pressed, Slot activates
    	void ReminderSlot(); // if Reminder button is pressed, Slot activates


	private:
		QTextEdit *m_textedit; // used to do output to GUI window
		QStringList m_advicelist; // stores list of strings of Advice.dat file
		QStringList m_weatherlist; // stores list of strings of Weather.dat file
		QStringList m_reminderlist; // stores list of strings of Reminder.dat file 
		QList<int> displayednums; // used to keep track of reminders that have been shown
};

#endif // MAINWINDOW_H

// Class MainWindow which is child of QWidget and has access to QWidget public functions
// declares a Q_OBJECT macro to declare signals and slots provided by meta-object system.

// Meta-Object Compiler handles the QT c++ extensions and are generated automatically. 