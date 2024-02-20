#ifndef ROMB_H
#define ROMB_H

#include <QGraphicsPolygonItem>
#include <QBrush>

class Romb : public QGraphicsPolygonItem
{
public:
    Romb(int x, int y, QGraphicsItem* parent = nullptr)
        : QGraphicsPolygonItem(parent)
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
    void mousePressEvent(QGraphicsSceneMouseEvent* event) override
    {
        QGraphicsItem::mousePressEvent(event);
    }
};

#endif // ROMB_H
