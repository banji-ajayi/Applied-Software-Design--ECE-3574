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

	int backVal = 0;

	qDebug() << "\nARGC is: " << RealArgCount;
	try
	{
		QString firstArg, secondArg, thirdArg;
		firstArg = argv[1];
		secondArg = argv[2];
		thirdArg = argv[3];

		if (RealArgCount == 0) // no arguments means to read from birthdays.dat and output
		{
			initialAdd();
			WriteContents();
			Global_Error = 0;
		}
		else if (RealArgCount >= 5)
		{
			Global_Error = 1;
			throw defErr;
			
		}
		else
		{
			initialAdd(); // Re-Add files in current birthdays.dat file as this is recreated every time
			

			qDebug() << "\n" << "  ############# Running Argument ##############" << endl;

			qDebug() << "First: " << firstArg << "\nSecond: " <<secondArg << "\nThird: " << thirdArg;

			if ((RealArgCount == 1))
			{
				if ((firstArg.isEmpty()))
				{
					Global_Error = 3;
					throw defErr;
				}
				else
				{
					qDebug() << "\n	Argument : NAMESPEC" << endl;

					NamePartialSpec(firstArg);

				}
				
			}

			if (firstArg == "-a")
			{
				//Format should be   ./birthdays -a yyyy-MM-dd “John Smith”

				qDebug() << "\n	Argument : -a" << endl;

				FileaddTolist(thirdArg, secondArg);
			}

			if (firstArg == "-d")
			{
				// Format 1    ./birthdays -d "John Smith"
				// Format 2	   ./birthdays -d yyyy-MM-dd

				qDebug() << "\n	Argument : -d" << endl;

				DeleteEntry(secondArg);

			}

			if (firstArg == "-n")
			{
				// Format     ./birthdays -n 40 shows birthdays coming up in the next 40 days.
				qDebug() << "\n	Argument : -n" << endl;

				WithinNumber(secondArg);


			}

			if (firstArg == "-m")
			{
				// Format     ./birthdays -m "John Smith" 40 shows birthdays coming up in the next 40 days
				qDebug() << "\n	Argument : -m" << endl;

				backVal = PersonWithinNumber(secondArg, thirdArg);
				qDebug() << "Returned Val: " << backVal << endl;

			}

			if (firstArg == "-u")
			{
				qDebug() << "\n	Argument : -u" << endl;
				updateApp();

			}

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
		else if (Global_Error == 3)
		{
			qCritical() << "\nNAMESPEC command not valid. Provide Valid Input" << endl;
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

}

void updateApp()
{	
	qDebug() << "\n" << "-------- updateApp -----------" << endl;

	for (int i = 0; i<cycle; i++)
	{
		//people[i].s_Nextbirthday.setDate(PCNow.pcYear, people[i].s_month, people[i].s_day);

		if (people[i].s_birthday >= PCNow.pcTime)
		{
			// DO NOTHING
			qDebug() << "Keeping Next: " << people[i].s_name << people[i].s_Nextbirthday << endl;
		}
		else
		{
			int add = 1;
			people[i].s_birthday = people[i].s_birthday.addYears(add);
			qDebug() << "Make NEW Next: " << people[i].s_name << people[i].s_Nextbirthday << endl;
		}

	}

}




void FileaddTolist(QString nameF, QString birthdayF)
{
	//qDebug() << "\n" << "-------- FileaddTolist -----------" << endl;
	//qDebug() << "Passed in: " << nameF << birthdayF << endl;

	people[cycle].s_name = nameF;

	people[cycle].s_birthday = QDate::fromString(birthdayF, "yyyy-MM-dd");

	people[cycle].s_birthday.getDate(&people[cycle].s_year, &people[cycle].s_month, &people[cycle].s_day); // outputs human birthday to ints
	
	/*
	people[cycle].s_Nextbirthday.setDate(PCNow.pcYear, people[cycle].s_month, people[cycle].s_day);

	if (people[cycle].s_Nextbirthday >= PCNow.pcTime)
	{
		//qDebug() << "Keeping Next: " << people[cycle].s_name << people[cycle].s_Nextbirthday << endl;
	}
	else
	{
		int add = 1;
		people[cycle].s_Nextbirthday = people[cycle].s_Nextbirthday.addYears(add);
		//qDebug() << "Make NEW Next: " << people[cycle].s_name << people[cycle].s_Nextbirthday << endl;
	}
	*/
	//qDebug() << "Array#: " << cycle << "\n" << people[cycle].s_name << "\n" << people[cycle].s_birthday << endl;
	//qDebug() <<"INT:  "<< people[cycle].s_year << people[cycle].s_month << people[cycle].s_day << endl;
	//qDebug() <<"Next:  " << people[cycle].s_Nextbirthday << endl;
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
	qDebug() << "\n" << "-------- DeleteEntry -----------" << endl;
	qDebug() << "Passed in: " << selection;

	QString bdayEmpty; // used soley to clear the birthday
	bdayEmpty.clear();

	QString tempBirth;


	for (int i = 0; i<cycle; i++)
	{
		tempBirth = people[i].s_birthday.toString("yyyy-MM-dd");

		if (people[i].s_name == selection)
		{
			qDebug() << "Name Delete";
			people[i].s_name.clear();
			people[i].s_birthday = QDate::fromString(bdayEmpty);

		}
		else if (tempBirth == selection)
		{
			qDebug() << "Birth Delete";
			people[i].s_name.clear();
			people[i].s_birthday = QDate::fromString(bdayEmpty);
		}

	}
}

void NamePartialSpec(QString nSpec)
{
	qDebug() << "\n" << "-------- NamePartialSpec -----------" << endl;
	qDebug() << "Passed in: " << nSpec;


	for (int i = 0; i<cycle; i++)
	{
		if(people[i].s_name.contains(nSpec, Qt::CaseSensitive))
		{
			qDebug() << "RAN Contains: " << people[i].s_name;
		}
		else
		{
			//qDebug() << "Else Contains: " << people[i].s_name;
		}
		//qDebug() << "RAN Contains: " << people[i].s_name;

	}


}


int run = 0;

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
		QDateTime endDate(people[i].s_Nextbirthday, QTime(0, 0, 0));
		//qDebug() << "\nDays from startDate to endDate: " << startDate.daysTo(endDate);
		if(startDate.daysTo(endDate) <= converted)
		{
			
			//qDebug() << qPrintable(people[i].s_name) << "\t" << qPrintable(tempBirth);

			sortAr[foundNum].s_name = people[i].s_name;
			sortAr[foundNum].s_Nextbirthday = people[i].s_Nextbirthday;
			tempBirth = sortAr[foundNum].s_Nextbirthday.toString("yyyy-MM-dd");

			//qDebug() << "SortGiven: " <<sortAr[foundNum].s_name << tempBirth;

			foundNum++;

		}
	}
	run = foundNum;
	sortDate(0);
	for (int i = 0; i<run; i++)
	{
		tempBirth = finalAr[i].s_Nextbirthday.toString("yyyy-MM-dd");
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

int small;
void sortDate(int item)
{
	//qDebug() << "\n" << "-------- sortDate -----------" << endl;
	//qDebug() << "ITEM:"<< item << " RUN:" << run << " SMALL:" << small << endl;

	QString tempBirth;
	QString bdayEmpty; // used soley to clear the birthday
	bdayEmpty.clear();
	small = 0;
	


	QDate smallest = sortAr[0].s_Nextbirthday;
	QString smallName = sortAr[0].s_name;
	if ((item+1) == run)
	{
		finalAr[item].s_name = sortAr[0].s_name;
		finalAr[item].s_Nextbirthday = sortAr[0].s_Nextbirthday;
		small = 0;
	}
	else
	{
		for (int i=1; i < run; i++)
		{
			if(!(sortAr[i].s_Nextbirthday.isNull()))
			{
				if (sortAr[i].s_Nextbirthday < smallest)
				{
					small = i;
					//qDebug() << "  <  INDEX" <<i << "ITEM"<<item;
					//qDebug() << sortAr[i].s_name << "  Less Than   " << smallName;
					//qDebug() << sortAr[i].s_Nextbirthday << "Less Than" << smallest;

					smallest = sortAr[i].s_Nextbirthday;
					smallName = sortAr[i].s_name;

					//qDebug() << "SMALLEST= "<< smallName << smallest << "at "<<small;
					finalAr[item].s_name = sortAr[i].s_name;
					finalAr[item].s_Nextbirthday = sortAr[i].s_Nextbirthday;
					//qDebug() << "Selected" << finalAr[item].s_name << finalAr[item].s_Nextbirthday << endl;
				}
				else
				{
					//qDebug() << "  >  INDEX" <<i << "ITEM"<<item;
					//qDebug() << sortAr[i].s_name << "  Greater Than   " << smallName;
					//qDebug() << sortAr[i].s_Nextbirthday << "Greater Than" << smallest;

					smallest = sortAr[small].s_Nextbirthday;
					smallName = sortAr[small].s_name;
					//qDebug() << "SMALLEST= "<< smallName << smallest << "at "<<small;

					finalAr[item].s_name = sortAr[small].s_name;
					finalAr[item].s_Nextbirthday = sortAr[small].s_Nextbirthday;

					//qDebug() << "Selected" << finalAr[item].s_name << finalAr[item].s_Nextbirthday << endl;

				}
				

				//tempBirth = sortAr[i-1].s_Nextbirthday.toString("yyyy-MM-dd");
				//qDebug() << "- SortGiven: " <<sortAr[i-1].s_name << tempBirth;

			}

		}

	}
	

	//tempBirth = finalAr[item].s_Nextbirthday.toString("yyyy-MM-dd");
	//qDebug() << "     Small Out:  " <<qPrintable(finalAr[item].s_name) << "\t" << qPrintable(tempBirth);

	item++;

	//qDebug() << "DELETE: " << sortAr[small].s_name << sortAr[small].s_Nextbirthday;
	sortAr[small].s_name.clear();
	sortAr[small].s_Nextbirthday = QDate::fromString(bdayEmpty);
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
				sortAr[i].s_Nextbirthday = sortAr[i+1].s_Nextbirthday;

				sortAr[i+1].s_name.clear();
				sortAr[i+1].s_Nextbirthday = QDate::fromString(bdayEmpty);
			}

		}
		tempBirth = sortAr[i].s_Nextbirthday.toString("yyyy-MM-dd");

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
			tempBirth = people[i].s_Nextbirthday;
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
			if(people[i].s_Nextbirthday < tempBirth)
			{
				int add = 1;
				people[i].s_Nextbirthday = people[i].s_Nextbirthday.addYears(add);
				//qDebug() << "Date Mod NExt: " << people[i].s_name << people[i].s_Nextbirthday;
			}

			QDateTime startDate(tempBirth, QTime(0, 0, 0));
			QDateTime endDate(people[i].s_Nextbirthday, QTime(0, 0, 0));
			//qDebug() << "\nDays from startDate to endDate: " << startDate.daysTo(endDate);
			if(startDate.daysTo(endDate) <= converted)
			{
				sortAr[foundBday].s_name = people[i].s_name;
				sortAr[foundBday].s_Nextbirthday = people[i].s_Nextbirthday;
				//printBirth = people[i].s_Nextbirthday.toString("yyyy-MM-dd");
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
			dateString = finalAr[i].s_Nextbirthday.toString("yyyy-MM-dd");
			qDebug()<< qPrintable(finalAr[i].s_name) << "\t" << qPrintable(dateString);

		}
		sprintf(OUT1, "\n");
		puts(OUT1);

	}

	return 0; // No problems occured
}



void GetTodayDate()
{
	qDebug() << "\n" << "-------- GetTodayDate -----------" << endl;

	PCNow.pcTime = QDate::currentDate();
	qDebug() << "Current QDate: " << PCNow.pcTime;

	PCNow.pcTime.getDate(&PCNow.pcYear, &PCNow.pcMonth, &PCNow.pcDay);
	qDebug() <<"PCNow.pcTime is: "<< PCNow.pcYear << PCNow.pcMonth << PCNow.pcDay;

}
