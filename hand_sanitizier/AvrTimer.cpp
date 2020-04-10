/* 
* AvrTimer.cpp
*
* Created: 12/28/2019 5:40:39 AM
* Author: Formulatrix
*/


#include "AvrTimer.h"

void CAvrTimer::Init(avrPrescaler prescaler)
{
	TCCR1B=(uint8_t)prescaler;
}

uint16_t CAvrTimer::GetTick()
{
	return TCNT1;
}

// default constructor
CAvrTimer::CAvrTimer()
{
} //AvrTimer

// default destructor
CAvrTimer::~CAvrTimer()
{
} //~AvrTimer
