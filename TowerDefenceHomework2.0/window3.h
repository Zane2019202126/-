#ifndef WINDOW3_H
#define WINDOW3_H

#include <QMainWindow>
#include "window1.h"

class Window3 : public QMainWindow
{
    Q_OBJECT
public:
    explicit Window3(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *);

signals:
    void goback();

public slots:
};

#endif // WINDOW3_H

