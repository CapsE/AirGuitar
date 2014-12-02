#include "chord.h"
#include <QDebug>
#include <QTimer>


Chord::Chord(){}
Chord::Chord(int* array, drumstick::rt::MIDIOutput* midiOutput)
{
    notes = array;
    midiOut = midiOutput;

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(500);

    int t = 0;
}

void Chord::Strum(){
    t = 0;
    qDebug() << t;
    qDebug() << "Strumm";
    //for(int i = 0; i < 6; i++){
    //    midiOut->sendNoteOn(0, notes[i], 127);
    //}
    qDebug() << "Strumm End";
}

void Chord::Pick(){
    for(int i = 0; i < 6; i++){
        qDebug() << notes[i];
    }
}

void Chord::update(){

    qDebug() << "Update";
    if(t < 6){
         midiOut->sendNoteOn(0, notes[t], 127);
         t++;
    }

}

