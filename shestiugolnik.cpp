#include "shestiugolnik.h"

Shestiugolnik::Shestiugolnik(int x, QGraphicsItem* parent): QGraphicsPolygonItem(parent)
{

    QPolygonF hex;
    setBrush(Qt::green);

    hex << QPoint(-x, 0)
        << QPoint(-x/2, -0.866*x)
        << QPoint(x/2, -0.866*x)
        << QPoint(x, 0)
        << QPoint(x/2, 0.866*x)
        << QPoint(-x/2, 0.866*x);
    setPolygon(hex);
    setFlag(QGraphicsItem::ItemIsMovable);

    QPolygon rhombus;
    rhombus << QPoint(2,0) << QPoint(0,2) << QPoint(-2,0)<< QPoint(0,-2);
    QGraphicsPolygonItem *rhombusItem = new QGraphicsPolygonItem(rhombus, this);
    rhombusItem->setBrush(Qt::red);
    rhombusItem->setFlag(QGraphicsItem::ItemIsMovable);
}
