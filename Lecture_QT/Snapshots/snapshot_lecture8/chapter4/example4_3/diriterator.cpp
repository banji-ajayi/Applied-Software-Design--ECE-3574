#include <QDir>
#include <QDirIterator>
#include <QString>
#include <QStringList>
#include <QTextStream>

QTextStream qtCout(stdout);
QTextStream qtCerr (stderr);
QStringList fileList;

void addFile(QString absoluteFilePath) {
  fileList << absoluteFilePath;
}

void usage (void) {
  qtCout << "Either no arguments or a path" << endl;
}

int main(int argc, char* argv[]) {
  QDir dir = QDir::current();
  if (argc > 1) {
    dir = QDir(QString(argv[1]));
  }

  if (!dir.exists()) {
    qtCerr << dir.path() << " does not exist!" << endl;
    usage();
    return -1;
  }

  QDirIterator qdi(dir.absolutePath(),
    QStringList() << "*",
    QDir::NoSymLinks | QDir::Files,
    QDirIterator::Subdirectories);
  while (qdi.hasNext()) {
    addFile(qdi.next());
  }

  foreach (const QString &str, fileList) {
    qtCout <<  str << endl;
  }

  return 0;
}

