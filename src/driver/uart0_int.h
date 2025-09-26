#include"../common/def.h"



void UART_Init();
void UART_Transmit(char data);
int UART_Transmit_Char(char data, FILE *stream);
unsigned char UART_Receive();


extern FILE OUTPUT;
extern char rxBuff[100];
extern volatile uint8_t rxFlag;