#ifndef SELECTION_H
#define SELECTION_H

#include <QLabel>
#include "accord.h"

class Selection : public QLabel
{
    Q_OBJECT
public:
    explicit Selection(QWidget *parent = 0, int slot=0, QPoint pos=QPoint(0,0));
    void setAccord(Accord* newAccord);
    Accord* getAccord();
private:
    Accord* accord;
    int slot;
    QPoint pos;
signals:

public slots:

};

#endif // SELECTION_H
