#ifndef MYTOWER_H
#define MYTOWER_H

#include <QObject>
#include <QPoint>
#include <QPixmap>

class MyTower : public QObject
{
    Q_OBJECT
public:
    //explicit MyTower(QObject *parent = nullptr);
    MyTower(QPoint pos, QString picName);
    void draw(QPainter* painter);
signals:
private:
    QPoint _pos;
    QPixmap _pixmap;

public slots:
};

#endif // MYTOWER_H
