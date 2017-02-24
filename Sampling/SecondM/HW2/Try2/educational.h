#ifndef EDUCATIONAL_H
#define EDUCATIONAL_H

#include "film.h"

enum Grade {A = 1, B = 2, C = 3, D = 4, F = 5};

class Educational : public Film {
    public:
        Educational(QString id, QString title, QString dir, quint32 len, QDate relDate, QString subject, Grade grade);
        Educational(QStringList propList);
        QString toString(bool labeled, QString sepchar);
    private:
        QString m_Subject;
        Grade m_GradeLevel;
};

#endif // EDUCATIONAL_H
