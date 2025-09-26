#include"./uart0_int.h"
#include"../common/def.h"

// 출력 스트림 설정
FILE OUTPUT = FDEV_SETUP_STREAM(UART_Transmit, NULL, _FDEV_SETUP_WRITE);

char rxBuff[100] = {0};         // 수신 버퍼
volatile uint8_t rxFlag  = 0;   // 수신 완료 플래그

ISR(USART0_RX_vect)             // 수신 인터럽트 서비스 루틴
{
    static uint8_t rxHead = 0;  // 수신된 데이터의 인덱스
    uint8_t rxData = UDR0;      // 수신된 데이터

    if(rxData == '\n' || rxData == '\r')    // 수신 된 데이터가 마지막이 개행이나 리턴이면
    {
        rxBuff[rxHead] = '\0';  // 문자열의 마지막에 널 문자삽입
        rxHead = 0;             // 인덱스 초기화
        rxFlag = 1;             // 문자열을 수신했다고 깃발 세움
    }
    else                                    // 그렇지 않다면 다음 문자를 계속 받음
    {
        rxBuff[rxHead] = rxData;    // 수신된 데이터를 버퍼에 계속 추가            
        rxHead++;                   // 버퍼 인덱스를 하나씩 증가
    }
}

void UART_Init()
{
    UBRR0H = 0x00;
    UBRR0L = 0xCF;   // 9600bps 
    
    UCSR0A |= (1 << U2X0);   // 2배속 모드
    UCSR0B |= (1 << RXCIE0)|(1 << TXEN0)|(1 << RXCIE0);   // 수신 인터럽트 활성화, 수신, 송신 활성화 Rx, Tx
    
}

void UART_Transmit(char data)
{
    while(!(UCSR0A & (1 << UDRE0)))     //송신 가능 ??? UDR이 비어있는지?
    {

    };
    UDR0 = data;
}

// //포인터 타입 맞추기용
// int UART_Transmit_Char(char data, FILE *stream)
// {
//     while(!(UCSR0A & (1 << UDRE0)));
//     UDR0 = data;
//     return 0;

// }

unsigned char UART_Receive()
{
    while(!(UCSR0A & (1 << RXC0)));     // 수신 확인
    
    return UDR0;
}