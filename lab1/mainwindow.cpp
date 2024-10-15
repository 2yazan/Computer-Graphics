#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "math.h"
#define M_PI 3.14159265358979323846

QPointF rotatePoint(QPointF center, QPointF point, double dgr) {
    QPointF p;
    double px = point.x() - center.x();
    double py = point.y() - center.y();
    double sn = sin((dgr * M_PI) / 180), cs = cos((dgr * M_PI) / 180);
    p.setX(center.x() + px * cs - py * sn);
    p.setY(center.y() + py * cs + px * sn);
    return p;
}

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    angle = 0;
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent* event) {
    QPainter painter(this);
    QColor White(255, 255, 255);
    QColor Black(0, 0, 0);
    painter.setPen(QPen(Black, 3));
    QPointF center = QPointF(width() * 0.5, height() * 0.5);
    double radius;
    if (width() > height())
        radius = (height() - 20) / 2;
    else
        radius = (width() - 20) / 2;
    if (width() < 30 || height() < 30)
        return;
    double rad[4] = {radius, radius - radius * 0.25, radius - radius * 0.5, radius - radius * 0.75};
    QRectF rectForEllipse;
    painter.setBrush(White);
    for (int i = 0; i < 4; i++) {
        rectForEllipse = QRectF(center.x() - rad[i], center.y() - rad[i], rad[i] * 2, rad[i] * 2);
        painter.drawEllipse(rectForEllipse);
    }

    // Squares
    int sqr = 8; // Increased number of squares
    QRectF Square = QRectF(center.x() - rad[3] * 0.375, center.y() - rad[3] * 1.85, rad[3] * 0.75, rad[3] * 0.75);
    QRectF SquareR = QRectF(-rad[3] * 0.375, -rad[3] * 0.375, rad[3] * 0.75, rad[3] * 0.75);
    double dgrS = angle;
    for (int i = 0; i < sqr; i++) {
        QColor Color = QColor::fromHsv(i * 360.0 / sqr, 255, 255);
        painter.setBrush(Color);
        painter.setPen(Color);
        painter.save();
        painter.translate(rotatePoint(center, Square.center(), dgrS));
        painter.rotate(dgrS);
        painter.drawRect(SquareR);
        painter.restore();
        dgrS += 360.0 / sqr;
    }

    // Triangles
    int trg = 15; // Increased number of triangles
    QRectF RectForT = QRectF(center.x() - rad[3] * 0.375, center.y() - rad[3] * 2.85, rad[3] * 0.75, rad[3] * 0.75);
    QRectF RectForTR = QRectF(-rad[3] * 0.375, -rad[3] * 0.375, rad[3] * 0.75, rad[3] * 0.75);
    QPolygonF Triangle;
    Triangle << QPointF(RectForTR.left(), RectForTR.bottom())
             << QPointF(RectForTR.center().x(), RectForTR.top())
             << QPointF(RectForTR.right(), RectForTR.bottom());
    double dgrT = angle;
    for (int i = 0; i < trg; i++) {
        QColor Color = QColor::fromHsv(i * 360.0 / trg, 255, 255);
        painter.setBrush(Color);
        painter.setPen(Color);
        painter.save();
        painter.translate(rotatePoint(center, RectForT.center(), dgrT));
        painter.rotate(dgrT);
        painter.drawPolygon(Triangle);
        painter.restore();
        dgrT += 360.0 / trg;
    }

    // Circles
    int rnd = 25; // Increased number of circles
    QRectF Round = QRectF(center.x() - rad[3] * 0.375, center.y() - rad[3] * 3.85, rad[3] * 0.75, rad[3] * 0.75);
    QRectF RoundR = QRectF(-rad[3] * 0.375, -rad[3] * 0.375, rad[3] * 0.75, rad[3] * 0.75);
    double dgrR = angle;
    for (int i = 0; i < rnd; i++) {
        QColor Color = QColor::fromHsv(i * 360.0 / rnd, 255, 255);
        painter.setBrush(Color);
        painter.setPen(Color);
        painter.save();
        painter.translate(rotatePoint(center, Round.center(), dgrR));
        painter.rotate(dgrR);
        painter.drawEllipse(RoundR);
        painter.restore();
        dgrR += 360.0 / rnd;
    }
}

void MainWindow::wheelEvent(QWheelEvent* wheelevent) {
    angle -= wheelevent->angleDelta().y() / 8;
    update();
}
