//
// Created by nra1 on 4/26/21.
//

#ifndef VIEWER0_MYGRAPHICSSCENE_H
#define VIEWER0_MYGRAPHICSSCENE_H

class MyGraphicsScene : public QGraphicsScene
{
    Q_OBJECT

public:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

    unsigned int createShapeId = 0;
    QPointF createShapeMousePressLoc;

    QGraphicsRectItem *createShapeHandles[4];
    QGraphicsRectItem *modifyShapeHandles[4] = {NULL, NULL, NULL, NULL};

    signals:
            void createShapeSign(unsigned int shapeId, qreal x, qreal y, qreal w, qreal h);
//            void selectionChanged();

public slots:
    void setCreateMode(unsigned int shapeId);
    void selectionChangedSlot();
};


#endif //VIEWER0_MYGRAPHICSSCENE_H
