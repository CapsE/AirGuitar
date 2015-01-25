#ifndef DRAGWIDGET_H
#define DRAGWIDGET_H

#include <QFrame>
#include <QLabel>
#include <QPushButton>
#include <QRect>
#include "accord.h"
#include "selection.h"
#include "button.h"
#include "../chordmanager.h"

class DragWidget : public QFrame
{
public:
    explicit DragWidget(QWidget *parent = 0, ChordManager* chordManager = NULL);
    Accord* akkordA;
    Accord* akkordH;
    Accord* akkordC;
    Accord* akkordD;
    Accord* akkordG;
    Accord* akkordE;
    Accord* akkordF;
    Accord* akkords[21];
    Accord* draggedAkkord;
    Selection* selection0;
    Selection* selection1;
    Selection* selection2;
    Selection* selection3;
    Selection* selections[4];
    ChordManager* chordManager;
    QLabel* selectedAccord0;
    QLabel* selectedAccord1;
    QLabel* selectedAccord2;
    QLabel* selectedAccord3;
    QLabel* chordTable;
    QLabel* guitarStrings;
    Button* button;

protected:
    void dragEnterEvent(QDragEnterEvent *event);
    void dragMoveEvent(QDragMoveEvent *event);
    void dropEvent(QDropEvent *event);
    void mousePressEvent(QMouseEvent *event);
    Selection* getSelection(Accord* accord);
    void moveChordTable();
signals:

public slots:

private:
    bool tableIsDown;
};

#endif // DRAGWIDGET_H
