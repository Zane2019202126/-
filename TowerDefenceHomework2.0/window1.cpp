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
    //ѡ�����Ϸ�İ�ť
    MyButton * easy_btn = new MyButton(":/easybtn.png");
    easy_btn->setParent(this);
    easy_btn->move(1500,450);
    Window2 * chooseeasy = new Window2;
    connect(easy_btn,&MyButton::clicked,this,[=](){
        easy_btn->jumpdown();                                  //ʵ�ְ�ť�ĵ���
        easy_btn->jumpup();
        QTimer::singleShot(150,this,[=](){
            this->close();
            chooseeasy->show();
        });
    });
    //ѡ��������Ϸ�İ�ť
    MyButton * difficult_btn = new MyButton(":/difficultbtn.png");
    difficult_btn->setParent(this);
    difficult_btn->move(1500,650);
    Window3 * choosedifficult = new Window3;
    connect(difficult_btn,&MyButton::clicked,this,[=](){
        difficult_btn->jumpdown();                                  //ʵ�ְ�ť�ĵ���
        difficult_btn->jumpup();
        QTimer::singleShot(150,this,[=](){
            this->close();
            choosedifficult->show();
        });
    });
    //����������İ�ť
    MyButton * back_btn = new MyButton(":/backbtn.png");
    back_btn->setParent(this);
    back_btn->move(1500,850);
    connect(back_btn,&MyButton::clicked,this,[=](){
        back_btn->jumpdown();                                  //ʵ�ְ�ť�ĵ���
        back_btn->jumpup();
        QTimer::singleShot(150,this,[=](){
            emit goback();
        });
    });
    //�˳��İ�ť
    MyButton * end_btn = new MyButton(":/endbtn.png");
    end_btn->setParent(this);
    end_btn->move(1500,1050);
    connect(end_btn,&MyButton::clicked,this,&Window1::close);
    //��Window2�ķ�����Window1����
    connect(chooseeasy,&Window2::goback,this,[=](){
        chooseeasy->hide();
        this->show();
    });
    //��Window3�ķ�����Window1����
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
//    QPixmap pixmap2(":/ͨ����.jpg");
//    painter.drawPixmap(0,0,this->width(),this->height(),pixmap2);
//    qDebug()<<pixmap2.isNull();
}
