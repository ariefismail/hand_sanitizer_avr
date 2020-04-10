/* 
* Keypad.h
*
* Created: 12/28/2019 7:50:11 AM
* Author: Formulatrix
*/


#ifndef __KEYPAD_H__
#define __KEYPAD_H__

#define F_CPU 16000000UL

#include <string.h>
#include "AvrGpio.h"
#include <util/delay.h>

#define ROW_COUNT 4
#define COL_COUNT 4

class CKeypad
{
public:
	void Init(CAvrGpio *rowList,CAvrGpio *colList);
	char Scan();
	CKeypad();
	~CKeypad();
	
private:
    char hexaKeys[ROW_COUNT][COL_COUNT];
	CAvrGpio *m_row[ROW_COUNT];
	CAvrGpio *m_col[COL_COUNT];
	
private:
	CKeypad( const CKeypad &c );
	CKeypad& operator=( const CKeypad &c );

}; //Keypad

#endif //__KEYPAD_H__
