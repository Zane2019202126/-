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

//ʵ�ֵ����ťʱ��ť������
void MyButton::jumpdown(){
    QPropertyAnimation* move=new QPropertyAnimation(this, "geometry");
    move->setDuration(100);              //��������ʱ��
    move->setStartValue(QRect(this->x(),this->y()+10,this->width(),this->height()));      //��������ʼ
    move->setEndValue(QRect(this->x(),this->y(),this->width(),this->height()));     //����������
    move->setEasingCurve(QEasingCurve::OutBounce);                                     //����������
    move->start();
}


//ʵ�ֵ����ťʱ��ť������
void MyButton::jumpup(){
    QPropertyAnimation* move=new QPropertyAnimation(this, "geometry");
    move->setDuration(100);              //��������ʱ��
    move->setStartValue(QRect(this->x(),this->y()+10,this->width(),this->height()));      //��������ʼ
    move->setEndValue(QRect(this->x(),this->y(),this->width(),this->height()));     //����������
    move->setEasingCurve(QEasingCurve::OutBounce);                                     //����������
    move->start();
}
