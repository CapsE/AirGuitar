#ifndef ACCORD_H
#define ACCORD_H

#include <QLabel>
#include "../chord.h"
#include "../chordmanager.h"

class Accord : public QLabel
{
    Q_OBJECT
public:
    explicit Accord(QWidget *parent = 0, QString chord ="", QPoint start = QPoint(0,0));
    bool isSelected();
    void setSelected(bool selection);
    QPoint getStartPos();
    void setStartPos(QPoint start);
    Chord chord;
signals:

private:
    bool selected;
    QPoint startPos;

public slots:

};

#endif // ACCORD_H
