#include "krug.h"
#include <QPainter>

Krug::Krug(qreal x, qreal y, qreal diameter)
{
    group = new QGraphicsItemGroup(this);

    QPixmap backgroundImage("/home/hxppy/Pictures/sv.jpg");

    QGraphicsEllipseItem* ellipse = new QGraphicsEllipseItem(x - diameter / 2, y - diameter / 2, diameter, diameter);

    QBrush imageBrush(backgroundImage);
    ellipse->setBrush(imageBrush);

    group->addToGroup(ellipse);

    QPolygon rhombus;
    rhombus << QPoint(2, 0) << QPoint(0, 2) << QPoint(-2, 0) << QPoint(0, -2);
    QGraphicsPolygonItem* rhombusItem = new QGraphicsPolygonItem(rhombus);
    rhombusItem->setBrush(Qt::red);
    group->addToGroup(rhombusItem);

    group->setFlag(QGraphicsItem::ItemIsMovable);
}

void KrugDraw::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QImage image("/home/hxppy/Pictures/sv.jpg");
    QBrush brush(image);

    painter->setPen(QPen(Qt::black, 3));
    painter->setBrush(brush);

    int sv = endPoint().x() > startPoint().x() ? startPoint().x() : endPoint().x();
    int ss = endPoint().y() > startPoint().y() ? startPoint().y() : endPoint().y();
    int min =std::min(qAbs(endPoint().x()-startPoint().x()),qAbs(endPoint().y()-startPoint().y()));
    QRectF rect (sv,ss,min, min);

    painter->drawEllipse(rect);

    Q_UNUSED(option)
    Q_UNUSED(widget)
}

