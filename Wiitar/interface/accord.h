#ifndef ACCORD_H
#define ACCORD_H

#include <QLabel>

class Accord : public QLabel
{
    Q_OBJECT
public:
    explicit Accord(QWidget *parent = 0, QString chord ="", QPoint start = QPoint(0,0));
    bool isSelected();
    void setSelected(bool selection);
    QPoint getStartPos();
    void setStartPos(QPoint start);
    QString getChord();
signals:

private:
    bool selected;
    QPoint startPos;
    QString chord;
public slots:

};

#endif // ACCORD_H
