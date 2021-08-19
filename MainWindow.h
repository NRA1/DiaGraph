#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "MainGraphicsView.h"
#include "MainGraphicsScene.h"

#include <QMainWindow>

#include <QToolBar>
#include <QPushButton>

#include <QSignalMapper>

// temp imports
#include <QDebug>

class MainWindow : public QMainWindow
{
    Q_OBJECT

 public:
    MainWindow();

    void createToolbars();
    void createView();

private:
    MainGraphicsView *mainView = new MainGraphicsView();
    MainGraphicsScene *mainScene = new MainGraphicsScene();

};

#endif
