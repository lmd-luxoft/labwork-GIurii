#ifndef IPADDR_HPP
#define IPADDR_HPP

#include<QString>
#include <QHash>


class IpAddr
{
   QString mIp{};

public:
   IpAddr(const QString& str): mIp(str){}
   IpAddr(const char* str): mIp(str){}
   IpAddr(QString&& str): mIp(str){
      str.clear();
   }

   inline bool operator ==(const IpAddr &other) const;

   QString ip() const;
   void setIp(const QString &ip);
   bool empty() const;
};

inline bool IpAddr::operator ==(const IpAddr &other) const
{
   return mIp == other.ip();
}

inline uint qHash(const IpAddr& key, uint seed = 0)
{
   if (key.empty())
      return seed;
   else
      return qHash(key.ip(), seed);
}

#endif // IPADDR_HPP
