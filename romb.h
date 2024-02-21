#ifndef ROMB_H
#define ROMB_H

#include "figure.h"
#include <QBrush>

class Romb : public Figure
{
public:
    Romb(int x, int y, QGraphicsPolygonItem* parent = nullptr);
};


#endif // ROMB_H
