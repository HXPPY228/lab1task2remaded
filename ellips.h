#ifndef ELLIPS_H
#define ELLIPS_H

#include "figure.h"
#include <QBrush>

class Ellips : public Figure
{
public:
    Ellips(qreal x,qreal y, qreal diametr1, qreal diametr2);

private:
    QGraphicsItemGroup* group;
};

#endif // ELLIPS_H
