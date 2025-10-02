// #include "ap.h"

// void apInit()
// {
    
// }

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
        // if(buttonGetState(&btnOn) == ACT_RELEASE)
        // {
        //     PORTD = 0xff;

        // }

        // if(buttonGetState(&btnOff) == ACT_RELEASE) {PORTD = 0x00;}

        // if(buttonGetState(&btnTog) == ACT_RELEASE) {PORTD ^= 0xff;}
//     }

// }

// #include "ap.h"

// void apInit()
// {
    
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


// #include "ap.h"

// void apInit()
// {
    
// }


// void apMain()
// {
//     UART0_Init();

//     DDRA = 0xff;
    
//     char data;

//     uint16_t fndData[10] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x27, 0x7f, 0x67};
    

//     while (1)
//     {
//         data = UART0_Receive();
//         UART0_Transmit(data);
        
//         //7세그먼트
//         switch(data)
//         {
//             case'0':
//                 PORTA = fndData[0];
//                 break;
            
//             case'1':
//                 PORTA = fndData[1];
//                 break;
            
//             case'2':
//                 PORTA = fndData[2];
//                 break;
//             case'3':
//                 PORTA = fndData[3];
//                 break;
//             case'4':
//                 PORTA = fndData[4];
//                 break;
//             case'5':
//                 PORTA = fndData[5];
//                 break;    
//             case'6':
//                 PORTA = fndData[6];
//                 break;
//             case'7':
//                 PORTA = fndData[7];
//                 break;
//             case'8':
//                 PORTA = fndData[8];
//                 break;
//             case'9':
//                 PORTA = fndData[9];
//                 break;
                    
//         }
        

        

//     }
    
// }






// #include "ap.h"

// void apInit()
// {
    
// }



// void apMain()
// {

//     stdout = &OUTPUT;
    
//     UART_Init();   
//     sei();

//     while (1)
//     {
//         if(rxFlag == 1)
//         {
//             rxFlag = 0;             
//             printf(rxBuff);
//             printf("\r");
//         }
//     }        
// }

/**
 * @brief 버튼을 이용한 선풍기 제어
 * 
 * 
 */


// #include "ap.h"

// void apInit()
// {
    
// }

// void apMain()
// {

//     pwmInit();
//     DDRD = 0xff;
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
            
//             OCR0 = 127;   
                
        

//         }

//         if(buttonGetState(&btnOff) == ACT_RELEASE) 
//         {
            
            
//             OCR0 = 255;
            
//         }

//         if(buttonGetState(&btnTog) == ACT_RELEASE) 
//         {
            
            
//             OCR0 = 0;
            
//         }
//     }

// }


/**
 * @brief UART를 이용한 선풍기 제어
 * 0 ~ 2 중 입력 받은 숫자로 선풍기가 작동함
 * 0 : 멈춤
 * 1 : 1단
 * 2 : 2단 
 */


// #include "ap.h"

// void apInit()
// {
    
// }


// void apMain()
// {
//     pwmInit();
//     UART0_Init();


//     char data;



//     while (1)
//     {
//         data = UART0_Receive();
//         UART0_Transmit(data);
        
//         
//         switch(data)
//         {
//             case'0':
//                 OCR0 = 0;
//                 break;
            
//             case'1':
//                 OCR0 = 127;
//                 break;
            
//             case'2':
//                 OCR0 = 255;
//                 break;
            
                    
//         }

//     }

// }



/**
 * @brief delay 함수 활용
 * Nomalmode 사용
 */




//  #include "ap.h"

// void apInit()
// {
    
// }

// void apMain()
// {
//     DDRD = 0xff;

//     delayInit();

//     while(1)
//     {
//         PORTD = 0x00;
//         delay_ms(300);
//         PORTD = 0xff;
//         delay_ms(300);
//     }
// }


/**
 * @brief millis 함수 활용
 * CTCmode 사용
 * 
 */


// #include "ap.h"

// void apInit()
// {
    
// }


// void apMain()
// {
//     DDRD |= (1 << PD7) | (1 << PD0);

//     millisInit();

//     uint32_t prevTime1 = 0;
//     uint32_t prevTime2 = 0;

//     while(1)
//     {
//         uint32_t now = millis();
        
//         // 1000ms 토글
//         if(now - prevTime1 >= 500)
//         {
//             prevTime1 = now;
//             PORTD ^= (1 << PORTD7);
//         }

//         // 2000ms 토글
//         if(now - prevTime2 >= 1000)
//         {
//             prevTime2 = now;
//             PORTD ^= (1 << PORTD0);
//         }


//     }
// }

# include "./ap.h"

void apInit()
{

}

void apMain()
{

    LCD_Init();

    LCD_GotoXY(0, 0);
    LCD_WriteString("Hello I2C");
    LCD_GotoXY(1, 0);
    LCD_WriteString("Hello 4Bit LCD");

    // char buff[30];

    // sprintf(buff, "Hello AVR");
    // LCD_WriteStringXY(0, 0, buff);

    // int count = 0;

    while(1)
    {
        // sprintf(buff, "count : %d", count++);
        // LCD_WriteStringXY(1, 0, buff);
        // _delay_ms(500);
    }
}