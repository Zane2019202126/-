#include "mybutton.h"
#include <QPixmap>
#include <QPropertyAnimation>

/*MyButton::MyButton(QWidget *parent) : QWidget(parent)
{

}*/

MyButton::MyButton(QString pix):QPushButton(0){
    QPixmap pixmap(pix);
    this->setFixedSize(pixmap.width(),pixmap.height());
    this->setStyleSheet("QPushButton{border:Opx;}");
    this->setIcon(pixmap);
    this->setIconSize(QSize(pixmap.width(),pixmap.height()));
}

//实现点击按钮时按钮向下跳
void MyButton::jumpdown(){
    QPropertyAnimation* move=new QPropertyAnimation(this, "geometry");
    move->setDuration(100);              //动画持续时间
    move->setStartValue(QRect(this->x(),this->y()+10,this->width(),this->height()));      //向下跳开始
    move->setEndValue(QRect(this->x(),this->y(),this->width(),this->height()));     //向下跳结束
    move->setEasingCurve(QEasingCurve::OutBounce);                                     //弹跳的曲线
    move->start();
}


//实现点击按钮时按钮向上跳
void MyButton::jumpup(){
    QPropertyAnimation* move=new QPropertyAnimation(this, "geometry");
    move->setDuration(100);              //动画持续时间
    move->setStartValue(QRect(this->x(),this->y()+10,this->width(),this->height()));      //向上跳开始
    move->setEndValue(QRect(this->x(),this->y(),this->width(),this->height()));     //向上跳结束
    move->setEasingCurve(QEasingCurve::OutBounce);                                     //弹跳的曲线
    move->start();
}
