#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QWheelEvent>
#include <QtMath>
#include <QObject>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_spinBox_valueChanged(int arg1);

private:
    Ui::MainWindow *ui;

    int angle,n=3;
    QPointF lastPos = QPointF(0,0);
    // Window redraw event handler
    void paintEvent(QPaintEvent* event);

    // Mouse Wheel Scroll Event Handler
    void wheelEvent(QWheelEvent* );
    void mousePressEvent(QMouseEvent *event);
};

#endif // MAINWINDOW_H
