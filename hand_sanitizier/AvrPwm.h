/* 
* AvrPwm.h
*
* Created: 4/10/2020 9:38:32 PM
* Author: Formulatrix
*/


#ifndef __AVRPWM_H__
#define __AVRPWM_H__

#include "AvrTimer.h"

class CAvrPwm : public CAvrTimer
{
//variables
public:
    void SetTop(uint16_t top);
    void Enable(bool enable=true);
    void EnableChannel(uint8_t channel,bool enable=true);
    void Set(uint8_t channel,uint16_t value);
    uint16_t Get(uint8_t channel);

protected:
private:

//functions
public:
	CAvrPwm();
	~CAvrPwm();
protected:
private:
	CAvrPwm( const CAvrPwm &c );
	CAvrPwm& operator=( const CAvrPwm &c );

}; //AvrPwm

#endif //__AVRPWM_H__
