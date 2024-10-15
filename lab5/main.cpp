#include <QtWidgets>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DrawArea* label = new DrawArea;
    QWidget *settings = new QWidget;
    QVBoxLayout *layout = new QVBoxLayout;
    QLabel *sName = new QLabel("Number of sides:");
    QLabel *bSelect = new QLabel("Design type:");
    QSpinBox *s = new QSpinBox;
    QComboBox *b = new QComboBox;

    b->addItem(QString("central"));
    b->addItem(QString("oblique cabinet"));
    b->addItem(QString("free oblique"));
    b->addItem(QString("parallel"));

    s->setRange(3,30);

    QObject::connect(s,SIGNAL(valueChanged(int)),label,SLOT(reGenModel(int)));
    QObject::connect(b,SIGNAL(currentIndexChanged(int)),label,SLOT(selectProjection(int)));

    layout->addWidget(sName);
    layout->addWidget(s);
    layout->addWidget(bSelect);
    layout->addWidget(b);
    settings->setLayout(layout);
    settings->show();
    label->show();
    return a.exec();
}
