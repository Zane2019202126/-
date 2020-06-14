#ifndef WINDOW4_H
#define WINDOW4_H

#include <QMainWindow>
#include "window2.h"
#include "window3.h"
#include "mytower.h"
#include <QList>

class Window4 : public QMainWindow
{
    Q_OBJECT
public:
    explicit Window4(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *);
    void set_tower();

signals:
private:
    QList<MyTower*> tower_list;
public slots:
};

#endif // WINDOW4_H
