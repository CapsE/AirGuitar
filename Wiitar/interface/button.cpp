#include "button.h"

Button::Button(QWidget *parent, QPoint downPos, QPoint upPos) :
    QLabel(parent)
{
    this->downPos = downPos;
    this->upPos = upPos;
    setPixmap(QPixmap(":assets/images/downButton.png"));
    move(upPos);
    show();

}

//QPoint Button::getPosition(){
//    if(this->pos() == downPos){
//        return downPos;
//    }else{
//        return upPos;
//    }

//}

void Button::setButton(bool isDown){
    if(isDown){
        move(downPos);
        setPixmap(QPixmap(":assets/images/upButton.png"));
    }else{
        move(upPos);
        setPixmap(QPixmap(":assets/images/downButton.png"));
    }
}
