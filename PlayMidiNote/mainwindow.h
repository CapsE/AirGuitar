#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>
#include "midioutput.h"
#include "chord.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void keyPressEvent(QKeyEvent *event);
    ~MainWindow();

private slots:
    void on_volume_valueChanged(int value);

    void on_pitchbend_valueChanged(int value);

    void on_midichannel_valueChanged(int arg1);

    void on_comboBox_activated(const QString &arg1);

    void on_program_valueChanged(int arg1);



    void on_testButton_clicked();


    void on_testButton_2_clicked();
    void on_eChord_clicked();

    void on_fChord_clicked();

    void on_gChord_clicked();

    void on_aChord_clicked();

private:
    Ui::MainWindow *ui;
    drumstick::rt::MIDIOutput midiOutput;
    int midichannel;
    Chord *e;
    Chord eChord;
    Chord fChord;
    Chord gChord;
    Chord aChord;
    Chord hChord;
    Chord cChord;
    Chord dChord;

    Chord *chordToPlay;
};

#endif // MAINWINDOW_H
