/*
* AvrGpio.cpp
*
* Created: 12/26/2019 4:25:09 AM
* Author: Formulatrix
*/


#include "AvrGpio.h"

void CAvrGpio::Init(volatile uint8_t* gpioBase,int8_t pinNumber,int mode)
{
	m_gpioBase=gpioBase;
	m_pinNumber=1<<pinNumber;
	if(mode)
		*(m_gpioBase+1)|=m_pinNumber;	
	else
		*(m_gpioBase+1)&=~(m_pinNumber);
}

void CAvrGpio::Set()
{
	*(m_gpioBase+2)|=m_pinNumber;
}

bool CAvrGpio::Get()
{
	return *(m_gpioBase)&m_pinNumber;
}

void CAvrGpio::Clear()
{
	*(m_gpioBase+2)&=~(m_pinNumber);
}

void CAvrGpio::Toggle()
{
	if(Get())
		Clear();
	else
		Set();
}

// default constructor
CAvrGpio::CAvrGpio()
{
} //AvrGpio

// default destructor
CAvrGpio::~CAvrGpio()
{
} //~AvrGpio
