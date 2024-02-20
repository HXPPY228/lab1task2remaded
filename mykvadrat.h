#ifndef MYKVADRAT_H
#define MYKVADRAT_H

#include <QGraphicsRectItem>
#include <QBrush>

class MyKvadrat: public QGraphicsRectItem
{
public:
    MyKvadrat(qreal x, qreal y, qreal sideLength) : QGraphicsRectItem(x,y,sideLength,sideLength)
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
        QGraphicsRectItem::mousePressEvent(event);
    }
};

#endif // MYKVADRAT_H
