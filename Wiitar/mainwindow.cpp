#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    analyser(new WiiAnalyser),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    chordManager = new ChordManager();
    chordManager->SetMidiMapper("Microsoft GS Wavetable Synth");
<<<<<<< HEAD
    chordManager->SetInstrument(25);
//    chordManager->SetMidiMapper("CoolSoft VirtualMIDISynth");
//    chordManager->SetInstrument(27);
=======
    chordManager->SetInstrument(27);
>>>>>>> origin/master
    dragWidget = new DragWidget(this, chordManager);

//    QStringList connections = chordManager.GetMidiMappers();
    //ui->comboBox->addItems(connections);
    connect(analyser, SIGNAL(sendStrum(float)), this, SLOT(receiveStrum(float)));
    connect(analyser, SIGNAL(sendChord(float)), this, SLOT(receiveChord(float)));
    dragWidget->show();
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

//void MainWindow::on_volume_valueChanged(int value)
//{

//}

//void MainWindow::on_midichannel_valueChanged(int arg1)
//{

//}

//void MainWindow::on_comboBox_activated(const QString &arg1)
//{
//    chordManager.SetMidiMapper(arg1);
//}

//void MainWindow::on_program_valueChanged(int arg1)
//{
//    chordManager.SetInstrument(arg1);
//}



//void MainWindow::on_testButton_clicked()
//{
//    qDebug() << "TestButton clicked";

//}

//void MainWindow::on_testButton_2_clicked()
//{
//    //eChord.Strum(300, true);
//}


//void MainWindow::on_eChord_clicked()
//{
//    chordManager.Strum("E", 0.95f);
//}


//void MainWindow::on_fChord_clicked()
//{
//    chordManager.Strum("F", 0.95f);
//}

//void MainWindow::on_gChord_clicked()
//{
//    chordManager.Strum("G", 0.95f);
//}

//void MainWindow::on_aChord_clicked()
//{
//    chordManager.Strum("A", 0.95f);
//}

//void MainWindow::keyPressEvent(QKeyEvent *ev)
//{
//    qDebug() << ev->key();
////    if(ev->key() == 65){
////        chordToPlay = &eChord;
////    }else if(ev->key() == 83){
////        chordToPlay = &fChord;
////    }else if(ev->key() == 68){
////        chordToPlay = &gChord;
////    }else if(ev->key() == 70){
////        chordToPlay = &aChord;
////    }else if(ev->key() == 16777248){
////        chordToPlay->Strum(ui->pitchbend->value(), true);
////    }else if(ev->key() == 16777249){
////       chordToPlay->Strum(ui->pitchbend->value(), false);
////    }
//}

//void MainWindow::on_oneUp_clicked()
//{
//    float f = (float) ui->pitchbend->value() / 100;
//    chordManager.Strum(ui->one->text(), f);
//}

//void MainWindow::on_oneDown_clicked()
//{
//    float f = (float) ui->pitchbend->value() / 100;
//    chordManager.Strum(ui->one->text(), f* -1);
//}

//void MainWindow::on_twoUp_clicked()
//{
//    float f = (float) ui->pitchbend->value() / 100;
//    chordManager.Strum(ui->two->text(), f);
//}

//void MainWindow::on_twoDown_clicked()
//{
//    float f = (float) ui->pitchbend->value() / 100;
//    chordManager.Strum(ui->two->text(), f* -1);
//}

//void MainWindow::on_threeUp_clicked()
//{
//    float f = (float) ui->pitchbend->value() / 100;
//    chordManager.Strum(ui->three->text(), f);
//}

//void MainWindow::on_threeDown_clicked()
//{
//    float f = (float) ui->pitchbend->value() / 100;
//    chordManager.Strum(ui->three->text(), f* -1);
//}

//void MainWindow::on_fourUp_clicked()
//{
//    float f = (float) ui->pitchbend->value() / 100;
//    chordManager.Strum(ui->four->text(), f);
//}

//void MainWindow::on_fourDown_clicked()
//{
//    float f = (float) ui->pitchbend->value() / 100;
//    chordManager.Strum(ui->four->text(), f* -1);
//}
