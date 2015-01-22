#include "chord.h"
#include <QDebug>
#include <QTimer>
#include <windows.h>
#include <math.h>

Chord::Chord(){

}
Chord::Chord(drumstick::rt::MIDIOutput* midiOutput) : time(6), instrument(1), capo(0), timer(this)
{

    midiOut = midiOutput;

    connect(&timer, SIGNAL(timeout()), this, SLOT(update()));
    timer.start(35);
}

Chord::Chord(QList<int> array, drumstick::rt::MIDIOutput* midiOutput) : time(6),instrument(1), timer(this)
{
    notes = array;
    midiOut = midiOutput;

    connect(&timer, SIGNAL(timeout()), this, SLOT(update()));
    timer.start(35);
    timer.setInterval(1000);
}

void Chord::SetNotes(QList<int> n){
    notes = n;
}

void Chord::Strum(float speed){
    qDebug() << speed;
    capo = 0;
    if(speed < 0){
        dir = false;
        speed = speed * -1;
    }else{
        dir = true;
    }
    volume = speed * 30;
    time = 0;
    timer.stop();
    update();
    qDebug() << 105 - speed*100;
    timer.start(105 - speed*100);
}

void Chord::Strum(float speed, int capot){
    qDebug() << speed;

    capo = capot;
    if(speed < 0){
        dir = false;
        speed = speed * -1;
    }else{
        dir = true;
    }
    volume = speed * 30;
    time = 0;
    timer.stop();
    update();
    qDebug() << 105 - speed*100;
    timer.start(105 - speed*100);

}

void Chord::Pick(){
    for(int i = 0; i < 6; i++){
        midiOut->sendNoteOn(instrument, notes[3], 127);
    }
}

void Chord::update(){

    if(time < notes.length() && time >= 0 && dir == true){
         midiOut->sendNoteOn(0, notes[time] + capo, 90 + volume);
         time++;
    }
    if(time < notes.length() && time >= 0 && dir == false){
         midiOut->sendNoteOn(0, notes[notes.length() -1 - time] + capo, 90 + volume);
         time++;
    }

}

void Chord::SetInstrument(int instru){
    instrument = instru;
    midiOut->sendProgram(0, instru);
}

