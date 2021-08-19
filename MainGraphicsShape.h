#ifndef MAINGRAPHICSSHAPE_H
#define MAINGRAPHICSSHAPE_H

#include <QGraphicsItem>

#include "MainGraphicsHandles.h"

#include <QDebug>

class MainGraphicsShape : public QGraphicsItem
{
public:
    MainGraphicsShape(QPointF sPos);
    MainGraphicsShape(QRectF sRect);

    QRectF boundingRect() const;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    bool isSelected() const;

    void showHandles();
    void hideHandles();

    QRectF rect() const;
    void setRect(QRectF sRect);

private:
    QRectF m_rect;
};


#endif
