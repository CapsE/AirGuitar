#ifndef WIIANALYSER_H
#define WIIANALYSER_H

#include "WiimoteThread.h"
#include <qdebug.h>
#include <QElapsedTimer>

class WiiAnalyser : public QObject
{
	Q_OBJECT

signals:
	void sendStrum(float);
    void sendChord(float);
	void sendConnect();

private slots:
    void receiveUpdate(wiiinfo *);
	void receiveConnect();

public:
	WiiAnalyser();
	~WiiAnalyser();
	bool isConnected();
    void lightLED(int);

private:
	WiimoteThread *wiiThread;
	QElapsedTimer *qTimer;

    void checkForChord(wiiinfo *, double);
    void checkForStrum(wiiinfo *);

    static const int CACHE_SIZE = 30;

    static const int POSITION_THRESHOLD_R = 300;
    float DEADZONE_R = 0.15;
    float BIAS_R = 0;
	int RUMBLE_TIME = 60;

	float DEADZONE_N = 0.25;
	float BIAS_N = 0;
	float MAX_STRUM_FORCE = 1.5;
	float MIN_STRUM_FORCE = DEADZONE_N;

	int cacheCounter;

	float mainButton[CACHE_SIZE];
	float accelerationR[CACHE_SIZE];
	int steadyCountR = 0;
    float velocityR = 0;
    float lastVelocityR = 0;
    float positionR = 0;
	float calibrationR = 0;
	float lastFilteredAccR = 0;
	float filteredAccR = 0;
	bool emitedChord = true;
	int rumbleTimer = 0;

	float nunButton[CACHE_SIZE];
	float accelerationN[CACHE_SIZE];
	int steadyCountN = 0;
	float calibrationN = 0;
    float filteredAccN = 0;
	int lastStateN = 0;
	float lastPeakN = 0;

	float lowPass(float [], int, int);
};

#endif // WIIANALYSER_H
