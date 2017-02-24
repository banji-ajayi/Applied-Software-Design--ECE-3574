#include "mainwindow.h"
#include <QtGui>

MainWindow::MainWindow() {
    QVBoxLayout *myLayout = new QVBoxLayout();
    QSignalMapper *myMapper = new QSignalMapper(this);
    // Connect our signal mapper to a function which takes the int value of the button as a parameter
    connect(myMapper, SIGNAL(mapped(int)), this, SLOT(buttonEvent(int)));

    myTextEdit = new QTextEdit("Welcome to this program");
    QPushButton* quit = new QPushButton("Quit", this);
    QPushButton* advise = new QPushButton("Advise", this);
    QPushButton* weather = new QPushButton("Weather", this);
    QPushButton* reminder = new QPushButton("Reminder", this);

    // Add widgets to our vertical layout
    myLayout->addWidget(myTextEdit);
    myLayout->addWidget(advise);
    myLayout->addWidget(weather);
    myLayout->addWidget(reminder);
    myLayout->addWidget(quit);

    // Connect our buttons to signals and slots
    // Map each button to an int value
    myMapper->setMapping(advise, 0);
    connect(advise, SIGNAL(clicked()), myMapper, SLOT(map()));
    myMapper->setMapping(weather, 1);
    connect(weather, SIGNAL(clicked()), myMapper, SLOT(map()));
    myMapper->setMapping(reminder, 2);
    connect(reminder, SIGNAL(clicked()), myMapper, SLOT(map()));
    myMapper->setMapping(quit, 3);
    connect(quit, SIGNAL(clicked()), myMapper, SLOT(map()));

    prompt = new QCheckBox("Show this message again");
    prompt->setChecked(true);

    this->setWindowTitle("ECE 3574 Homework 6");
    this->setLayout(myLayout);
    this->show();
}

void MainWindow::buttonEvent(int button) {
    switch (button) {
    case 0: {
        QFile advFile("advice.dat");
        if (!advFile.open(QIODevice::ReadOnly))
            qDebug() << "Error: Unable to open file";
        QStringList fileLines = getLinesWithBreaks(advFile);
        int numLines = fileLines.length();
        int randLine = rand() % numLines;
        QString myMessage = "Advice: " + fileLines.at(randLine);
        myTextEdit->append(myMessage);
        break;
    }
    case 1: {
        QFile wthrFile("weather.dat");
        if (!wthrFile.open(QIODevice::ReadOnly))
            qDebug() << "Error: Unable to open file";
        QStringList fileLines = getLinesWithBreaks(wthrFile);
        int numLines = fileLines.length();
        int randLine = rand() % numLines;
        QString myMessage = "Weather: " + fileLines.at(randLine);
        myTextEdit->append(myMessage);
        break;
    }
    case 2: {
        QFile rmndFile("reminder.dat");
        if (!rmndFile.open(QIODevice::ReadOnly))
            qDebug() << "Error: Unable to open file";
        QStringList fileLines = getLinesWithBreaks(rmndFile);
        int numLines = fileLines.length();
        int randLine = rand() % numLines;
        QString message = fileLines.at(randLine);
        QMessageBox *myReminderBox = new QMessageBox(this);

        prompt->blockSignals(true);
        myReminderBox->addButton(prompt, QMessageBox::ActionRole);
        myReminderBox->addButton("OK", QMessageBox::RejectRole);
        myReminderBox->setIcon(QMessageBox::Information);
        myReminderBox->setModal(true);

        while (alreadyDisplayed.contains(message) && alreadyDisplayed.length() != numLines) {
            numLines = fileLines.length();
            randLine = rand() % numLines;
            message = fileLines.at(randLine);
        }
        if (alreadyDisplayed.length() != numLines) {
            prompt->setChecked(true);
            myReminderBox->setText(message);
            myReminderBox->exec();
            if (prompt->checkState() == Qt::Unchecked) {
                alreadyDisplayed.append(message);
            }
        }
        else
            myTextEdit->append("There are no more reminders.");
        break;
    }
    case 3: {
        QMessageBox *closeBox = new QMessageBox(this);
        closeBox->setStandardButtons(QMessageBox::Yes | QMessageBox::No);
        closeBox->setText("Are you sure you want to quit?");
        closeBox->setIcon(QMessageBox::Question);
        closeBox->setModal(true);
        int clicked = closeBox->exec();
        if (clicked == 16384)
            QApplication::quit();
    }
    }
}

QStringList MainWindow::getLinesWithBreaks(QFile &myFile) {
    QTextStream inFile(&myFile);
    QString line;
    QStringList lines;
    while (!inFile.atEnd()) {
        line = inFile.readLine();
        while (line.endsWith('\\')) {
            line.replace('\\',' ');
            line.append(inFile.readLine());
        }
        lines.append(line);
    }
    return lines;
}
