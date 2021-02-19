#include "human.hpp"

Human::Human(QObject *parent) : QObject(parent)
{

}

qint16 Human::getAge() const
{
   return age;
}

void Human::setAge(const qint16 &value)
{
   age = value;
}

char Human::getSex() const
{
   return sex;
}

void Human::setSex(const char value)
{
   sex = value;
}
