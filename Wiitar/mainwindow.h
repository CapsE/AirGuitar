#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>
#include "chord.h"
#include "midioutput.h"
#include "chordmanager.h"
#include "interface/dragwidget.h"
#include "WiiAnalyser.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
//   void keyPressEvent(QKeyEvent *event);
    ~MainWindow();

public slots:
    void hide_logo();
    void setConnected();

private slots:
    void receiveStrum(float);

    void receiveChord(float);

private:
    WiiAnalyser *analyser;
    Ui::MainWindow *ui;
    ChordManager* chordManager;
    QTimer* timer;
    int currentChord = 0;
    DragWidget* dragWidget;
    bool isConnected;
};

#endif // MAINWINDOW_H
