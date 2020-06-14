#include "window1.h"
#include "ui_window1.h"
#include "mybutton.h"
#include <QPainter>
#include <QPixmap>
#include <QPaintEvent>
#include <QPushButton>
#include <QDebug>
#include "Window2.h"
#include "Window3.h"
#include <QTimer>

Window1::Window1(QWidget *parent) : QMainWindow(parent),ui(new Ui::Window1)
{
    this->setFixedSize(2000,1500);
    ui->setupUi(this);
    //选择简单游戏的按钮
    MyButton * easy_btn = new MyButton(":/easybtn.png");
    easy_btn->setParent(this);
    easy_btn->move(1500,450);
    Window2 * chooseeasy = new Window2;
    connect(easy_btn,&MyButton::clicked,this,[=](){
        easy_btn->jumpdown();                                  //实现按钮的弹跳
        easy_btn->jumpup();
        QTimer::singleShot(150,this,[=](){
            this->close();
            chooseeasy->show();
        });
    });
    //选择困难游戏的按钮
    MyButton * difficult_btn = new MyButton(":/difficultbtn.png");
    difficult_btn->setParent(this);
    difficult_btn->move(1500,650);
    Window3 * choosedifficult = new Window3;
    connect(difficult_btn,&MyButton::clicked,this,[=](){
        difficult_btn->jumpdown();                                  //实现按钮的弹跳
        difficult_btn->jumpup();
        QTimer::singleShot(150,this,[=](){
            this->close();
            choosedifficult->show();
        });
    });
    //返回主界面的按钮
    MyButton * back_btn = new MyButton(":/backbtn.png");
    back_btn->setParent(this);
    back_btn->move(1500,850);
    connect(back_btn,&MyButton::clicked,this,[=](){
        back_btn->jumpdown();                                  //实现按钮的弹跳
        back_btn->jumpup();
        QTimer::singleShot(150,this,[=](){
            emit goback();
        });
    });
    //退出的按钮
    MyButton * end_btn = new MyButton(":/endbtn.png");
    end_btn->setParent(this);
    end_btn->move(1500,1050);
    connect(end_btn,&MyButton::clicked,this,&Window1::close);
    //将Window2的返回与Window1连接
    connect(chooseeasy,&Window2::goback,this,[=](){
        chooseeasy->hide();
        this->show();
    });
    //将Window3的返回与Window1连接
    connect(choosedifficult,&Window3::goback,this,[=](){
        choosedifficult->hide();
        this->show();
    });
}

Window1::~Window1()
{
    delete ui;
}

void Window1::paintEvent(QPaintEvent *){
    QPainter painter(this);
    QPixmap pixmap1(":/center.jpg");
    painter.drawPixmap(0,0,this->width(),this->height(),pixmap1);
//    QPixmap pixmap2(":/通缉令.jpg");
//    painter.drawPixmap(0,0,this->width(),this->height(),pixmap2);
//    qDebug()<<pixmap2.isNull();
}
