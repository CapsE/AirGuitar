#include "WiiAnalyser.h"

WiiAnalyser::WiiAnalyser()
	:wiiThread(new WiimoteThread)
	,qTimer(new QElapsedTimer)
{
	connect(wiiThread, SIGNAL(sendUpdate(wiiinfo *)), this, SLOT(receiveUpdate(wiiinfo *)));
	connect(wiiThread, SIGNAL(sendConnect()), this, SLOT(receiveConnect()));
	qTimer->start();
	wiiThread->start();

	cacheCounter = 0;
	for (int i = 0; i < CACHE_SIZE; i++)
	{
		accelerationN[i] = 0;
		accelerationR[i] = 0;
		mainButton[i] = 0;
		nunButton[i] = 0;
	}
}

WiiAnalyser::~WiiAnalyser()
{
	wiiThread->terminate();
	delete wiiThread;
    delete qTimer;
}

void WiiAnalyser::receiveConnect()
{
	emit sendConnect();
}

void WiiAnalyser::receiveUpdate(wiiinfo *info)
{
	double millisecondsElapsed = qTimer->restart();

    mainButton[cacheCounter] = info->mainButton ? 1 : 0;
    nunButton[cacheCounter] = info->nunButton ? 1 : 0;

    checkForChord(info, millisecondsElapsed);
    checkForStrum(info);

    // qDebug() << steadyCountR << ";" << info->accY << ";" << filteredAccR << ";" << velocityR << ";" << positionR;

	if (rumbleTimer > 0)
	{
		wiiThread->doRumble(true);
		rumbleTimer -= millisecondsElapsed;
	}
	else
	{
		wiiThread->doRumble(false);
	}

    cacheCounter++;
    if (cacheCounter == CACHE_SIZE)
    {
        cacheCounter = 0;
    }
}

void WiiAnalyser::checkForChord(wiiinfo *info, double millisecondsElapsed)
{
    // simple check for data integrity:
    if (info->accY < 4 && info->accY > -4)
    {
        accelerationR[cacheCounter] = info->accY;
    }
    else
    {
        // Use last value:
        accelerationR[cacheCounter] =
                accelerationR[(cacheCounter + CACHE_SIZE - 1) % CACHE_SIZE];
    }

    // Reset / calibrate when remote is not moved:
    if (info->isSteadyRemote)
    {
        steadyCountR++;
        if (steadyCountR > CACHE_SIZE)
        {
            positionR = 0;
            velocityR = 0;
            // Check what the value is when remote is stationary
            calibrationR = lowPass(accelerationR,
                    CACHE_SIZE - 10,
					10);
        }
    }
    else
    {
        steadyCountR = 0;
    }

    // Low pass filter and apply calibration value
    filteredAccR = lowPass(accelerationR, 6, 0) - calibrationR;

    // Apply deadzone and bias:
    if (filteredAccR < DEADZONE_R * (1 + BIAS_R) &&
            filteredAccR > DEADZONE_R * (-1 + BIAS_R))
    {
        filteredAccR = 0;
    }
    if (filteredAccR > 0)
    {
        filteredAccR *= (1 - BIAS_R);
    }
    else
    {
        filteredAccR *= (1 + BIAS_R);
    }

    // Intgrate acceleration for velocity
    // Integrate velocity for position
    for (int i = millisecondsElapsed; i > 0; i--)
    {
		// TODO: Check if this is accurate enough
        velocityR = velocityR + filteredAccR +
                ((lastFilteredAccR - filteredAccR) / 2);
        positionR = positionR + velocityR +
                (lastVelocityR - velocityR) / 2;
    }
    lastFilteredAccR = filteredAccR;
    lastVelocityR = velocityR;

    // Reset on button press:
    if (lowPass(mainButton, 3, 0) > 0)
    {
        positionR = 0;
        velocityR = 0;
        emitedChord = false;
    }
    else
    {
        // Check for chord change condition
        if (positionR < -POSITION_THRESHOLD_R && !emitedChord)
        {
            emit sendChord(-1);
            emitedChord = true;
			rumbleTimer = RUMBLE_TIME;
        }
        if (positionR > POSITION_THRESHOLD_R && !emitedChord)
        {
            emit sendChord(1);
            emitedChord = true;
			rumbleTimer = RUMBLE_TIME;
		}
    }
}

void WiiAnalyser::checkForStrum(wiiinfo *info)
{
    // simple check for data integrity:
    if (info->nunAccZ < 4 && info->nunAccZ > -4)
    {
        accelerationN[cacheCounter] = info->nunAccZ;
    }
    else
    {
        // Use last value:
        accelerationN[cacheCounter] =
                accelerationN[(cacheCounter + CACHE_SIZE - 1) % CACHE_SIZE];
    }

    // Calibrate when nunchuck is not moved:
    if (info->isSteadyNun)
    {
        steadyCountN++;
        if (steadyCountN > 25)
        {
            // Check what the  average value is when remote is stationary
            calibrationN = lowPass(accelerationN,
                    CACHE_SIZE - 10,
					10);
        }
    }
    else
    {
        steadyCountN = 0;
    }

    // Low pass filter and apply calibration value
    filteredAccN = lowPass(accelerationN, 6, 0) - calibrationN;

    // Apply deadzone and bias:
	if (filteredAccN < DEADZONE_N * (1 + BIAS_N) &&
		filteredAccN > DEADZONE_N * (-1 + BIAS_N))
    {
		filteredAccN = 0;
    }
    if (filteredAccN > 0)
    {
		filteredAccN *= (1 - BIAS_N);
    }
    else
    {
		filteredAccN *= (1 + BIAS_N);
    }

	// Check for strum condition
	if (lowPass(nunButton, 3, 0) == 1)
	{
		if (filteredAccN > 0)
		{
			if (lastStateN == -1)
			{
				float emitValue = (lastPeakN + MIN_STRUM_FORCE) /
								(MAX_STRUM_FORCE - MIN_STRUM_FORCE);
				emitValue = emitValue < -1 ? -1 : emitValue;
				emit sendStrum(emitValue);
			}
			lastStateN = 1;
		}
		else if (filteredAccN < 0)
		{
			if (lastStateN == 1)
			{
				float emitValue = (lastPeakN - MIN_STRUM_FORCE) /
					(MAX_STRUM_FORCE - MIN_STRUM_FORCE);
				emitValue = emitValue > 1 ? 1 : emitValue;
				emit sendStrum(emitValue);
			}
			lastStateN = -1;
		}
	}
	else if (lowPass(nunButton, 3, 0) == 0)
	{
		lastStateN = 0;
	}

	// Check for peaks
	if ((filteredAccN < 0 &&
		lastPeakN > filteredAccN) ||
		(filteredAccN > 0 &&
		lastPeakN < filteredAccN))
	{
		lastPeakN = filteredAccN;
	}
}

float WiiAnalyser::lowPass(float cache[], int range, int offset)
{
	float result = 0;
	int index;
	for (int i = offset; i < range + offset; i++)
	{
		index = (cacheCounter + CACHE_SIZE - i) % CACHE_SIZE;
		result += cache[index];
	}
	result = result / range;
	return result;
}
