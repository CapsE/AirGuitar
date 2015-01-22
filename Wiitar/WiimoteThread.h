#ifndef WIIMOTETHREAD_H
#define WIIMOTETHREAD_H

#include <qthread.h>
#include <qdebug.h>
#include "wiiyourself/wiimote.h"

struct wiiinfo {
	float accY;
	float nunAccZ;
	bool nunButton;
	bool mainButton;
	bool isSteadyRemote;
	bool isSteadyNun;
};
// We have to register structs that we want to use with QObjects and SLOTs
Q_DECLARE_METATYPE(wiiinfo)

class WiimoteThread : public QThread
{
	Q_OBJECT

	public:
		WiimoteThread();
		~WiimoteThread();
		void doRumble(bool);

	protected:
		void run() Q_DECL_OVERRIDE;

	public slots :

	signals :
		void sendUpdate(wiiinfo *);
		void sendConnect();

	private:
		wiimote *remote;
};

#endif // WIIMOTETHREAD_H