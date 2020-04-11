/*
 * hand_sanitizier.cpp
 *
 * Created: 3/29/2020 11:11:40 AM
 * Author : Formulatrix
 */ 
#define F_CPU 16000000UL
#include <util/delay.h>
#include <avr/io.h>
#include "AvrGpio.h"
#include "AvrPwm.h"
#include "HeartBeat.h"
#include "PinMapping.h"
#include "lcd.h"


int main(void)
{
	// heartbeat init
	//CHeartBeat heartBeat;
	//CAvrGpio led;
	//CAvrTimer timer;
	//led.Init(PIN_HEARTBEAT,1);
	//timer.Init(CAvrTimer::psc256);
	//heartBeat.Init(&led,&timer,30000);
    
    // lcd init
    CAvrGpio pRs;
    CAvrGpio pEn;
    CAvrGpio pRw;
    CAvrGpio dT[4];
    CAvrGpio *pDt[4];
    pRs.Init(PIN_RS,1);
    pEn.Init(PIN_EN,1);
    pRw.Init(PIN_RW,1);
    dT[0].Init(PIN_DT4,1);
    dT[1].Init(PIN_DT5,1);
    dT[2].Init(PIN_DT6,1);
    dT[3].Init(PIN_DT7,1);
    for(uint8_t i=0;i<4;i++)
    {
        pDt[i] = &dT[i];
    };   
    CLcd lcd;
    lcd.Init(&pRs,&pEn,&pRw,pDt);
    lcd.On();
    lcd.ReturnHome();
    lcd.Clear();
    lcd.Lprintf("haha");
    
    CAvrGpio pwmB;
    pwmB.Init(&PIND,4,1);
    CAvrPwm pwm;
    pwm.Init(CAvrTimer::psc64);
    pwm.SetTop(2500);
    pwm.Enable();
    pwm.EnableChannel(1);
    pwm.Set(1,250);
    while (1) 
    {
        //heartBeat.Execute();
    }
}

