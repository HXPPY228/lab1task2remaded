#include "paintscene.h"
#include "romb.h"
#include "treugolnik.h"
#include "mykvadrat.h"

PaintScene::PaintScene(QObject *parent) : QGraphicsScene(parent)
{

}

PaintScene::~PaintScene()
{

}

int PaintScene::typeFigure() const
{
    return m_typeFigure;
}

void PaintScene::setTypeFigure(const int type)
{
    m_typeFigure = type;
}

void PaintScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    /* Устанавливаем конечную координату положения мыши
         * в текущую отрисовываемую фигуру
         * */
    tempFigure->setEndPoint(event->scenePos());
    /* Обновляем содержимое сцены,
         * необходимо для устранения артефактов при отрисовке фигур
         * */
    this->update(QRectF(0,0,this->width(), this->height()));
}

/* Как только нажали кнопку мыши, создаём фигуру одного из трёх типов
     * и помещаем её на сцену, сохранив указатель на неё в переменной
     * tempFigure
     * */
void PaintScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    switch (m_typeFigure) {
    case SquareType: {
        KvadratDraw1 *item = new KvadratDraw1(event->scenePos());
        item->setPos(event->pos());
        tempFigure = item;
        break;
    }
    case RombType: {
        RombDraw *item = new RombDraw(event->scenePos());
        item->setPos(event->pos());
        tempFigure = item;
        break;
    }
        case TriangleType: {
        TreugolnikDraw *item = new TreugolnikDraw(event->scenePos());
        item->setPos(event->pos());
        tempFigure = item;
        break;
    }
    default:{
        KvadratDraw1 *item = new KvadratDraw1(event->scenePos());
        item->setPos(event->pos());
        tempFigure = item;
        break;
    }
    }
    this->addItem(tempFigure);
}
