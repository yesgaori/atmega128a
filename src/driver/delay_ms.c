#include "./delay_ms.h"

ISR(TIMER0_OVF_vect)
{
    static uint16_t count;              // 정적변수 초기화 하지 않아도 0이고 ISR 함수내에서만 사용

    if(++count >= countValue)
    {
        count = 0;
        TCCR0 &= ~((1 << CS02)|(1 << CS00)); // 초기화
        delayCompleteFlag = 1;               // 깃발 세움 (내가 설정한 시간까지 delay 되면)
    }
}


void delayInit()
{
    delayCompleteFlag = 0;

    TIMSK |= (1 << TOIE0);              // Interrupt Enable (Overflow)

    TCCR0 |= (1 << CS02) | (1 << CS00);

    sei();                              // 글로벌 인터럽트 인에이블
}

void delay_ms(uint16_t ms)
{
    delayCompleteFlag = 0;              // 호출 하면 초기화 개념
    countValue = ms;                    // 초기화 개념

    TCNT0 = 256 - 125;                  // TCNT 값을 131 부터 세어나감
    TCCR0 |= (1 << CS02) | (1 << CS00); // 타이머 다시 시작 개념

    while (!delayCompleteFlag);         // 깃발 세울때 까지.....
    
    
}