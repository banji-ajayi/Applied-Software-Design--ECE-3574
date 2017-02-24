#include <QFile>
#include <QFileInfo>
#include <QDir>
#include <QString>
#include <QStringList>
#include <QTextStream>

QTextStream qtCout(stdout);
QStringList fileList;

void addFile(QString absoluteFilePath) {
  fileList << absoluteFilePath;
}

void recurseAddDir(QDir d, bool recursive=true, bool symlinks=false) {
  d.setSorting(QDir::Name);
  QDir::Filters df = QDir::Files | QDir::NoDotAndDotDot;
  
  if (recursive)
    df |= QDir::Dirs;
  if (not symlinks)
    df |= QDir::NoSymLinks;

  QStringList qsl = d.entryList(df, QDir::Name | QDir::DirsFirst);
  foreach (const QString &entry, qsl) {
    QFileInfo finfo(d, entry);
    if (finfo.isDir()) {
      QDir sd(finfo.absoluteFilePath());
      recurseAddDir(sd);
    } else {
      //if (finfo.completeSuffix() == "mp3")
        //addMp3File(finfo.absoluteFilePath());
	addFile(finfo.absoluteFilePath());
    }
  }
}

int main(int argc, char * argv[]) {
  QDir curDir = QDir::current();

  recurseAddDir(curDir);

  foreach (const QString &str, fileList) {
    qtCout <<  str << endl;
  }

  return EXIT_SUCCESS;
}

