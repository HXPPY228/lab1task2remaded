#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
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

InputDialogkv::InputDialogkv(QWidget *parent) :
    QDialog(parent),
    xInput(new QLineEdit(this))
{
    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    QHBoxLayout *xLayout = new QHBoxLayout;
    QLabel *xLabel = new QLabel("Введите значение стороны/диаметра в пикселях: ", this);
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

int InputDialogkv::getX()
{
    return xInput->text().toInt();
}

void MainWindow::on_pushButton_clicked()
{
    scene->clear();
    if (ui->comboBox->currentIndex() == 1)
    {
        int x=0;
        InputDialogkv dialog(this);
        if (dialog.exec()== QDialog::Accepted)
        {
            x=dialog.getX();
        }
        Krug* kv =new Krug(0,0,x);
        kv ->setPos(0,0);
        scene->addItem(kv);
        QString S=QString::number(3.1415*x*x/4), P = QString::number(3.1415*x);
        ui->label->setText("Площадь в пикселях: " + S + ". Периметр в пикселях: " + P);
    }
    else if (ui->comboBox->currentIndex() == 3)
    {
        int x=0;
        InputDialogkv dialog(this);
        if (dialog.exec()== QDialog::Accepted)
        {
            x=dialog.getX();
        }
        MyKvadrat* kv =new MyKvadrat(0,0,x);
        kv ->setPos(0,0);
        scene->addItem(kv);
        QString S=QString::number(x*x), P = QString::number(x*4);
        ui->label->setText("Площадь в пикселях: " + S + ". Периметр в пикселях: " + P);
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
        MyRectangle* rect =new MyRectangle(0,0,x,y);
        rect ->setPos(0,0);
        scene->addItem(rect);
        QString S=QString::number(x*y), P = QString::number((x+y)*2);
        ui->label->setText("Площадь в пикселях: " + S + ". Периметр в пикселях: " + P);
    }


}


void MainWindow::on_pushButton_2_clicked()
{
    scene->clear();
}

void MainWindow::on_pushButton_3_clicked()
{
    turnLeft=true;
}
