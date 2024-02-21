#ifndef TREUGOLNIK_H
#define TREUGOLNIK_H

#include "figure.h"
#include <QBrush>

class Treugolnik : public Figure
{
public:
    Treugolnik(int x, QGraphicsPolygonItem* parent = nullptr);
};

#endif // TREUGOLNIK_H
