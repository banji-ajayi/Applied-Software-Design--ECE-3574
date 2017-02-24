
using namespace std;

int main(int argc, char* argv[])
{
	if (argc != 3)
	{
		cout << "Too few arguments " << endl;
		exit (-1);
	}

	mqd_t mqMailbox;

	const char* mqIds[] = {"/70", "/71", "/72", "/73", "/74", "/75", "/76"};

	QString tempString(argv[1]);
	bool ok;
	const int instId = tempString.toInt(&ok);

	if(!ok || instId < 0 || instId > 6)
	{
		cout << "Invalid instance id " << tempString.toStdString() << endl;
		exit(-1);
	}

	tempString = argv[2];
	const float temperature = tempString.toFloat(&ok);
	if(!ok)
	{
		cout << "Invalid temperature " << tempString.toStdString() << endl;
		exit(-1);
	}

	struct mq_attr attr;
	attr.mq_flags = O_NONBLOCK;
	attr.mq_maxmsg = 10;
	attr.msgsize = 15;
	attr.mq_curmsgs = 0;

	// Looking at the signature of mq_open you can see the attributes you need
	mqMailbox = mq_open(mqIds[instId], O_NONBLOCK | O_RDONLY | O_CREAT | O_EXCL, 0666, &attr);

	if(mqMailbox == (mqd_t)-1)
	{
		cout << "Error creating mailbox: " << strerror(errno) << endl;
		exit(-1);
	}

	QList<const char*> upIds, dnIds;
	bool up = false, down = false;

	for (int i = 0; i<7; i++)
	{
		if(i != instId)
		{
			if (instId == 0 && (i == 1 || i == 2))
			{
				up = false;
				down = true;
			}
			else if (instId == 1 || instId == 2)
			{
				if (i == 0)
				{
					up = true;
					down = false;
				}
				else if (instId == 1 && (i == 3 || i == 4))
				{
					up = false;
					down = true;
				}
				else
				{
					up = false;
					down = false;
				}
			}
			else
			{
				if ((instId == 3 || instId == 4) && i == 1)
				{
					up = true;
					down = false;
				}
				else if ((instId == 5 || instId == 6) && i == 2)
				{
					up = true;
					down = false;
				}
				else
				{
					up = false;
					down = false;
				}
			}

			if (up)
			{
				upIds.append(mqIds[i]);
			}
			if (down)
			{
				dnIds.append(mqIds[i]);
			}
		}
	}

	MQManager manager(instId, temperature, mqMailbox, upIds, dnIds);

	if (instId == 0)
	{
		manager.start();
	}

	// This call returns ONLY once the process is over!

	manager.receiveTemp();
	mq_close(mqMailbox);
	mq_unlink(mqIds[instId]);

	return 0;




}
