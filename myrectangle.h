#ifndef MYRECTANGLE_H
#define MYRECTANGLE_H

#include <QGraphicsRectItem>
#include <QBrush>

class MyRectangle : public QGraphicsRectItem
{
public:
    MyRectangle(qreal x,qreal y, qreal width, qreal height);
    void mousePressEvent(QGraphicsSceneMouseEvent* event) override
    {
        QGraphicsRectItem::mousePressEvent(event);
    }
};

#endif // MYRECTANGLE_H
