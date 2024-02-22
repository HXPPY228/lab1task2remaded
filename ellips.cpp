#include "ellips.h"

Ellips::Ellips(qreal x,qreal y, qreal diametr1, qreal diametr2)
{
    group = new QGraphicsItemGroup(this);

    QGraphicsEllipseItem* ellipse = new QGraphicsEllipseItem(x,y,diametr1,diametr2);
    ellipse->setBrush(Qt::green);
    group->addToGroup(ellipse);

    QPolygon rhombus;
    rhombus << QPoint(2,0) << QPoint(0,2) << QPoint(-2,0)<< QPoint(0,-2);
    QGraphicsPolygonItem *rhombusItem = new QGraphicsPolygonItem(rhombus);
    rhombusItem->setBrush(Qt::red);

    group->addToGroup(rhombusItem);
    ellipse->setFlag(QGraphicsItem::ItemIsMovable);
}
