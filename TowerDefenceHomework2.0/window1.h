#ifndef WINDOW1_H
#define WINDOW1_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class Window1;
}
QT_END_NAMESPACE

class Window1 : public QMainWindow
{
    Q_OBJECT
public:
    explicit Window1(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *);
    ~Window1();

signals:
    void goback();
public slots:

private:
    Ui::Window1 *ui;
};

#endif // WINDOW1_H
