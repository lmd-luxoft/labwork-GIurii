#include "handler.hpp"
#include <QDebug>
Handler::Handler(QObject *root, QObject *parent) : QObject(parent), m_root(root)
{
   QObject *pmyButton = m_root->findChild<QObject*>("myButton");
   connect(pmyButton, SIGNAL(buttonClicked(QString)), this, SLOT(buttonHandler(QString)));
}

void Handler::buttonHandler(QString str)
{

   QObject *pmyText = m_root->findChild<QObject*>("myText");
   pmyText->setProperty("text", "Thanks!!!");
   qDebug() << str;
}
