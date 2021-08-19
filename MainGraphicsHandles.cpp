#include "MainGraphicsHandles.h"
#include "MainGraphicsShape.h"
#include <qpoint.h>
#include <qpolygon.h>

MainGraphicsHandles::MainGraphicsHandles(QGraphicsItem *parent)
{
    setParentItem(parent);
    MainGraphicsRectHandle *h0 = new MainGraphicsRectHandle(QPointF(-10, -10), QSizeF(10, 10), this, 0);
    handles[0] = h0;
    MainGraphicsRectHandle *h1 = new MainGraphicsRectHandle(QPointF(static_cast<MainGraphicsShape *>(parentItem())->rect().width(),
								    -10), QSizeF(10, 10), this, 1);
    handles[1] = h1;
    MainGraphicsRectHandle *h2 = new MainGraphicsRectHandle(QPointF(-10, static_cast<MainGraphicsShape *>(parentItem())->rect().height()),
							    QSizeF(10, 10), this, 2);
    handles[2] = h2;
    MainGraphicsRectHandle *h3 = new MainGraphicsRectHandle(QPointF(static_cast<MainGraphicsShape *>(parentItem())->rect().width(),
								    static_cast<MainGraphicsShape *>(parentItem())->rect().height()), QSizeF(10, 10), this, 3);
    handles[3] = h3;
}

bool MainGraphicsHandles::isSelected() const
{
    if(QGraphicsItem::isSelected())
        return true;
    else
    {
        for(int i = 0; i < childItems().size(); i++)
        {
            if(childItems()[i]->isSelected())
                return true;
        }
        return false;
    }
}

QRectF MainGraphicsHandles::boundingRect() const
{
    return childrenBoundingRect();
}

void MainGraphicsHandles::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
}

QGraphicsRectItem* MainGraphicsHandles::addHandle(QPointF point)
{
    QGraphicsRectItem *handle = new QGraphicsRectItem(point.x(), point.y(), 10, 10);
    handle->setFlags(ItemIsSelectable | ItemIsMovable);
    handle->setParentItem(this);
    return handle;
}

void MainGraphicsHandles::handleMoved(int id, QPointF pos)
{
    QPolygonF oRect = parentItem()->mapToScene(parentItem()->boundingRect());
    if (id == 0)
    {
        handles[1]->setPos(handles[1]->pos().x(), pos.y());
        handles[2]->setPos(pos.x(), handles[2]->pos().y());
    }
    else if (id == 1)
    {
        handles[0]->setPos(handles[0]->pos().x(), pos.y());
        handles[3]->setPos(pos.x(), handles[3]->pos().y());
    }
    else if (id == 2)
    {
        handles[3]->setPos(handles[3]->pos().x(), pos.y());
        handles[0]->setPos(pos.x(), handles[0]->pos().y());
    }
    else if (id == 3)
    {
        handles[2]->setPos(handles[2]->pos().x(), pos.y());
        handles[1]->setPos(pos.x(), handles[1]->pos().y());
    }
    QRectF rect(handles[0]->mapToParent(10, 10).x(), handles[0]->mapToParent(10, 10).y(),
		handles[3]->mapToParent(0, 0).x() - handles[0]->mapToParent(10, 10).x(),
		handles[3]->mapToParent(0, 0).y() - handles[0]->mapToParent(10, 10).y());
    static_cast<MainGraphicsShape *>(parentItem())->setRect(rect);

//    parentItem()->update(point.x(), point.y(), oRect.width(), oRect.height());
    parentItem()->scene()->update(oRect[0].x(), oRect[0].y(),
                                  oRect[2].x() - oRect[0].x(),
                                  oRect[2].y() - oRect[0].y());
}
