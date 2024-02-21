#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QPropertyAnimation>
#include <QTimer>
#include "inputdialogs.h"
#include "krug.h"
#include "myrectangle.h"
#include "mykvadrat.h"
#include "treugolnik.h"
#include "romb.h"
#include "shestiugolnik.h"
#include "ellips.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class Mnogougolnik
{
public:
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

    void on_pushButton_3_pressed();

    void on_pushButton_3_released();

    void on_pushButton_4_pressed();

    void on_pushButton_4_released();
private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    QTimer *timer, *timer2;
};

#endif // MAINWINDOW_H
