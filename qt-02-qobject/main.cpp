#include <QCoreApplication>
#include <QDebug>

#include "human.hpp"

void printTreeInfo(QObject *parent)
{
    // TODO: print here info about all nodes
    Human* human = qobject_cast<Human*>(parent);

    qDebug() << parent->objectName()
             << "age: " << human->getAge()
             << "sex: " << human->getSex();

    for (int i = 0; i < human->children().length(); ++i) {
       printTreeInfo(human->children().at(i));
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Human* parent = new Human;

    // TODO: create here required hierarchy
    // parent = new Human;

    parent->setObjectName("Lucas Grey");
    parent->setAge(54);
    parent->setSex('M');

    Human* maryGray = new Human(parent);
    maryGray->setObjectName("Mary Grey");
    maryGray->setAge(28);
    maryGray->setSex('F');

    Human* jasonGray = new Human(parent);
    jasonGray->setObjectName("Jason Grey");
    jasonGray->setAge(32);
    jasonGray->setSex('M');

    Human* freadSmith = new Human(maryGray);
    freadSmith->setObjectName("Fread Smith");
    freadSmith->setAge(2);
    freadSmith->setSex('M');

    Human* janeSmith = new Human(maryGray);
    janeSmith->setObjectName("Jane Smith");
    janeSmith->setAge(2);
    janeSmith->setSex('F');

    Human* seanGray = new Human(jasonGray);
    seanGray->setObjectName("Sean Grey");
    seanGray->setAge(5);
    seanGray->setSex('M');

    Human* jessicaGray = new Human(jasonGray);
    jessicaGray->setObjectName("Jessica Grey");
    jessicaGray->setAge(1);
    jessicaGray->setSex('F');

    Human* hannahGray = new Human(jasonGray);
    hannahGray->setObjectName("Hannah Grey");
    hannahGray->setAge(1);
    hannahGray->setSex('F');


   // TODO: dump tree info using standard Qt method
    parent->dumpObjectTree();

    printTreeInfo(parent);

    // TODO: delete here what need only

    delete parent;

    return a.exec();
}
