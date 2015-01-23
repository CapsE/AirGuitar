#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QApplication"
#include "interface/dragwidget.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    dragWidget = new DragWidget(this);
    dragWidget->hide();
    logo = new QLabel();
    logo->setPixmap(QPixmap(":/images/logo.png"));
    logo->show();

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(hide_logo()));
    timer -> start(3000);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::hide_logo(){
    logo->hide();
    dragWidget->show();
}
