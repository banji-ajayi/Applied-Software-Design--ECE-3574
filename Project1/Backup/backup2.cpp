////////////////////////////////////////////////////////
// ECE 3574, Homework 1, Bowei Zhao
//
// File name: main.cpp
// Description: cpp main for birthday 
// Date: 2/5/2016
//
// *-----------------------------------------------* //

#include "birthdays.h"

struct Human
{
	QString s_name;
	QDate s_birthday;
	QDate s_Nextbirthday;
	int s_year;
	int s_month;
	int s_day;
};

Human people[100];
Human sortAr[100]; // make sortAr of Human Struct type. This temporary array will sort the output
Human finalAr[100];

struct CurrenTime
{
	QDate pcTime; // current system clock time
	int pcYear;
	int pcMonth;
	int pcDay;

}PCNow;


int Global_Error = 0; // used along with std::exception to produce error exceptions
int cycle = 0; // keeps track of iteration through loop
int maxval;
bool complete;

int main (int argc, char* argv[])
{
	int RealArgCount = argc-1;


	QString firstArg, secondArg, thirdArg;
	firstArg = argv[1];
	secondArg = argv[2];
	thirdArg = argv[3];

	QString NoString; // used soley to pass in an empty string as argument.
	NoString.clear();

	//qDebug() << "\nARGC is: " << RealArgCount;
	try
	{
		if (RealArgCount == 0) // no arguments means to read from birthdays.dat and output
		{
			initialAdd();
			QString str = "30";

			WithinNumber(str);

			WriteContents();
			Global_Error = 0;
		}
		else if (RealArgCount >= 4)
		{
			Global_Error = 1;
			throw defErr;
		}
		else
		{
			initialAdd(); // Re-Add files in current birthdays.dat file as this is recreated every time

			//qDebug() << "\n" << "  ############# Running Argument ##############" << endl;

			//qDebug() << "First: " << firstArg << "\nSecond: " <<secondArg << "\nThird: " << thirdArg;

			if ((RealArgCount == 1))
			{
				if ((firstArg.isEmpty()))
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

					NamePartialSpec(firstArg);
				}
			}
			if (firstArg == "-a")
			{
				if (!(RealArgCount == 3))
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
			if (firstArg == "-d")
			{
				// Format 1    ./birthdays -d "John Smith"
				// Format 2	   ./birthdays -d yyyy-MM-dd
				//qDebug() << "\n	Argument : -d" << endl;

				if (!(RealArgCount == 2))
				{
					Global_Error = 100;
					throw defErr;
				}

				if (!( ValidInput(secondArg, NoString)==0))
				{
					Global_Error = 4;
					throw defErr;
				}

				DeleteEntry(secondArg);
			}

			if (firstArg == "-n")
			{
				// Format     ./birthdays -n 40 shows birthdays coming up in the next 40 days.
				//qDebug() << "\n	Argument : -n" << endl;

				if (!(RealArgCount == 2))
				{
					Global_Error = 100;
					throw defErr;
				}

				if (!( ValidInput(secondArg, NoString)==0))
				{
					Global_Error = 5;
					throw defErr;
				}

				WithinNumber(secondArg);
			}

			if (firstArg == "-m")
			{
				// Format     ./birthdays -m "John Smith" 40 shows birthdays coming up in the next 40 days
				//qDebug() << "\n	Argument : -m" << endl;
				if (!(RealArgCount == 3))
				{
					Global_Error = 100;
					throw defErr;
				}

				if (!( ValidInput(secondArg, NoString)==0))
				{
					Global_Error = 7;
					throw defErr;
				}
				if (!( ValidInput(thirdArg, NoString)==0))
				{
					Global_Error = 7;
					throw defErr;
				}

				PersonWithinNumber(secondArg, thirdArg);

			}

			if (firstArg == "-u")
			{
				if (!(RealArgCount == 1))
				{
					Global_Error = 100;
					throw defErr;
				}
				//qDebug() << "\n	Argument : -u" << endl;
				updateApp();
			}
			char OutLine [50];
			sprintf(OutLine,"\n\n\n\n");
			puts(OutLine);
			// --------------------------------------------------------------------------
			// --- Files will finally be re-written back and be updated while doing so.
			WriteContents();
		}
	}
	catch (std::exception& e)
	{
		std::cerr << e.what();

		if (Global_Error == 1)
		{
			qCritical() << "\nInvalid Number of Inputs: You Gave too many inputs." << endl;
		}
		else if (Global_Error == 2)
		{
			qCritical() << "\nYour input is not valid. Date or Name not in right format" << endl;
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
			qCritical() << "\nNAMESPEC provided not Valid. Provide a valid name" << endl;
		}
		else if (Global_Error == 100)
		{
			qCritical() << "\nThe argument of"<< firstArg <<"does not have correct parameters";
			qCritical() << "You gave too many or too few. Try again" << endl;
		}
	}
}

int ValidInput(QString Nargument, QString Dargument)
{
	QDate tempBirth;
	QChar print;
	int lengthstrName;
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
			if (Nargument.at(i) == ' ')
			{
				NumSpace++;
				if (NumSpace > maxNum)
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
		if (NumSpace >=2)
		{
			return 2;
		}
	}

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
	}

	return 0;

}

void updateApp()
{	
	//qDebug() << "\n" << "-------- updateApp -----------" << endl;

	for (int i = 0; i<cycle; i++)
	{
		//people[i].s_birthday.setDate(PCNow.pcYear, people[i].s_month, people[i].s_day);

		if (people[i].s_birthday >= PCNow.pcTime)
		{
			// DO NOTHING
			//qDebug() << "Keeping Next: " << people[i].s_name << people[i].s_birthday << endl;
		}
		else
		{
			int add = 1;
			people[i].s_birthday = people[i].s_birthday.addYears(add);
			//qDebug() << "Make NEW Next: " << people[i].s_name << people[i].s_birthday << endl;
		}

	}

}

void initialAdd()
{

	QString name;
	QString birthday;

	QString bdayname = "birthdays.dat";
	//qDebug() << "\n" << "-------- initialAdd -----------" << endl;

	QFile file(bdayname);
	file.open(QIODevice::ReadOnly);

	QTextStream in(&file);

	GetTodayDate();

	while (!in.atEnd())
	{
		QString line = in.readLine();
		QStringList seperate = line.split(",");

		name = seperate[0];
		birthday = seperate[1];

		FileaddTolist(name, birthday);

	}
	//qDebug() << "Finishes Add";

}



void FileaddTolist(QString nameF, QString birthdayF)
{
	//qDebug() << "\n" << "-------- FileaddTolist -----------" << endl;
	//qDebug() << "Passed in: " << nameF << birthdayF << endl;

	people[cycle].s_name = nameF;

	people[cycle].s_birthday = QDate::fromString(birthdayF, "yyyy-MM-dd");

	people[cycle].s_birthday.getDate(&people[cycle].s_year, &people[cycle].s_month, &people[cycle].s_day); // outputs human birthday to ints
	
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
	cycle++;
}

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
int small;
int run = 0;

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
	run = foundPer;
	sortName(0);
	for (int i = 0; i<run; i++)
	{
		tempBirth = finalAr[i].s_birthday.toString("yyyy-MM-dd");
		qDebug()<< qPrintable(finalAr[i].s_name) << "\t" << qPrintable(tempBirth);

	}
	sprintf(OUT1, "\n");
	puts(OUT1);

}

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
	run = foundNum;
	sortDate(0);
	for (int i = 0; i<run; i++)
	{
		tempBirth = finalAr[i].s_birthday.toString("yyyy-MM-dd");
		qDebug()<< qPrintable(finalAr[i].s_name) << "\t" << qPrintable(tempBirth);

	}
	sprintf(OUT1, "\n");
	puts(OUT1);

	if (foundNum == 0)
	{
		sprintf(OUT1, "No birthdays Found\n");
		puts(OUT1);
	}

}


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
		QString dateString;

		run = foundBday;
		sortDate(0);
		for (int i = 0; i<run; i++)
		{
			dateString = finalAr[i].s_birthday.toString("yyyy-MM-dd");
			qDebug()<< qPrintable(finalAr[i].s_name) << "\t" << qPrintable(dateString);

		}
		sprintf(OUT1, "\n");
		puts(OUT1);

	}

	return 0; // No problems occured
}

void GetTodayDate()
{
	//qDebug() << "\n" << "-------- GetTodayDate -----------" << endl;

	PCNow.pcTime = QDate::currentDate();
	//qDebug() << "Current QDate: " << PCNow.pcTime;

	PCNow.pcTime.getDate(&PCNow.pcYear, &PCNow.pcMonth, &PCNow.pcDay);
	//qDebug() <<"PCNow.pcTime is: "<< PCNow.pcYear << PCNow.pcMonth << PCNow.pcDay;

}
