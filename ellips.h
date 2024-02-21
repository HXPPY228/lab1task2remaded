#ifndef ELLIPS_H
#define ELLIPS_H

#include <QGraphicsEllipseItem>
#include <QBrush>

class Ellips : public QGraphicsEllipseItem
{
public:
    Ellips(qreal x,qreal y, qreal diametr1, qreal diametr2) : QGraphicsEllipseItem(x,y,diametr1,diametr2)
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

#endif // ELLIPS_H
