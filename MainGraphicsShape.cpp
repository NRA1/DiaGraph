#include "MainGraphicsShape.h"

MainGraphicsShape::MainGraphicsShape(QPointF sPos)
{
    setPos(sPos);
    setRect(QRectF(0, 0, 100, 50));
    setFlags(ItemIsFocusable | ItemIsSelectable | ItemIsMovable);
    setSelected(true);
    MainGraphicsHandles *handles = new MainGraphicsHandles(this);
    handles->isSelected();
}

MainGraphicsShape::MainGraphicsShape(QRectF sRect)
{
    setPos(QPointF(sRect.x(), sRect.y()));
    setRect(QRectF(0, 0, sRect.width(), sRect.height()));
    setFlags(ItemIsFocusable | ItemIsSelectable | ItemIsMovable);
    setSelected(true);
    MainGraphicsHandles *handles = new MainGraphicsHandles(this);
    handles->isSelected();
}

void MainGraphicsShape::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if(isSelected())
    {
        QPen pen(Qt::red, 1);
        painter->setPen(pen);
        showHandles();
    }
    else
    {
        QPen pen(Qt::black, 1);
        painter->setPen(pen);
        hideHandles();
    }
    painter->drawRect(rect());
}

QRectF MainGraphicsShape::boundingRect() const
{
    return rect();
}

void MainGraphicsShape::showHandles()
{
        childItems()[0]->setVisible(true);
}

void MainGraphicsShape::hideHandles()
{
        childItems()[0]->setVisible(false);
}

bool MainGraphicsShape::isSelected() const
{
    if(QGraphicsItem::isSelected() || static_cast<MainGraphicsHandles *>(childItems()[0])->isSelected())
        return true;
    return false;
}

QRectF MainGraphicsShape::rect() const
{
    return m_rect;
}

void MainGraphicsShape::setRect(QRectF sRect)
{
    QRectF oRect = rect();
    m_rect = sRect;
    update(rect());
}
