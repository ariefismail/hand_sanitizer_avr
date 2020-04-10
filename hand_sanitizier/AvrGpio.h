/* 
* AvrGpio.h
*
* Created: 12/26/2019 4:25:09 AM
* Author: Formulatrix
*/


#ifndef __AVRGPIO_H__
#define __AVRGPIO_H__

#include <avr/io.h>
#include <stdint.h>
#include <stdbool.h>

class CAvrGpio
{
//functions
public:
	void Init(volatile uint8_t* gpioBase,int8_t pinNumber,int mode);
	void Set();
	bool Get();
	void Clear();
	void Toggle();
	
	CAvrGpio();
	~CAvrGpio();

private:
	volatile uint8_t* m_gpioBase;
	int8_t m_pinNumber;
	
	CAvrGpio( const CAvrGpio &c );
	CAvrGpio& operator=( const CAvrGpio &c );

}; //AvrGpio

#endif //__AVRGPIO_H__
