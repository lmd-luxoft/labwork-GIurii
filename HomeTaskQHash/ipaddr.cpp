#include "ipaddr.hpp"

QString IpAddr::ip() const
{
   return mIp;
}

void IpAddr::setIp(const QString &ip)
{
   mIp = ip;
}

bool IpAddr::empty() const
{
   return mIp.isEmpty();
}
