#include "mainwindow.h"
#include "ui_mainwindow.h"

/////////////////Global Variables/////////////////////
QTextStream cout(stdout);
pthread_t tid; // input file1 thread id

struct node{
    int number;
    bool isPrime;
};

myWidget widget;
QList<node> intList; //list to hold all the numbers to check
QList<int> primeList; //list to hold all the prime numbers
pthread_mutex_t mutex; //mutex lock used on primeList
bool done = false; //set to true when all the primes have been found
int value1 =0, value2 =0; //beginning to ending value
int i = 0; //number of elements beteewn values entered in the GUI
int prevLength = 0;
//////////////////////////////////////////////////////
void *findPrimes(void*);
void deleteList(void*);
void unlock(void*);

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->actionStop->setEnabled(false); //default disabled
    ui->stopButton->setEnabled(false); //default disabled
    ui->progressBar->reset(); //clear progress bar at the beginning since it starts at 24%
    pthread_mutex_init(&mutex, NULL); //setup the mutex lock
    connect(&widget, SIGNAL(update(bool)), this, SLOT(slot_Update(bool)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void *findPrimes(void*) {
    pthread_cleanup_push(deleteList, NULL);

    //fill list with all the integers between the two values
    for(int k = value1; k <= value2; k++) {
        node tempNode;
        tempNode.number = k;
        tempNode.isPrime = true; //set all numbers initially to true
        intList.append(tempNode);
    }

    //Sieve of Eratosthenes
    for(i = 0; i <= (value2-value1); i++) {
        if (intList[i].isPrime == true) {
            for(int k = i+1; k <=(value2-value1) && intList[k].number > 2; k++) {
                if (intList[k].number % intList[i].number == 0)
                    intList[k].isPrime = false;
            }
            pthread_cleanup_push(unlock, (void*) &mutex);
            pthread_mutex_lock(&mutex);
            if (intList[i].number != 0) //don't let be 0 counted as a prime number
                primeList.append(intList[i].number);

            if (primeList.length() % 100 == 0) {
                widget.updateFunction(false); //only update occasionaly
            }

            pthread_cleanup_pop(1); //unlock the mutex since the thread wasn't asyncronously cancelled
        }

    }
    i--; //for loop will increment i one last time and then end, this screws up progress bar
    widget.updateFunction(true); //send true now that all primes have been found
    pthread_cleanup_pop(1); //run the deleteList cleanup handler
    pthread_exit(0);
}

void myWidget::updateFunction(bool finish) {
    emit update(finish);
}

void deleteList(void*) {
    cout << "Cleanup handler has been called, and memory has been deallocated." << endl;
    intList.clear();
}

void unlock(void* mut) {
    pthread_mutex_unlock((pthread_mutex_t*)mut);
}

void MainWindow::resetForms() {
    ui->primesEdit->clear();
    ui->counterEdit->clear();
    ui->solutionEdit->setText("Waiting for answer ...");
    ui->progressBar->reset();
    pthread_mutex_lock(&mutex); //lock mutex before doing anything with the primeList
    primeList.clear();
    pthread_mutex_unlock(&mutex); //unlock mutex after finishing with the primeList
    prevLength = 0;
    done = false; //reset to false now that we are restarting
}

void MainWindow::on_actionExit_triggered()
{
    exit(1);
}

void MainWindow::on_actionStart_triggered()
{
    resetForms();
    ui->actionStop->setEnabled(true); //enable after start is pressed
    ui->stopButton->setEnabled(true); //enable after start is pressed
    ui->actionStart->setEnabled(false); //disable after start is pressed
    ui->startButton->setEnabled(false); //disable after start is pressed
    value1 = ui->fromEdit->text().toInt();
    value2 = ui->toEdit->text().toInt();
    pthread_create(&tid, NULL, findPrimes, NULL);

    ui->progressBar->setMinimum(0); //set to match the way i works so that i can update it
    ui->progressBar->setMaximum(ui->toEdit->text().toInt() - ui->fromEdit->text().toInt());

    pthread_detach(tid); //substitute for join so that GUI thread isn't blocked
}

void MainWindow::on_actionStop_triggered()
{
    ui->actionStop->setEnabled(false); //disable after stop is pressed
    ui->stopButton->setEnabled(false); //disable after stop is pressed
    ui->actionStart->setEnabled(true); //enable after stop is pressed
    ui->startButton->setEnabled(true); //enable after stop is pressed
    pthread_mutex_lock(&mutex); //lock mutex before doing anything with the primeList
    pthread_cancel(tid);
    ui->counterEdit->setText(QString::number(primeList.length()));
    ui->solutionEdit->setText(QString::number(primeList.length()));
    pthread_mutex_unlock(&mutex); //unlock mutex after finishing with the primeList
    done = true;
}

void MainWindow::on_startButton_clicked()
{
    on_actionStart_triggered();
}

void MainWindow::on_stopButton_clicked()
{
    on_actionStop_triggered();
}

void MainWindow::on_exitButton_clicked()
{
    on_actionExit_triggered();
}

void MainWindow::slot_Update(bool finish) {
    pthread_mutex_lock(&mutex); //lock mutex before doing anything with the primeList

    if (finish) {
        ui->actionStop->setEnabled(false); //disable after finishing
        ui->stopButton->setEnabled(false); //disable after finishing
        ui->actionStart->setEnabled(true); //enable after finishing
        ui->startButton->setEnabled(true); //enable after finishing
        //search has completed, update number of primes found
        //don't need lock at this point because primes thread has exited
        ui->solutionEdit->setText(QString::number(primeList.length()));
    }

    if(primeList.length() != prevLength && !done) { //don't update if stop has been triggered
        for (int j = prevLength; j< primeList.length(); j++) {
            ui->progressBar->setValue(i); //global iterator of value other thread should be on
            ui->primesEdit->append(QString::number(primeList.at(j)));
            ui->counterEdit->setText(QString::number(primeList.length()));
        }
    }
    prevLength = primeList.length();
    pthread_mutex_unlock(&mutex); //unlock mutex after finishing with the primeList  
}
