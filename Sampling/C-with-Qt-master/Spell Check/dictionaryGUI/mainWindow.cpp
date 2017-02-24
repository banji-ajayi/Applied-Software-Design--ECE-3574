// Matt Luckam
// 905660738
// mcl209@vt.edu
// ECE 3574
// Homework 3
// 2/26/13


#include "mainWindow.h"
#include "ui_mainWindow.h"
#include<QtGui>


//Constructor
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

//Destructor
MainWindow::~MainWindow()
{
    delete ui;
}

//opens file
void MainWindow::openFile()
{
    QString fileName = QFileDialog::getOpenFileName(this);
    if (!fileName.isEmpty())
    {
        loadFile(fileName);
    }
}

//loads file
void MainWindow::loadFile(const QString &fileName)
{
    QFile file(fileName);
    if (!file.open(QFile::ReadOnly | QFile::Text))
    {
        QMessageBox::warning(this, tr("Mian Window"),
                             tr("Cannot read file %1:\n%2.")
                             .arg(fileName).arg(file.errorString()));
        return;
    }

    myDictionary.clearWordCount();
    outputSpellCheck( fileName );
    if( m_numberOfWords >= 0)
    {
        outputMostUsedWords( m_numberOfWords );
    }

    setCurrentFile(fileName);


    //outputs N number of most used words if a dictionary is loaded
    if( DictionaryNotLoaded == false  )
    {
        outputMostUsedWords( m_numberOfWords );
    }

    statusBar()->showMessage(tr("File loaded"), 2000);

    FileNotLoaded = false;
}

//Saves file to current location
void MainWindow::saveFile(const QString &fileName)
{
    QFile file(fileName);
    if (!file.open(QFile::WriteOnly | QFile::Text))
    {
        QMessageBox::warning(this, tr("Mian Window"),
                             tr("Cannot write file %1:\n%2.")
                             .arg(fileName).arg(file.errorString()));
        return;
    }

    QTextStream out(&file);
    QApplication::setOverrideCursor(Qt::WaitCursor);
    out << ui->textEdit->toPlainText();
    QApplication::restoreOverrideCursor();
    setCurrentFile(fileName);

    statusBar()->showMessage(tr("File saved"), 2000);

}

//sets name of file being used as current file m_FileName
void MainWindow::setCurrentFile(const QString &fileName)
{
    m_FileName = fileName;
}

//Opens file when open is pushed
void MainWindow::on_actionOpen_triggered()
{
    openFile();
}

//Exits application when exit is pushed
void MainWindow::on_actionExit_activated()
{
    qApp->quit();
}

//When ComboBox value is changed the dictionary is changed
void MainWindow::on_dictionaryBox_currentIndexChanged(const QString &language)
{
    //does nothing if default it selected
    if( language == "Select a Dictionary")
    {
        return;
    }

    buildDictionary( language );

    //outputs document with incorrect words in red if the file has been loaded
    if( FileNotLoaded == false )
    {
        outputSpellCheck( m_FileName );
    }

    //output most used correct words if dictionary and file are loaded
    if( CountNotStarted == false && FileNotLoaded == false )
    {
        outputMostUsedWords( m_numberOfWords );
    }

}

//When spinbox value is changed number of most used words to ouput changes
void MainWindow::on_spinBox_valueChanged(int numberOfWords)
{

    //Checks that file is loaded and dictionary is compiled
    if( FileNotLoaded == false && DictionaryNotLoaded == false )
    {
        outputMostUsedWords( numberOfWords );
    }

    //if file is cloed and program is not quit most common word will not display
    if( FileNotLoaded == true )
    {
        ui->textEdit_2->clear();
    }

    m_numberOfWords = numberOfWords;
    CountNotStarted = false;
}

//saves when save is pushed
void MainWindow::on_actionSave_triggered()
{
    saveFile(m_FileName);
}

//Saves and allows change of directory and name when save as is pushed
void MainWindow::on_actionSave_As_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this);
    saveFile( fileName );
}

//clears both textedits and sets current file to empty
void MainWindow::on_actionClose_triggered()
{
    ui->textEdit->clear();
    ui->textEdit_2->clear();
    m_FileName = "";
    FileNotLoaded = true;
    myDictionary.clearWordCount();
}

//displays most used words into textEdit 2
void MainWindow::outputMostUsedWords( int numberOfWords )
{
    ui->textEdit_2->clear();
    QStringList outputCorrectWords;
    outputCorrectWords = myDictionary.correctWordCount( numberOfWords );

    //prevents crash from more words given than words exist
    for( int i = 0; i < outputCorrectWords.length(); i++ )
    {
        if( i < numberOfWords )
        {
            ui->textEdit_2->append( outputCorrectWords[i] );
        }
        else
        {
            break;
        }
    }
}

//outputs file with incorrect words in red
void MainWindow::outputSpellCheck( QString fileName )
{
    QString Output = myDictionary.isWord( fileName );
    QApplication::setOverrideCursor(Qt::WaitCursor);
    ui->textEdit->clear();
    ui->textEdit->append( Output );
    QApplication::restoreOverrideCursor();
}

//creates dictionary based on language given in dictionaryBox
void MainWindow::buildDictionary( QString language)
{
    if( language == "American-English")
    {
        Dictionary temp( QString( "/usr/share/dict/american-english" ) );
        myDictionary = temp;
        DictionaryNotLoaded = false;
        myDictionary.clearWordCount();
    }

    if( language == "British-English" )
    {
        Dictionary temp( QString( "/usr/share/dict/british-english" ) );
        myDictionary = temp;
        DictionaryNotLoaded = false;
        myDictionary.clearWordCount();
    }
}
