#ifndef INPUTDIALOGS_H
#define INPUTDIALOGS_H

#include <QDialog>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>

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

class InputDialogrb : public QDialog
{
    Q_OBJECT

public:
    explicit InputDialogrb(QWidget *parent = nullptr);

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


#endif // INPUTDIALOGS_H
