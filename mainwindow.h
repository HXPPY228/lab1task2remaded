#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsEllipseItem>
#include <QDialog>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QPropertyAnimation>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE
class Figury
{
public:

};

class Krug : public QGraphicsEllipseItem, Figury
{
public:
    Krug(qreal x,qreal y, qreal diametr) : QGraphicsEllipseItem(x,y,diametr,diametr)
    {
        setBrush(Qt::green);
        setFlag(QGraphicsItem::ItemIsMovable);
    }
    void mousePressEvent(QGraphicsSceneMouseEvent* event) override
    {
        QGraphicsItem::mousePressEvent(event);
    }
};

class MyRectangle : public QGraphicsRectItem
{
public:
    MyRectangle(qreal x,qreal y, qreal width, qreal height) : QGraphicsRectItem(x,y,width,height)
    {
        setBrush(Qt::green);
        setFlag(QGraphicsItem::ItemIsMovable);
    }
    void mousePressEvent(QGraphicsSceneMouseEvent* event) override
    {
        QGraphicsRectItem::mousePressEvent(event);
    }
};

class MyKvadrat: public QGraphicsRectItem
{
public:
    MyKvadrat(qreal x, qreal y, qreal sideLength) : QGraphicsRectItem(x,y,sideLength,sideLength)
    {
        setBrush(Qt::green);
        setFlag(QGraphicsItem::ItemIsMovable);
    }
    void mousePressEvent(QGraphicsSceneMouseEvent* event) override
    {
        QGraphicsRectItem::mousePressEvent(event);
    }
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    bool turnLeft=false, turnRight=false;
};

class InputDialog : public QDialog
{
    Q_OBJECT

public:
    explicit InputDialog(QWidget *parent = nullptr);

    int getX();
    int getY();

private:
    QLineEdit *xInput, *yInput;
};

class InputDialogkv : public QDialog
{
    Q_OBJECT

public:
    explicit InputDialogkv(QWidget *parent = nullptr);

    int getX();

private:
    QLineEdit *xInput;
};
#endif // MAINWINDOW_H
