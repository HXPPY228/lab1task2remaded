#ifndef ROMB_H
#define ROMB_H

#include <QGraphicsPolygonItem>
#include <QBrush>

class Romb : public QGraphicsPolygonItem
{
public:
    Romb(int x, int y, QGraphicsPolygonItem* parent = nullptr);
    void mousePressEvent(QGraphicsSceneMouseEvent* event) override
    {
        QGraphicsItem::mousePressEvent(event);
    }
};

#endif // ROMB_H
