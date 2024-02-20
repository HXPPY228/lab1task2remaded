#ifndef TREUGOLNIK_H
#define TREUGOLNIK_H

#include <QGraphicsPolygonItem>
#include <QBrush>

class Treugolnik : public QGraphicsPolygonItem
{
public:
    Treugolnik(int x, QGraphicsItem* parent = nullptr)
        : QGraphicsPolygonItem(parent)
    {
        QPolygon triangle;
        triangle << QPoint(-x/2, 0.2887*x)
                 << QPoint(x/2, 0.2887*x)
                 << QPoint(0, -x*0.577);
        setPolygon(triangle);
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

#endif // TREUGOLNIK_H
