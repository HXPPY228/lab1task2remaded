#ifndef TREUGOLNIK_H
#define TREUGOLNIK_H

#include <QGraphicsPolygonItem>
#include <QBrush>

class Treugolnik : public QGraphicsPolygonItem
{
public:
    Treugolnik(int x, QGraphicsItem* parent = nullptr);
    void mousePressEvent(QGraphicsSceneMouseEvent* event) override
    {
        QGraphicsItem::mousePressEvent(event);
    }
};

#endif // TREUGOLNIK_H
