#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "drawablegenericgate.h"
using namespace Logicsim;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Gate *gate = new Gate();
    gate->setPos(0, 0);
    Gate *gate2 = new Gate();
    gate2->setPos(100, 100);
    QGraphicsScene *sc=new QGraphicsScene();
    sc->addItem(gate);
    sc->addItem(gate2);
    ui->graphicsView->setScene(sc);
}

MainWindow::~MainWindow()
{
    delete ui;
}
