/* 
* AvrSpi.cpp
*
* Created: 12/26/2019 5:10:27 AM
* Author: Formulatrix
*/


#include "AvrSpi.h"

void CAvrSpi::Init(CAvrGpio *ssPin,Prescaler prescaler,uint8_t clockMode,uint8_t lsbFirst)
{
	m_ssPin=ssPin;
	m_ssPin->Set();
	
	// set clock speed and mode
	SPCR= (lsbFirst<<5) |((clockMode&0x3)<<2)  | (prescaler & 0x3);
    SPSR|=prescaler>>2;
    
    // master mode
    SPCR|=1<<4;
	
	// enable spi
	SPCR|=1<<6;
    //SPCR=0x50; // FOSC/2 frekuensi transfer data SPI = 16MHZ/2 = 8MHz
    //SPSR=0x01;
    //SPCR = (1<<SPE)|(1<<MSTR)|(1<<SPR0);
}
	
void CAvrSpi::Transfer(char *data,uint8_t size)
{
	m_ssPin->Clear();
	for(uint8_t i=0;i<size;i++)
	{
		SPDR=*data++;
        while(!(SPSR & (1<<SPIF)));
	}
	m_ssPin->Set();
}

// default constructor
CAvrSpi::CAvrSpi()
{
} //AvrSpi

// default destructor
CAvrSpi::~CAvrSpi()
{
} //~AvrSpi
