#ifndef BUTTON_H
#define BUTTON_H

#include <QLabel>

class Button : public QLabel
{
    Q_OBJECT
public:
    explicit Button(QWidget *parent = 0, QPoint downPos= QPoint(0,0), QPoint upPos= QPoint(0,0));
    void setButton(bool isDown);

signals:

public slots:

private:
    QPoint downPos;
    QPoint upPos;


};

#endif // BUTTON_H
