#ifndef MAINGRAPHICSHANDLES_H
#define MAINGRAPHICSHANDLES_H

#include "MainGraphicsRectHandle.h"

#include <QGraphicsItem>
#include <QGraphicsScene>

#include <QDebug>

class MainGraphicsHandles : public QGraphicsItem
{
public:
    MainGraphicsHandles(QGraphicsItem *parent);

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0);

    QGraphicsRectItem* addHandle(QPointF point);

    bool isSelected() const;

    void handleMoved(int id, QPointF pos);

    MainGraphicsRectHandle *handles[4];

};


#endif
