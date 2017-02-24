////////////////////////////////////////////////////////
// ECE 3574, Homework 4, Bowei Zhao
//// ID: 905789193
// email: bowei@vt.edu
// File name: mainwindow.cpp
// Description: mainwindow implementation file
// Date: 3/11/2016
//
// *-----------------------------------------------* //

#include "mainwindow.h"
QTextStream outS(stdout); // output stream for standard output
QTextStream inS(stdin); // input stream for standard input
QTextStream errS(stderr); // error stream for standard error exception

mainwindow::mainwindow() 
{
	QWidget *b_widgmain = new QWidget(); // allocates memory and creates a new Widget
	QWidget::setWindowTitle("Advisor"); // sets title of Window to project spec 

	m_textedit = new QTextEdit(); // allocates memory for a new QTextEdit which is private variable
	initializeDat(); // calls regular function to initialize .dat file and store in data

	// Code below initializes and allocates memory for new Pushbuttons 
	// that will be used to give advice,weather, reminder, or quit the program
	QPushButton *b_advice = new QPushButton("Advice", this);
	QPushButton *b_weather = new QPushButton("Weather", this);
	QPushButton *b_reminder = new QPushButton("Reminder", this);
	QPushButton *b_quit = new QPushButton("Quit", this);

	// Used to make the 'layout' of the widget UI box
	QVBoxLayout *vlayout = new QVBoxLayout();
	// code below used to continuously add the widgets and set the layout
	vlayout->addWidget(m_textedit);
	vlayout->addWidget(b_advice);
	vlayout->addWidget(b_weather);
	vlayout->addWidget(b_reminder);
	vlayout->addWidget(b_quit);
	// finally sets the layout in the widget itself
	b_widgmain->setLayout(vlayout);
	setCentralWidget(b_widgmain); // important code to actually 'activates' the code
	b_widgmain->show();

	// Connect code below is what connects the Signals that the QPushButton has 
	// by default and connects it to a slot by calling a function to run it.
	// Continuous event code keeps watch of signals and will send if is detected
	QObject::connect(b_advice, SIGNAL(clicked()), this, SLOT(AdviceSlot()));
	QObject::connect(b_weather, SIGNAL(clicked()), this, SLOT(WeatherSlot()));
	QObject::connect(b_reminder, SIGNAL(clicked()), this, SLOT(ReminderSlot()));
	QObject::connect(b_quit, SIGNAL(clicked()), this, SLOT(QuitSlot()));

    //QWidget::move(300, 300);
    QWidget::resize(350, 400); // makes it look similar to size of what is in spec
    
}

// SLOT FUNCTION
void mainwindow::AdviceSlot()
{
	// Slot for advice is called. So program will ask for a random value
	// from the program based on how many valid entires Advice.dat is
	// and uses that to output a string to gui Window
	int randomnumberA = giveRandom(1); // 1 is used to specify I am asking about
										// the Advice.dat file
	QString adviceOut = "Advice: " + m_advicelist.at(randomnumberA);
	m_textedit->append(adviceOut);
	// Keeps scrollbar at the bottom which makes it easier to see if many outputs
	m_textedit->verticalScrollBar()->setValue(m_textedit->verticalScrollBar()->maximum());
}
// SLOT FUNCTION
void mainwindow::WeatherSlot()
{
	// Slot for Weather is called. So program will ask for a random value
	// from the program based on how many valid entires Weather.dat is
	// and uses that to output a string to gui Window
	int randomnumberW = giveRandom(2);// 2 is used to specify I am asking about
										// the weather.dat file
	QString weatherOut = "Weather: " + m_weatherlist.at(randomnumberW);
	m_textedit->append(weatherOut);
	// Keeps scrollbar at the bottom which makes it easier to see if many outputs
	m_textedit->verticalScrollBar()->setValue(m_textedit->verticalScrollBar()->maximum());

}

// SLOT FUNCTION
void mainwindow::ReminderSlot()
{
	int randomnumberR = giveRandom(3); // calls 3 to grab random value for Reminder.dat file specifically

	// while loop checks if my private QList of ints has been used in the past. The StringList for all 
	// 3 .dat files are stored sequentially so the # used is the same to see if they ran before

	// The program makes sure number not used and makes sure they aren't the same size to grab a new random
	// number in case the number was used before. Allows for unique messages for when checkbox is unchecked
	while ((displayednums.contains(randomnumberR)) && ((displayednums.size()) < (m_reminderlist.size())))
	{
		randomnumberR = giveRandom(3);
	}
	//qDebug() << "B: display size " << displayednums.size() << "  reminderlist size " << m_reminderlist.size() << endl;

	// if loop makes sure to only make pop up if messages still remain
	if ((displayednums.size()) < (m_reminderlist.size())) 
	{
		// code below feeds in random value and calls for a message from my List of entries
		QString reminderOut = m_reminderlist.at(randomnumberR); 
		QString genDT = generateDateTime(); // calls non-slot function to generate a Date and Time
		reminderOut = reminderOut + genDT; // overloads QString to add two strings together

		QCheckBox *askR = new QCheckBox("Show this message again", this); // initializes checkbeck
		askR->setChecked(true); // sets the checkbox status to initially be checked

		QMessageBox *reminderbox = new QMessageBox(this); // creates and initializes/allocates new QMessagebox
		// code below are giving my new popup QMEssagebox some parameters
		reminderbox->setCheckBox(askR); // important to crate checkbox
		reminderbox->setText(reminderOut); // puts the actual Reminder message
		reminderbox->setStandardButtons(QMessageBox::Ok); // makes the OK button for exit
		reminderbox->setDefaultButton(QMessageBox::Ok); // sets Ok as default button
		reminderbox->setIcon(QMessageBox::Information); // makes the Icon the information one
		reminderbox->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding); // hopes to make box dynamic
		reminderbox->setModal(true); // QMessageBox is default modal, but this just in case

		reminderbox->exec(); // runs and executes it
		// if the box at the end is unchecked, then I store what value was used to pull from List
		if (askR->checkState() == Qt::Unchecked)
		{
			//qDebug() << "Unchecked" << endl;
			displayednums.append(randomnumberR); // appends to list of displayed nunbers
			/*
			for (int i = 0; i < displayednums.size(); i++)
			{
				qDebug() << displayednums.at(i) << endl;
			}
			*/

		}
		else if (askR->checkState() == Qt::Checked) // checks if left checked
		{	// no code. Only used for debuggin purpose
			//qDebug() << "Checked" << endl;
		}

	}
	else // runs when no more reminders are left and will output to the main text window of widget
	{
		m_textedit->append("There are no more reminders");
		// Keeps scrollbar at the bottom which makes it easier to see if many outputs
		m_textedit->verticalScrollBar()->setValue(m_textedit->verticalScrollBar()->maximum());

	}
	//qDebug() << "A: display size " << displayednums.size() << "  reminderlist size " << m_reminderlist.size() << endl;
}

// SLOT FUNCTION
void mainwindow::QuitSlot()
{
	// creates QMessagebox and asks for quit. If pressed, then quits
	QMessageBox::StandardButton askexit;
  	askexit = QMessageBox::question(this, "Advisor", "Are you sure you want to quit?",
  				 QMessageBox::Yes|QMessageBox::No);
  	if (askexit == QMessageBox::Yes)
  	{
	    QApplication::quit();
  	} 	
}


// REGULAR FUNCTION
int mainwindow::giveRandom(int sel)
{
	int listSize;
	int universaltime = QDateTime::currentDateTimeUtc().toMSecsSinceEpoch()/100;
	//qDebug() << "universe " << universaltime << endl;

	// uses UTC Epoch time to generate new srand seed
	qsrand(universaltime);

	// sel is used to select which type of random value to give back
	// makes it dynamic to work with multiple functions that want different
	// ranges of numbers to be returned. 
	if (sel == 1) // Advice was picked
	{
		listSize = m_advicelist.size();
		//qDebug() << "Advicelist Rand size is: " << listSize << endl;
	}
	else if (sel == 2) // Weather was picked
	{
		listSize = m_weatherlist.size();
		//qDebug() << "Weatherlist Rand size is: " << listSize << endl;
	}
	else if (sel == 3) // Reminder was picked
	{
		listSize = m_reminderlist.size();
		//qDebug() << "Reminderlist Rand size is: " << listSize << endl;
	}
	else if (sel == 4) // Generate Month and Hour
	{
		listSize = 10;
	}
	else if (sel == 5) // Generate Day
	{
		listSize = 26;
	}
	else if (sel == 6) // Generate Year
	{
		listSize = 17;
	}
	else if (sel == 7) // generate Minutes
	{
		listSize = 59;
	}
	else if (sel == 8) // Generates AM or PM
	{
		listSize = 2;
	}
	else // else case just in case
	{
		listSize = 5;
	}

	// used to actually generate random value
	int outRand = qrand() % listSize;
	return outRand;
}

// REGULAR FUNCTION
// Used to generate unique and valid Date & Time for the Reminder pop up
QString mainwindow::generateDateTime()
{
	// initializing data and information which will be overloaded later
	QString initialDate = "01/01/2000";
	QString initialTime = "1:00";
	QString finalDate, finalTime, finalWeek;
	QString finalOut = " at ";
	int Numbah, nonZero, dayOWeek;

	// converts the initial string to a QDate and then asks for a random value
	// of the correct range and adds those months, days, and years to it
	QDate startDate = QDate::fromString(initialDate, "MM/dd/yyyy");
	Numbah = giveRandom(4);
	startDate = startDate.QDate::addMonths(Numbah);
	Numbah = giveRandom(5);
	startDate = startDate.QDate::addDays(Numbah);
	Numbah = giveRandom(6);
	startDate = startDate.QDate::addYears(Numbah);
	
	// check to make sure the date is valid at least
	while (!(startDate.isValid()))
	{
		initialDate = "01/01/2000";
		startDate = QDate::fromString(initialDate, "MM/dd/yyyy");
		startDate.QDate::addMonths(giveRandom(4));
		startDate.QDate::addDays(giveRandom(5));
		startDate.QDate::addYears(giveRandom(6));
	}
	// sees which day of the week it is (Monday -> Sunday) and returns # corresponding
	dayOWeek = startDate.QDate::dayOfWeek();

	// depending on # value, it sets QString to the correct output for later overloading
	if (dayOWeek == 1)
	{
		finalWeek = " Monday ";
	}
	else if (dayOWeek == 2)
	{
		finalWeek = " Tuesday ";
	}
	else if (dayOWeek == 3)
	{
		finalWeek = " Wednesday ";
	}
	else if (dayOWeek == 4)
	{
		finalWeek = " Thursday ";
	}
	else if (dayOWeek == 5)
	{
		finalWeek = " Friday ";
	}
	else if (dayOWeek == 6)
	{
		finalWeek = " Saturday ";
	}
	else if (dayOWeek == 7)
	{
		finalWeek = " Sunday ";
	}
	else
	{
		finalWeek = " Monday ";
	}
	// converts QDate to QString
	finalDate = startDate.toString("MM/dd/yyyy");

	//outS << "Debug Date " << finalDate << endl;
	//outS << "dayOWeek " << dayOWeek << finalWeek << endl;

	// converts the time from QTime to QString
	QTime startTime = QTime::fromString(initialTime, "h:mm");

	// unique random generated to make sure value is non-zero and between 1 and 11 for
	// the hour of the day. 12 is not used as too complex for AM/PM
	nonZero = rand() % (11-1 + 1) + 1;
	// sets Hours, Minutes, Seconds of the QTime using function
	startTime.QTime::setHMS(nonZero, giveRandom(7), 0);
	// converts the final QTime to a QString
	finalTime = startTime.QTime::toString("h:mm");

	// generates random number between 0 and 1. Picks AM or PM
	// depending on what value is given back
	if (giveRandom(8) == 1)
	{
		finalTime = finalTime + " PM,";
	}
	else
	{
		finalTime = finalTime + " AM,";
	}
	//outS << "Debug Time " << finalTime << endl;

	// Does a final QString overloading to add all the pieces
	// together so that it looks right on the output
	finalOut = finalOut + finalTime + finalWeek + finalDate;
	
	//outS << "Final out time is " << finalOut << endl;
	return finalOut;

}

// REGULAR FUNCTION
// used to initially take in data from .dat file and load  it into lists
//
void mainwindow::initializeDat()
{
	// variables used to store  the data are made at first
	QString warningOut;
    QString inLine, checkline;
    QStringList tempA, tempW, tempR, tempcheck;
    QString backslashA, backslashW, backslashR;

    QString nothingin; 
    nothingin.clear(); // nothingin is used to provide empty string if need be
    // -------------- Initialize Advice File /////
    tempcheck.clear();// clear temporary storage Stringlist if needed


//	Format is to first make an initial list and take in data from the  device and  file
    // and store it without any modification into the temporary list
    QFile adviceFile2("advice.dat");
	adviceFile2.open(QIODevice::ReadOnly);
    QTextStream inA2(&adviceFile2);
    while (!inA2.atEnd())
    {
    	checkline = inA2.readLine();
    	tempcheck.append(checkline);
    }
    adviceFile2.close();

    /*
    qDebug() << "\nAdvice Check" << endl;
	for (int i = 0; i < tempcheck.size(); i++)
	{
		qDebug() << tempcheck.at(i) << endl;
	}
	*/

// Next, we re-open the  same file and thistime take in data while checking for the \ character
// while it sees one atthe end, it will replace itwith the empty string.
// finally it stores contents into the the  private class variable to finish up
	QFile adviceFile("advice.dat");
	adviceFile.open(QIODevice::ReadOnly);
	QTextStream inA(&adviceFile);
    while (!inA.atEnd())
    {
        inLine = inA.readLine();
        while (inLine.endsWith('\\'))
        {
            inLine.replace('\\',nothingin);
            inLine.append(inA.readLine());
        }
        tempA.append(inLine);
    }
    adviceFile.close();
	m_advicelist = tempA;

    backslashA = tempcheck.at(tempcheck.size()-1);
	//qDebug() << "backslash " << backslashA << endl;
	if (backslashA.endsWith('\\'))
	{	
		errS << "\nWARNING: Advice.dat has an ending message"
		<< " of: " << backslashA << "\n"
		<< " with a backslash symbol \\ that is not allowed.\n"
		<< "This message will be removed from the final list"
		<< " of available outputs.\n" << "The program will proceed normally." << endl;
		m_advicelist.removeLast();
		warningOut = "Warning Adivce.dat, see terminal.\n";
		m_textedit->append(warningOut);
		m_textedit->verticalScrollBar()->setValue(m_textedit->verticalScrollBar()->maximum());
	}

	/*
	qDebug() << "\nAdvice List" << endl;
	for (int i = 0; i < m_advicelist.size(); i++)
	{
		qDebug() << m_advicelist.at(i) << endl;
	}
	*/


	// ------------- Initialize Weather File //////
	tempcheck.clear();

//	Format is to first make an initial list and take in data from the  device and  file
    // and store it without any modification into the temporary list
	QFile weatherFile2("weather.dat");
	weatherFile2.open(QIODevice::ReadOnly);
	QTextStream inW2(&weatherFile2);
    while (!inW2.atEnd())
    {
    	checkline = inW2.readLine();
    	tempcheck.append(checkline);
    }
    weatherFile2.close();
    /*
    qDebug() << "\nWeather Check" << endl;
	for (int i = 0; i < tempcheck.size(); i++)
	{
		qDebug() << tempcheck.at(i) << endl;
	}
	*/
	
// Next, we re-open the  same file and thistime take in data while checking for the \ character
// while it sees one atthe end, it will replace itwith the empty string.
// finally it stores contents into the the  private class variable to finish up
	QFile weatherFile("weather.dat");
	weatherFile.open(QIODevice::ReadOnly);
	QTextStream inW(&weatherFile);
    while (!inW.atEnd())
    {
        inLine = inW.readLine();
        while (inLine.endsWith('\\'))
        {
            inLine.replace('\\',nothingin);
            inLine.append(inW.readLine());
        }
        tempW.append(inLine);
    }
    weatherFile.close();
    m_weatherlist = tempW;

    backslashW = tempcheck.at(tempcheck.size()-1);
	//qDebug() << "backslash " << backslashW << endl;
	if (backslashW.endsWith('\\'))
	{
		errS << "\nWARNING: Weather.dat has an ending message"
		<< " of: " << backslashW << "\n"
		<< " with a backslash symbol \\ that is not allowed.\n"
		<< "This message will be removed from the final list"
		<< " of available outputs.\n"
		<< "The program will proceed normally." << endl;
		m_weatherlist.removeLast();
		warningOut = "\nWarning Weather.dat, see terminal.\n";
		m_textedit->append(warningOut);
		m_textedit->verticalScrollBar()->setValue(m_textedit->verticalScrollBar()->maximum());
	}
	/*
    qDebug() << "\nWeather List" << endl;
	for (int i = 0; i < m_weatherlist.size(); i++)
	{
		qDebug() << m_weatherlist.at(i) << endl;
	}
	*/

	// ------------- Initialize Reminder File //////
	tempcheck.clear();
//	Format is to first make an initial list and take in data from the  device and  file
    // and store it without any modification into the temporary list
	QFile reminderFile2("reminder.dat");
	reminderFile2.open(QIODevice::ReadOnly);
	QTextStream inR2(&reminderFile2);
    while (!inR2.atEnd())
    {
    	checkline = inR2.readLine();
    	tempcheck.append(checkline);
    }
    reminderFile2.close();
    /*
	qDebug() << "\nReminder Check" << endl;
	for (int i = 0; i < tempcheck.size(); i++)
	{
		qDebug() << tempcheck.at(i) << endl;
	}
	*/

// Next, we re-open the  same file and thistime take in data while checking for the \ character
// while it sees one atthe end, it will replace itwith the empty string.
// finally it stores contents into the the  private class variable to finish up
	QFile reminderFile("reminder.dat");
	reminderFile.open(QIODevice::ReadOnly);
	QTextStream inR(&reminderFile);
    while (!inR.atEnd())
    {
        inLine = inR.readLine();
        while (inLine.endsWith('\\'))
        {
            inLine.replace('\\',nothingin);
            inLine.append(inR.readLine());
        }
        tempR.append(inLine);
    }
    reminderFile.close();
    m_reminderlist = tempR;

    backslashR = tempcheck.at(tempcheck.size()-1);
	//qDebug() << "backslash " << backslashR << endl;
	if (backslashR.endsWith('\\'))
	{
		errS << "\nWARNING: Reminder.dat has an ending message"
		<< " of: " << backslashR << "\n"
		<< " with a backslash symbol \\ that is not allowed.\n"
		<< "This message will be removed from the final list"
		<< " of available outputs.\n"
		 << "The program will proceed normally." << endl;
		m_reminderlist.removeLast();
		warningOut = "\nWarning Reminder.dat, see terminal.\n";
		m_textedit->append(warningOut);
		m_textedit->verticalScrollBar()->setValue(m_textedit->verticalScrollBar()->maximum());
	}
	/*
    qDebug() << "\nReminder List" << endl;
	for (int i = 0; i < m_reminderlist.size(); i++)
	{
		qDebug() << m_reminderlist.at(i) << endl;
	}
	*/

}


