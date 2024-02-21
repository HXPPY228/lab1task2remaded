#ifndef FIGURE_H
#define FIGURE_H

#include <QGraphicsPolygonItem>

class Figure : public QGraphicsPolygonItem
{
public:
    Figure(QGraphicsPolygonItem* parent = nullptr) : QGraphicsPolygonItem(parent) {}
    void mousePressEvent(QGraphicsSceneMouseEvent* event) override
    {
        QGraphicsItem::mousePressEvent(event);
    }
};


#endif // FIGURE_H
