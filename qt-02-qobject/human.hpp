#ifndef HUMAN_HPP
#define HUMAN_HPP

#include <QObject>

class Human : public QObject
{
   Q_OBJECT
public:
   explicit Human(QObject *parent = nullptr);

   qint16 getAge() const;
   void setAge(const qint16 &value);

   char getSex() const;
   void setSex(const char value);

signals:

public slots:

private:
   qint16  age { 0 };
   char    sex { 'M' };
};

#endif // HUMAN_HPP
