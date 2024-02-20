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
    }
    void mousePressEvent(QGraphicsSceneMouseEvent* event) override
    {
        QGraphicsRectItem::mousePressEvent(event);
    }
};

#endif // MYKVADRAT_H
