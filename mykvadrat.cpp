#include "mykvadrat.h"
#include <QPainter>

MyKvadrat::MyKvadrat(int x, QGraphicsPolygonItem* parent): Figure(parent)
{
    QPolygonF kv;
    setBrush(Qt::green);

    kv << QPoint(-x/2, x/2)
        << QPoint(x/2, x/2)
        << QPoint(x/2, -x/2)
        << QPoint(-x/2, -x/2);
    setPolygon(kv);
    setFlag(QGraphicsItem::ItemIsMovable);

    QPolygon rhombus;
    rhombus << QPoint(2,0) << QPoint(0,2) << QPoint(-2,0)<< QPoint(0,-2);
    QGraphicsPolygonItem *rhombusItem = new QGraphicsPolygonItem(rhombus, this);
    rhombusItem->setBrush(Qt::red);
    rhombusItem->setFlag(QGraphicsItem::ItemIsMovable);
}

void KvadratDraw1::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(QPen(Qt::black, 3));
    painter->setBrush(QBrush(Qt::blue));

    int min =std::min(qAbs(endPoint().x()-startPoint().x()),qAbs(endPoint().y()-startPoint().y()));
    QRectF rect (endPoint().x() > startPoint().x() ? startPoint().x() : endPoint().x(),endPoint().y() > startPoint().y() ? startPoint().y() : endPoint().y(),min, min);

    painter->drawRect(rect);

    Q_UNUSED(option)
    Q_UNUSED(widget)
}
