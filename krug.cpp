#include "krug.h"

Krug::Krug(qreal x,qreal y, qreal diametr)
    {
    group = new QGraphicsItemGroup(this);

    QGraphicsEllipseItem* ellipse = new QGraphicsEllipseItem(x,y,diametr,diametr);
    ellipse->setBrush(Qt::green);
    group->addToGroup(ellipse);

    QPolygon rhombus;
    rhombus << QPoint(2,0) << QPoint(0,2) << QPoint(-2,0)<< QPoint(0,-2);
    QGraphicsPolygonItem *rhombusItem = new QGraphicsPolygonItem(rhombus);
    rhombusItem->setBrush(Qt::red);
    group->addToGroup(rhombusItem);
    group->setFlag(QGraphicsItem::ItemIsMovable);

    }
