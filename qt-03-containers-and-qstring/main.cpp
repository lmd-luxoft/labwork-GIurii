#include <QCoreApplication>
#include <QDebug>
#include <QStack>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QList<QString> names;
    names << "Mary" << "Ann" << "Charlynn" << "Marylynn" << "Margaret"
          << "Kate" << "Rose" << "Gwendolyn";

    qDebug() << "Original list: " << names;


    // TODO: using Java-style iterators print the longest name from the list
    // use QString::arg to output message with this name

    QListIterator<QString> javaIterator(names);

    QString longestName{};

    while(javaIterator.hasNext()) {
       QString currentName = javaIterator.next();
       if (longestName.size() < currentName.size())
       {
          longestName = currentName;
       }
    }

    QString output("(JAVA Style)Longest name: %1");
    qDebug() << output.arg(longestName);



    // TODO: using STL-style iterators print the shortest name from the list
    // use QString::prepend and append to output message with this name

    QString shortestName(*names.begin());

    for(QList<QString>::const_iterator cIt = names.cbegin(); cIt != names.cend(); ++cIt) {
       QString currentName = *cIt;
       if (shortestName.size() > currentName.size())
       {
          shortestName = currentName;
       }
    }

    qDebug() << shortestName.prepend("(STL Style) Shortest name: ");


    // TODO: using foreach and QStringList show all names with "lynn" suffix
    // and print it separated by ',' as one string

    QStringList lynn;

    foreach (const QString& s, names) {
       if(s.contains("lynn")){
          lynn.append(s);
       }
    }

    qDebug() << "names with \"lynn\" suffix: " << lynn.join(", ");

    // print all names in reverse order
    // TODO: 1. Using QStack

    QStack<QString> stack;

    for(QList<QString>::reverse_iterator cIt = names.rbegin(); cIt != names.rend(); ++cIt) {
       stack.push(*cIt);
    }

    qDebug() << "1. Using QStack: " << stack.toList();


    // TODO: 2. Using other QList

    QList<QString> list(names.rbegin(), names.rend());

    qDebug() << "2. Using other QList: " << list.join(", ");

    // TODO: 3. Without other containers

    for (int size = names.size(), i = 0; i < size / 2; ++i) {
       names.swapItemsAt(i, size - i - 1);
    }

    qDebug() << "3. Without other containers: " << names.join(", ");

    return a.exec();
}
