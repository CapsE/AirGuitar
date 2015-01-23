#include "chord.h"
#include <QDebug>
#include <QTimer>
#include <windows.h>
#include <math.h>

Chord::Chord(){

}
//Erstellt den Chord mit einer Referenz zum Midioutput. Töne werden später hinzugefügt.
Chord::Chord(drumstick::rt::MIDIOutput* midiOutput) : time(6), instrument(1), capo(0), timer(this)
{

    midiOut = midiOutput;

    connect(&timer, SIGNAL(timeout()), this, SLOT(update()));
    timer.start(35);
}

//Erstellt den Chord mit Tönen und Referenz zum Midioutput
Chord::Chord(QList<int> array, drumstick::rt::MIDIOutput* midiOutput) : time(6),instrument(1), timer(this)
{
    notes = array;
    midiOut = midiOutput;

    connect(&timer, SIGNAL(timeout()), this, SLOT(update()));
    timer.start(35);
    timer.setInterval(1000);
}

//Setzt die zu spielenden Noten. Sollte eigentlich nicht nötig sein nachdem die ursprünglichen Noten eingetragen wurden.
void Chord::SetNotes(QList<int> n){
    notes = n;
}

//Überladung von Strum um auf das Kapodaster verzichten zu können.
void Chord::Strum(float speed){
    Strum(speed, 0);
}

//Spielt den Akkord an. Setzt Geschwindigkeit und startet den Timer neu. Töne werden erst bei einem Update erzeugt.
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

//Methode nicht vollständig implementiert. Könnte in Zukunft genutzt werden um einen anderen Anspielmodus bereitzustellen.
void Chord::Pick(){
    for(int i = 0; i < 6; i++){
        midiOut->sendNoteOn(instrument, notes[3], 127);
    }
}

//Wird regelmäßig aufgerufen und spielt die Töne des Akkords der Reihe nach entweder von oben oder von unten
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

//Ändert das Instrument des Akkords. Wird vom Chordmanager immer für alle Akkorde aufgerufen.
void Chord::SetInstrument(int instru){
    instrument = instru;
    midiOut->sendProgram(0, instru);
}

