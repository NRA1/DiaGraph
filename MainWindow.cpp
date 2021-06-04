//
// Created by nra1 on 4/25/21.
//

#include "MainWindow.h"


MainWindow::MainWindow()
    : QMainWindow()
{
    /// configure window
    this->setMinimumSize(1200, 750);

    /// configure scene
    //connect(mainScene, &QGraphicsScene::focusItemChanged, this, &MainWindow::focusItemChangedSlot);
    connect(mainScene, SIGNAL(createShapeSign(unsigned int, qreal, qreal, qreal, qreal)), this, SLOT(createShapeClickSlot(unsigned int, qreal, qreal, qreal, qreal)));
    connect(this, SIGNAL(setCreateModeSign(unsigned int)), mainScene, SLOT(setCreateMode(unsigned int)));
    connect(mainScene, SIGNAL(selectionChanged()), mainScene, SLOT(selectionChangedSlot()));
//    connect(mainScene, SIGNAL(changed(QList<QRectF>)), mainScene, SLOT(selectionChangedSlot()));

    /// configure graphics view
    mainView->setScene(mainScene);
    //mainView->setSceneRect(0, 0, mainView->width(), mainView->height()); // sets static scene size. Use that or line under this one
    connect(mainView, SIGNAL(resizeSceneSign()), mainView, SLOT(resizeScene()));
    connect(mainScene, SIGNAL(changed(QList<QRectF>)), mainView, SLOT(resizeScene()));
    //mainView->setViewport(new QOpenGLWidget); // makes text look extremely pixelated
    this->setCentralWidget(mainView);

//    mainView->setDragMode(QGraphicsView::ScrollHandDrag);
    mainView->scale(1, 1);
    mainView->setInteractive(true);
    mainView->setAlignment(Qt::AlignCenter);

    /// create dock
    QDockWidget *mainTD = new QDockWidget(tr("Tools"), this);
    mainTD->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
    addDockWidget(Qt::LeftDockWidgetArea, mainTD);
    // create grouping widget
    QWidget *tdWidgetGroup = new QWidget;
    QGridLayout *tdWidgetGroupLayout = new QGridLayout;
    tdWidgetGroupLayout->setAlignment(Qt::AlignTop);
    tdWidgetGroup->setLayout(tdWidgetGroupLayout);
    mainTD->setWidget(tdWidgetGroup);
    // create buttons and add them
    QPushButton *createRectTDBtn = new QPushButton("Add rectangle");
    connect(createRectTDBtn, SIGNAL(clicked(bool)), this, SLOT(createRectTDBtnClick()));
    QPushButton *createCircleTDBtn = new QPushButton("Add circle");
    connect(createCircleTDBtn, SIGNAL(clicked(bool)), this, SLOT(createCircleTDBtnClick()));
    QPushButton *createSquareTDBtn = new QPushButton("Add square");
    connect(createSquareTDBtn, SIGNAL(clicked(bool)), this, SLOT(createSquareTDBtnClick()));
    tdWidgetGroupLayout->addWidget(createRectTDBtn);
    tdWidgetGroupLayout->addWidget(createCircleTDBtn);
    tdWidgetGroupLayout->addWidget(createSquareTDBtn);

    // create default rect
//    createRect(0, 0);
}