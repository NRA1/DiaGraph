//
// Created by nra1 on 4/25/21.
//

#include "MainWindow.h"
#include "MyGraphicsView.h"


// configure QGraphicsView scrolling
void MyGraphicsView::wheelEvent(QWheelEvent *event)
{
    if (event->modifiers() & Qt::ControlModifier) {
        // zoom
        const ViewportAnchor anchor = transformationAnchor();
        setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
        int angle = event->angleDelta().y();
        qreal factor;
        if (angle > 0) {
            factor = 1.1;
        } else {
            factor = 0.9;
        }
        scale(factor, factor);
        setTransformationAnchor(anchor);
    } else {
        QGraphicsView::wheelEvent(event);
    }
    resizeScene();
}

void MyGraphicsView::resizeScene()
{
    QRectF boundingRect = this->scene()->itemsBoundingRect();
    QRectF rect1 = QRectF(boundingRect.x() - (this->width() / 2), boundingRect.y() - (this->height() / 2),
                          boundingRect.width() * 2, boundingRect.height() * 2);
    QPointF view00 = this->mapToScene(0, 0);
    QRectF rect2 = QRectF(view00.x() - (this->width() / 2), view00.y() - (this->height() / 2), this->width() * 2, this->height() * 2);
    this->scene()->setSceneRect(rect1.united(rect2));


}
