/* 
* SevenSegment.h
*
* Created: 12/28/2019 9:53:38 AM
* Author: Formulatrix
*/


#ifndef __SEVENSEGMENT_H__
#define __SEVENSEGMENT_H__

#include "AvrSpi.h"
#include "Keypad.h"

#define NUM_OF_DIGIT 4

class CSevenSegment
{
public:
    void Init(CKeypad *keypadInstance,CAvrSpi *spiInstance);
	void Execute();
    
    CSevenSegment();
	~CSevenSegment();

private:
    char textToDisplay(char text);

private:
    CKeypad *m_keypad;
    CAvrSpi *m_spi;
    char m_display[NUM_OF_DIGIT];
    uint8_t m_index;

private:
	CSevenSegment( const CSevenSegment &c );
	CSevenSegment& operator=( const CSevenSegment &c );

}; //SevenSegment

#endif //__SEVENSEGMENT_H__
