/* 
* AvrTimer.h
*
* Created: 12/28/2019 5:40:39 AM
* Author: Formulatrix
*/


#ifndef __AVRTIMER_H__
#define __AVRTIMER_H__

#include <avr/io.h>
#include <stdint.h>

class CAvrTimer
{
public:
	enum avrPrescaler{
		psc1= 1,
		psc8= 2,
		psc64=3,
		psc256=4,
		psc1024=5
	};
public:
	void Init(avrPrescaler prescaler);
	uint16_t GetTick();

	CAvrTimer();
	~CAvrTimer();

private:


private:
	CAvrTimer( const CAvrTimer &c );
	CAvrTimer& operator=( const CAvrTimer &c );

}; //AvrTimer

#endif //__AVRTIMER_H__
