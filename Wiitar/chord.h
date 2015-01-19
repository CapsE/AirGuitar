#ifndef CHORD_H
#define CHORD_H

#include "midioutput.h"
#include <QTimer>

class Chord : public QObject
{
    Q_OBJECT

public:
    Chord();
    Chord(drumstick::rt::MIDIOutput* midiOutput);
    Chord(QList<int> array, drumstick::rt::MIDIOutput* midiOutput);

    void Strum(float speed);
    void Strum(float speed, int capo);
    void Pick();
    void SetNotes(QList<int> notes);
    void SetInstrument(int channel);

private slots:
    void update();

private:
  QList<int> notes;
  int time;
  int instrument;
  int capo;
  bool dir;
  drumstick::rt::MIDIOutput* midiOut;
  QTimer timer;
};




#endif // CHORD_H
