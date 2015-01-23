#include "chordmanager.h"
#include "chord.h"
#include <QDebug>

//Initialisiert den Chordmanager und erstellt alle 7 Akkorde in Dur und Moll
ChordManager::ChordManager() :
    eChord(&midiOutput),
    emChord(&midiOutput),
    fChord(&midiOutput),
    fmChord(&midiOutput),
    gChord(&midiOutput),
    gmChord(&midiOutput),
    aChord(&midiOutput),
    amChord(&midiOutput),
    hChord(&midiOutput),
    hmChord(&midiOutput),
    cChord(&midiOutput),
    cmChord(&midiOutput),
    dChord(&midiOutput),
    dmChord(&midiOutput),

    chords()
{
    midiMapper = midiOutput.connections(true)[1];
    qDebug() << midiMapper;
    midiOutput.open(midiMapper);
    //Setup der Akkorde
    //E
    QList<int> notes;
    notes.append(40);
    notes.append(47);
    notes.append(52);
    notes.append(55);
    notes.append(59);
    notes.append(64);
    eChord.SetNotes(notes);
    chords.insert("E", &eChord);
    notes[3] -= 1;
    emChord.SetNotes(notes);
    chords.insert("Em", &emChord);

    notes.clear();
    //F
    notes.append(41);
    notes.append(48);
    notes.append(53);
    notes.append(57);
    notes.append(60);
    notes.append(65);
    fChord.SetNotes(notes);
    chords.insert("F", &fChord);
    notes[3] -= 1;
    fmChord.SetNotes(notes);
    chords.insert("Fm", &fmChord);

    notes.clear();
    //G
    notes.append(43);
    notes.append(47);
    notes.append(50);
    notes.append(55);
    notes.append(59);
    notes.append(67);
    gChord.SetNotes(notes);
    chords.insert("G", &gChord);
    notes[3] -= 1;
    gmChord.SetNotes(notes);
    chords.insert("Gm", &gmChord);

    notes.clear();
    //A
    notes.append(45);
    notes.append(52);
    notes.append(57);
    notes.append(61);
    notes.append(64);
    aChord.SetNotes(notes);
    chords.insert("A", &aChord);
    notes[3] -= 1;
    amChord.SetNotes(notes);
    chords.insert("Am", &amChord);

    notes.clear();
    //H
    notes.append(47);
    notes.append(54);
    notes.append(59);
    notes.append(61);
    notes.append(66);
    hChord.SetNotes(notes);
    chords.insert("H", &hChord);
    notes[3] -= 1;
    hmChord.SetNotes(notes);
    chords.insert("Hm", &hmChord);

    notes.clear();
    //C
    notes.append(48);
    notes.append(52);
    notes.append(55);
    notes.append(60);
    notes.append(64);
    cChord.SetNotes(notes);
    chords.insert("C", &cChord);
    notes[3] -= 1;
    cmChord.SetNotes(notes);
    chords.insert("Cm", &cmChord);

    notes.clear();
    //D
    notes.append(50);
    notes.append(57);
    notes.append(62);
    notes.append(66);
    dChord.SetNotes(notes);
    chords.insert("D", &dChord);
    notes[3] -= 1;
    dmChord.SetNotes(notes);
    chords.insert("Dm", &dmChord);
}

//Sucht den zu spielenden Akkord und ruft bei ihm die Strum-Methode auf.
void ChordManager::Strum(QString chord, float speed){
    QString sign = chord.mid(1,1);
    Chord* c;
    if(sign == "#"){
        chord = chord.mid(0,1) + chord.mid(2,1);
        c = chords[chord];
        c->Strum(speed, 1);
    }else if(sign == "b"){
        chord = chord.mid(0,1) + chord.mid(2,1);
        c = chords[chord];
        c->Strum(speed, -1);
    }else{
        c = chords[chord];
        c->Strum(speed);
    }
}

//Ändert das Instrument für alle Akkorde
void ChordManager::SetInstrument(int instrument){
    foreach(Chord* c, chords.values()){
        c->SetInstrument(instrument);
    }
}

//Wechselt das Zielprogramm zum abspielen der Midi sounds.
void ChordManager::SetMidiMapper(QString mapper){
    midiOutput.close();
    midiOutput.open(mapper);
}

//Nicht implementiert. Könnte verwedet werden um alle Akkorde anzuheben oder abzusenken
void ChordManager::SetCapo(int amount){

}

//Gibt eine Liste von verfügbaren Programme zur Midi-Wiedergabe zurück. Kann verwendet werden um diese in der UI anzuzeigen.
QStringList ChordManager::GetMidiMappers(){
    return midiOutput.connections(true);
}

//Beendet sofort alle Noten. Ist insbesondere für Instrumente wie Orgeln erforderlich die nicht automatisch den Ton beeden.
void ChordManager::Silence(){
    for(int i = 40; i < 70; i++){
        midiOutput.sendNoteOff(0, i, 128);
    }
}
