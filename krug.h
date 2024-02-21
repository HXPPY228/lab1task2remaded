#ifndef KRUG_H
#define KRUG_H

#include "figure.h"
#include <QBrush>

class Krug : public Figure
{
public:
    Krug(qreal x,qreal y, qreal diametr);
private:
    QGraphicsItemGroup* group;
};

#endif // KRUG_H
