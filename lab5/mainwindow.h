#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets>
#include "Model3D.h"

Model3D genTaskModel(int n);

class DrawArea:public QWidget{
    Q_OBJECT
    private:
        QMatrix4x4 mouseRotateMatr;
        Model3D model;
        QMatrix4x4 projectionMatr;
        QPoint lastPos;
        bool needColorize;
        QPoint colorizePoint;
    public:
        DrawArea();
        void paintEvent(QPaintEvent *event);
        void wheelEvent(QWheelEvent *event);
        void mouseMoveEvent(QMouseEvent *m_event);
        void mousePressEvent(QMouseEvent *event);
        void mouseDoubleClickEvent(QMouseEvent *m_event);
    public slots:
        void reGenModel(int n);
        void selectProjection(int index);
};

#endif // MAINWINDOW_H
