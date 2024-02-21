#include "myrectangle.h"

MyRectangle::MyRectangle(int x, int y, QGraphicsPolygonItem* parent): Figure(parent)
{
    QPolygonF kv;
    setBrush(Qt::green);

    kv << QPoint(-x/2, y/2)
       << QPoint(x/2, y/2)
       << QPoint(x/2, -y/2)
       << QPoint(-x/2, -y/2);
    setPolygon(kv);
    setFlag(QGraphicsItem::ItemIsMovable);

    QPolygon rhombus;
    rhombus << QPoint(2,0) << QPoint(0,2) << QPoint(-2,0)<< QPoint(0,-2);
    QGraphicsPolygonItem *rhombusItem = new QGraphicsPolygonItem(rhombus, this);
    rhombusItem->setBrush(Qt::red);
    rhombusItem->setFlag(QGraphicsItem::ItemIsMovable);
}
