#include "accord.h"
#include "../chordmanager.h"

Accord::Accord(QWidget *parent, QString chord, QPoint start) :
    QLabel(parent)
{
    ChordManager* chordmanager = new ChordManager();
    selected = false;
    setPixmap(QPixmap(":/images/akkord" + chord +".png"));
    QHash<QString, Chord*> chords = chordmanager->getChords();
    QHash<QString, Chord*>::iterator i;
     for (i = chords.begin(); i != chords.end(); ++i){
        if(i.key() == chord){
            //this->chord = i.key();
        }
     }
    startPos = start;
    move(startPos);
    show();
    setAttribute(Qt::WA_DeleteOnClose);

}

void Accord::setSelected(bool selection){

    selected = selection;
}

bool Accord::isSelected(){
    return selected;
}
void Accord::setStartPos(QPoint start){
//   startPos->setX(start.x());
//   startPos->setY(start.y());
    startPos = start;
}

QPoint Accord::getStartPos(){
    return startPos;
}

