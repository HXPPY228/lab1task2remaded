#ifndef KRUG_H
#define KRUG_H

#include <QGraphicsEllipseItem>
#include <QBrush>

class Krug : public QGraphicsEllipseItem
{
public:
    Krug(qreal x,qreal y, qreal diametr) : QGraphicsEllipseItem(x,y,diametr,diametr)
    {
        setBrush(Qt::green);
        setFlag(QGraphicsItem::ItemIsMovable);

        QPolygon rhombus;
        rhombus << QPoint(2,0) << QPoint(0,2) << QPoint(-2,0)<< QPoint(0,-2);
        QGraphicsPolygonItem *rhombusItem = new QGraphicsPolygonItem(rhombus, this);
        rhombusItem->setBrush(Qt::red);
        rhombusItem->setFlag(QGraphicsItem::ItemIsMovable);
    }
    void mousePressEvent(QGraphicsSceneMouseEvent* event) override
    {
        QGraphicsItem::mousePressEvent(event);
    }
};

#endif // KRUG_H