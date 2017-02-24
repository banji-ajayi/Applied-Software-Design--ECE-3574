#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"Dictionary.h"

// forward declarations
class QLabel;
class QTextEdit;
class QSplitter;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    Ui::MainWindow *ui;
    //Dictionary for display window
    Dictionary myDictionary;
    //prevents spellcheck and wordcount from acting on file before it is loaded
    bool FileNotLoaded;
    //prevents spellcheck and wordcount from acting on dictionary before it is loaded
    bool DictionaryNotLoaded;
    //prevents wordcount from acting on spellcheck before it is loaded
    bool CountNotStarted;
    //number of correct words to output
    int m_numberOfWords;
    //name of current file being used
    QString m_FileName;

    //loads file
    //Parameter: fileName - file to load
    virtual void loadFile(const QString &fileName);
    //sets current file to m_FileName
    //Parameter: fileName - file to set as current
    virtual void setCurrentFile(const QString &fileName);
    //saves current file in current location
    //Paramter: fileName - file to save
    virtual void saveFile(const QString &fileName);
    //opens file
    virtual void openFile();
    //Outputs most used words
    //parameters: numberOfWords - word count to output
    void outputMostUsedWords( int numberOfWords );
    //Outputs spell check
    //parameters: fileName - file to spellcheck
    void outputSpellCheck( QString fileName );
    //Creates dictionary from dictionaryBox selection
    //parameters: language - file from dictionaryBox
    void buildDictionary( QString language);

private slots:
    //allows file to textEdit when Open is pushed and file is selected
    void on_actionOpen_triggered();
    //closes mainwindow when exit is pushed
    void on_actionExit_activated();
    //changes dictionary being used when comboBox value is changed between to acceptable values
    //Parameter: language - dictionary language to load
    void on_dictionaryBox_currentIndexChanged(const QString &language);
    //changes number of correct words to display in textEdit2 from 0-1000
    //Parameter: numberOfWords - number of most common words to display
    void on_spinBox_valueChanged(int numberOfWords);
    //when save is pushed file is saved in current location
    void on_actionSave_triggered();
    //when save as is pushed a locationa and filename can be chosen for the file
    void on_actionSave_As_triggered();
    //closes textEdit  but doesnt exit program
    void on_actionClose_triggered();

public:
    //Constructor
    explicit MainWindow(QWidget *parent = 0);
    //Destructor
    ~MainWindow();
};

#endif // MAINWINDOW_H
