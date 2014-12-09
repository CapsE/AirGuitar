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

    void Strum(int speed, bool direction);
    void Pick();
    void SetNotes(QList<int> notes);

private slots:
    void update();

private:
  QList<int> notes;
  int time;
  bool dir;
  drumstick::rt::MIDIOutput* midiOut;
  QTimer timer;
};




#endif // CHORD_H
