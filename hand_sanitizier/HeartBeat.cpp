/* 
* HeartBeat.cpp
*
* Created: 12/28/2019 6:17:01 AM
* Author: Formulatrix
*/


#include "HeartBeat.h"

void CHeartBeat::Init(CAvrGpio *ledInstance,CAvrTimer *timerInstance,uint16_t period)
{
	m_led=ledInstance;
	m_timer.Init(timerInstance);
	m_timer.SetExpiry(period);
}
	
void CHeartBeat::Execute()
{
	if(!m_timer.HasElapsed())
		return;
	m_timer.Reset();
	m_led->Toggle();
	
}

// default constructor
CHeartBeat::CHeartBeat()
{
} //HeartBeat

// default destructor
CHeartBeat::~CHeartBeat()
{
} //~HeartBeat
