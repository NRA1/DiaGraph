#include "MainWindow.h"

MainWindow::MainWindow()
{
    this->resize(700, 500);
    createToolbars();
    createView();
}

void MainWindow::createToolbars()
{
    QToolBar *mainToolbar = new QToolBar();

    QSignalMapper *shapeBtnsSignalMapper = new QSignalMapper();
    QPushButton *shapeBtn1 = new QPushButton("Shape 1");
    connect(shapeBtn1, SIGNAL(clicked(bool)), shapeBtnsSignalMapper, SLOT(map()));
    shapeBtnsSignalMapper->setMapping(shapeBtn1, 0);
    connect(shapeBtnsSignalMapper, SIGNAL(mapped(int)), mainScene, SLOT(createShapeBtnClickSlot(int)));
    mainToolbar->addWidget(shapeBtn1);

    this->addToolBar(Qt::TopToolBarArea, mainToolbar);
}

void MainWindow::createView()
{
    //MainGraphicsShape *shape = new MainGraphicsShape(100, 100);
    //mainScene->addItem(shape);
    mainView->setScene(mainScene);
    this->setCentralWidget(mainView);
}