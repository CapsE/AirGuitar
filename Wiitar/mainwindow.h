#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>
#include "chord.h"
#include "midioutput.h"
#include "chordmanager.h"
#include "WiiAnalyser.h"

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

    void on_oneUp_clicked();

    void on_oneDown_clicked();

    void on_twoUp_clicked();

    void on_twoDown_clicked();

    void on_threeUp_clicked();

    void on_threeDown_clicked();

    void on_fourUp_clicked();

    void on_fourDown_clicked();

private:
    WiiAnalyser *analyser;
    Ui::MainWindow *ui;
    ChordManager chordManager;
};

#endif // MAINWINDOW_H
