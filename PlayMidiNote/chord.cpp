#include "chord.h"
#include <QDebug>
#include <QTimer>
#include <windows.h>

Chord::Chord(){}
Chord::Chord(int* array, drumstick::rt::MIDIOutput* midiOutput) : time(6)
{
    qDebug("Constructor called");
    notes = array;
    midiOut = midiOutput;

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(1000);
}

void Chord::Strum(){
    qDebug() << "Strumm";
    time = 0;
}

void Chord::Pick(){
    for(int i = 0; i < 6; i++){
        midiOut->sendNoteOn(1, notes[3], 127);
    }
}

void Chord::update(){

    qDebug() << notes[time];
    if(time < 6){
         midiOut->sendNoteOn(1, notes[time], 127);
         time++;
    }

}

