#include"./uart0.h"


// 통신속도 9600pbs
// 비동기모드, 2배속, 8비트 데이터, 패리티비트 없음, 스톱비트 1개

void UART0_Init()
{
    // 일단 통신속도
    UBRR0H = 0x00;
    UBRR0L = 207;

    // 2배속 모드 세팅
    UCSR0A |= (1 << U2X0);
    // 수신활성화, 송신활성화 
    UCSR0B |= (1 << RXEN0)|(1 << TXEN0);
    // 비동기 세팅, 패리티 없음, 스톱비트 1개, 데이터8비트
    UCSR0C |= (1 << UCSZ01)|(1 << UCSZ00);      // 이 세팅값이 디폴트값이다. 쓰거나 지우거나 해도 됨.
}

void UART0_Transmit(char data)
{
    while(!(UCSR0A & (1 << UDRE0)));     //송신 가능 ??? UDR이 비어있는지?
    
        UDR0 = data;

}

unsigned UART0_Receive()
{
    while(!(UCSR0A & (1 << RXC0)))     // 데이터 수신 대기
    {

    };
        return UDR0;    
    
}