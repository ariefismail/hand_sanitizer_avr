/* 
* Timeout.h
*
* Created: 12/28/2019 6:18:22 AM
* Author: Formulatrix
*/


#ifndef __TIMEOUT_H__
#define __TIMEOUT_H__

#include "AvrTimer.h"

class CTimeout
{
public:
	void Init(CAvrTimer *timerInstance);
	void Reset();
	void SetExpiry(uint16_t tick);
	bool HasElapsed();
	
	CTimeout();
	~CTimeout();
private:
	CAvrTimer *m_timer;
	uint16_t m_expiry;
	uint16_t m_prevTimer;
	bool m_hasElapsed;
		
private:
	CTimeout( const CTimeout &c );
	CTimeout& operator=( const CTimeout &c );

}; //Timeout

#endif //__TIMEOUT_H__
