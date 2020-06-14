#include "window4.h"
#include "mybutton.h"
#include <QPainter>
#include <QPixmap>
#include <QPaintEvent>
#include <QPushButton>
#include <QDebug>
#include <QTimer>
#include "mytower.h"

Window4::Window4(QWidget *parent) : QMainWindow(parent)
{
    this->setFixedSize(2000,1500);
    MyButton* setTower = new MyButton(":/mask1_1.png");
    setTower->setParent(this);
    setTower->move(700,200);
//    QSize picSize(10,10);
//    QPixmap scaledPixmap = parent->scaled(picSize);
    connect(setTower, &MyButton::clicked,this, &Window4::set_tower);
}

void Window4::paintEvent(QPaintEvent *){
    QPainter painter(this);
    QPixmap pixmap(":/level1.png");                                       //添加第一关背景
    painter.drawPixmap(0,0,this->width(),this->height(),pixmap);
    foreach (MyTower*tower, tower_list) {
        tower->draw(&painter);
    }
}

//创建一个新的塔
void Window4::set_tower(){
    MyTower* new_tower = new MyTower(QPoint(350,600),":/mask1_2.png");
    tower_list.push_back(new_tower);
    update();
}
