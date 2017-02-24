




#include <pthread.h>
#include <mqueue.h>
#include <errno.h>
#include <QString>
#include <QTextStream>
#include <QStringList>
#include <QDebug>
#include <QByteArray>

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

void MQManager::start()
{
	if(m_InstId == 0)
	{
		openMailboxes();
		for(int i=0;i<m_DownMailboxes.size();i++)
		{
			sendTemp(m_DownMailboxes[i]);
		}
		m_Begun = true;
	}
}

void MQManager::processDownTemp(float temp)
{
	m_PrevTemp = m_Temp;
	m_Temp = (temp + m_Temp)/2.0;
	sendTempDown();
}


bool MQManager::processUpTemp(float temp)
{
	static int count = 0;
	static float temp_a = 0;

	if (count == 0)
	{
		temp_a = temp;
		count++;
		return false;
	}
	else
	{
		m_PrevTemp = m_Temp;
		m_Temp = (temp_a + temp + m_Temp)/3;
		cout << "Process a " << m_InstId << ": current Temperature " << m_Temp << endl;
		sendTempUp();
		count = 0;
		return true;
	}
}

void MQManager::processTemp(float temp)
{
	static bool down = (m_InstId == 0) ? false : true;
	if(down)
	{
		processDownTemp(temp);
		down = (m_InstId <= 2) ? false : true;
		// blah blah more. 
	}
}

