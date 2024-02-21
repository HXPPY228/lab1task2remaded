#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    scene->setBackgroundBrush(Qt::lightGray);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(on_pushButton_3_pressed()));
    timer2 = new QTimer(this);
    connect(timer2, SIGNAL(timeout()), this, SLOT(on_pushButton_4_pressed()));
}

MainWindow::~MainWindow()
{
    delete ui;
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
        ui->label->setText(S);
        ui->label_4->setText(P);
        ui->label_5->setText("Центр масс помечен красной точкой.");
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
        ui->label->setText(S);
        ui->label_4->setText(P);
        ui->label_5->setText("Центр масс помечен красной точкой.");
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
        ui->label->setText(S);
        ui->label_4->setText(P);
        ui->label_5->setText("Центр масс помечен красной точкой.");
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
        ui->label->setText(S);
        ui->label_4->setText(P);
        ui->label_5->setText("Центр масс помечен красной точкой.");
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
        ui->label->setText(S);
        ui->label_4->setText(P);
        ui->label_5->setText("Центр масс помечен красной точкой.");
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
        ui->label->setText(S);
        ui->label_4->setText(P);
        ui->label_5->setText("Центр масс помечен красной точкой.");
    }
    else if (ui->comboBox->currentIndex() == 6)
    {

    }
    else if (ui->comboBox->currentIndex() == 7)
    {
        int x=0,y=0;
        InputDialogrb dialog(this);
        if (dialog.exec()== QDialog::Accepted)
        {
            x=dialog.getX();
            y=dialog.getY();
        }
        Ellips* el =new Ellips(-y/2,-x/2,y,x);
        scene->addItem(el);
        QString S=QString::number(3.1415*x/2*y/2), P = QString::number(2 * 3.1415 * sqrt((x/2 * x/2 + y/2 * y/2) / (2 * 1.0)));
        ui->label->setText(S);
        ui->label_4->setText(P);
        ui->label_5->setText("Центр масс помечен красной точкой.");
    }
}


void MainWindow::on_pushButton_2_clicked()
{
    scene->clear();
    ui->label->setText("Очищено!");
    ui->label_4->setText("Очищено!");
    ui->label_5->setText("Очищено!");
}



void MainWindow::on_pushButton_3_pressed()
{
    QList<QGraphicsItem*> allItems = scene->items();
    for (QGraphicsItem* item : allItems){
        item->setRotation(item->rotation()-1);
    }
    timer->start(10);
}

void MainWindow::on_pushButton_3_released()
{
    timer->stop();
}

void MainWindow::on_pushButton_4_pressed()
{
    QList<QGraphicsItem*> allItems = scene->items();
    for (QGraphicsItem* item : allItems){
        item->setRotation(item->rotation()+1);
    }
    timer2->start(10);
}

void MainWindow::on_pushButton_4_released()
{
    timer2->stop();
}


