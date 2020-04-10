/* 
* Keypad.cpp
*
* Created: 12/28/2019 7:50:11 AM
* Author: Formulatrix
*/


#include "Keypad.h"

void CKeypad::Init(CAvrGpio *rowList,CAvrGpio *colList)
{
	for(uint8_t i=0;i<ROW_COUNT;i++)
    {
        m_row[i]=rowList++;    
        m_row[i]->Set();
    }
    for(uint8_t i=0;i<COL_COUNT;i++)
    {
        m_col[i]=colList++;
        m_col[i]->Set();
    }
    hexaKeys[0][0]='7';
    hexaKeys[0][1]='8';
    hexaKeys[0][2]='9';
    hexaKeys[0][3]='A';
    hexaKeys[1][0]='4';
    hexaKeys[1][1]='5';
    hexaKeys[1][2]='6';
    hexaKeys[1][3]='B';
    hexaKeys[2][0]='1';
    hexaKeys[2][1]='2';
    hexaKeys[2][2]='3';
    hexaKeys[2][3]='C';
    hexaKeys[3][0]='*';
    hexaKeys[3][1]='0';
    hexaKeys[3][2]='#';
    hexaKeys[3][3]='D';
}
	
char CKeypad::Scan()
{
    for(int8_t r=0;r<ROW_COUNT;r++)
    {
        m_row[r]->Clear();
        for(int8_t c=0;c<COL_COUNT;c++)
        {
            _delay_ms(1);
            if(m_col[c]->Get())
                continue;
            _delay_ms(200);
            m_row[r]->Set();
            return hexaKeys[r][c];
        }
        m_row[r]->Set();
    }
	return 0;
}

// default constructor
CKeypad::CKeypad()
{
} //Keypad

// default destructor
CKeypad::~CKeypad()
{
} //~Keypad
