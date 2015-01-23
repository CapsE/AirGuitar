#ifndef DRAGWIDGET_H
#define DRAGWIDGET_H

#include <QFrame>
#include <QLabel>
#include "accord.h"
#include "selection.h"

class DragWidget : public QFrame
{
public:
    explicit DragWidget(QWidget *parent = 0);
    Accord* akkord1;
    Accord* akkord2;
    Accord* akkord3;
    Accord* akkord4;
    Accord* draggedAkkord;
    Selection* selection1;
    Selection* selection2;
    Selection* selection3;
    Selection* selection4;


protected:
    void dragEnterEvent(QDragEnterEvent *event);
    void dragMoveEvent(QDragMoveEvent *event);
    void dropEvent(QDropEvent *event);
    void mousePressEvent(QMouseEvent *event);
signals:

public slots:

};

#endif // DRAGWIDGET_H
