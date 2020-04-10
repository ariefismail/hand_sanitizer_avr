/*
* SevenSegment.cpp
*
* Created: 12/28/2019 9:53:38 AM
* Author: Formulatrix
*/


#include "SevenSegment.h"

void CSevenSegment::Init(CKeypad *keypadInstance,CAvrSpi *spiInstance)
{
    m_keypad=keypadInstance;
    m_spi=spiInstance;
    char clearByte[NUM_OF_DIGIT];
    memset(clearByte,0xff,NUM_OF_DIGIT);    
    m_spi->Transfer(clearByte,NUM_OF_DIGIT);
}

void CSevenSegment::Execute()
{
    char key=m_keypad->Scan();
    if(key==0)
    return;
    char dataSend[NUM_OF_DIGIT];
    if(key!='C')
    {
        // stack data structure
        for(uint8_t i=NUM_OF_DIGIT;i>1;i--)
        {
            m_display[i-1]=m_display[i-2];
        }
        m_display[0]=key;
        
        for(uint8_t i=0;i<NUM_OF_DIGIT;i++)
        {
            dataSend[i]=~(textToDisplay(m_display[i]));
        }
    }
    else
    {
        memset(m_display,0,sizeof(m_display));
        memset(dataSend,0xff,sizeof(dataSend));
        m_index=0;
    }

    m_spi->Transfer(dataSend,NUM_OF_DIGIT);
    
}

char CSevenSegment::textToDisplay(char text)
{
    switch(text){
        case '0':return 0b01111111;
        case '1':return 0b01100000;
        case '2':return 0b10110110;
        case '3':return 0b10011110;
        case '4':return 0b11001100;
        case '5':return 0b11011010;
        case '6':return 0b11111010;
        case '7':return 0b00001110;
        case '8':return 0b11111110;
        case '9':return 0b11011110;
        case 'A':return 0b11101110;
        case 'B':return 0b11111000;
        case 'C':return 0b11110010;
        case 'D':return 0b10111100;
        case 'E':return 0b10011110;
        case 'F':return 0b10001110;
        default: return 0;
    }
}


// default constructor
CSevenSegment::CSevenSegment()
{
    memset(m_display,0,sizeof(m_display));
    m_index=0;
} //SevenSegment

// default destructor
CSevenSegment::~CSevenSegment()
{
} //~SevenSegment
