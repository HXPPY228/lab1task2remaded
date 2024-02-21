#include "inputdialogs.h"

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
