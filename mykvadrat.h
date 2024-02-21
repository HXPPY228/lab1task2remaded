#ifndef MYKVADRAT_H
#define MYKVADRAT_H

#include "figure.h"
#include <QBrush>

class MyKvadrat: public Figure
{
public:
    MyKvadrat(int x,QGraphicsPolygonItem* parent = nullptr);
};

#endif // MYKVADRAT_H
