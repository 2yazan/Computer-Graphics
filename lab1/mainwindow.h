#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QWheelEvent>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    int angle;

    // Window redraw event handler
    void paintEvent(QPaintEvent* event);

    // Mouse Wheel Scroll Event Handler
    void wheelEvent(QWheelEvent* );
};
#endif // MAINWINDOW_H
