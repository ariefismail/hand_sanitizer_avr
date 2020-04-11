#include "lcd.h"


#include <stdio.h>
#include <util/delay.h>

void CLcd::Command(uint8_t command)
{
    Send(command, 0);
}

void CLcd::Write(uint8_t value)
{
    Send(value, 1);
}

void CLcd::Send(uint8_t value, uint8_t mode)
{
    if (mode)
    m_pRs->Set();
    else
    m_pRs->Clear();

    m_pRw->Clear();
    
    WriteNibble(value >> 4);
    WriteNibble(value);
}

void CLcd::WriteNibble(uint8_t nibble)
{
    for(uint8_t i=0;i<LCD_NUM_OF_DATA_PIN;i++)
    {
        if(nibble & (1<<i))
        m_pDt[i]->Set();
        else
        m_pDt[i]->Clear();
    }
    m_pEn->Clear();
    m_pEn->Set();
    m_pEn->Clear();
    
    _delay_ms(1);																// If delay less than this value, the data is not correctly displayed
}

void CLcd::Init(CAvrGpio *pRs,CAvrGpio *pEn,CAvrGpio *pRw,CAvrGpio **pDt,uint8_t numOfCol,uint8_t numOfRow) {
    // Configure pins as output
    m_pRs=pRs;
    m_pEn=pEn;
    m_pRw=pRw;
    m_pDt=pDt;
    m_col=numOfCol;
    m_row=numOfRow;
    m_buffer = (char*)malloc(m_col);
    
    // Wait for LCD to become ready (docs say 15ms+)
    _delay_ms(15);
    
    m_pEn->Clear();
    m_pRs->Clear();
    m_pRw->Clear();

    _delay_ms(5);

    WriteNibble(0x03); // Switch to 4 bit mode
    _delay_ms(5);

    WriteNibble(0x03); // 2nd time
    _delay_ms(5);

    WriteNibble(0x03); // 3rd time
    _delay_ms(5);

    WriteNibble(0x02); // Set 8-bit mode (?)

    Command(LCD_FUNCTIONSET | LCD_4BITMODE | LCD_2LINE | LCD_5x8DOTS);

    m_displayparams = LCD_CURSOROFF | LCD_BLINKOFF;
    Command(LCD_DISPLAYCONTROL | m_displayparams);
}

void CLcd::On(void)
{
    m_displayparams |= LCD_DISPLAYON;
    Command(LCD_DISPLAYCONTROL | m_displayparams);
}

void CLcd::Off(void)
{
    m_displayparams &= ~LCD_DISPLAYON;
    Command(LCD_DISPLAYCONTROL | m_displayparams);
}

void CLcd::Clear(void)
{
    Command(LCD_CLEARDISPLAY);
    _delay_ms(2);
}

void CLcd::ReturnHome(void)
{
    Command(LCD_RETURNHOME);
    _delay_ms(2);
}

void CLcd::EnableBlinking(void)
{
    m_displayparams |= LCD_BLINKON;
    Command(LCD_DISPLAYCONTROL | m_displayparams);
}

void CLcd::DisableBlinking(void)
{
    m_displayparams &= ~LCD_BLINKON;
    Command(LCD_DISPLAYCONTROL | m_displayparams);
}

void CLcd::EnableCursor(void)
{
    m_displayparams |= LCD_CURSORON;
    Command(LCD_DISPLAYCONTROL | m_displayparams);
}

void CLcd::DisableCursor(void)
{
    m_displayparams &= ~LCD_CURSORON;
    Command(LCD_DISPLAYCONTROL | m_displayparams);
}

void CLcd::ScrollLeft(void)
{
    Command(LCD_CURSORSHIFT | LCD_DISPLAYMOVE | LCD_MOVELEFT);
}

void CLcd::ScrollRight(void)
{
    Command(LCD_CURSORSHIFT | LCD_DISPLAYMOVE | LCD_MOVERIGHT);
}

void CLcd::SetLeftToRight(void) {
    m_displayparams |= LCD_ENTRYLEFT;
    Command(LCD_ENTRYMODESET | m_displayparams);
}

void CLcd::SetRightToLeft(void)
{
    m_displayparams &= ~LCD_ENTRYLEFT;
    Command(LCD_ENTRYMODESET | m_displayparams);
}

void CLcd::EnableAutoscroll(void)
{
    m_displayparams |= LCD_ENTRYSHIFTINCREMENT;
    Command(LCD_ENTRYMODESET | m_displayparams);
}

void CLcd::DisableAutoscroll(void) {
    m_displayparams &= ~LCD_ENTRYSHIFTINCREMENT;
    Command(LCD_ENTRYMODESET | m_displayparams);
}

void CLcd::CreateChar(uint8_t location, uint8_t *charmap) {
    Command(LCD_SETCGRAMADDR | ((location & 0x7) << 3));
    for (int i = 0; i < 8; i++)
    {
        Write(charmap[i]);
    }
}

void CLcd::SetCursor(uint8_t col, uint8_t row)
{
    static uint8_t offsets[] = { 0x00, 0x40, 0x14, 0x54 };
    Command(LCD_SETDDRAMADDR | (col + offsets[row]));
}

void CLcd::Lputs(const char *string)
{
    for (const char *it = string; *it; it++) {
        Write(*it);
    }
}

void CLcd::Lprintf(const char *format, ...)
{
    va_list args;

    va_start(args, format);
    vsnprintf(m_buffer, m_col + 1, format, args);
    va_end(args);

    Lputs(m_buffer);
}
