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
    Accord* akkordAm;
    Accord* akkordHm;
    Accord* akkordCm;
    Accord* akkordDm;
    Accord* akkordGm;
    Accord* akkordEm;
    Accord* akkordFm;
    Accord* akkords[21];
    Accord* draggedAkkord;
    Selection* selection0;
    Selection* selection1;
    Selection* selection2;
    Selection* selection3;
    Selection* selections[4];
    ChordManager* chordManager;
    QLabel* selectedSlot0;
    QLabel* selectedSlot1;
    QLabel* selectedSlot2;
    QLabel* selectedSlot3;
    QLabel* chordTable;
    QLabel* guitarStrings;
    QLabel* unselect0;
    QLabel* unselect1;
    QLabel* unselect2;
    QLabel* unselect3;
    QLabel* unselects[4];
    QLabel* selectedSlots[4];
    Button* button;
    void highlightSelection(int slot);

protected:
    void dragEnterEvent(QDragEnterEvent *event);
    void dragMoveEvent(QDragMoveEvent *event);
    void dropEvent(QDropEvent *event);
    void mousePressEvent(QMouseEvent *event);
    Selection* getSelection(Accord* accord);
    void moveChordTable();
    void loadAccords();
    void loadSelections();
    void loadSelectedSlots();
    void loadUnselects();
signals:

public slots:

private:
    bool tableIsDown;
};

#endif // DRAGWIDGET_H
