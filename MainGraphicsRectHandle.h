#ifndef MAINGRAPHICSRECTHANDLE_H
#define MAINGRAPHICSRECTHANDLE_H

#include <QGraphicsRectItem>

#include <QBrush>
#include <QPainter>

#include <QDebug>
#include <qsize.h>

class MainGraphicsRectHandle : public QGraphicsItem
{
public:
    MainGraphicsRectHandle(QPointF sPos, QSizeF sSize, QGraphicsItem *parent, int sId);

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0);

    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);

    QSizeF size() const;
    void setSize(QSizeF size);
private:
    QSizeF m_size;
    int id;

};

#endif
