//
// Created by nra1 on 4/26/21.
//

#ifndef VIEWER0_MYGRAPHICSVIEW_H
#define VIEWER0_MYGRAPHICSVIEW_H

class MyGraphicsView : public QGraphicsView
{
    Q_OBJECT


public:
    void wheelEvent(QWheelEvent *event) override;

    signals:
    void resizeSceneSign();

public slots:
    void resizeScene();

};

#endif //VIEWER0_MYGRAPHICSVIEW_H
