void sortDate(int item)
{
	qDebug() << "\n" << "-------- sortDate -----------" << endl;
	qDebug() << "ITEM:"<< item << " RUN:" << run << " SMALL:" << small << endl;

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
					qDebug() << "  <  INDEX" <<i << "ITEM"<<item;
					qDebug() << sortAr[i].s_name << "  Less Than   " << smallName;
					qDebug() << sortAr[i].s_birthday << "Less Than" << smallest;
					smallest = sortAr[i].s_birthday;
					smallName = sortAr[i].s_name;
					qDebug() << "SMALLEST= "<< smallName << smallest << "at "<<small;
					finalAr[item].s_name = sortAr[i].s_name;
					finalAr[item].s_birthday = sortAr[i].s_birthday;
					qDebug() << "Selected" << finalAr[item].s_name << finalAr[item].s_birthday << endl;
				}
				else
				{
					qDebug() << "  >  INDEX" <<i << "ITEM"<<item;
					qDebug() << sortAr[i].s_name << "  Greater Than   " << smallName;
					qDebug() << sortAr[i].s_birthday << "Greater Than" << smallest;
					smallest = sortAr[small].s_birthday;
					smallName = sortAr[small].s_name;
					qDebug() << "SMALLEST= "<< smallName << smallest << "at "<<small;
					finalAr[item].s_name = sortAr[small].s_name;
					finalAr[item].s_birthday = sortAr[small].s_birthday;
					qDebug() << "Selected" << finalAr[item].s_name << finalAr[item].s_birthday << endl;
				}
				tempBirth = sortAr[i-1].s_birthday.toString("yyyy-MM-dd");
				qDebug() << "- SortGiven: " <<sortAr[i-1].s_name << tempBirth;
			}

		}

	}
	tempBirth = finalAr[item].s_birthday.toString("yyyy-MM-dd");
	qDebug() << "     Small Out:  " <<qPrintable(finalAr[item].s_name) << "\t" << qPrintable(tempBirth);
	item++;
	qDebug() << "DELETE: " << sortAr[small].s_name << sortAr[small].s_birthday;
	sortAr[small].s_name.clear();
	sortAr[small].s_birthday = QDate::fromString(bdayEmpty);
	qDebug() << "\n" << "-------- ^^^^ -----------" << endl;
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
		qDebug() << "SortGiven" << i << sortAr[i].s_name << tempBirth;
	}

	if (!(item == run))
	{
		sortDate(item);
	}

}






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


	////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                                          Function Description:
// 
//
//
//
//
//