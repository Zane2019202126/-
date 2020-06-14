#ifndef MYBUTTON_H
#define MYBUTTON_H

#include <QWidget>
#include <QPushButton>

class MyButton : public QPushButton
{
    Q_OBJECT
public:
    //explicit MyButton(QWidget *parent = nullptr);
    MyButton(QString pix);
    void jumpdown();
    void jumpup();

signals:

public slots:
};

#endif // MYBUTTON_H
