#include <QCoreApplication>
#include <QHash>
#include <QDebug>
#include <QTextStream>
#include <ipaddr.hpp>


static QHash<IpAddr, QString> sites = {{"192.168.0.1", "youtube.com"},
                                          {"192.168.0.2", "www.google.com"},
                                          {"192.168.0.3", "apple.com"},
                                          {"192.168.0.4", "linkedin.com"},
                                          {"192.168.0.5", "microsoft.com"}};

QString getHostname(const QString& ip)
{
   return sites.value(ip, "There is no sites with provided ip.");
}


int main(int argc, char *argv[])
{
   QCoreApplication a(argc, argv);

   qDebug() << "Type ip: ";

   QTextStream stream(stdin);
   QString line = stream.readLine();

   qDebug() << getHostname(line);

   return a.exec();
}
