#ifndef MYRECTANGLE_H
#define MYRECTANGLE_H

#include "figure.h"
#include <QBrush>

class MyRectangle : public Figure
{
public:
    MyRectangle(int x,int y, QGraphicsPolygonItem* parent = nullptr);
};

#endif // MYRECTANGLE_H
