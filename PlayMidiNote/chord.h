#ifndef CHORD_H
#define CHORD_H

#include "midioutput.h"
#include <QTimer>

class Chord : public QObject
{
    Q_OBJECT

public:
    Chord();
    Chord(int* array, drumstick::rt::MIDIOutput* midiOutput);

    void Strum();
    void Pick();


public slots:
    void update();

private:
  int* notes;
  int* zeigerT;
  int t;
  int* zeigerAufT;
  drumstick::rt::MIDIOutput* midiOut;
  QTimer timer;
};




#endif // CHORD_H
