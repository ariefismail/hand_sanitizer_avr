/*
* AvrPwm.cpp
*
* Created: 4/10/2020 9:38:32 PM
* Author: Formulatrix
*/


#include "AvrPwm.h"

void CAvrPwm::SetTop(uint16_t top)
{
    ICR1=top;
}

void CAvrPwm::Enable(bool enable)
{
    if(enable)
    {
        TCCR1A|=1<<1;
        TCCR1B|=1<<4;
    }       
    else
    {
        TCCR1A&=~(3);  
        TCCR1B&=~(3<<3);   
    }
}   

void CAvrPwm::EnableChannel(uint8_t channel,bool enable)
{
    if(channel>1)
        return;
    if(enable)
        TCCR1A|=1<<(7-channel*2);
    else
        TCCR1A&=~(1<<(7-channel*2));
}

void CAvrPwm::Set(uint8_t channel,uint16_t value)
{
    switch(channel)
    {
        case 0:
            OCR1A = value;
            break;
            
        case 1:
            OCR1B = value;
            break;
    }
}

uint16_t CAvrPwm::Get(uint8_t channel)
{
    switch(channel)
    {
        case 0:
        return OCR1A;
        case 1:
        return OCR1B;
    }
}

// default constructor
CAvrPwm::CAvrPwm()
{
} //AvrPwm

// default destructor
CAvrPwm::~CAvrPwm()
{
} //~AvrPwm
