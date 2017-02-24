#include "mainwindow.h"
#include "ui_mainwindow.h"

// Globals
pthread_t prime_thread;
pthread_mutex_t myMutex;
quint64 firstPrime = 0, lastPrime = 0;

// Local Functions
void *findPrimes(void*);

// MainWindow Class functions
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    listModel = new myListModel(this);
    ui->setupUi(this);
    ui->primeResults->setModel(listModel);

    pthread_mutex_init(&myMutex, NULL);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::clearUI() {
    ui->primeCountField->clear();
    ui->progressBar->reset();

    pthread_mutex_lock(&myMutex);
    listModel->clear();
    pthread_mutex_unlock(&myMutex);
}

void MainWindow::updateEmiter(bool signalUI)
{
    emit updateUI(signalUI);
}

void MainWindow::on_startButton_clicked() {
    on_actionStart_triggered();
}

void MainWindow::on_stopButton_clicked() {
    on_actionStop_triggered();
}

void MainWindow::on_exitButton_clicked() {
    on_actionExit_triggered();
}

void MainWindow::on_actionStart_triggered() {
    clearUI();
    ui->actionStop->setEnabled(true);
    ui->actionStart->setEnabled(false);
    ui->stopButton->setEnabled(true);
    ui->startButton->setEnabled(false);

    firstPrime = QString::toULongLong(ui->fromFIeld->text());
    lastPrime = QString::toULongLong(ui->toField->text());

    pthread_create(prime_thread, NULL, findPrimes, NULL);

    ui->progressBar->setMinimum(0);
    ui->progressBar->setMaximum(lastPrime - firstPrime);

    pthread_detach(prime_thread);
}

void MainWindow::on_actionStop_triggered() {
    ui->actionStop->setEnabled(false);
    ui->actionStart->setEnabled(true);
    ui->stopButton->setEnabled(false);
    ui->startButton->setEnabled(true);

    pthread_mutex_lock(&myMutex);
    pthread_cancel(prime_thread);

    ui->primeCountField->setText(QString::number(listModel->rowCount(QModelIndex())));

    pthread_mutex_unlock(&myMutex);
}

void MainWindow::on_actionExit_triggered() {
    QApplication::quit();
}

void MainWindow::refreshUI(bool signalIn) {
    // Update progress bar
}

// Find primes function
void *findPrimes(void *) {
    // execute sieve of eratosthenes on a list of all our primes
    // Every time we find a prime we should update the UI, possibly with a signal
    // Once we found all the primes we want to do a final UI update and clean up our threads.
}
