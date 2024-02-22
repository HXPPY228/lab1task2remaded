#ifndef ZVEZDA_H
#define ZVEZDA_H

#include "figure.h"
#include <QBrush>

class Zvezda5 : public Figure
{
public:
    Zvezda5(int radius1,int radius2, QGraphicsPolygonItem* parent = nullptr);
};

class Zvezda6 : public Figure
{
public:
    Zvezda6(int radius1,int radius2, QGraphicsPolygonItem* parent = nullptr);
};

class Zvezda8 : public Figure
{
public:
    Zvezda8(int radius1,int radius2, QGraphicsPolygonItem* parent = nullptr);
};

#endif // ZVEZDA_H
