#include "mainWindow.h"
#include <QtGui>

mainWindow::mainWindow() {

    textEdit = new QTextEdit;
    setWindowTitle("HW4 Main Window");
    textEdit->append("Welcome to this program");

    QSignalMapper *signalMapper = new QSignalMapper(this);
    connect(signalMapper, SIGNAL(mapped(int)), this, SLOT(buttonPress(int)));

    buttons[0] = new QPushButton("Advise", this);
    buttons[1] = new QPushButton("Weather", this);
    buttons[2] = new QPushButton("Reminder", this);
    buttons[3] = new QPushButton("Quit", this);

    for (int i = 0; i < 4; ++i) {
        signalMapper->setMapping(buttons[i], i);
        connect(buttons[i], SIGNAL(clicked()), signalMapper, SLOT(map()));
    }

    QGridLayout *myLayout = new QGridLayout(this);
    myLayout->setMargin(10);
    myLayout->setSpacing(8);
    myLayout->addWidget(textEdit, 0, 0);

    for (int i = 0; i < 4; ++i)
        myLayout->addWidget(buttons[i], i+1, 0);

    this->setLayout(myLayout);
    this->show();
    prompt = new QCheckBox("Show this message again", this);
    prompt->setChecked(true); //default the checkbox to be already checked
}

void mainWindow::buttonPress(int buttonNumber) {
    //advice button
    if (buttonNumber == 0){
        QFile adviceFile("advice.dat");
        adviceFile.open(QIODevice::ReadOnly);
        QStringList lines = getFileStringList(adviceFile);
        int linesLength = lines.length();
        int randLineNumber = rand() % linesLength; //random number between 0 and lineLength
        QString displayLine = lines.at(randLineNumber);
        displayLine.prepend("Advice: ");
        textEdit->append(displayLine);
    }

    //weather button
    if (buttonNumber == 1) {
        QFile weatherFile("weather.dat");
        weatherFile.open(QIODevice::ReadOnly);
        QStringList lines = getFileStringList(weatherFile);
        int linesLength = lines.length();
        int randLineNumber = rand() % linesLength; //random number between 0 and lineLength
        QString displayLine = lines.at(randLineNumber);
        displayLine.prepend("Weather: ");
        textEdit->append(displayLine);
    }

    //reminder button
    if (buttonNumber == 2) {
        QFile reminderFile("reminder.dat");
        reminderFile.open(QIODevice::ReadOnly);
        QStringList lines = getFileStringList(reminderFile);
        int linesLength = lines.length();
        int randLineNumber = rand() % linesLength; //random number between 0 and lineLength
        QString displayLine = lines.at(randLineNumber);
        QMessageBox *reminderBox =new QMessageBox(this);

        prompt->blockSignals(true);
        reminderBox->addButton(prompt, QMessageBox::ActionRole);
        reminderBox->setModal(true); //prevent the rest of the application from being used while the dialog box is open
        reminderBox->setIcon(QMessageBox::Information);
        reminderBox->addButton("OK", QMessageBox::RejectRole);

        //randomly select new message while current message is on the do not display list and while
        //there are still messages that aren't on the do not display list
        while (dontDisplayMessages.contains(displayLine) && dontDisplayMessages.length() != linesLength) {
            int linesLength = lines.length();
            int randLineNumber = rand() % linesLength; //random number between 0 and lineLength
            displayLine = lines.at(randLineNumber);
        }
        if (dontDisplayMessages.length() != linesLength) {
            reminderBox->setText(displayLine);
            reminderBox->exec();
            if (prompt->checkState() == Qt::Unchecked) {
                dontDisplayMessages.append(displayLine);
            }
        }
    }

    //quit button
    if (buttonNumber == 3) {
        QMessageBox *quitBox =new QMessageBox(this);
        quitBox->setIcon(QMessageBox::Question);
        quitBox->setModal(true); //prevent the rest of the application from being used while the dialog box is open
        quitBox->setStandardButtons(QMessageBox::Yes | QMessageBox::No);
        quitBox->setText("Are you sure you want to quit?");
        int buttonClicked = quitBox->exec();
        if (buttonClicked == 16384) //0x00004000 for yes clicked
            exit(0);
    }
}

QStringList mainWindow::getFileStringList(QFile &file) {
    QTextStream fileIn(&file);
    QString line;
    QStringList lines;
    while (!fileIn.atEnd()) {
        line = fileIn.readLine();
        while (line.endsWith('\\')) {
            line.replace('\\',' ');
            line.append(fileIn.readLine());
        }
        lines.append(line);
    }
    return lines;
}
