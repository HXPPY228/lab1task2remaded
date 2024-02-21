#ifndef ELLIPS_H
#define ELLIPS_H

#include <QGraphicsEllipseItem>
#include <QBrush>

class Ellips : public QGraphicsEllipseItem
{
public:
    Ellips(qreal x,qreal y, qreal diametr1, qreal diametr2);
    void mousePressEvent(QGraphicsSceneMouseEvent* event) override
    {
        QGraphicsItem::mousePressEvent(event);
    }
};

#endif // ELLIPS_H
