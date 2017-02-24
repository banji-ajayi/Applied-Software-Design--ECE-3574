
#include <QVariant>
#include <QString>
#include <QTextStream>
#include <QDataStream>
#include <QUrl>
#include <QTime>
#include <QImage>
#include <QFile>

#include <QCoreApplication>

#include "metadatavalue.h"

QTextStream qtCout(stdout);

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QFile textFile("playlist1.tsv");
    QFile binaryFile("playlist1.bin");
    QTextStream textStream;
    QDataStream dataStream;

    if (textFile.open(QIODevice::ReadOnly)) {
        textStream.setDevice(&textFile);
        qtCout << "open text file for mdv" << endl;
    }
    else
        return EXIT_FAILURE;
    if (binaryFile.open(QIODevice::WriteOnly)) {
        dataStream.setDevice(&binaryFile);
        qtCout << "open binary file for mdv" << endl;
    }
    else
        return EXIT_FAILURE;

    QList<MetaDataValue> values;
    while (!textStream.atEnd()) {
        MetaDataValue mdv;
        textStream >> mdv;
        values << mdv;
        dataStream << mdv;
        qtCout << mdv;
    }
    textFile.close();
    binaryFile.close();

    if (binaryFile.open(QIODevice::ReadOnly)) {
        dataStream.setDevice(&binaryFile);
        for (int i=0; i<values.size(); ++i) {
            MetaDataValue mdv;
            dataStream >> mdv;
            if (mdv == values[i])
                qtCout << "mdv " << i << " is the same" << endl;
            else
                qtCout << "mdv " << i << " differs" << endl;
        }
    }
    binaryFile.close();

    return EXIT_SUCCESS;
}

