
class Person : public QObject {
public:
    explicit Person(QString name, QObject* parent = 0); // Person(QString name, QObject* parent = 0);
    Person(const Person& p)
//        : QObject(p){ } //ERROR QObject copy constructor is private
        : QObject(p.parent()) { //NOTE this will create another QObject<-Person with the same parent
        this->setObjectName(QString("%1_cc").arg(p.objectName()));
    }
    virtual ~Person();
};
