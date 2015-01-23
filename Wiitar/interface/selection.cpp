#include "selection.h"

Selection::Selection(QWidget *parent) :
    QLabel(parent)
{
}

void Selection::setAccord(Accord *newAccord){
    accord = newAccord;
}

Accord* Selection::getAccord() {
    return accord;
}
