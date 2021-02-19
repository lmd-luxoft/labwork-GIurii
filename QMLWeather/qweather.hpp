#ifndef QWEATHER_HPP
#define QWEATHER_HPP

#include <QObject>

class Qweather : public QObject
{
   Q_OBJECT

public:
   explicit Qweather(QObject *parent = nullptr);

   Q_PROPERTY(QString city READ city WRITE setCity NOTIFY cityChanged)
   Q_PROPERTY(QString currentWeather READ processWeather)
   Q_INVOKABLE void forceUpdate();

   QString city() const;
   void setCity(const QString& city);

signals:
   void cityChanged(QString City);
   void currentWeatherChanged(QString CurrentWeather);

private:
   QString processWeather();

   QString m_city;
   QString m_currentWeather;
};

#endif // QWEATHER_HPP
