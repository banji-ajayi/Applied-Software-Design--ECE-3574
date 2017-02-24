#include <QtGui>

QStandardItemModel* createModel(QObject* parent, int rows, int cols, int childNodes)
{
    QStandardItemModel* model = new QStandardItemModel(rows, cols, parent);
    for (int r=0; r<rows; r++)
        for (int c=0; c<cols; c++) {
            QStandardItem * item = new QStandardItem(QString("Row:%0, Column:%1").arg(r).arg(c));
            if (c==0)
                for (int i=0; i<childNodes; i++) {
                    QStandardItem * child = new QStandardItem(QString("Item %0").arg(i));
                    item->appendRow(child);
                }
            model->setItem(r, c, item);
        }
    model->setHorizontalHeaderItem(0, new QStandardItem("Name"));
    model->setHorizontalHeaderItem(1, new QStandardItem("Value"));
    return model;
}
