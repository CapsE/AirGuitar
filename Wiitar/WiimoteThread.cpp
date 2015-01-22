#include "wiimotethread.h"

WiimoteThread::WiimoteThread()
	:remote(new wiimote)
{
}

WiimoteThread::~WiimoteThread()
{
    remote->Disconnect();
    delete remote;
}

void WiimoteThread::doRumble(bool rumble)
{
	remote->SetRumble(rumble);
}

void WiimoteThread::run()
{
	qDebug() << "Looking for Wiimote";
	while (!remote->Connect(wiimote::FIRST_AVAILABLE))
	{
		// TODO(yannick): Show connection status to user
		Sleep(1000);
	}

	emit sendConnect();

	// Just for fun, light all the remotes LEDs
	remote->SetLEDs(0x0f);

	// This report type allows for the nunchucks extension data to come through
	// but it disables IR dots, which we probably won't need.
	remote->SetReportType(wiimote::IN_BUTTONS_ACCEL_IR_EXT);
	
	// display the wiimote state data
    // TODO(yannick): Termination handling
    while (true)
	{
		while (remote->RefreshState() == NO_CHANGE)
		{
			Sleep(1); // don't hog the CPU if nothing changed
		}

		// did we loose the connection?
		if (remote->ConnectionLost())
		{
			qDebug() << "CONNECTION LOST";
			// TODO(yannick): tell user about this
			// TODO(yannick): initiate reconnection
		}

		// we package the actual info in a struct that is defined in WiimoteThread.h
		wiiinfo info;

		// int roll = remote->Acceleration.Orientation.Roll;
		// int pitch = remote->Acceleration.Orientation.Pitch;

		info.accY = remote->Acceleration.Y;
        info.mainButton = remote->Button.A() ? true : false;
		info.isSteadyRemote = remote->Acceleration.Orientation.UpdateAge == 0 ? true : false;

		if (remote->ExtensionType == wiimote_state::NUNCHUK)
		{
			info.nunAccZ = remote->Nunchuk.Acceleration.Z;
			info.nunButton = (remote->Nunchuk.C || remote->Nunchuk.Z) ? true : false;
			info.isSteadyNun = remote->Nunchuk.Acceleration.Orientation.UpdateAge == 0 ? true : false;
		}
		else
		{
			qDebug() << "Nunchuk not connected?";
		}

		emit sendUpdate(&info);
	}

	// disconnect (auto-happens on wiimote destruction anyway, but let's play nice)
	remote->Disconnect();
}
