#include "mytower.h"
#include <QPoint>
#include <QPixmap>
#include <QPainter>

MyTower::MyTower(QPoint pos, QString picName) : QObject(0), _pixmap(picName)
{
    _pos=pos;
}

void MyTower::draw(QPainter* painter){
    painter->drawPixmap(_pos,_pixmap);
    QSize picSize(10,10);
    QPixmap scaledPixmap = _pixmap.scaled(picSize);
}
