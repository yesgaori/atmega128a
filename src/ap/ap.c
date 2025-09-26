#include "ap.h"

void apInit()
{
    
}

// void apMain()
// {   
//     DDRD = 0xff;     //대충 LED 셋팅


//     BUTTON btnOn;
//     BUTTON btnOff;
//     BUTTON btnTog;

//     // 3개를 전부 입력으로 설정
//     buttonInit(&btnOn, &BUTTON_DDR, &BUTTON_PIN, BUTTON_ON);
//     buttonInit(&btnOff, &BUTTON_DDR, &BUTTON_PIN, BUTTON_OFF);
//     buttonInit(&btnTog, &BUTTON_DDR, &BUTTON_PIN, BUTTON_TOGGLE);

//     while(1)
//     {
//         if(buttonGetState(&btnOn) == ACT_RELEASE)
//         {
//             PORTD = 0xff;

//         }

//         if(buttonGetState(&btnOff) == ACT_RELEASE) {PORTD = 0x00;}

//         if(buttonGetState(&btnTog) == ACT_RELEASE) {PORTD ^= 0xff;}
//     }

// }

// void apMain()
// {

//     FND_DATA_DDR = 0xff;
//     FND_SELECT_DDR = 0xff;

//     FND_SELECT_PORT = 0x00;

//     uint16_t count = 0;
//     uint32_t timeTick = 0;
//     uint32_t prevTime = 0;
    
//     while(1)
//     {
//         FND_Display(count);                 // FND에 count 값을 출력

//         if(timeTick - prevTime > 100)       // 100ms 지날때마다 count 값을 1씩 증가
//         {
//             prevTime = timeTick;    
//             count++;
//         }
//         _delay_ms(5);
//         timeTick ++;

//     }
// }

void apMain()
{
    UART0_Init();

    DDRD = 0xff;

    char data;

    while (1)
    {
        data = UART0_Recive();
        UART0_Transmit(data);
        if(data == 'a')
        {
            PORTD = 0xff;
        }
        else
        {
            PORTD = 0x00;
        }

    }
    
}