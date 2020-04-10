/* 
* HeartBeat.h
*
* Created: 12/28/2019 6:17:01 AM
* Author: Formulatrix
*/


#ifndef __HEARTBEAT_H__
#define __HEARTBEAT_H__

#include "Timeout.h"
#include "AvrGpio.h"

class CHeartBeat
{
//functions
public:
	void Init(CAvrGpio *ledInstance,CAvrTimer *timerInstance,uint16_t period);
	void Execute();
	CHeartBeat();
	~CHeartBeat();

private:
	CAvrGpio *m_led;
	CTimeout m_timer;

private:
	CHeartBeat( const CHeartBeat &c );
	CHeartBeat& operator=( const CHeartBeat &c );

}; //HeartBeat

#endif //__HEARTBEAT_H__
