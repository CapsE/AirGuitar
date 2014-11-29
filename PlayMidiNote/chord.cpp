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

    int * zeigerT = 0;
    int t = 6;
    zeigerT = &t;
}

void Chord::Strum(){

    qDebug() << *zeigerT;
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

    qDebug() << notes[t];
    qDebug() << "Update";
    if(t < 6){
         midiOut->sendNoteOn(0, notes[t], 127);
         t++;
    }

}

