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
    //开始游戏的按钮
    MyButton * start_btn = new MyButton(":/startbtn.png");
    start_btn->setParent(this);
    start_btn->move(1500,450);
    Window4 * choose1 = new Window4;
    connect(start_btn,&MyButton::clicked,this,[=](){
        start_btn->jumpdown();                                  //实现按钮弹跳
        start_btn->jumpup();
        QTimer::singleShot(150,this,[=](){
            this->close();
            choose1->show();
        });
    });
    //返回菜单的按钮
    MyButton * back_btn = new MyButton(":/backbtn.png");
    back_btn->setParent(this);
    back_btn->move(1500,650);
    connect(back_btn,&MyButton::clicked,this,[=](){
        back_btn->jumpdown();                                  //实现按钮弹跳
        back_btn->jumpup();
        QTimer::singleShot(150,this,[=](){
            emit goback();
        });
    });
    //结束游戏的按钮
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
