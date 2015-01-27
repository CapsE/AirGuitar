#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    analyser(new WiiAnalyser),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    showFullScreen();

    chordManager = new ChordManager();
    chordManager->SetMidiMapper("CoolSoft VirtualMIDISynth");
    chordManager->SetInstrument(120);

    dragWidget = new DragWidget(this, chordManager);

    isConnected = false;

    connect(analyser, SIGNAL(sendStrum(float)), this, SLOT(receiveStrum(float)));
    connect(analyser, SIGNAL(sendChord(float)), this, SLOT(receiveChord(float)));
    connect(analyser, SIGNAL(sendConnect()), this, SLOT(setConnected()));

    dragWidget->show();

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(hide_logo()));
    timer -> start(3000);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete analyser;
}

void MainWindow::receiveStrum(float strength)
{
    qDebug() << "Received Strum:" << strength;
    chordManager->Silence();
    QString chordString;
    if (currentChord == 0)
    {
        chordString = dragWidget->selection0->getAccord()->getChord();
        qDebug()<<chordString;
    }
    if (currentChord == 1)
    {
        chordString = dragWidget->selection1->getAccord()->getChord();
        qDebug()<<chordString;
    }
    if (currentChord == 2)
    {
        chordString = dragWidget->selection2->getAccord()->getChord();
        qDebug()<<chordString;
    }
    if (currentChord == 3)
    {
        chordString = dragWidget->selection3->getAccord()->getChord();
        qDebug()<<chordString;
    }
    chordManager->Strum(chordString, strength);
}

void MainWindow::receiveChord(float direction)
{
    chordManager->Silence();
    currentChord += direction;
    if (currentChord < 0)
    {
        currentChord = 0;
    }
    if (currentChord > 3)
    {
        currentChord = 3;
    }
    analyser->lightLED(currentChord);

    dragWidget->highlightSelection(currentChord);
    qDebug() << "Slot:" << currentChord << "Direction:" << direction;
}

void MainWindow::hide_logo(){
//    if(!(isConnected)){
//        timer -> start(2000);
//    }else{
        dragWidget->startscreen->hide();
//    }
}

void MainWindow::setConnected(){
    isConnected = true;
}

void MainWindow::keyPressEvent(QKeyEvent *event){
    if(event->key() == Qt::Key_Escape){
    this->close();}
}
