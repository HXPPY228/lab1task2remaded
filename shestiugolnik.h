#ifndef SHESTIUGOLNIK_H
#define SHESTIUGOLNIK_H

#include <QGraphicsPolygonItem>
#include <QBrush>

class Shestiugolnik : public QGraphicsPolygonItem
{
public:
    Shestiugolnik(int x, QGraphicsItem* parent = nullptr)
        : QGraphicsPolygonItem(parent)
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
    void mousePressEvent(QGraphicsSceneMouseEvent* event) override
    {
        QGraphicsItem::mousePressEvent(event);
    }
};

#endif // SHESTIUGOLNIK_H
