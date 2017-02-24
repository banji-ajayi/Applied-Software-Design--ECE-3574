oid Billing::addBillingEntry(QString name, QString date, QString Starthour, QString Endhour)
{
	// convert the QString date into a QDate, and starhour and endhour into Qtime
	QDate newDate = QDate::fromString(date, "MM/dd/yy");
	QTime newStarthour = QTime::fromString(Starthour, "hh:mm");
	QTime newEndhour = QTime::fromString(Endhour, "hh:mm");
	
	
	// Invalid input checking
	// If the date entered is of valid year/month/date
	if (!newDate.isValid())
	{
		
		sm_cout << "The date " << date << " is invalid" << endl;
		return;
	}
	//If the starthour or endhour is of valid format
	if (!newStarthour.isValid())
	{
		sm_cout << "The Starthour " << Starthour << " is invalid" << endl;
		return;
	}
	
	//If the starthour or endhour is of valid format
	if (!newEndhour.isValid())
	{
		sm_cout << "The Endhour " << Endhour << " is invalid" << endl;
		return;
	}
	\
	else if (newDate > QDate::currentDate())
	{
		sm_cout << "The year must be in the past" <<endl;
		return;
	}
	
	else if (newStarthour > QTime::currentTime() || newEndhour > QTime::currentTime())
	{
		sm_cout << "The time must be in the past" << endl;
		return;
	}
	
	int posInsert = m_listBillingEntries.size();
	int confirmation = 25690;
	// Loop through each element, keeping track of an index variable
	// Compares billings and inserts the new bill record in chronological order.
	for ( int i = 0; i < m_listBillingEntries.size(); i++)
	{
		
		confirmation++;
		// get the nameDate
		QString element = m_listBillingEntries[i];
		
		//extract just the date
		QString elem = element.split(" ")[2];
		sm_cout << elem << endl;
		QString elem2 = element.split(" ")[3];
		sm_cout << elem2 << endl;
		QString elem3 = elem2.split("-")[0];
		sm_cout << elem3 << endl;
		QString elem4 = elem2.split("-")[1];
		sm_cout << elem4 << endl;
		// convert string to QDate in correct format
		QTime tmpstartTime = QTime::fromString(elem3, "hh:mm");
		QTime tmpendTime = QTime::fromString(elem4, "hh:mm");
		QDate tmpDate = QDate::fromString(elem, "MM/dd/yy");
		
		if (newDate < tmpDate )
		{
			sm_cout << "here" << endl;
			posInsert = i;
			QString confstring = QString::number(confirmation);
			
			// insert new Billing entry with correct index position
			QString newBillingEntry = confstring + " " + name + " " + date + " " + Starthour + "-" +Endhour;
			m_listBillingEntries.insert(posInsert, newBillingEntry);
			
			sm_cout << "The Billing entry for " << name << " has been added." << endl;
			
			break;
		}
		
		if ( newDate == tmpDate ) // compare dates
		{
			
			if ((newStarthour >= tmpstartTime && newEndhour <= tmpendTime) || (newStarthour <= tmpstartTime && newEndhour <=tmpendTime) || (newStarthour <= tmpstartTime && newEndhour >= tmpendTime) || (newStarthour >= tmpstartTime && newEndhour >= tmpendTime) )
			{
				sm_cout << "The time period overlaps a current billing record." << endl;
				break;
			}
			
			else {
				if ( newStarthour <tmpstartTime )
				{
					posInsert = i;
					
					QString confstring = QString::number(confirmation);
					
					// insert new Billing entry with correct index position
					QString newBillingEntry = confstring + " " + name + " " + date + " " + Starthour + "-" +Endhour;
					m_listBillingEntries.insert(posInsert, newBillingEntry);
					
					sm_cout << "The Billing entry for " << name << " has been added." << endl;
					
					break;
				}
			}
			
		}
	}
	
}
