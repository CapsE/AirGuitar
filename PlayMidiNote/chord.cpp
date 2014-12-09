#include "chord.h"
#include <QDebug>
#include <QTimer>
#include <windows.h>
#include <math.h>

Chord::Chord(){}
Chord::Chord(drumstick::rt::MIDIOutput* midiOutput) : time(6), timer(this)
{
    qDebug("Constructor1 called");
    midiOut = midiOutput;

    connect(&timer, SIGNAL(timeout()), this, SLOT(update()));
    timer.start(35);
}

Chord::Chord(QList<int> array, drumstick::rt::MIDIOutput* midiOutput) : time(6), timer(this)
{
    qDebug("Constructor2 called");
    notes = array;
    midiOut = midiOutput;

    connect(&timer, SIGNAL(timeout()), this, SLOT(update()));
    timer.start(35);
    timer.setInterval(1000);
}

void Chord::SetNotes(QList<int> n){
    notes = n;
}

void Chord::Strum(int speed, bool direction){
    qDebug() << "Strumm";
    dir = direction;
    time = 0;
    timer.stop();
    update();
    timer.start(500 - speed);

}

void Chord::Pick(){
    for(int i = 0; i < 6; i++){
        midiOut->sendNoteOn(1, notes[3], 127);
    }
}

void Chord::update(){

    if(time < notes.length() -1 && time >= 0 && dir == true){
         midiOut->sendNoteOn(1, notes[time], 127);
         time++;
    }
    if(time < notes.length() -1 && time >= 0 && dir == false){
         midiOut->sendNoteOn(1, notes[notes.length() -1 - time], 127);
         time++;
    }

}

