#ifndef __LCD_H__
#define __LCD_H__

#define F_CPU 16000000UL
#include <stdint.h>
#include <stdarg.h>
#include <stdlib.h>
#include <avr/io.h>
#include <util/delay.h>
#include "AvrGpio.h"

// The rest should be left alone
#define LCD_CLEARDISPLAY   0x01
#define LCD_RETURNHOME     0x02
#define LCD_ENTRYMODESET   0x04
#define LCD_DISPLAYCONTROL 0x08
#define LCD_CURSORSHIFT    0x10
#define LCD_FUNCTIONSET    0x20
#define LCD_SETCGRAMADDR   0x40
#define LCD_SETDDRAMADDR   0x80

#define LCD_ENTRYRIGHT          0x00
#define LCD_ENTRYLEFT           0x02
#define LCD_ENTRYSHIFTINCREMENT 0x01
#define LCD_ENTRYSHIFTDECREMENT 0x00

#define LCD_DISPLAYON  0x04
#define LCD_DISPLAYOFF 0x00
#define LCD_CURSORON   0x02
#define LCD_CURSOROFF  0x00
#define LCD_BLINKON    0x01
#define LCD_BLINKOFF   0x00

#define LCD_DISPLAYMOVE 0x08
#define LCD_CURSORMOVE  0x00
#define LCD_MOVERIGHT   0x04
#define LCD_MOVELEFT    0x00

#define LCD_8BITMODE 0x10
#define LCD_4BITMODE 0x00
#define LCD_2LINE    0x08
#define LCD_1LINE    0x00
#define LCD_5x10DOTS 0x04
#define LCD_5x8DOTS  0x00

#define LCD_NUM_OF_DATA_PIN 4

class CLcd{
    public:
    void Init(CAvrGpio *pRs,CAvrGpio *pEn,CAvrGpio *pRw,CAvrGpio **pDt,uint8_t numOfCol=16,uint8_t numOfRow=2);

    void Command(uint8_t command);
    void Write(uint8_t value);

    void On(void);
    void Off(void);

    void Clear(void);
    void ReturnHome(void);

    void EnableBlinking(void);
    void DisableBlinking(void);

    void EnableCursor(void);
    void DisableCursor(void);

    void ScrollLeft(void);
    void ScrollRight(void);

    void SetLeftToRight(void);
    void SetRightToLeft(void);

    void EnableAutoscroll(void);
    void DisableAutoscroll(void);

    void CreateChar(uint8_t location, uint8_t *charmap);

    void SetCursor(uint8_t col, uint8_t row);

    void Lputs(const char *string);
    void Lprintf(const char *format, ...);
    
    public:
    CLcd(){};
    ~CLcd(){};

private:
    void Send(uint8_t value, uint8_t mode);
    void WriteNibble(uint8_t nibble);
        
private:
    CAvrGpio *m_pRs;
    CAvrGpio *m_pEn;
    CAvrGpio *m_pRw;
    CAvrGpio **m_pDt;
    uint8_t m_col;
    uint8_t m_row;
    uint8_t m_displayparams;
    char *m_buffer;
};
#endif