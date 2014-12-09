#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "chord.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    eChord(&midiOutput),
    fChord(&midiOutput),
    gChord(&midiOutput),
    aChord(&midiOutput),
    hChord(&midiOutput),
    cChord(&midiOutput),
    dChord(&midiOutput)
{
    ui->setupUi(this);
    QStringList connections = midiOutput.connections(true);
    ui->comboBox->addItems(connections);
    midiOutput.open("Microsoft GS Wavetable Synth");
    midichannel = ui->midichannel->value();

    //Setup der Akkorde
    //E
    QList<int> notes;
    notes.append(40);
    notes.append(47);
    notes.append(52);
    notes.append(55);
    notes.append(59);
    notes.append(64);
    eChord.SetNotes(notes);

    notes.clear();
    //F
    notes.append(41);
    notes.append(48);
    notes.append(53);
    notes.append(57);
    notes.append(60);
    notes.append(65);
    fChord.SetNotes(notes);

    notes.clear();
    //G
    notes.append(43);
    notes.append(47);
    notes.append(50);
    notes.append(55);
    notes.append(59);
    notes.append(67);
    gChord.SetNotes(notes);

    notes.clear();
    //A
    notes.append(45);
    notes.append(52);
    notes.append(57);
    notes.append(61);
    notes.append(64);
    aChord.SetNotes(notes);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_volume_valueChanged(int value)
{
   midiOutput.sendController(midichannel, 7, value);
}

void MainWindow::on_pitchbend_valueChanged(int value)
{
    //midiOutput.sendPitchBend(midichannel, value);

}

void MainWindow::on_midichannel_valueChanged(int arg1)
{
    midichannel = arg1;
}

void MainWindow::on_comboBox_activated(const QString &arg1)
{
    midiOutput.open(arg1);
}

void MainWindow::on_program_valueChanged(int arg1)
{
    midiOutput.sendProgram(midichannel, arg1);
}



void MainWindow::on_testButton_clicked()
{
    qDebug() << "TestButton clicked";
    QList<int> notes;
    notes.append(28);
    notes.append(35);
    notes.append(40);
    notes.append(55);
    notes.append(59);
    notes.append(64);
    Chord *e = new Chord(notes, &midiOutput);
    e->Strum(450, true);
}

void MainWindow::on_testButton_2_clicked()
{
    eChord.Strum(300, true);
}


void MainWindow::on_eChord_clicked()
{
    eChord.Strum(ui->pitchbend->value(), true);
}


void MainWindow::on_fChord_clicked()
{
    fChord.Strum(ui->pitchbend->value(), true);
}

void MainWindow::on_gChord_clicked()
{
    gChord.Strum(ui->pitchbend->value(), true);
}

void MainWindow::on_aChord_clicked()
{
    aChord.Strum(ui->pitchbend->value(), true);
}
