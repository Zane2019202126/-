#include "window3.h"
#include "mybutton.h"
#include <QPainter>
#include <QPixmap>
#include <QPaintEvent>
#include <QPushButton>
#include <QDebug>
#include "window4.h"
#include <QTimer>

Window3::Window3(QWidget *parent) : QMainWindow(parent)
{
    this->setFixedSize(2000,1500);
    //��ʼ��Ϸ�İ�ť
    MyButton * start_btn = new MyButton(":/startbtn.png");
    start_btn->setParent(this);
    start_btn->move(1500,450);
    Window4 * choose1 = new Window4;
    connect(start_btn,&MyButton::clicked,this,[=](){
        start_btn->jumpdown();                                  //ʵ�ְ�ť����
        start_btn->jumpup();
        QTimer::singleShot(150,this,[=](){
            this->close();
            choose1->show();
        });
    });
    //���ز˵��İ�ť
    MyButton * back_btn = new MyButton(":/backbtn.png");
    back_btn->setParent(this);
    back_btn->move(1500,650);
    connect(back_btn,&MyButton::clicked,this,[=](){
        back_btn->jumpdown();                                  //ʵ�ְ�ť����
        back_btn->jumpup();
        QTimer::singleShot(150,this,[=](){
            emit goback();
        });
    });
    //������Ϸ�İ�ť
    MyButton * end_btn = new MyButton(":/endbtn.png");
    end_btn->setParent(this);
    end_btn->move(1500,850);
    connect(end_btn,&MyButton::clicked,this,&Window1::close);
}

void Window3::paintEvent(QPaintEvent *){
    QPainter painter(this);
    QPixmap pixmap(":/difficult.jpg");
    painter.drawPixmap(0,0,this->width(),this->height(),pixmap);
}
