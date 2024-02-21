#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);

    QPixmap pixmap("/home/hxppy/Pictures/1646165847_1-abrakadabra-fun-p-list-v-kletku-na-prozrachnom-fone-1.jpg");
    scene->setBackgroundBrush(pixmap);

    ui->graphicsView->setScene(scene);


    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(on_pushButton_3_pressed()));
    timer2 = new QTimer(this);
    connect(timer2, SIGNAL(timeout()), this, SLOT(on_pushButton_4_pressed()));
    timer3 = new QTimer(this);
    connect(timer3, SIGNAL(timeout()), this, SLOT(on_pushButton_vverh_pressed()));
    timer4 = new QTimer(this);
    connect(timer4, SIGNAL(timeout()), this, SLOT(on_pushButton_vniz_pressed()));
    timer5 = new QTimer(this);
    connect(timer5, SIGNAL(timeout()), this, SLOT(on_pushButton_vlevo_pressed()));
    timer6 = new QTimer(this);
    connect(timer6, SIGNAL(timeout()), this, SLOT(on_pushButton_vpravo_pressed()));
    timer7 = new QTimer(this);
    connect(timer7, SIGNAL(timeout()), this, SLOT(on_pushButton_plus_pressed()));
    timer8 = new QTimer(this);
    connect(timer8, SIGNAL(timeout()), this, SLOT(on_pushButton_minus_pressed()));
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
        MyKvadrat* kv =new MyKvadrat(x);
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
        MyRectangle* rect =new MyRectangle(x,y);
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



void MainWindow::on_pushButton_vverh_pressed()
{
    QList<QGraphicsItem*> allItems = scene->items();
    for (QGraphicsItem* item : allItems){
        if (item->parentItem() == nullptr) {
            item->setPos(item->pos().x(),item->pos().y()-1);
        }
    }
    timer3->start(10);
}


void MainWindow::on_pushButton_vverh_released()
{
    timer3->stop();
}


void MainWindow::on_pushButton_vniz_pressed()
{
    QList<QGraphicsItem*> allItems = scene->items();
    for (QGraphicsItem* item : allItems){
        if (item->parentItem() == nullptr) {
            item->setPos(item->pos().x(),item->pos().y()+1);
        }
    }
    timer4->start(10);
}


void MainWindow::on_pushButton_vniz_released()
{
    timer4->stop();
}


void MainWindow::on_pushButton_vlevo_pressed()
{
    QList<QGraphicsItem*> allItems = scene->items();
    for (QGraphicsItem* item : allItems){
        if (item->parentItem() == nullptr) {
            item->setPos(item->pos().x()-1,item->pos().y());
        }
    }
    timer5->start(10);
}


void MainWindow::on_pushButton_vlevo_released()
{
    timer5->stop();
}


void MainWindow::on_pushButton_vpravo_pressed()
{
    QList<QGraphicsItem*> allItems = scene->items();
    for (QGraphicsItem* item : allItems){
        if (item->parentItem() == nullptr) {
            item->setPos(item->pos().x()+1,item->pos().y());
        }
    }
    timer6->start(10);
}


void MainWindow::on_pushButton_vpravo_released()
{
    timer6->stop();
}


void MainWindow::on_pushButton_plus_pressed()
{
    QList<QGraphicsItem*> allItems = scene->items();
    for (QGraphicsItem* item : allItems){
        if (item->parentItem() == nullptr) {

            item->setScale(item->scale() + 0.01);
        }
    }
    timer7->start(10);
}


void MainWindow::on_pushButton_plus_released()
{
    timer7->stop();
}


void MainWindow::on_pushButton_minus_pressed()
{
    QList<QGraphicsItem*> allItems = scene->items();
    for (QGraphicsItem* item : allItems){
        if (item->parentItem() == nullptr) {

            item->setScale(item->scale() - 0.01);
        }
    }
    timer8->start(10);
}


void MainWindow::on_pushButton_minus_released()
{
    timer8->stop();
}

