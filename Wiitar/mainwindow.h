#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>
#include "midioutput.h"
#include "chord.h"
#include "chordmanager.h"

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
    Chord *chordToPlay;
    ChordManager chordManager;
};

#endif // MAINWINDOW_H
