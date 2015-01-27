#include "accord.h"

Accord::Accord(QWidget *parent, QString chord, QPoint start) :
    QLabel(parent)
{
    selected = false;
    setPixmap(QPixmap(":assets/images/akkord" + chord + ".png"));
    startPos = start;
    move(startPos);
    show();
    setAttribute(Qt::WA_DeleteOnClose);
    this->chord = chord;

}

void Accord::setSelected(bool selection){

    if(selection){
        setPixmap(QPixmap(":assets/images/akkord" + chord + "selected.png"));
    }else{
        setPixmap(QPixmap(":assets/images/akkord" + chord + ".png"));
    }
    selected = selection;
}

bool Accord::isSelected(){
    return selected;
}
void Accord::setStartPos(QPoint start){
    startPos = start;
}

QPoint Accord::getStartPos(){
    return startPos;
}

QString Accord::getChord(){
    return chord;
}

