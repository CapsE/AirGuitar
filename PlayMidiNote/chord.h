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


private slots:
    void update();

private:
  int* notes;
  int time;
  drumstick::rt::MIDIOutput* midiOut;
  QTimer timer;
};




#endif // CHORD_H
