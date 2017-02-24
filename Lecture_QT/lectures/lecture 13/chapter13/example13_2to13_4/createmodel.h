#ifndef CREATEMODEL
#define CREATEMODEL

class QObject;
class QStandardItemModel;

QStandardItemModel* createModel(QObject* parent=0, int rows=5, int cols=2, int childNodes =3);

#endif // CREATEMODEL

