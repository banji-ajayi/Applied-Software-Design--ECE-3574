////////////////////////////////////////////////////////
// ECE 3574, Homework 1, Bowei Zhao
//
// File name: main.cpp
// Description: cpp main for birthday 
// Date: 2/5/2016
//
// *-----------------------------------------------* //

#include "birthdays.h"

// I made an array of structs with variables inside that every array will have access to
struct Human
{
	QString s_name; // I wanted to store the name as a string
	QDate s_birthday; // the birthday as an official QDate
	QDate s_Nextbirthday; // I originally used s_Nextbirthday for update but this is no longer used
	int s_year; // I break apart the Birthday into year, month, and day automatically and store them together as well
	int s_month;
	int s_day;
};

Human people[100]; // I made a Human struct of people which will be my MAIN array of structs
Human sortAr[100]; // make sortAr of Human Struct type. This temporary array will sort the output
Human finalAr[100]; // this will store the final values used in printing.

// Struct CurrenTime is used precisely and only for storing my current PC Computer time using QDate function
// it is not hard coded but rather gets the data from the system computers
struct CurrenTime
{
	QDate pcTime; // current system clock time
	int pcYear;
	int pcMonth;
	int pcDay;

}PCNow;


int Global_Error = 0; // used along with std::exception to produce error exceptions
int cycle = 0; // keeps track of iteration through loop

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                           Main Function Description:
//   I used my main function mainly as a distribution center for commands. It takes in variables from the command line
//   and then shoots them out to different functions depending on what is provided.
//
//   I used a combination of argument numbers and what is passed in to dictate where I want information to go.
//   I store arguments as QStrings and do conversions later. They are checked for validity in seperate functions.
//

int main (int argc, char* argv[])
{ 
	//  Used to provide a real amount of arguments provided minus the ./birthdays
	int RealArgCount = argc-1;

	// These Qstring are used to store my variables I pass in
	QString firstArg, secondArg, thirdArg;
	firstArg = argv[1];
	secondArg = argv[2];
	thirdArg = argv[3];

	QString NoString; // used soley to pass in an empty string as argument.
	NoString.clear(); // this is so I can use one function for multiple validation checks

	//qDebug() << "\nARGC is: " << RealArgCount;
	// Try, Catch loop for exception handling

	// I use Global_Error, defErr, and stderr combined to handle my error output
	try
	{
		if (RealArgCount == 0) // no arguments means to read from birthdays.dat and output 30 nearest days
		{
			initialAdd(); // add information from birthday data
			QString str = "30"; // hard coded 30 days
			WithinNumber(str); // passing 30 days into my function that uses the information to see 
			WriteContents(); // writes data back into file
			Global_Error = 0; // means no issues
		}
		else if (RealArgCount >= 4) // the maximum number of arguments every defined in project specification was 4
		{
			//Error handlings
			Global_Error = 1;
			throw defErr;
		}
		else
		{
			initialAdd(); // Re-Add files in current birthdays.dat file as this is recreated every time

			//qDebug() << "\n" << "  ############# Running Argument ##############" << endl;

			//qDebug() << "First: " << firstArg << "\nSecond: " <<secondArg << "\nThird: " << thirdArg;
			if (firstArg == "-u") // checks if argument is to update files and output 
			{
				if (!(RealArgCount == 1)) // maximum of 1 argument allowed or else not valid
				{
					Global_Error = 100;
					throw defErr;
				}
				//qDebug() << "\n	Argument : -u" << endl;
				updateApp(); // cals function
			}
			else if (firstArg == "-a")
			{
				if (!(RealArgCount == 3)) // maximum of 3 arguments allowed
				{
					Global_Error = 100;
					throw defErr;
				}
				//Format should be   ./birthdays -a yyyy-MM-dd “John Smith”
				//qDebug() << "\n	Argument : -a" << endl;

				if (!( ValidInput(thirdArg, secondArg)==0))
				{
					Global_Error = 2;
					throw defErr;
				}
				FileaddTolist(thirdArg, secondArg);
			}
			else if (firstArg == "-d")
			{
				// Format 1    ./birthdays -d "John Smith"
				// Format 2	   ./birthdays -d yyyy-MM-dd
				//qDebug() << "\n	Argument : -d" << endl;

				if (!(RealArgCount == 2)) // max of 2 arguments allowed
				{
					Global_Error = 100;
					throw defErr;
				}

				if (!( ValidInput(secondArg, NoString)==0))
				{
					Global_Error = 4;
					throw defErr;
				}

				DeleteEntry(secondArg); // calls delete function
			}
			else if (firstArg == "-n")
			{
				// Format     ./birthdays -n 40 shows birthdays coming up in the next 40 days.
				//qDebug() << "\n	Argument : -n" << endl;

				if (!(RealArgCount == 2)) // max of 2 allowed
				{
					Global_Error = 100;
					throw defErr;
				}

				if (!( ValidInput(secondArg, NoString)==0)) // checks for validity
				{
					Global_Error = 5;
					throw defErr;
				}

				WithinNumber(secondArg);
			}
			else if (firstArg == "-m")
			{
				// Format     ./birthdays -m "John Smith" 40 shows birthdays coming up in the next 40 days
				//qDebug() << "\n	Argument : -m" << endl;
				if (!(RealArgCount == 3))
				{
					Global_Error = 100;
					throw defErr;
				}

				if (!( ValidInput(secondArg, NoString)==0)) //checks for validity twice
				{
					Global_Error = 7;
					throw defErr;
				}
				if (!( ValidInput(thirdArg, NoString)==0)) // this is because there are multiple arguments
				{
					Global_Error = 7;
					throw defErr;
				}

				PersonWithinNumber(secondArg, thirdArg);

			}
			else if ((RealArgCount == 1)) // lastly checks for Namespec
			{
				if ((firstArg.isEmpty())) // makes sure it has content
				{
					Global_Error = 3;
					throw defErr;
				}
				else
				{
					//qDebug() << "\n	Argument : NAMESPEC" << endl; 
					if (!( ValidInput(firstArg, NoString)==0)) 
					{
						Global_Error = 6;
						throw defErr;
					}

					NamePartialSpec(firstArg);// runs namespec command
				}
			}
			else
			{
				// if code reaches this point. It means command given was legal and valid but
				// didn't match anything available as a choice. It is thus technically illegal

				Global_Error = 8; 
				throw defErr;

			}

			// makes it so the output isn't as close to the terminal prompt window
			char OutLine [50];
			sprintf(OutLine,"\n");
			puts(OutLine);
			// --------------------------------------------------------------------------
			// --- Files will finally be re-written back and be updated while doing so.

			// Cycle is a global variable that tracks how many entities are in birthdays.dat
			// it will only write contents if this is >0 to avoid segment errors
			if (cycle >0)
			{
				WriteContents();
			}
			
		}
	}
	catch (std::exception& e) // EXCEPTION HANDLING 
	{
		std::cerr << e.what(); // I output the default ERROR PHRASE

		// Tthe following errors below are self explanatory. They describe different patterns for bad input

		if (Global_Error == 1)
		{
			qCritical() << "\nInvalid Number of Inputs: You Gave too many inputs." << endl;
		}
		else if (Global_Error == 2)
		{
			qCritical() << "\nYour input is not valid. Date or Name not in right format";
			qCritical() << "You can not enter past dates from current Time. Try Again" << endl;
		}
		else if (Global_Error == 3)
		{
			qCritical() << "\nNAMESPEC command not valid. Provide Valid Input" << endl;
		}
		else if (Global_Error == 4)
		{
			qCritical() << "\nDelete Command not valid. Invalid input" << endl;
		}
		else if (Global_Error == 5)
		{
			qCritical() << "\nInput for -n should be a number. Try again" << endl;
		}
		else if (Global_Error == 6)
		{
			qCritical() << "\nNAMESPEC provided not Valid. Provide a valid name" << endl;
		}
		else if (Global_Error == 7)
		{
			qCritical() << "\nName or Number for -m is not in valid format. Try Again" << endl;
		}
		else if (Global_Error == 8)
		{
			qCritical() << "\nThe command argument given of" << firstArg << "is not valid";
			qCritical() << "Please provide a valid command argument" << endl;
		}
		else if (Global_Error == 100)
		{
			qCritical() << "\nThe argument of"<< firstArg <<"does not have correct parameters";
			qCritical() << "You gave too many or too few. Try again" << endl;
		}
	}
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                                          Function Description:
// ValidInput takes in arguments of QString and checks for their validity. The left/first argument can be used to check
// if a Name or number value is valid whereas the right/second argument checks just if the date is valid
// 
// This is used to check for indents, tabs, or extra uneeded spaces in the input command line
// It can detect special characters, if you put the date in a slightly different format, and also move through fast
//
//

int ValidInput(QString Nargument, QString Dargument)
{
	QDate tempBirth; // stores the temporary birth day
	QChar print; // used soley for matching characters

	int lengthstrName; // stores the length of the string name
	int NumSpace = 0;
	int maxNum = 0;

	if (!(Nargument.isEmpty() || Nargument.isNull()))
	{
		//qDebug() << "Empty Name";
		lengthstrName = Nargument.length();
		//qDebug() << "Length str" << lengthstrName;
		for(int i = 0; i<lengthstrName; i++)
		{
			if (Nargument.at(i).unicode() > 127)
			{
				//qDebug() << "Illegal Unicode";
				return 2;

			}
			if (Nargument.at(i) == ' ') // detects spaces
			{
				NumSpace++;
				if (NumSpace > maxNum) // allows no more than 1 space in between names
				{
					maxNum = NumSpace;
				}
				//qDebug() << "Space Detected" << NumSpace;
			}
			else
			{
				NumSpace--;
			}
		}
		if (NumSpace >=2) // keeps track of maximum number of spaces
		{
			return 2;
		}
	}

	// checks for date validity
	if (!(Dargument.isEmpty() || Dargument.isNull()))
	{
		//qDebug() << "Empty Date";
		print = Dargument.at(6);

		if(print == '-')
		{
			//qDebug() << "equal -";
			return 2;
		}
		tempBirth = QDate::fromString(Dargument, "yyyy-MM-dd");

		if (!(tempBirth.isValid())) {
			//qDebug() << "Birthday not Valid";
			return 2;
		}

		if (PCNow.pcTime > tempBirth)
		{
			return 2;
		}
	}

	return 0;

}

int small; // global variables used for SORT functions
int run = 0; // global sort function variable
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                                          Function Description:
// 
// UpdateApp function is used with the -u function to output and also update past birthdays. this code also handles time left output
//
// It accomplishes this by using the current PC Date and matching it to see if a birthday has or has not happened yet. If it has not, it will leave it
// as is. If it has already, then it will increment to the next year intelligently. It can detect leap years
//
//
//

void updateApp()
{	
	char OUT1 [100];
	QString tempBirth;
	sprintf(OUT1,"\nName      \t Birthday   \t  Time Left\n========== \t ========== \t========================");
	puts(OUT1);
	int add;
	int foundUp = 0;
	QDate future;

	int whole = 0;
	double remainder = 0;

	int month = 0; // stores Time Left output
	int week = 0;
	int day = 0;

	future = PCNow.pcTime.addYears(1);
	//PCNow.pcTime.setDate(2016,03,03);
	//qDebug() << "future date" << future;

	//qDebug() << "\n" << "-------- updateApp -----------" << endl;

	// cycles through birthdays and sees if a birthday has already happened. 
	for (int i = 0; i<cycle; i++)
	{
		if (people[i].s_birthday > future)
		{
			people[i].s_birthday.setDate(PCNow.pcYear+1, people[i].s_month, people[i].s_day); // used for if a birthday was inputed far far ahead of current
			sortAr[foundUp].s_name = people[i].s_name; // sotres it into global array for sorting
			sortAr[foundUp].s_birthday = people[i].s_birthday; 
			foundUp++; // used for sorting function to know how many went in

		}
		if(!(people[i].s_birthday >= PCNow.pcTime))
		{
			add = PCNow.pcYear - people[i].s_year; // adds a certain number of years depending on how far the previous birthday was behind
			people[i].s_birthday = people[i].s_birthday.addYears(add);
			
			if(!(people[i].s_birthday >= PCNow.pcTime))
			{
				// if it was not enough, as in it is the 2016 year, it will add another
				people[i].s_birthday = people[i].s_birthday.addYears(1); // add another year
				
			}
			// outputs to global for sorting
			sortAr[foundUp].s_name = people[i].s_name;
			sortAr[foundUp].s_birthday = people[i].s_birthday;
			foundUp++;

		}
		

	}
	//qDebug() << "foundUp" << foundUp;

	// makes sure to run only if it found results
	if (!(foundUp == 0))
	{
		run = foundUp; // run is global and used in sorting function to keep track of how many there were
		sortDate(0); // we pass sort date a static 0 as its first position. It recursively runs the code by itself later

		// Final output of -u for updateApp. Calculates months, week and day as well
		for (int i = 0; i<run; i++)
		{
			remainder = 0; // uses double for the .# values
			whole = 0; // uses whole to subtract to get proper value

			// QDateTime is used to calculate days in between updates and then convert
			QDateTime startDate(PCNow.pcTime, QTime(0, 0, 0));
			QDateTime endDate(finalAr[i].s_birthday, QTime(0, 0, 0));
			//qDebug() << "\nDays from startDate to endDate: " << startDate.daysTo(endDate);
			whole = startDate.daysTo(endDate); 
			remainder = startDate.daysTo(endDate);
			//qDebug() << whole << remainder;

			remainder = remainder * 0.0328767; // we convert by a value to get months from days
			whole = whole * 0.0328767;
			//qDebug() << "Whole" << whole << "remainder" << remainder;
			if (remainder >= 1)
			{
				month = whole;
			}
			//qDebug() << "month" << month << "remainder" << remainder;
			remainder = remainder - whole;
			//qDebug() << "New update" << whole << remainder;
			remainder = remainder * 4.34524;
			whole = remainder;
			//qDebug() << "Whole" << whole << "remainder" << remainder;
			if (remainder >= 1)
			{
				week = whole;
			}
			//qDebug() << "week" << week << "remainder" << remainder;
			remainder = remainder - whole;
			//qDebug() << "New update" << whole << remainder;
			remainder = remainder * 7;
			whole = remainder;
			if (remainder >=1)
			{
				day = whole;
			}
			//qDebug() << "Month Week Day" << month << week << day;

			// FINAL OUTPUT of variables onto terminal

			tempBirth = finalAr[i].s_birthday.toString("yyyy-MM-dd");
			qDebug()<< qPrintable(finalAr[i].s_name) << "\t" << qPrintable(tempBirth) << "\t"<< month << "months,"<<week << "weeks,"<< day <<"days";
		}
	}
	else
	{
		// if nothing was found, it will output no birthdays
		sprintf(OUT1, "No birthdays Updated\n");
		puts(OUT1);

	}

}

	////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                                          Function Description:
//  initialAdd is called at the very beginning of the code to re-run and store the database in case of changes manually or by TA
//  it opens the files and set the device up for input/output. It then stores into StringList and then gets split to output
//
//  This is used as a 'constructor' of sorts for my array of structs Human that I made a variable of people for. It inputs 
//  the correct arguments into what I need
//

void initialAdd()
{

	QString name;
	QString birthday;

	QString bdayname = "birthdays.dat";
	//qDebug() << "\n" << "-------- initialAdd -----------" << endl;

	QFile file(bdayname);
	
	file.open(QIODevice::ReadWrite); // opens device. Will make file if it does not exist

	QTextStream in(&file); // pass in file

	GetTodayDate(); // I call function to grab todays date from here. Not actually needed but convenient place to run a function

	while (!in.atEnd()) // runs through full file
	{
		QString line = in.readLine();
		if (!(line.isEmpty() || line.isNull())) // makes sure it doesn't take in white space
		{
			QStringList seperate = line.split(","); // splits input 
			name = seperate[0]; // stores seperately
			birthday = seperate[1];
			//qDebug() << "add debug" << name << birthday;

			FileaddTolist(name, birthday); // calls sub-function to ACTUALLY add the variables it takes into the Array
		}

	}
	//qDebug() << "Finishes Add";

}

	////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                                          Function Description:
//   FileAddToList function is mainly used with InitialAdd(). This one here is meant to take in all the stuff passed to it from initialAdd
//   which are the name and birthday arguments from the .dat file and then actually store them into the array
//
//  It does a light re-checking of inputs here before storing it into my bins. It also does date conversion back and forth
//   Used to re-initiate my birthday reminder list
//

void FileaddTolist(QString nameF, QString birthdayF)
{
	//qDebug() << "\n" << "-------- FileaddTolist -----------" << endl;
	//qDebug() << "Passed in: " << nameF << birthdayF << endl;

	if (!(nameF.isEmpty() || (birthdayF.isEmpty()))) // checks to make sure data is valid again
	{
		people[cycle].s_name = nameF; // stores name

		people[cycle].s_birthday = QDate::fromString(birthdayF, "yyyy-MM-dd"); // converst from string to a QDate

		people[cycle].s_birthday.getDate(&people[cycle].s_year, &people[cycle].s_month, &people[cycle].s_day); // outputs human birthday to ints

		cycle++; // incrememnts cycle
	}

	/*
	people[cycle].s_birthday.setDate(PCNow.pcYear, people[cycle].s_month, people[cycle].s_day);

	if (people[cycle].s_birthday >= PCNow.pcTime)
	{
		//qDebug() << "Keeping Next: " << people[cycle].s_name << people[cycle].s_birthday << endl;
	}
	else
	{
		int add = 1;
		people[cycle].s_birthday = people[cycle].s_birthday.addYears(add);
		//qDebug() << "Make NEW Next: " << people[cycle].s_name << people[cycle].s_birthday << endl;
	}
	*/
	//qDebug() << "Array#: " << cycle << "\n" << people[cycle].s_name << "\n" << people[cycle].s_birthday << endl;
	//qDebug() <<"INT:  "<< people[cycle].s_year << people[cycle].s_month << people[cycle].s_day << endl;
	//qDebug() <<"Next:  " << people[cycle].s_birthday << endl;
	
}

	////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                                          Function Description:
//  Writecontents is used as one of my final arguments. It is used soley to write my data to the io stream output
//
// // it opens the file, makes sure data isnt' empty and then writes to it and closes
//
//
//

void WriteContents()
{
	//qDebug() << "\n" << "-------- WriteContents -----------" << endl;

	QFile file("birthdays.dat");
	file.open(QIODevice::WriteOnly);

	QString tempBirth;

	QTextStream out(&file);

	for (int i = 0; i<cycle; i++)
	{
		if(people[i].s_name.isEmpty()) // checks if it is empty. It won't run write function if it is
		{
			//qDebug() << "\n-- Empty at: i=" <<i << endl;
		}
		else
		{
			// converts QDate to QString
			tempBirth = people[i].s_birthday.toString("yyyy-MM-dd");
			out << people[i].s_name << "," << tempBirth << endl;
			//qDebug() << "\n-- Writing: i=" <<i << people[i].s_name << tempBirth << endl;
		}

	}
	file.close();
	
}


	////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                                          Function Description:
// Delete Entry is used just for the purpose of deleting a name from the list if it matches what it finds
//
//
//
//
//

void DeleteEntry(QString selection)
{
	//qDebug() << "\n" << "-------- DeleteEntry -----------" << endl;
	//qDebug() << "Passed in: " << selection;

	QString bdayEmpty; // used soley to clear the birthday
	bdayEmpty.clear();

	QString tempBirth;


	for (int i = 0; i<cycle; i++)
	{
		tempBirth = people[i].s_birthday.toString("yyyy-MM-dd");

		if (people[i].s_name == selection)
		{
			//qDebug() << "Name Delete";
			people[i].s_name.clear();
			people[i].s_birthday = QDate::fromString(bdayEmpty);

		}
		else if (tempBirth == selection)
		{
			//qDebug() << "Birth Delete";
			people[i].s_name.clear();
			people[i].s_birthday = QDate::fromString(bdayEmpty);
		}

	}
}


	////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                                          Function Description:
// 
//  Namepartialspec is used with the NAMESPEC function to find partial names and then sort the output alphabetically
//
//  Can print name in any order. Uses some functions from QChar
//
//

void NamePartialSpec(QString nSpec)
{
	//qDebug() << "\n" << "-------- NamePartialSpec -----------" << endl;
	//qDebug() << "Passed in: " << nSpec;
	int foundPer = 0;
	char OUT1 [50];
	QString tempBirth;

	sprintf(OUT1,"\nName      \t Birthday\n========== \t ==========");
	puts(OUT1);

	for (int i = 0; i<cycle; i++)
	{
		if(people[i].s_name.contains(nSpec, Qt::CaseSensitive))
		{
			//tempBirth = people[i].s_birthday.toString("yyyy-MM-dd");
			//qDebug()<< qPrintable(people[i].s_name) << "\t" << qPrintable(tempBirth);	
			sortAr[foundPer].s_name = people[i].s_name;
			sortAr[foundPer].s_birthday = people[i].s_birthday;	
			foundPer++;
		}
		//qDebug() << "RAN Contains: " << people[i].s_name;
	}
	if (!(foundPer == 0))
	{
		run = foundPer;
		sortName(0);
		for (int i = 0; i<run; i++)
		{
			tempBirth = finalAr[i].s_birthday.toString("yyyy-MM-dd");
			qDebug()<< qPrintable(finalAr[i].s_name) << "\t" << qPrintable(tempBirth);

		}
	}
	else
	{
		sprintf(OUT1, "No birthdays Found\n");
		puts(OUT1);

	}

	sprintf(OUT1, "\n");
	puts(OUT1);

}


	////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                                          Function Description:
// 
// Function that is used to sort names alphabetically. Takes in an item iterator it recursively runs through
//
//
//
//

void sortName(int item)
{
	//qDebug() << "\n" << "-------- sortName -----------" << endl;
	//qDebug() << "ITEM:"<< item << " RUN:" << run << " SMALL:" << small << endl;

	QString tempBirth;
	small = 0;
	int compareAware =0;

	QString bdayEmpty; // used soley to clear the birthday
	bdayEmpty.clear();

	QDate smallest = sortAr[0].s_birthday;
	QString smallName = sortAr[0].s_name;
	if ((item+1) == run)
	{
		finalAr[item].s_name = sortAr[0].s_name;
		finalAr[item].s_birthday = sortAr[0].s_birthday;
		small = 0;
	}
	else{

		for (int i = 1; i<run; i++){
			if(!(sortAr[i].s_name.isNull())){
				compareAware = QString::localeAwareCompare(sortAr[i].s_name,smallName);
				if(compareAware < 0)
				{
					small = i;
					//qDebug() << "  <  INDEX" <<i << "ITEM"<<item;
					//qDebug() << sortAr[i].s_name << "  Less Than   " << smallName;
					//qDebug() << sortAr[i].s_birthday << "Less Than" << smallest;
					smallest = sortAr[i].s_birthday;
					smallName = sortAr[i].s_name;
					//qDebug() << "SMALLEST= "<< smallName << smallest << "at "<<small;
					finalAr[item].s_name = sortAr[i].s_name;
					finalAr[item].s_birthday = sortAr[i].s_birthday;
					//qDebug() << "Selected" << finalAr[item].s_name << finalAr[item].s_birthday << endl;


				}
				else{
					//qDebug() << "  >  INDEX" <<i << "ITEM"<<item;
					//qDebug() << sortAr[i].s_name << "  Greater Than   " << smallName;
					//qDebug() << sortAr[i].s_birthday << "Greater Than" << smallest;
					smallest = sortAr[small].s_birthday;
					smallName = sortAr[small].s_name;
					//qDebug() << "SMALLEST= "<< smallName << smallest << "at "<<small;
					finalAr[item].s_name = sortAr[small].s_name;
					finalAr[item].s_birthday = sortAr[small].s_birthday;
					//qDebug() << "Selected" << finalAr[item].s_name << finalAr[item].s_birthday << endl;

				}
				tempBirth = sortAr[i-1].s_birthday.toString("yyyy-MM-dd");
				//qDebug() << "- SortGiven: " <<sortAr[i-1].s_name << tempBirth;
			}
		}

	}
	tempBirth = finalAr[item].s_birthday.toString("yyyy-MM-dd");
	//qDebug() << "     Small Out:  " <<qPrintable(finalAr[item].s_name) << "\t" << qPrintable(tempBirth);
	item++;
	//qDebug() << "DELETE: " << sortAr[small].s_name << sortAr[small].s_birthday;

	sortAr[small].s_name.clear();
	sortAr[small].s_birthday = QDate::fromString(bdayEmpty);
	//qDebug() << "\n" << "-------- ^^^^ -----------" << endl;


	for(int i = 0; i<run; i++){
		if(sortAr[i].s_name.isEmpty()){
			if(sortAr[i+1].s_name.isEmpty())
			{

			}
			else{

				sortAr[i].s_name = sortAr[i+1].s_name;
				sortAr[i].s_birthday = sortAr[i+1].s_birthday;
				sortAr[i+1].s_name.clear();
				sortAr[i+1].s_birthday = QDate::fromString(bdayEmpty);

			}
		}
		tempBirth = sortAr[i].s_birthday.toString("yyyy-MM-dd");
		//qDebug() << "SortGiven" << i << sortAr[i].s_name << tempBirth;
	}
	if (!(item == run))
	{
		sortName(item);
	}

}

	////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                                          Function Description:
// 
//  Function used for the -n function. It is used to find dates within the value passed in and output correctly
//
//
//
//



void WithinNumber(QString number)
{
	//qDebug() << "\n" << "-------- WithinNumber -----------" << endl;
	//qDebug() << "Passed in: " << number;
	int converted;
	QString tempBirth;

	int foundNum = 0;
	converted = number.toInt();
	//qDebug() << "Converted to: " << converted;

	char OUT1 [50];

	sprintf(OUT1,"\nName      \t Birthday\n========== \t ==========");
	puts(OUT1);

	for (int i = 0; i<cycle; i++)
	{
		QDateTime startDate(PCNow.pcTime, QTime(0, 0, 0));
		QDateTime endDate(people[i].s_birthday, QTime(0, 0, 0));
		//qDebug() << "\nDays from startDate to endDate: " << startDate.daysTo(endDate);
		if((startDate.daysTo(endDate) <= converted) && (startDate.daysTo(endDate) > 0) )
		{
			
			//qDebug() << qPrintable(people[i].s_name) << "\t" << qPrintable(tempBirth);

			sortAr[foundNum].s_name = people[i].s_name;
			sortAr[foundNum].s_birthday = people[i].s_birthday;

			//qDebug() << "SortGiven: " <<sortAr[foundNum].s_name << tempBirth;

			foundNum++;

		}
	}
	if (!(foundNum == 0))
	{
		run = foundNum;
		sortDate(0);
		for (int i = 0; i<run; i++)
		{
			tempBirth = finalAr[i].s_birthday.toString("yyyy-MM-dd");
			qDebug()<< qPrintable(finalAr[i].s_name) << "\t" << qPrintable(tempBirth);

		}
	}
	sprintf(OUT1, "\n");
	puts(OUT1);

	if (foundNum == 0)
	{
		sprintf(OUT1, "No birthdays Found\n");
		puts(OUT1);
	}

}

	////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                                          Function Description:
// Function used to sortDate by when it was in time. Is run recursively as well. Uses temp and final storage arrays for output
//
//
//
//
//

void sortDate(int item)
{
	//qDebug() << "\n" << "-------- sortDate -----------" << endl;
	//qDebug() << "ITEM:"<< item << " RUN:" << run << " SMALL:" << small << endl;

	QString tempBirth;
	QString bdayEmpty; // used soley to clear the birthday
	bdayEmpty.clear();
	small = 0;
	


	QDate smallest = sortAr[0].s_birthday;
	QString smallName = sortAr[0].s_name;
	if ((item+1) == run)
	{
		finalAr[item].s_name = sortAr[0].s_name;
		finalAr[item].s_birthday = sortAr[0].s_birthday;
		small = 0;
	}
	else
	{
		for (int i=1; i < run; i++)
		{
			if(!(sortAr[i].s_birthday.isNull()))
			{
				if (sortAr[i].s_birthday < smallest)
				{
					small = i;
					//qDebug() << "  <  INDEX" <<i << "ITEM"<<item;
					//qDebug() << sortAr[i].s_name << "  Less Than   " << smallName;
					//qDebug() << sortAr[i].s_birthday << "Less Than" << smallest;
					smallest = sortAr[i].s_birthday;
					smallName = sortAr[i].s_name;
					//qDebug() << "SMALLEST= "<< smallName << smallest << "at "<<small;
					finalAr[item].s_name = sortAr[i].s_name;
					finalAr[item].s_birthday = sortAr[i].s_birthday;
					//qDebug() << "Selected" << finalAr[item].s_name << finalAr[item].s_birthday << endl;
				}
				else
				{
					//qDebug() << "  >  INDEX" <<i << "ITEM"<<item;
					//qDebug() << sortAr[i].s_name << "  Greater Than   " << smallName;
					//qDebug() << sortAr[i].s_birthday << "Greater Than" << smallest;
					smallest = sortAr[small].s_birthday;
					smallName = sortAr[small].s_name;
					//qDebug() << "SMALLEST= "<< smallName << smallest << "at "<<small;
					finalAr[item].s_name = sortAr[small].s_name;
					finalAr[item].s_birthday = sortAr[small].s_birthday;
					//qDebug() << "Selected" << finalAr[item].s_name << finalAr[item].s_birthday << endl;
				}
				//tempBirth = sortAr[i-1].s_birthday.toString("yyyy-MM-dd");
				//qDebug() << "- SortGiven: " <<sortAr[i-1].s_name << tempBirth;
			}

		}

	}
	//tempBirth = finalAr[item].s_birthday.toString("yyyy-MM-dd");
	//qDebug() << "     Small Out:  " <<qPrintable(finalAr[item].s_name) << "\t" << qPrintable(tempBirth);
	item++;
	//qDebug() << "DELETE: " << sortAr[small].s_name << sortAr[small].s_birthday;
	sortAr[small].s_name.clear();
	sortAr[small].s_birthday = QDate::fromString(bdayEmpty);
	//qDebug() << "\n" << "-------- ^^^^ -----------" << endl;
	for(int i = 0; i < run; i++)
	{
		if(sortAr[i].s_name.isEmpty())
		{
			if(sortAr[i+1].s_name.isEmpty())
			{

			}
			else
			{
				sortAr[i].s_name = sortAr[i+1].s_name;
				sortAr[i].s_birthday = sortAr[i+1].s_birthday;

				sortAr[i+1].s_name.clear();
				sortAr[i+1].s_birthday = QDate::fromString(bdayEmpty);
			}

		}
		tempBirth = sortAr[i].s_birthday.toString("yyyy-MM-dd");
		//qDebug() << "SortGiven" << i << sortAr[i].s_name << tempBirth;
	}

	if (!(item == run))
	{
		sortDate(item);
	}

}


	////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                                          Function Description:
// 
// used for -m command. Does the same as -n but also takes in a name and searches for that
//
//
//
//
int PersonWithinNumber(QString nameP, QString numberP)
{
	qDebug() << "\n" << "-------- PersonWithinNumber -----------" << endl;
	qDebug() << "Passed in: " << nameP << numberP;

	QString tempName;
	QDate tempBirth;
	QString printBirth;

	int converted;
	int foundNum = 0; // used to see if a matching name was found
	int foundBday = 0; // used to see if any birthdays are within that day
	converted = numberP.toInt();
	//qDebug() << "Converted to: " << converted;
	char OUT1 [50];

	sprintf(OUT1,"\nName      \t Birthday\n========== \t ==========");
	puts(OUT1);

	for (int i = 0; i<cycle; i++)
	{
		if (nameP == people[i].s_name)
		{
			tempName = people[i].s_name;
			tempBirth = people[i].s_birthday;
			//qDebug() << "Temps: " << tempName << tempBirth;
			foundNum++;
		}
	}
	if (foundNum == 0)
	{
		sprintf(OUT1, "Name not Found\n");
		puts(OUT1);
		return 6; // error has occured. Name wasn't found
	}
	else
	{
		for (int i = 0; i<cycle; i++)
		{
			/*
			if(people[i].s_birthday < tempBirth)
			{
				int add = 1;
				people[i].s_birthday = people[i].s_birthday.addYears(add);
				//qDebug() << "Date Mod NExt: " << people[i].s_name << people[i].s_birthday;
			}
			*/
			QDateTime startDate(tempBirth, QTime(0, 0, 0));
			QDateTime endDate(people[i].s_birthday, QTime(0, 0, 0));
			//qDebug() << "\nDays from startDate to endDate: " << startDate.daysTo(endDate);
			if((startDate.daysTo(endDate) <= converted) && (startDate.daysTo(endDate) >= 0) )
			{
				sortAr[foundBday].s_name = people[i].s_name;
				sortAr[foundBday].s_birthday = people[i].s_birthday;
				//printBirth = people[i].s_birthday.toString("yyyy-MM-dd");
				//qDebug() << qPrintable(people[i].s_name) << "\t" << qPrintable(printBirth);
				foundBday++;
			}
		}
		if(foundBday == 0)
		{
			sprintf(OUT1, "No birthdays Found\n");
			puts(OUT1);
		}
		if (!(foundBday == 0))
		{
			QString dateString;

			run = foundBday;
			sortDate(0);
			for (int i = 0; i<run; i++)
			{
				dateString = finalAr[i].s_birthday.toString("yyyy-MM-dd");
				qDebug()<< qPrintable(finalAr[i].s_name) << "\t" << qPrintable(dateString);

			}
		}

		sprintf(OUT1, "\n");
		puts(OUT1);

	}

	return 0; // No problems occured
}


	////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                                          Function Description:
// 
// takes in todays date
//
//
//
//

void GetTodayDate()
{
	//qDebug() << "\n" << "-------- GetTodayDate -----------" << endl;

	PCNow.pcTime = QDate::currentDate();
	//qDebug() << "Current QDate: " << PCNow.pcTime;

	PCNow.pcTime.getDate(&PCNow.pcYear, &PCNow.pcMonth, &PCNow.pcDay);
	//qDebug() <<"PCNow.pcTime is: "<< PCNow.pcYear << PCNow.pcMonth << PCNow.pcDay;

}
