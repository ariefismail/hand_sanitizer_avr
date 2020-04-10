/* 
* Timeout.cpp
*
* Created: 12/28/2019 6:18:22 AM
* Author: Formulatrix
*/


#include "Timeout.h"

void CTimeout::Init(CAvrTimer *timerInstance)
{
	m_timer=timerInstance;
}

void CTimeout::Reset()
{
	m_prevTimer=m_timer->GetTick();
	m_hasElapsed=false;
}

void CTimeout::SetExpiry(uint16_t tick)
{
	m_expiry=tick;
	Reset();
}

bool CTimeout::HasElapsed()
{
	if(!m_hasElapsed)
	if(m_timer->GetTick()-m_prevTimer>=m_expiry)
	m_hasElapsed=true;
	
	return m_hasElapsed;
}

// default constructor
CTimeout::CTimeout()
{
} //Timeout

// default destructor
CTimeout::~CTimeout()
{
} //~Timeout
