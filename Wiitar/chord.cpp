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
    volume = speed * 10;
    capo = 0;
    if(speed < 0){
        dir = false;
        speed = speed * -1;
    }else{
        dir = true;
    }
    time = 0;
    timer.stop();
    update();
    qDebug() << 100 - speed*100;
    timer.start(100 - speed*100);
}

void Chord::Strum(float speed, int capot){
    qDebug() << speed;
    volume = speed * 10;
    capo = capot;
    if(speed < 0){
        dir = false;
        speed = speed * -1;
    }else{
        dir = true;
    }
    time = 0;
    timer.stop();
    update();
    qDebug() << 100 - speed*100;
    timer.start(100 - speed*100);

}

void Chord::Pick(){
    for(int i = 0; i < 6; i++){
        midiOut->sendNoteOn(instrument, notes[3], 127);
    }
}

void Chord::update(){

    if(time < notes.length() && time >= 0 && dir == true){
         midiOut->sendNoteOn(instrument, notes[time] + capo, 127 + volume);
         time++;
    }
    if(time < notes.length() && time >= 0 && dir == false){
         midiOut->sendNoteOn(instrument, notes[notes.length() -1 - time] + capo, 127 + volume);
         time++;
    }

}

void Chord::SetInstrument(int channel){
    instrument = channel;
}

