#include "./millis.h"

volatile uint32_t timer0_Millis = 0;

ISR(TIMER0_COMP_vect)
{
    timer0_Millis++;                    // ISR함수가 1ms 마다 호출되므로 1ms씩 증가됨
}

void millisInit()
{
    // Timer CTC 모드로 설정
    TCCR0 |= (1 << WGM01);              //TCCR0 &= ~(1 << WGM00);

    // 분주비 64
    TCCR0 |= (1 << CS02);

    OCR0 = 249;                         // 250개 카운팅 필요 Top값 할당

    TIMSK |= (1 << OCIE0);              // 인터럽트 인에이블
    sei();
} 
uint32_t millis()
{
    uint32_t ms;

    cli();                              // 인터럽트 디스에이블
    ms = timer0_Millis;
    sei();

    return ms;
}