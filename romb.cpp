#include "romb.h"

Romb::Romb(int x, int y, QGraphicsPolygonItem* parent) : Figure(parent)
{
    QPolygonF romb;
    setBrush(Qt::green);

    romb << QPoint(0, -y/2)
         << QPoint(x/2, 0)
         << QPoint(0, y/2)
         << QPoint(-x/2, 0);
    setPolygon(romb);
    setFlag(QGraphicsItem::ItemIsMovable);

    QPolygon rhombus;
    rhombus << QPoint(2,0) << QPoint(0,2) << QPoint(-2,0)<< QPoint(0,-2);
    QGraphicsPolygonItem *rhombusItem = new QGraphicsPolygonItem(rhombus, this);
    rhombusItem->setBrush(Qt::red);
    rhombusItem->setFlag(QGraphicsItem::ItemIsMovable);
}
