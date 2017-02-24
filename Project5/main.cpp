////////////////////////////////////////////////////////
// ECE 3574, Homework 5, Bowei Zhao
//// inID: 905789193
// email: bowei@vt.edu
// File name: main.cpp
// Description: main implementation file
// Date: 4/09/2016
//
// *-----------------------------------------------* //
#include "message.h"


QTextStream outS(stdout); // output stream for standard output
QTextStream inS(stdin); // input stream for standard input
QTextStream errS(stderr); // error stream for standard error exception
void ProcessAllTemps();

int ID;
float parent_temp, down_temp, up_temp, child_a_temp, child_b_temp;
QString notification;
QString quitall = "quitall"; // tries to make other programs quit
bool flagQuitAll = false; // not really used

int main(int argc, char *argv[])
{ // local vars
	int loopquit = 0;
	int send_to_children = 1;
	// message boxes

	mqd_t mq70, mq71, mq72, mq73, mq74, mq75, mq76;
	bool notstable = true;
	char* RxGet = new char[8192]; // place to store the char from reception and transmission
    char* TxSend = new char();
    QString begin = "begin"; // radio messages to command other boxes to do stuff
    QString outputnow = "outputnow";

	QCoreApplication app(argc, argv); // used to create a seperate instance for error checking. 
    QStringList arginput = app.arguments();
	int initialSuccess = StartupErrorCheck(argc, arginput); // sneds to other function to check if valid
	//qDebug() << "\nSuccess reach with output StartupErrorCheck =" << initialSuccess << endl;

	bool initok;
	if (initialSuccess == 0) // if not successful. Program ends. 
	{
		return 0;
	}
	else if (flagQuitAll == true)
	{
		errS << "\nERROR: Was not able to create queue for IDs. Exiting" << endl;
		return 0;
	}
	else // else, the program is good so we start
	{
		// input values again
		ID = arginput[1].toInt(&initok, 10);
		parent_temp = arginput[2].toFloat(&initok);

		//qDebug() << "\nInput arguments: " << ID << parent_temp << endl;

		// perform actions depending on which ID value is sent in

		if (ID == 6)
		{
			// it opens up MQ 6 with the exact tags
			outS << "Process #" << ID << " : Initial Temperature " << parent_temp << endl;
			mq76 = mq_open("/76",  O_RDONLY | O_CREAT | O_EXCL, 0666, NULL);

			// if mq_open returns -1 and thus <0, then an error happened
			if (mq76 < 0)
			{

				errS << "\nERROR: Was not able to create queue for ID " << ID  << ". \n" 
				<< "Please manually close all terminal windows now with Ctrl+C and to \n"
				<< "manually delete the message queues in /dev/mqueue. Restart the program afterwards" << endl;
				//mq72 = mq_open("/72", O_RDWR, NULL, NULL);
				// close all boxes

	            mq_unlink("/70");
	            mq_close(mq70);
	            mq_unlink("/71");
	            mq_close(mq71);
	            mq_unlink("/72");
	            mq_close(mq72);
	            mq_unlink("/73");
	            mq_close(mq73);
	            mq_unlink("/74");
	            mq_close(mq74);
	            mq_unlink("/75");
	            mq_close(mq75);
	            mq_unlink("/76");
	            mq_close(mq76);
	            return 0;				
			}
			// waits in loop per application until a trigger message from MQD0 is sent alerting it to make the bool false
			// so it will then run other code
			while(notstable == true)
			{
				//qDebug() << "\nID " << ID <<" is not stable yet" << endl;
				// recceives messages from any other parent or children that wants to send it while in this loop
				mq_receive(mq76, RxGet, 8192, NULL);

				// converts the message to a readable string so we can use QString overloaded to compare

				notification = QString::fromLocal8Bit(RxGet);

				if (notification == "quitall")
				{
					qDebug() << "Sub ID " << ID << "quitting now" << endl;
		            mq_unlink("/70");
		            mq_close(mq70);
		            mq_unlink("/71");
		            mq_close(mq71);
		            mq_unlink("/72");
		            mq_close(mq72);
		            mq_unlink("/73");
		            mq_close(mq73);
		            mq_unlink("/74");
		            mq_close(mq74);
		            mq_unlink("/75");
		            mq_close(mq75);
		            mq_unlink("/76");
		            mq_close(mq76);
		            return 0;	

				}
				else if (notification == "begin")
				{ // checks for when begin is sent from the parent and thus then opens up protocal to them
					mq72 = mq_open("/72", O_RDWR, NULL, NULL);
				}
				else if (notification == "outputnow")
				{
					// if mq70 tells it to output, it will quit loop and plug final temp out
					notstable = false;
					outS << "Process #" << ID << " : Final Temperature " << parent_temp << endl;
				}
				else
				{
					// else it will do temperature conversions and output to the terminal. 
					ProcessAllTemps();

					outS << "Process #" << ID << " : Current Temperature " << parent_temp << endl;
					TxSend = QString::number(parent_temp).toLocal8Bit().data();
					mq_send(mq72, TxSend, 8192, 1);


				}
			}
		}
		else if (ID == 5)
		{
			outS << "Process #" << ID << " : Initial Temperature " << parent_temp << endl;
			mq75 = mq_open("/75",  O_RDONLY | O_CREAT | O_EXCL, 0666, NULL);
			if (mq75 < 0)
			{


				errS << "\nERROR: Was not able to create queue for ID " << ID  << ". \n" 
				<< "Please manually close all terminal windows now with Ctrl+C and to \n"
				<< "manually delete the message queues in /dev/mqueue. Restart the program afterwards" << endl;

	            mq_unlink("/70");
	            mq_close(mq70);
	            mq_unlink("/71");
	            mq_close(mq71);
	            mq_unlink("/72");
	            mq_close(mq72);
	            mq_unlink("/73");
	            mq_close(mq73);
	            mq_unlink("/74");
	            mq_close(mq74);
	            mq_unlink("/75");
	            mq_close(mq75);
	            mq_unlink("/76");
	            mq_close(mq76);	
	         	return 0;				
			
			}
			while (notstable == true)
			{
				//qDebug() << "\nID " << ID <<" is not stable yet" << endl;

				mq_receive(mq75, RxGet, 8192, NULL);

				notification = QString::fromLocal8Bit(RxGet);
				if (notification == "quitall")
				{
					qDebug() << "Sub ID " << ID << "quitting now" << endl;
		            mq_unlink("/70");
		            mq_close(mq70);
		            mq_unlink("/71");
		            mq_close(mq71);
		            mq_unlink("/72");
		            mq_close(mq72);
		            mq_unlink("/73");
		            mq_close(mq73);
		            mq_unlink("/74");
		            mq_close(mq74);
		            mq_unlink("/75");
		            mq_close(mq75);
		            mq_unlink("/76");
		            mq_close(mq76);
		            return 0;	

				}
				else if (notification == "begin")
				{
					mq72 = mq_open("/72", O_RDWR, NULL, NULL);
				}
				else if (notification == "outputnow")
				{
					notstable = false;
					outS << "Process #" << ID << " : Final Temperature " << parent_temp << endl;
				}
				else
				{
					ProcessAllTemps();


					outS << "Process #" << ID << " : Current Temperature " << parent_temp << endl;
					TxSend = QString::number(parent_temp).toLocal8Bit().data();
					mq_send(mq72, TxSend, 8192, 1);


				}
			}			

		}
		else if (ID == 4)
		{
			outS << "Process #" << ID << " : Initial Temperature " << parent_temp << endl;
			mq74 = mq_open("/74",  O_RDONLY | O_CREAT | O_EXCL, 0666, NULL);
			if (mq74 < 0)
			{


				errS << "\nERROR: Was not able to create queue for ID " << ID  << ". \n" 
				<< "Please manually close all terminal windows now with Ctrl+C and to \n"
				<< "manually delete the message queues in /dev/mqueue. Restart the program afterwards" << endl;

	            mq_unlink("/70");
	            mq_close(mq70);
	            mq_unlink("/71");
	            mq_close(mq71);
	            mq_unlink("/72");
	            mq_close(mq72);
	            mq_unlink("/73");
	            mq_close(mq73);
	            mq_unlink("/74");
	            mq_close(mq74);
	            mq_unlink("/75");
	            mq_close(mq75);
	            mq_unlink("/76");
	            mq_close(mq76);	
	            return 0;			
			}
			while (notstable == true)
			{
				//qDebug() << "\nID " << ID <<" is not stable yet" << endl;

				mq_receive(mq74, RxGet, 8192, NULL);
				notification = QString::fromLocal8Bit(RxGet);

				if (notification == "quitall")
				{
					qDebug() << "Sub ID " << ID << "quitting now" << endl;
		            mq_unlink("/70");
		            mq_close(mq70);
		            mq_unlink("/71");
		            mq_close(mq71);
		            mq_unlink("/72");
		            mq_close(mq72);
		            mq_unlink("/73");
		            mq_close(mq73);
		            mq_unlink("/74");
		            mq_close(mq74);
		            mq_unlink("/75");
		            mq_close(mq75);
		            mq_unlink("/76");
		            mq_close(mq76);
		            return 0;	

				}
				else if (notification == "begin")
				{
					mq71 = mq_open("/71", O_RDWR, NULL, NULL);
				}
				else if (notification == "outputnow")
				{
					notstable = false;
					outS << "Process #" << ID << " : Final Temperature " << parent_temp << endl;
				}
				else
				{
					ProcessAllTemps();


					outS << "Process #" << ID << " : Current Temperature " << parent_temp << endl;
					TxSend = QString::number(parent_temp).toLocal8Bit().data();
					mq_send(mq71, TxSend, 8192, 1);


				}
			}				
		}
		else if (ID == 3)
		{
			outS << "Process #" << ID << " : Initial Temperature " << parent_temp << endl;
			mq73 = mq_open("/73",  O_RDONLY | O_CREAT | O_EXCL, 0666, NULL);
			if (mq73 < 0)
			{

				errS << "\nERROR: Was not able to create queue for ID " << ID  << ". \n" 
				<< "Please manually close all terminal windows now with Ctrl+C and to \n"
				<< "manually delete the message queues in /dev/mqueue. Restart the program afterwards" << endl;	            mq_unlink("/70");
	            mq_close(mq70);
	            mq_unlink("/71");
	            mq_close(mq71);
	            mq_unlink("/72");
	            mq_close(mq72);
	            mq_unlink("/73");
	            mq_close(mq73);
	            mq_unlink("/74");
	            mq_close(mq74);
	            mq_unlink("/75");
	            mq_close(mq75);
	            mq_unlink("/76");
	            mq_close(mq76);	
	            return 0;			
			}
			while (notstable == true)
			{
				//qDebug() << "\nID " << ID <<" is not stable yet" << endl;

				mq_receive(mq73, RxGet, 8192, NULL);
				notification = QString::fromLocal8Bit(RxGet);

				if (notification == "quitall")
				{
					qDebug() << "Sub ID " << ID << "quitting now" << endl;
		            mq_unlink("/70");
		            mq_close(mq70);
		            mq_unlink("/71");
		            mq_close(mq71);
		            mq_unlink("/72");
		            mq_close(mq72);
		            mq_unlink("/73");
		            mq_close(mq73);
		            mq_unlink("/74");
		            mq_close(mq74);
		            mq_unlink("/75");
		            mq_close(mq75);
		            mq_unlink("/76");
		            mq_close(mq76);
		            return 0;	

				}
				else if (notification == "begin")
				{
					mq71 = mq_open("/71", O_RDWR, NULL, NULL);
				}
				else if (notification == "outputnow")
				{
					notstable = false;
					outS << "Process #" << ID << " : Final Temperature " << parent_temp << endl;
				}
				else
				{
					ProcessAllTemps();
					outS << "Process #" << ID << " : Current Temperature " << parent_temp << endl;
					TxSend = QString::number(parent_temp).toLocal8Bit().data();
					mq_send(mq71, TxSend, 8192, 1);


				}
			}			
		}
		else if (ID == 2)
		{
			outS << "Process #" << ID << " : Initial Temperature " << parent_temp << endl;

			mq72 = mq_open("/72",  O_RDONLY | O_CREAT | O_EXCL, 0666, NULL);
			mq75 = mq_open("/75", O_RDWR, NULL, NULL);
			mq76 = mq_open("/76", O_RDWR, NULL, NULL);

			if (mq72 < 0)
			{

				errS << "\nERROR: Was not able to create queue for ID " << ID  << ". \n" 
				<< "Please manually close all terminal windows now with Ctrl+C and to \n"
				<< "manually delete the message queues in /dev/mqueue. Restart the program afterwards" << endl;
				//mq70 = mq_open("/70", O_RDWR, NULL, NULL);

				while (flagQuitAll == false)
				{
					TxSend = quitall.toLocal8Bit().data();

		            mq_send(mq75, TxSend, 8192, 1); 
					mq_send(mq76, TxSend, 8192, 1);

					usleep(300000);

					loopquit++;
					if (loopquit >= 10)
					{
						flagQuitAll = true;
					}

				}
				loopquit = 0;
				errS << "\nExit success for ID: "<< ID << endl;

	            mq_unlink("/70");
	            mq_close(mq70);
	            mq_unlink("/71");
	            mq_close(mq71);
	            mq_unlink("/72");
	            mq_close(mq72);
	            mq_unlink("/73");
	            mq_close(mq73);
	            mq_unlink("/74");
	            mq_close(mq74);
	            mq_unlink("/75");
	            mq_close(mq75);
	            mq_unlink("/76");
	            mq_close(mq76);	
	            return 0;			
			}
			while (notstable == true)
			{
				//qDebug() << "\nID " << ID <<" is not stable yet" << endl;

				mq_receive(mq72, RxGet, 8192, NULL);				
				notification = QString::fromLocal8Bit(RxGet);

				mq70 = mq_open("/70", O_WRONLY, NULL, NULL);

				if (notification == "quitall")
				{
					qDebug() << "Sub ID " << ID << "quitting now" << endl;
		            mq_unlink("/70");
		            mq_close(mq70);
		            mq_unlink("/71");
		            mq_close(mq71);
		            mq_unlink("/72");
		            mq_close(mq72);
		            mq_unlink("/73");
		            mq_close(mq73);
		            mq_unlink("/74");
		            mq_close(mq74);
		            mq_unlink("/75");
		            mq_close(mq75);
		            mq_unlink("/76");
		            mq_close(mq76);
		            return 0;	

				}
				else if (notification == "begin")
				{
					TxSend = notification.toLocal8Bit().data();
	                mq_send(mq75, TxSend, 8192, 1);
	                mq_send(mq76, TxSend, 8192, 1); 
				}
				else if (notification == "outputnow")
				{
					notstable = false;
					TxSend = notification.toLocal8Bit().data();
	                mq_send(mq75, TxSend, 8192, 1);
	                mq_send(mq76, TxSend, 8192, 1); 
					outS << "Process #" << ID << " : Final Temperature " << parent_temp << endl;
				}
				else if (send_to_children == 1)
				{
					down_temp = (parent_temp + notification.toFloat())/2.0;
					parent_temp = down_temp;
					send_to_children = 0;
					TxSend = QString::number(parent_temp).toLocal8Bit().data();
	                mq_send(mq75, TxSend, 8192, 1);
	                mq_send(mq76, TxSend, 8192, 1); 

				}
				else
				{

					child_a_temp = notification.toFloat();
					mq_receive(mq72, RxGet, 8192, NULL);
					notification = QString::fromLocal8Bit(RxGet);
					child_b_temp = notification.toFloat();

					up_temp = (parent_temp + child_a_temp + child_b_temp) / 3;
					parent_temp = up_temp;

					send_to_children = 1;



					outS << "Process #" << ID << " : Current Temperature " << parent_temp << endl;
					TxSend = QString::number(parent_temp).toLocal8Bit().data();
					mq_send(mq70, TxSend, 8192, 1);


				}
			}			
		}
		else if (ID == 1)
		{
			outS << "Process #" << ID << " : Initial Temperature " << parent_temp << endl;

			mq71 = mq_open("/71",  O_RDONLY | O_CREAT | O_EXCL, 0666, NULL);
			mq73 = mq_open("/73", O_RDWR, NULL, NULL);
			mq74 = mq_open("/74", O_RDWR, NULL, NULL);

			if (mq71 < 0)
			{

				errS << "\nERROR: Was not able to create queue for ID " << ID  << ". \n" 
				<< "Please manually close all terminal windows now with Ctrl+C and to \n"
				<< "manually delete the message queues in /dev/mqueue. Restart the program afterwards" << endl;
				//mq70 = mq_open("/70", O_RDWR, NULL, NULL);

				while (flagQuitAll == false)
				{
					TxSend = quitall.toLocal8Bit().data();
					
		      		mq_send(mq73, TxSend, 8192, 1);
		            mq_send(mq74, TxSend, 8192, 1); 
	

					usleep(300000);
					loopquit++;
					if (loopquit >= 10)
					{
						flagQuitAll = true;
					}

				}
				loopquit = 0;
				errS << "\nExit success for ID: "<< ID << endl;

	            mq_unlink("/70");
	            mq_close(mq70);
	            mq_unlink("/71");
	            mq_close(mq71);
	            mq_unlink("/72");
	            mq_close(mq72);
	            mq_unlink("/73");
	            mq_close(mq73);
	            mq_unlink("/74");
	            mq_close(mq74);
	            mq_unlink("/75");
	            mq_close(mq75);
	            mq_unlink("/76");
	            mq_close(mq76);
	            return 0;				
			}
			while (notstable == true)
			{
				//qDebug() << "\nID " << ID <<" is not stable yet" << endl;

				mq_receive(mq71, RxGet, 8192, NULL);				
				notification = QString::fromLocal8Bit(RxGet);

				mq70 = mq_open("/70", O_WRONLY, NULL, NULL);

				if (notification == "quitall")
				{
					qDebug() << "Sub ID " << ID << "quitting now" << endl;
		            mq_unlink("/70");
		            mq_close(mq70);
		            mq_unlink("/71");
		            mq_close(mq71);
		            mq_unlink("/72");
		            mq_close(mq72);
		            mq_unlink("/73");
		            mq_close(mq73);
		            mq_unlink("/74");
		            mq_close(mq74);
		            mq_unlink("/75");
		            mq_close(mq75);
		            mq_unlink("/76");
		            mq_close(mq76);
		            return 0;	

				}
				else if (notification == "begin")
				{
					TxSend = notification.toLocal8Bit().data();
	                mq_send(mq73, TxSend, 8192, 1);
	                mq_send(mq74, TxSend, 8192, 1); 
				}
				else if (notification == "outputnow")
				{
					notstable = false;
					TxSend = notification.toLocal8Bit().data();
	                mq_send(mq73, TxSend, 8192, 1);
	                mq_send(mq74, TxSend, 8192, 1); 
					outS << "Process #" << ID << " : Final Temperature " << parent_temp << endl;
				}
				else if (send_to_children == 1)
				{
					down_temp = (parent_temp + notification.toFloat())/2.0;
					parent_temp = down_temp;
					send_to_children = 0;
					TxSend = QString::number(parent_temp).toLocal8Bit().data();
	                mq_send(mq73, TxSend, 8192, 1);
	                mq_send(mq74, TxSend, 8192, 1); 

				}
				else
				{

					child_a_temp = notification.toFloat();
					mq_receive(mq71, RxGet, 8192, NULL);
					notification = QString::fromLocal8Bit(RxGet);
					child_b_temp = notification.toFloat();

					up_temp = (parent_temp + child_a_temp + child_b_temp) / 3;
					parent_temp = up_temp;

					send_to_children = 1;


					outS << "Process #" << ID << " : Current Temperature " << parent_temp << endl;
					TxSend = QString::number(parent_temp).toLocal8Bit().data();
					mq_send(mq70, TxSend, 8192, 1);


				}
			}				
		}
		else if (ID == 0)
		{
			outS << "Process #" << ID << " : Initial Temperature " << parent_temp << endl;

			//qDebug() << "First 0 instance" << endl;
			mq70 = mq_open("/70",  O_RDONLY | O_CREAT | O_EXCL, 0666, NULL);
			mq71 = mq_open("/71", O_RDWR, NULL, NULL);
			mq72 = mq_open("/72", O_RDWR, NULL, NULL);

			TxSend = begin.toLocal8Bit().data();
            mq_send(mq71, TxSend, 8192, 1);
            mq_send(mq72, TxSend, 8192, 1); 

			TxSend = QString::number(parent_temp).toLocal8Bit().data();
            mq_send(mq71, TxSend, 8192, 1);
            mq_send(mq72, TxSend, 8192, 1); 


			//qDebug() << "Second 0 instance" << endl;
			mq70 = mq_open("/70", O_RDWR, 0666, NULL);
			mq71 = mq_open("/71", O_RDWR, NULL, NULL);
			mq72 = mq_open("/72", O_RDWR, NULL, NULL);

			if (mq70 < 0)
			{
				flagQuitAll = true;

				errS << "\nERROR: Was not able to create queue for ID " << ID  << ". \n" 
				<< "Please manually close all terminal windows now with Ctrl+C and to \n"
				<< "manually delete the message queues in /dev/mqueue. Restart the program afterwards" << endl;

				TxSend = quitall.toLocal8Bit().data();
				mq_send(mq71, TxSend, 8192, 1);
	            mq_send(mq72, TxSend, 8192, 1); 

	            mq_unlink("/70");
	            mq_close(mq70);
	            mq_unlink("/71");
	            mq_close(mq71);
	            mq_unlink("/72");
	            mq_close(mq72);
	            mq_unlink("/73");
	            mq_close(mq73);
	            mq_unlink("/74");
	            mq_close(mq74);
	            mq_unlink("/75");
	            mq_close(mq75);
	            mq_unlink("/76");
	            mq_close(mq76);
	            return 0;				
			}
			while (notstable == true)
			{
				//qDebug() << "\nID " << ID <<" is not stable yet" << endl;

				mq_receive(mq70, RxGet, 8192, NULL);				
				notification = QString::fromLocal8Bit(RxGet);

				child_a_temp = notification.toFloat();
				mq_receive(mq70, RxGet, 8192, NULL);

				notification = QString::fromLocal8Bit(RxGet);
				child_b_temp = notification.toFloat();

				up_temp = (parent_temp + child_a_temp + child_b_temp) / 3;
				down_temp = up_temp;

				float compareT = parent_temp - up_temp;

				//qDebug() << "Prev compareT " << compareT << endl;
				
				if (compareT < 0)
				{
					compareT = compareT*(-1);
					//qDebug() << "Abs compareT " << compareT << endl;
				}

				if (compareT < 0.01)
				{
					//qDebug() << " RAN compareT < 0.01" << endl;
					parent_temp = up_temp;
					notstable = false;

					outS << "Process #" << ID << " : Final Temperature " << parent_temp << endl;
					TxSend = outputnow.toLocal8Bit().data();
					mq_send(mq71, TxSend, 8192, 1);
					mq_send(mq72, TxSend, 8192, 1);

				}
				

				else if (notification == "quitall")
				{
					qDebug() << "Sub ID " << ID << "quitting now" << endl;
		            mq_unlink("/70");
		            mq_close(mq70);
		            mq_unlink("/71");
		            mq_close(mq71);
		            mq_unlink("/72");
		            mq_close(mq72);
		            mq_unlink("/73");
		            mq_close(mq73);
		            mq_unlink("/74");
		            mq_close(mq74);
		            mq_unlink("/75");
		            mq_close(mq75);
		            mq_unlink("/76");
		            mq_close(mq76);
		            return 0;	

				}
				else
				{
					//qDebug() << "Ran else" << endl;
					parent_temp = up_temp;
					outS << "Process #" << ID << " : Current Temperature " << parent_temp << endl;
					TxSend = QString::number(parent_temp).toLocal8Bit().data();
					mq_send(mq71, TxSend, 8192, 1);
					mq_send(mq72, TxSend, 8192, 1);

				}


			}				

		}
	}

    mq_unlink("/70");
    mq_close(mq70);
    mq_unlink("/71");
    mq_close(mq71);
    mq_unlink("/72");
    mq_close(mq72);
    mq_unlink("/73");
    mq_close(mq73);
    mq_unlink("/74");
    mq_close(mq74);
    mq_unlink("/75");
    mq_close(mq75);
    mq_unlink("/76");
    mq_close(mq76);

	return 0;
}

void ProcessAllTemps()
{
	down_temp = (parent_temp + notification.toFloat())/2.0;
	parent_temp = down_temp;
	up_temp = down_temp;
}