/* 
* AvrSpi.h
*
* Created: 12/26/2019 5:10:27 AM
* Author: Formulatrix
*/


#ifndef __AVRSPI_H__
#define __AVRSPI_H__

#include <avr/io.h>
#include <stdint.h>

#include "AvrGpio.h"

class CAvrSpi
{
public:
	enum Prescaler{
			psc2=4,
			psc4=0,
			psc8=5,
			psc16=1,
			psc32=6,
			psc64=2,
			psc128=3,
		};
public:
	void Init(CAvrGpio *ssPin,Prescaler prescaler=psc2,uint8_t clockMode=0,uint8_t lsbFirst=0);
	void Transfer(char *data,uint8_t size);
	
	CAvrSpi();
	~CAvrSpi();
private:
	CAvrGpio *m_ssPin;
	CAvrSpi( const CAvrSpi &c );
	CAvrSpi& operator=( const CAvrSpi &c );

}; //AvrSpi

#endif //__AVRSPI_H__
