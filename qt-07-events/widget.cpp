#include "widget.h"
#include "ui_widget.h"
#include <QMouseEvent>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setWindowTitle("Mouse Position");
    this->setMouseTracking(true);
}

Widget::~Widget()
{
   delete ui;
}

void Widget::mouseMoveEvent(QMouseEvent *event)
{
   int xPosition = event->pos().x();
   int yPosition = event->pos().y();
   findChild<QLineEdit *>("xLineEdit")->setText(QString::number(xPosition));
   findChild<QLineEdit *>("yLineEdit")->setText(QString::number(yPosition));
}
