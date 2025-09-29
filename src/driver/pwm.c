#include"./pwm.h"

void pwmInit()
{
    DDRB |= (1 << PB4);
    TCCR0 |= (1 << WGM00) | (1 << COM01) | (1 << WGM01) | (1 << CS02) | (1 << CS01);
}

void pwmPower(uint16_t data)
{

    switch(data)
    {
        case '2':
            OCR0 = 255;
            break;
        case '1':
            OCR0 = 127;
            break;
        case '0':
            OCR0 = 0;
            break;
    }


}

