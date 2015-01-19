#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "chord.h"
#include "chordmanager.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    chordManager(),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QStringList connections = chordManager.GetMidiMappers();
    ui->comboBox->addItems(connections);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_volume_valueChanged(int value)
{

}

void MainWindow::on_midichannel_valueChanged(int arg1)
{

}

void MainWindow::on_comboBox_activated(const QString &arg1)
{
    chordManager.SetMidiMapper(arg1);
}

void MainWindow::on_program_valueChanged(int arg1)
{
    chordManager.SetInstrument(arg1);
}



void MainWindow::on_testButton_clicked()
{
    qDebug() << "TestButton clicked";
    QString a = ui->lineEdit->text();
    float f = (float) ui->pitchbend->value() / 100;
    chordManager.Strum(a, f);
}

void MainWindow::on_testButton_2_clicked()
{
    //eChord.Strum(300, true);
}


void MainWindow::on_eChord_clicked()
{
    chordManager.Strum("E", 0.95f);
}


void MainWindow::on_fChord_clicked()
{
    chordManager.Strum("Em", 0.95f);
}

void MainWindow::on_gChord_clicked()
{
    chordManager.Strum("G", 0.95f);
}

void MainWindow::on_aChord_clicked()
{
    chordManager.Strum("A", 0.95f);
}

void MainWindow::keyPressEvent(QKeyEvent *ev)
{
    qDebug() << ev->key();
//    if(ev->key() == 65){
//        chordToPlay = &eChord;
//    }else if(ev->key() == 83){
//        chordToPlay = &fChord;
//    }else if(ev->key() == 68){
//        chordToPlay = &gChord;
//    }else if(ev->key() == 70){
//        chordToPlay = &aChord;
//    }else if(ev->key() == 16777248){
//        chordToPlay->Strum(ui->pitchbend->value(), true);
//    }else if(ev->key() == 16777249){
//       chordToPlay->Strum(ui->pitchbend->value(), false);
//    }
}
