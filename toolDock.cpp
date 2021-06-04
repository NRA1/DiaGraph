//
// Created by nra1 on 4/26/21.
//

#include "MainWindow.h"

void MainWindow::createRectTDBtnClick()
{
//    mainView->setDragMode(QGraphicsView::NoDrag);
    mainView->setCursor(Qt::CrossCursor);
    for (int i = 0; i < mainScene->items().length(); i++)
    {
        mainScene->items()[i]->setEnabled(false);
    }
    emit setCreateModeSign(1);
}

void MainWindow::createCircleTDBtnClick()
{
//    mainView->setDragMode(QGraphicsView::NoDrag);
    mainView->setCursor(Qt::CrossCursor);
    for (int i = 0; i < mainScene->items().length(); i++)
    {
        mainScene->items()[i]->setEnabled(false);
    }
    emit setCreateModeSign(2);
}

void MainWindow::createSquareTDBtnClick()
{
//    mainView->setDragMode(QGraphicsView::NoDrag);
    mainView->setCursor(Qt::CrossCursor);
    for (int i = 0; i < mainScene->items().length(); i++)
    {
        mainScene->items()[i]->setEnabled(false);
    }
    emit setCreateModeSign(3);
}