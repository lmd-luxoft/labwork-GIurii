#ifndef HANDLER_HPP
#define HANDLER_HPP

#include <QObject>

class Handler : public QObject
{
   Q_OBJECT
public:
   explicit Handler(QObject *root, QObject *parent = nullptr);

public slots:
   void buttonHandler(QString str);

private:
   QObject *m_root;

};

#endif // HANDLER_HPP
