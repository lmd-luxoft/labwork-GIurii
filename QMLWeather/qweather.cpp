#include "qweather.hpp"

Qweather::Qweather(QObject *parent) : QObject(parent)
{
}

void Qweather::forceUpdate()
{
   // simulation weather service
   if (0 == m_city.compare("Saint Peterburg"))
   {
      m_currentWeather = "Температура -" + QString::number(std::rand() % 20) + " градусов";
   }
   else if (0 == m_city.compare("Odessa"))
   {
      m_currentWeather = "Температура +" + QString::number(std::rand() % 20) + " градусов";
   }
   else
   {
      m_currentWeather = "No city found";
   }
   emit currentWeatherChanged(m_currentWeather);
}

QString Qweather::city() const
{
   return m_city;
}

void Qweather::setCity(const QString& city)
{
   if (m_city == city)
      return;

   m_city = city;
   emit forceUpdate();
}

QString Qweather::processWeather()
{
   return m_currentWeather;
}
