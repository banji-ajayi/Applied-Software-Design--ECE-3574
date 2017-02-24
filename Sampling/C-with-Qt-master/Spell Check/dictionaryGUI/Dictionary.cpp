// Matt Luckam
// 905660738
// mcl209@vt.edu
// ECE 3574
// Homework 3
// 2/26/13

#include "Dictionary.h"


//default constructor
Dictionary::Dictionary()
{

}

//paramaterized constructor
Dictionary::Dictionary( QString fileName )
{
    QFile file ( fileName );
    file.open(QIODevice::ReadOnly);
    QTextStream readFile( &file );

    // read line by line and insert into a QMap
    while ( !readFile.atEnd() )
    {
        //removes all non alphanumeric characters from string
        QString input = (readFile.readLine() );

        //inputs word as key and data
        m_Dictionary.insert( input.toLower() );
    }

    file.close();
}

//Empties all structures
Dictionary::~Dictionary()
{
    m_Dictionary.clear();
    m_CorrectWord.clear();
    m_incorrectWord.clear();
}

//helper function to isWord
void Dictionary::helpIsWord(QString inputWord, QTextStream &buf)
{
    QString temp = inputWord;

    QString inputWordEdit = temp.remove( QRegExp( QString::fromUtf8( "[-`~!@#$%^&*()_—+=|:;<>«»,.?/{}\'\"\\\[\\\]\\\\]" ) ) ).toLower();

    if( inputWordEdit.toInt() != 0 )
    {
    }

    //checks that inputWordEdit is in dictionary
    else if(m_CorrectWord.contains( inputWordEdit ) || m_Dictionary.contains( inputWordEdit ))
    {
        //writes file in correct output format
        //outputFile.append( inputWord +  ' ' );

        buf << inputWord + ' ';

        //Checks if inputWordEdit is already used in file
        if( m_CorrectWord.contains( inputWordEdit ) )
        {
            //increments counter on inputWordEdit
            m_CorrectWord.insert( inputWordEdit, m_CorrectWord.value( inputWordEdit ) + 1 );
        }

        //If inputWordEdit is in dictionary and has not been used in file
        else
        {
            m_CorrectWord.insert( inputWordEdit, 1 );
        }
    }

    //If word is not in dictionary
    else if ( inputWordEdit != "" )
    {
        //writes file in correct output format
        buf<< "<font color = \"red\">" + inputWord + "</font>" + ' ';

        //Checks if inputWordEdit is already used in file
        if( m_incorrectWord.contains( inputWordEdit ) )
        {
            //increments counter on inputWordEdit
            m_incorrectWord.insert( inputWordEdit, m_incorrectWord.value( inputWordEdit ) + 1 );
        }

        //If inputWordEdit is not in dictionary and has not been used in file
        else
        {
            m_incorrectWord.insert( inputWordEdit, 1 );
        }
    }
}

//helper function to wordCount
QStringList Dictionary::helpWordCount(QMap<QString, int> wordType, int numberOfWords )
{
    QStringList returnTo;

    QList<QString> keysList = wordType.keys();
    QMap<int, QString> numericOrder;

    //inserts words in map in ascending numeric order
    for(int i = 0; i < keysList.size(); i++ )
    {
        numericOrder.insertMulti( wordType.value(keysList[i]), keysList[i] );
    }

    //Ouputs given number of most used words
    QMap<int, QString>::iterator it;
    int i = 0;
    for( it = ( numericOrder.end() - 1 ); it != numericOrder.begin(); it--)
    {
        //creates list of the N most used words
        if( i < numberOfWords )
        {
            QString insert = it.value() + ": " + QString::number( it.key() );

            returnTo.append( insert );
        }

        //breaks after i > N words to output
        else if( i >= numberOfWords)
        {
            break;
        }
        i++;
    }

    QString insert = it.value() +": " + QString::number( it.key() );
    returnTo.append( insert );

    return returnTo;
}

//determines if words in a file are in the dictionary
QString Dictionary::isWord( QString fileName )
{
    QString toReturn;

    //takes file and opens
    QFile file ( fileName );
    file.open( QIODevice::ReadOnly );
    QTextStream readFile( &file );
    QString message;    //maybe
    QTextStream buf( &message ); //maybe

    // read line by line and insert into a QMap
    while( !readFile.atEnd() )
    {
        QStringList inputLine =  readFile.readLine().split(' ');

        //reads individual lines
        for( int i = 0; i != inputLine.length(); i++)
        {

            //reads indivual words an removes punctuation
            QString inputWord = inputLine[i];

            //sorts words and keeps count of each occurance
            helpIsWord( inputWord, buf );
        }

        buf <<"<br>";
    }

    toReturn.append( &message );
    file.close();

    return toReturn;
}

// returns a list of N most used words
QStringList Dictionary::correctWordCount(int numberOfWords )
{
    QStringList returnTo;

    //prints n number of most used words
    returnTo = helpWordCount(m_CorrectWord, numberOfWords);

    return returnTo;
}

//returns a list on N most used words not in the dictionary
QStringList Dictionary::incorrectWordCount( int numberOfWords )
{
    QStringList returnTo;

    //prints n number of most used incorrect word
    returnTo = helpWordCount(m_incorrectWord, numberOfWords );

    return returnTo;
}

QString Dictionary::isWordFromString(QString String)
{
    QString toReturn;

    QString message;
    QTextStream buf( &message ); //maybe

    // read line by line and insert into a QMap

    QStringList inputLine =  String.split(' ');

    //reads individual lines
    for( int i = 0; i != inputLine.length(); i++)
    {

        //reads indivual words an removes punctuation
        QString inputWord = inputLine[i];

        //sorts words and keeps count of each occurance
        helpIsWord( inputWord, buf );
    }


    toReturn.append( &message );

    return toReturn;
}

void Dictionary::clearWordCount()
{
    m_CorrectWord.clear();
    m_incorrectWord.clear();
}
