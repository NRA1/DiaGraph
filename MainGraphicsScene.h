#ifndef MAINGRAPHICSSCENE_H
#define MAINGRAPHICSSCENE_H

#include "MainGraphicsShape.h"

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsView>

#include <QDebug>

class MainGraphicsScene : public QGraphicsScene
{
    Q_OBJECT
public:

    MainGraphicsScene();

    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

public slots:
    void createShapeBtnClickSlot(int pathId);

private:
    QPointF pressPos = QPointF(0, 0);
    int creationShapePathId = -1;
};

#endif
