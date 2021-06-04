//
// Created by nra1 on 4/26/21.
//

#include "MainWindow.h"

void MainWindow::createShapeClickSlot(unsigned int shapeId, qreal x, qreal y, qreal w, qreal h)
{
    switch(shapeId)
    {
        case 1:
            createRect(x, y, w, h);
            break;
        case 2:
            createCircle(x, y, w, h);
            break;
        case 3:
            createSquare(x, y, w, h);
            break;
        default:
            qInfo("wrong shape id");
    }
}

void MainWindow::createRect(qreal x, qreal y, qreal w, qreal h)
{
    QGraphicsRectItem *rect = new QGraphicsRectItem(x, y, w, h);
    rect->setFlag(QGraphicsItem::ItemIsSelectable);
    rect->setFlag(QGraphicsItem::ItemIsMovable);
    rect->setCursor(Qt::SizeAllCursor);
    mainScene->addItem(rect);
    rect->setSelected(true);
}

void MainWindow::createCircle(qreal x, qreal y, qreal w, qreal h)
{
    QGraphicsEllipseItem *circle = new QGraphicsEllipseItem(x, y, w, h);
    circle->setFlag(QGraphicsItem::ItemIsSelectable);
    circle->setFlag(QGraphicsItem::ItemIsMovable);
    circle->setCursor(Qt::SizeAllCursor);
    mainScene->addItem(circle);

}

void MainWindow::createSquare(qreal x, qreal y, qreal w, qreal h)
{
    QGraphicsRectItem *square = new QGraphicsRectItem( x, y, w, h);
    square->setFlag(QGraphicsItem::ItemIsSelectable);
    square->setFlag(QGraphicsItem::ItemIsMovable);
    square->setCursor(Qt::SizeAllCursor);
    mainScene->addItem(square);
}