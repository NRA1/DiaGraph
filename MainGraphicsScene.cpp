#include "MainGraphicsScene.h"

MainGraphicsScene::MainGraphicsScene()
{
    setSceneRect(-500, -500, 1000, 1000);
}

void MainGraphicsScene::createShapeBtnClickSlot(int pathId)
{
    creationShapePathId = pathId;
}

void MainGraphicsScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->button() == Qt::LeftButton && creationShapePathId > -1)
    {
        pressPos = event->scenePos();
    }
    else
    {
        QGraphicsScene::mousePressEvent(event);
    }
}

void MainGraphicsScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{

    QGraphicsScene::mouseMoveEvent(event);
}

void MainGraphicsScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->button() == Qt::LeftButton && creationShapePathId > -1)
    {
        if(pressPos == event->scenePos())
        {
            MainGraphicsShape *shape = new MainGraphicsShape(QPointF(event->scenePos().x() - 50, event->scenePos().y() - 25));
            this->addItem(shape);

        }
        else
        {
            MainGraphicsShape *shape = new MainGraphicsShape(QRectF(pressPos.x(), pressPos.y(),
                                                                    event->scenePos().x() - pressPos.x(),
                                                                    event->scenePos().y() - pressPos.y()));
            this->addItem(shape);
        }
        creationShapePathId = -1;
    }
    else
    {
        QGraphicsScene::mouseReleaseEvent(event);
    }
}

