#include "MainGraphicsRectHandle.h"
#include "MainGraphicsHandles.h"

MainGraphicsRectHandle::MainGraphicsRectHandle(QPointF sPos, QSizeF sSize, QGraphicsItem *parent, int sId)
{
    setParentItem(parent);
    setFlags(ItemIsSelectable | ItemIsMovable);
    setSize(sSize);
    setPos(sPos);    
    id = sId;
}

QRectF MainGraphicsRectHandle::boundingRect() const
{
    return QRectF(0, 0, size().width(), size().height());
}


void MainGraphicsRectHandle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QBrush brush(Qt::red);
    painter->setBrush(brush);
    painter->setPen(nullptr);
    painter->drawRect(QRectF(0, 0, size().width(), size().height()));
}

void MainGraphicsRectHandle::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsItem::mousePressEvent(event);
}

void MainGraphicsRectHandle::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    static_cast<MainGraphicsHandles *>(parentItem())->handleMoved(id, this->pos());
    QGraphicsItem::mouseMoveEvent(event);
}

QSizeF MainGraphicsRectHandle::size() const
{
    return m_size;
}

void MainGraphicsRectHandle::setSize(QSizeF size)
{
    m_size = size;
}
