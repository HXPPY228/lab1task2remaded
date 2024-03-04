#include "krug.h"

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
