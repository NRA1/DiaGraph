//
// Created by nra1 on 4/26/21.
//

#include "MainWindow.h"
#include "MyGraphicsScene.h"

void MyGraphicsScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->button() == Qt::LeftButton && createShapeId > 0 && createShapeId < 4)
    {
        createShapeMousePressLoc = event->scenePos();
        QColor brushColor;
        brushColor.setNamedColor("#E10C01");
        QBrush handleBrush = QBrush(brushColor);
        QPen handlePen = QPen(Qt::NoPen);
        QGraphicsRectItem *handle0 = this->addRect(createShapeMousePressLoc.x(), createShapeMousePressLoc.y(), 5, 5, handlePen, handleBrush);
        QGraphicsRectItem *handle1 = this->addRect(createShapeMousePressLoc.x(), createShapeMousePressLoc.y() - 5, 5, 5, handlePen, handleBrush);
        QGraphicsRectItem *handle2 = this->addRect(createShapeMousePressLoc.x() - 5, createShapeMousePressLoc.y(), 5, 5, handlePen, handleBrush);
        QGraphicsRectItem *handle3 = this->addRect(createShapeMousePressLoc.x() - 5, createShapeMousePressLoc.y() - 5, 5, 5, handlePen, handleBrush);
        createShapeHandles[0] = handle0;
        createShapeHandles[1] = handle1;
        createShapeHandles[2] = handle2;
        createShapeHandles[3] = handle3;
    } else
    {
        QGraphicsScene::mousePressEvent(event);
    }

}

void MyGraphicsScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->button() == Qt::LeftButton && createShapeId > 0 && createShapeId < 4)
    {
        QPointF pos = event->scenePos();
        emit createShapeSign(createShapeId, createShapeHandles[3]->pos().x() + createShapeMousePressLoc.x(),
                             createShapeHandles[3]->pos().y() + createShapeMousePressLoc.y(),
                             createShapeHandles[0]->pos().x() - createShapeHandles[3]->pos().x(),
                             createShapeHandles[0]->pos().y() - createShapeHandles[3]->pos().y());
        createShapeId = 0;
        for (int i = 0; i < 4; ++i) {
            this->removeItem(createShapeHandles[i]);
            createShapeHandles[i] = nullptr;
        }
        for (int i = 0; i < this->items().length(); i++)
        {
            this->items()[i]->setEnabled(true);
        }
        this->views()[0]->unsetCursor();
    }
    else
    {
        QGraphicsScene::mouseReleaseEvent(event);
    }
}

void MyGraphicsScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if (createShapeId > 0 && event->buttons() == Qt::LeftButton)
    {
        if(event->modifiers() == Qt::ShiftModifier)
        {
            createShapeHandles[3]->setPos(0, 0);
            createShapeHandles[2]->setPos(0, event->scenePos().y() - createShapeMousePressLoc.y());
            createShapeHandles[1]->setPos(event->scenePos().y() - createShapeMousePressLoc.y(), 0);
            createShapeHandles[0]->setPos(event->scenePos().y() - createShapeMousePressLoc.y(), event->scenePos().y() - createShapeMousePressLoc.y());

        }
        else if(event->modifiers() == Qt::AltModifier)
        {
            createShapeHandles[0]->setPos(event->scenePos().x() - createShapeMousePressLoc.x(),
                                          event->scenePos().y() - createShapeMousePressLoc.y());
            createShapeHandles[1]->setPos(event->scenePos().x() - createShapeMousePressLoc.x(),
                                          (event->scenePos().y() - createShapeMousePressLoc.y()) * (-1)); // y = createShapeHandles[0].y() * -1
            createShapeHandles[2]->setPos((event->scenePos().x() - createShapeMousePressLoc.x()) * (-1),
                                          event->scenePos().y() - createShapeMousePressLoc.y());
            createShapeHandles[3]->setPos((event->scenePos().x() - createShapeMousePressLoc.x()) * (-1),
                                          (event->scenePos().y() - createShapeMousePressLoc.y()) * (-1));
        }
        else if(event->modifiers() == (Qt::ShiftModifier|Qt::AltModifier))
        {
            createShapeHandles[0]->setPos(event->scenePos().y() - createShapeMousePressLoc.y(),
                                          event->scenePos().y() - createShapeMousePressLoc.y());
            createShapeHandles[1]->setPos(event->scenePos().y() - createShapeMousePressLoc.y(),
                                          (event->scenePos().y() - createShapeMousePressLoc.y()) * (-1)); // y = createShapeHandles[0].y() * -1
            createShapeHandles[2]->setPos((event->scenePos().y() - createShapeMousePressLoc.y()) * (-1),
                                          event->scenePos().y() - createShapeMousePressLoc.y());
            createShapeHandles[3]->setPos((event->scenePos().y() - createShapeMousePressLoc.y()) * (-1),
                                          (event->scenePos().y() - createShapeMousePressLoc.y()) * (-1));
        }
        else
        {
            createShapeHandles[0]->setPos(event->scenePos().x() - createShapeMousePressLoc.x(), event->scenePos().y() - createShapeMousePressLoc.y());
            createShapeHandles[1]->setPos(event->scenePos().x() - createShapeMousePressLoc.x(), 0);
            createShapeHandles[2]->setPos(0, event->scenePos().y() - createShapeMousePressLoc.y());
            createShapeHandles[3]->setPos(0, 0);
        }
    }
    else
    {
        QGraphicsScene::mouseMoveEvent(event);
        selectionChangedSlot();
    }
}


void MyGraphicsScene::setCreateMode(unsigned int shapeId) {
    createShapeId = shapeId;
}

void MyGraphicsScene::selectionChangedSlot()
{
/*    if(modifyShapeHandles[0] != NULL)
    {
        this->removeItem(modifyShapeHandles[0]);
        this->removeItem(modifyShapeHandles[1]);
        this->removeItem(modifyShapeHandles[2]);
        this->removeItem(modifyShapeHandles[3]);
        modifyShapeHandles[0] = NULL;
        modifyShapeHandles[1] = NULL;
        modifyShapeHandles[2] = NULL;
        modifyShapeHandles[3] = NULL;
    }
    if(!this->selectedItems().empty())
    {
        qDebug() << selectedItems()[0]->x() << ", " << selectedItems()[0]->y();
        qDebug() << selectedItems()[0]->mapToScene(selectedItems()[0]->x(), selectedItems()[0]->y());
        QRectF selectionRect;
        for (int i = 0; i < selectedItems().length(); ++i) {
            QRectF boundingRect = QRectF(selectedItems()[i]->x(),
                                         selectedItems()[i]->y(),
                                         selectedItems()[i]->boundingRect().width(),
                                         selectedItems()[i]->boundingRect().height());
            selectionRect = boundingRect.united(selectionRect);
        }
        QColor brushColor;
        brushColor.setNamedColor("#E10C01");
        QBrush handleBrush = QBrush(brushColor);
        QPen handlePen = QPen(Qt::NoPen);
        QGraphicsRectItem *handle0 = this->addRect(selectionRect.x() + selectionRect.width(), selectionRect.y() + selectionRect.height(), 5, 5, handlePen, handleBrush);
        QGraphicsRectItem *handle1 = this->addRect(selectionRect.x() + selectionRect.width(), selectionRect.y() - 5, 5, 5, handlePen, handleBrush);
        QGraphicsRectItem *handle2 = this->addRect(selectionRect.x() - 5, selectionRect.y() + selectionRect.height(), 5, 5, handlePen, handleBrush);
        QGraphicsRectItem *handle3 = this->addRect(selectionRect.x() - 5, selectionRect.y() - 5, 5, 5, handlePen, handleBrush);
        modifyShapeHandles[0] = handle0;
        modifyShapeHandles[1] = handle1;
        modifyShapeHandles[2] = handle2;
        modifyShapeHandles[3] = handle3;
    }*/
}