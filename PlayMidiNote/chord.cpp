#include "chord.h"
#include <QDebug>
#include <QTimer>
#include <windows.h>
#include <math.h>

Chord::Chord(){}
Chord::Chord(drumstick::rt::MIDIOutput* midiOutput) : time(6)
{
    qDebug("Constructor1 called");
    midiOut = midiOutput;

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(35);
}

Chord::Chord(QList<int> array, drumstick::rt::MIDIOutput* midiOutput) : time(6)
{
    qDebug("Constructor2 called");
    notes = array;
    midiOut = midiOutput;

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(35);
}

void Chord::SetNotes(QList<int> n){
    notes = n;
}

void Chord::Strum(int speed, bool direction){
    qDebug() << "Strumm";
    timer.stop();
    timer.setInterval(500 - speed);
    dir = direction;
    time = 0;
}

void Chord::Pick(){
    for(int i = 0; i < 6; i++){
        midiOut->sendNoteOn(1, notes[3], 127);
    }
}

void Chord::update(){

    if(time < 5 && time >= 0 && dir == true){
         midiOut->sendNoteOn(1, notes[time], 127);
         time++;
    }
    if(time < 5 && time >= 0 && dir == false){
         midiOut->sendNoteOn(1, notes[5 - time], 127);
         time++;
    }

}

