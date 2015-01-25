#include "selection.h"

Selection::Selection(QWidget *parent, int slot, QPoint pos) :
    QLabel(parent)
{
    this->slot = slot;
    this->pos = pos;
    setPixmap(QPixmap(":assets/images/slot" + QString::number(slot) +".png"));
    move(pos);
    show();
    setAttribute(Qt::WA_DeleteOnClose);
    accord = NULL;
}

void Selection::setAccord(Accord *newAccord){
    accord = newAccord;
}

Accord* Selection::getAccord() {       
        return accord;
}
