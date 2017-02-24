#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <QDate>
#include <QTime>
#include <QFile>
#include <QString>
#include <QStringList>
#include <QTextStream>
#include<QMap>
#include<QDebug>

using namespace std;

class Dictionary
{
private:
    //directs all output streamed into here, to stdout
    static QTextStream sm_cout;
    //stores all dictionary entires
    //QHash<QString, QString> m_Dictionary;
    QSet<QString> m_Dictionary;
    //stores correct words
    QMap<QString, int> m_CorrectWord;
    //stores incorrect words
    QMap<QString, int> m_incorrectWord;

    //Inserts word in correctWord or incorrectWord QMap
    //sorts word to CorrectWord or incorrectWord and writes output accordingly
    //parameters: InputWord word to sort
    //            outputFile output to be printed
    void helpIsWord( QString InputWord, QTextStream &buf );

    //helps output word fucntion
    // takes in returns of list of the most used words
    //parameters: QMap takes in CorrectWord or incorrectWord QMap
    //            int length of list of most used words to return
    QStringList helpWordCount(QMap<QString, int> wordType, int numberOfWords);


public:
    //Default Constructor
    Dictionary();
    //Paramaterized Constructor
    //build as dictionary
    //parameter: takes in a dictionary file
    Dictionary( QString fileName );
    //Destructor
    ~Dictionary();

    //determines if words in a file exist in the given dictionary
    //parameter: file that you want to read
    QString isWord( QString fileName );

    QString isWordFromString( QString String );

    //counts the number of occurances of each word
    //parameter: number of words to return
    QStringList correctWordCount( int numberOfWords );

    //counts the number of occurances of words not in the dictionary
    //parameter: number of incorrect words to return
    QStringList incorrectWordCount( int numberOfWords );

    //clears correct and incorrect word count
    void clearWordCount();

};

#endif
