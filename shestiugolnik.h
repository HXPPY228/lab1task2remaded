#ifndef SHESTIUGOLNIK_H
#define SHESTIUGOLNIK_H

#include <QGraphicsPolygonItem>
#include <QBrush>

class Shestiugolnik : public QGraphicsPolygonItem
{
public:
    Shestiugolnik(int x, QGraphicsItem* parent = nullptr);
    void mousePressEvent(QGraphicsSceneMouseEvent* event) override
    {
        QGraphicsItem::mousePressEvent(event);
    }
};

#endif // SHESTIUGOLNIK_H
