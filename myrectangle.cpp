#include "myrectangle.h"

MyRectangle::MyRectangle(qreal x,qreal y, qreal width, qreal height) : QGraphicsRectItem(x,y,width,height)
{
    setBrush(Qt::green);
    setFlag(QGraphicsItem::ItemIsMovable);

    QPolygon rhombus;
    rhombus << QPoint(2,0) << QPoint(0,2) << QPoint(-2,0)<< QPoint(0,-2);
    QGraphicsPolygonItem *rhombusItem = new QGraphicsPolygonItem(rhombus, this);
    rhombusItem->setBrush(Qt::red);
    rhombusItem->setFlag(QGraphicsItem::ItemIsMovable);
}
