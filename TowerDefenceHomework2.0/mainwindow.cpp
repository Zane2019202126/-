#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QPixmap>
#include <QPaintEvent>
#include <QPushButton>
#include <QDebug>
#include "mybutton.h"
#include "window1.h"
#include <QTimer>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    this->setFixedSize(2000,1500);
    ui->setupUi(this);
    //开始游戏的按钮
    MyButton * start_btn = new MyButton(":/startgame.png");
    start_btn->setParent(this);
    start_btn->move(500,1150);
    //connect(btn,&MyButton::clicked,this,&QMainWindow::close);
    Window1 * menu = new Window1;
    connect(start_btn,&QPushButton::clicked,this,[=](){
        start_btn->jumpdown();
        start_btn->jumpup();
        QTimer::singleShot(150,this,[=](){
            this->close();
            menu->show();
        });
    });
    //结束游戏的按钮
    MyButton * end_btn = new MyButton(":/endgame.png");
    end_btn->setParent(this);
    end_btn->move(1100,1150);
    connect(end_btn,&MyButton::clicked,this,&Window1::close);
    //将Window1的返回与MainWindow连接
    connect(menu,&Window1::goback,this,[=](){
        menu->hide();
        this->show();
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

/*void MainWindow::on_slider1_valueChanged(int value)
{

}*/

void MainWindow::paintEvent(QPaintEvent *){
    QPainter painter(this);
    QPixmap pixmap(":/pix1.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pixmap);
}
