#include <QCoreApplication>
#include <QFile>
#include <QDataStream>
#include <QTextStream>
#include <QMetaType>
#include <QVariant>
#include <QDebug>

#include "fraction.h"

/*
 * This example function allocate an object using the type system,
 * first queries for the class Fraction, than asks for the size such class
 * and then calls the (default) constructor.
 */
void createTest() {
  static int fracType = QMetaType::type("Fraction");
  void *vp = new char(QMetaType::sizeOf(fracType));
  QMetaType::construct(fracType, vp, 0);
  Fraction *fp = reinterpret_cast<Fraction*>(vp); //first use of reinterpret cast in the book

  fp->first = 1;
  fp->second = 2;
  Q_ASSERT(*fp == Fraction(1,2));

  delete [] (char *) vp; //return the memory
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qRegisterMetaType<Fraction>("Fraction");
    Fraction twoThirds(2, 3);
    QVariant var;
    var.setValue(twoThirds);
    Q_ASSERT(var.value<Fraction>() == twoThirds);

    Fraction oneHalf(1,2);
    Fraction threeQuarters(3,4);

    qDebug() << "QList<Fraction> to QVariant and back.";

    QList<Fraction> fractions;
    fractions << oneHalf << twoThirds << threeQuarters;

    QFile binaryTestFile("testMetaType.bin");
    binaryTestFile.open(QIODevice::WriteOnly);
    QDataStream dout(&binaryTestFile);
    dout << fractions;
    binaryTestFile.close();

    binaryTestFile.open(QIODevice::ReadOnly);
    QDataStream din(&binaryTestFile);
    QList<Fraction> fract2;
    din >> fract2;
    binaryTestFile.close();
    Q_ASSERT(fractions == fract2);

    qDebug() << "Using moc to allocate a class.";
    createTest();
    qDebug() << "If this output appears, all tests passed.";

    return EXIT_SUCCESS; //a.exec();
}

