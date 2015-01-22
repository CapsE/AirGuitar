#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include "dragwidget.h"
#include "output/chordmanager.h"
#include "output/chord.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QLabel logo;


public slots:
    void hide_logo();
private slots:


private:
    Ui::MainWindow *ui;
    QTimer* timer;
    DragWidget* dragWidget;
};

#endif // MAINWINDOW_H
