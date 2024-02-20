#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "krug.h"
#include "myrectangle.h"
#include "mykvadrat.h"
#include "treugolnik.h"
#include "romb.h"
#include "shestiugolnik.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    scene->setBackgroundBrush(Qt::lightGray);
}

MainWindow::~MainWindow()
{
    delete ui;
}

InputDialog::InputDialog(QWidget *parent) :
    QDialog(parent),
    xInput(new QLineEdit(this)),
    yInput(new QLineEdit(this))
{
    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    QHBoxLayout *xLayout = new QHBoxLayout;
    QLabel *xLabel = new QLabel("Введите значение x в пикселях: ", this);
    xLayout->addWidget(xLabel);
    xLayout->addWidget(xInput);
    mainLayout->addLayout(xLayout);

    QHBoxLayout *yLayout = new QHBoxLayout;
    QLabel *yLabel = new QLabel("Введите значение y в пикселях: ", this);
    yLayout->addWidget(yLabel);
    yLayout->addWidget(yInput);
    mainLayout->addLayout(yLayout);

    QPushButton *button = new QPushButton("OK", this);
    connect(button, SIGNAL(clicked()), this, SLOT(accept()));
    mainLayout->addWidget(button);
}

InputDialogrb::InputDialogrb(QWidget *parent) :
    QDialog(parent),
    xInput(new QLineEdit(this)),
    yInput(new QLineEdit(this))
{
    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    QHBoxLayout *xLayout = new QHBoxLayout;
    QLabel *xLabel = new QLabel("Введите значение первой диагонали в пикселях: ", this);
    xLayout->addWidget(xLabel);
    xLayout->addWidget(xInput);
    mainLayout->addLayout(xLayout);

    QHBoxLayout *yLayout = new QHBoxLayout;
    QLabel *yLabel = new QLabel("Введите значение второй диагонали в пикселях: ", this);
    yLayout->addWidget(yLabel);
    yLayout->addWidget(yInput);
    mainLayout->addLayout(yLayout);

    QPushButton *button = new QPushButton("OK", this);
    connect(button, SIGNAL(clicked()), this, SLOT(accept()));
    mainLayout->addWidget(button);
}

InputDialogkv::InputDialogkv(QWidget *parent) :
    QDialog(parent),
    xInput(new QLineEdit(this))
{
    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    QHBoxLayout *xLayout = new QHBoxLayout;
    QLabel *xLabel = new QLabel("Введите значение стороны/диаметра(шара) в пикселях: ", this);
    xLayout->addWidget(xLabel);
    xLayout->addWidget(xInput);
    mainLayout->addLayout(xLayout);

    QPushButton *button = new QPushButton("OK", this);
    connect(button, SIGNAL(clicked()), this, SLOT(accept()));
    mainLayout->addWidget(button);
}

int InputDialog::getX()
{
    return xInput->text().toInt();
}

int InputDialog::getY()
{
    return yInput->text().toInt();
}

int InputDialogrb::getX()
{
    return xInput->text().toInt();
}

int InputDialogrb::getY()
{
    return yInput->text().toInt();
}

int InputDialogkv::getX()
{
    return xInput->text().toInt();
}

void MainWindow::on_pushButton_clicked()
{
    //scene->clear();
    if (ui->comboBox->currentIndex() == 0)
    {
        int x=0;
        InputDialogkv dialog(this);
        if (dialog.exec()== QDialog::Accepted)
        {
            x=dialog.getX();
        }
        Treugolnik* triangle = new Treugolnik(x);
        triangle->setPos(0, x*0.866);

        scene->addItem(triangle);
        QString S=QString::number(0.433*x*x), P = QString::number(3*x);
        ui->label->setText("Площадь в пикселях: " + S + ". Периметр в пикселях: " + P + ". Центр масс треугольника помечен красной точкой. ");
    }
    else if (ui->comboBox->currentIndex() == 1)
    {
        int x=0;
        InputDialogkv dialog(this);
        if (dialog.exec()== QDialog::Accepted)
        {
            x=dialog.getX();
        }
        Krug* kv =new Krug(-x/2,-x/2,x);
        kv ->setPos(0,0);
        scene->addItem(kv);
        QString S=QString::number(3.1415*x*x/4), P = QString::number(3.1415*x);
        ui->label->setText("Площадь в пикселях: " + S + ". Периметр в пикселях: " + P + ". Центр масс круга помечен красной точкой. ");
    }
    else if (ui->comboBox->currentIndex() == 2)
    {
        int x=0,y=0;
        InputDialogrb dialog(this);
        if (dialog.exec()== QDialog::Accepted)
        {
            x=dialog.getX();
            y=dialog.getY();
        }
        Romb* romb =new Romb(y,x);
        romb ->setPos(0,0);
        scene->addItem(romb);
        QString S=QString::number(x*y/2), P = QString::number(sqrt(x*x+y*y)*2);
        ui->label->setText("Площадь в пикселях: " + S + ". Периметр в пикселях: " + P + ". Центр масс ромба помечен красной точкой. ");
    }
    else if (ui->comboBox->currentIndex() == 3)
    {
        int x=0;
        InputDialogkv dialog(this);
        if (dialog.exec()== QDialog::Accepted)
        {
            x=dialog.getX();
        }
        MyKvadrat* kv =new MyKvadrat(-x/2,-x/2,x);
        kv ->setPos(0,0);
        scene->addItem(kv);
        QString S=QString::number(x*x), P = QString::number(x*4);
        ui->label->setText("Площадь в пикселях: " + S + ". Периметр в пикселях: " + P + ". Центр масс квадрата помечен красной точкой. ");
    }
    else if (ui->comboBox->currentIndex() == 4)
    {
        int x=0,y=0;
        InputDialog dialog(this);
        if (dialog.exec()== QDialog::Accepted)
        {
            x=dialog.getX();
            y=dialog.getY();
        }
        MyRectangle* rect =new MyRectangle(-x/2,-y/2,x,y);
        rect ->setPos(0,0);
        scene->addItem(rect);
        QString S=QString::number(x*y), P = QString::number((x+y)*2);
        ui->label->setText("Площадь в пикселях: " + S + ". Периметр в пикселях: " + P + ". Центр масс прямоугольника помечен красной точкой. ");
    }
    else if (ui->comboBox->currentIndex() == 5)
    {
        int x=0;
        InputDialogkv dialog(this);
        if (dialog.exec()== QDialog::Accepted)
        {
            x=dialog.getX();
        }
        Shestiugolnik* hex =new Shestiugolnik(x);
        scene->addItem(hex);
        QString S=QString::number(2.598*x*x), P = QString::number(x*6);
        ui->label->setText("Площадь в пикселях: " + S + ". Периметр в пикселях: " + P + ". Центр масс шестиугольника помечен красной точкой. ");
    }

}


void MainWindow::on_pushButton_2_clicked()
{
    scene->clear();
    ui->label->setText("Очищено!");
}

void MainWindow::on_pushButton_3_clicked()
{
    QList<QGraphicsItem*> allItems = scene->items();
    for (QGraphicsItem* item : allItems){
        item->setRotation(item->rotation()-30);
    }
}

void MainWindow::on_pushButton_4_clicked()
{
    QList<QGraphicsItem*> allItems = scene->items();
    for (QGraphicsItem* item : allItems){
        item->setRotation(item->rotation()+30);
    }
}

