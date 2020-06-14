#ifndef WINDOW2_H
#define WINDOW2_H

#include <QMainWindow>
#include "window1.h"

class Window2 : public QMainWindow
{
    Q_OBJECT
public:
    explicit Window2(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *);

signals:
    void goback();

public slots:
};

#endif // WINDOW2_H
