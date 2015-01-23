#include "chord.h"

#include <QHash>
#include <QString>

#ifndef CHORDMANAGER_H
#define CHORDMANAGER_H

class ChordManager
{
public:
    ChordManager();
    void Strum(QString chord, float speed);
    void SetCapo(int amount);
    void SetInstrument(int instrument);
    void SetMidiMapper(QString mapper);
    QStringList GetMidiMappers();
    void Silence();
    QHash<QString, Chord*> getChords();

private:
    Chord eChord;
    Chord emChord;
    Chord fChord;
    Chord fmChord;
    Chord gChord;
    Chord gmChord;
    Chord aChord;
    Chord amChord;
    Chord hChord;
    Chord hmChord;
    Chord cChord;
    Chord cmChord;
    Chord dChord;
    Chord dmChord;

    QHash<QString, Chord*> chords;
    drumstick::rt::MIDIOutput midiOutput;
    QString midiMapper;
};

#endif // CHORDMANAGER_H
