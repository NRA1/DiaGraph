//
// Created by nra1 on 4/25/21.
//

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

#ifndef VIEWER0_MAINWINDOW_H
#define VIEWER0_MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QPushButton>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QOpenGLWidget>
#include <QWheelEvent>
#include <QGraphicsSimpleTextItem>
#include <QDockWidget>
#include <QGridLayout>
#include <QDebug>
#include <QGraphicsSceneMouseEvent>
#include <QString>
#include <QGraphicsItem>

#include "MyGraphicsView.h"
#include "MyGraphicsScene.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();

    void createRect(qreal x, qreal y, qreal w, qreal h);
    void createCircle(qreal x, qreal y, qreal w, qreal h);
    void createSquare(qreal x, qreal y, qreal w, qreal h);

    // create main view and scene
    QGraphicsView *mainView = new MyGraphicsView;
    QGraphicsScene *mainScene = new MyGraphicsScene;

    signals:
    void setCreateModeSign(unsigned int shapeId);


public slots:
    void createRectTDBtnClick();
    void createCircleTDBtnClick();
    void createSquareTDBtnClick();

    void createShapeClickSlot(unsigned int shapeId, qreal x, qreal y, qreal w, qreal h);

};
#endif //VIEWER0_MAINWINDOW_H
