#include "./src/common/def.h"
#include "./src/ap/ap.h"


// int main()
// {
//     // (DDRD) 방향 레지스터를 총해서 PORTD를 출력으로 설정
//     DDRD = 0b11111111; //2진수, 방향레지스터 1을 쓰면 출력
//     // DDRD = 0xFF;    // 16진수 
//     PORTD = 0x00;
//     _delay_ms(500);
//     PORTD = 0x01;
//     while(1)
//     {
//         PORTD = 0x00;   // 출력이니까.. 전압(전류)를 내보내라 ..
//         _delay_ms(500); // 500ms동안 멈춰(지연)라..
//         PORTD = 0xFF;  // 출력이지만.. 전압(전류)도 내보내지마라..
//         _delay_ms(500); // 500ms 멈춰(지연)...

//     }
// }

// #define LED_DDR DDRD
// #define LED_PORT PORTD

// int main ()
// {
//     DDRD = 0xff;

//     while(1)
//     {
//         // led 를 왼쪽으로 이동
//         LED_PORT = 0x0f;    // 하위비트 4개만 on
//         _delay_ms(500);
//         LED_PORT = 0xf0;     // 상위비트 4개만 on
//         _delay_ms(500);
        

//         LED_PORT = 0xaa;    // 짝
//         _delay_ms(500);
//         LED_PORT = 0x55;     // 홀
//         _delay_ms(500);
//     }
// }

// int main()
// {
//     DDRD = 0xff;
//         // 2진수를 이용해 여러번 코드를 입력 해야하지만 직관적이게 순차적인 점등을 할 수 있다.    
//     while (1)
//     {
//         PORTD = 0b10000000;
//         _delay_ms(200);
//         PORTD = 0b11000000;
//         _delay_ms(200);
//         PORTD = 0b11100000;
//         _delay_ms(200);
//         PORTD = 0b11110000;
//         _delay_ms(200);
//         PORTD = 0b11111000;
//         _delay_ms(200);
//         PORTD = 0b11111100;
//         _delay_ms(200);
//         PORTD = 0b11111110;
//         _delay_ms(200);
//         PORTD = 0b11111111;
//         _delay_ms(200);
//         PORTD = 0b100000000;
//         _delay_ms(200);
//     }
    
// }

// int main()
// {
//     DDRD = 0xff;
//         //OR 연산을 통해 led를 밀어냄과 동시에 그전에 들어왔던 부분을 함께 점등시킬 수 있다.
//     while(1)
//     {
//         for(uint8_t i = 0; i < 8; i++)
//         {
//             PORTD |= (0x01 << i);           //OR연산.
//             _delay_ms(200);
//         }
//         PORTD = 0x00;
//         _delay_ms(200);
//     }
// }
// //배열에 저장하여 for문을 이용해 원하는 패턴으로 점등할 수 있다.
// LED_Array[] =
// {
//     0x81,
//     0x42,
//     0x24,
//     0x18,
//     0x24,
//     0x42,
//     0x81
// };

// int main()
// {
//     DDRD = 0xff;
    // while(1)
    // {
    //    //2진수로 표현하면 코드의 줄이 많아진다.
    //    PORTD = 0b00011000;
    //    _delay_ms(200);
    //    PORTD = 0b00111100;
    //    _delay_ms(200);
    //    PORTD = 0b01111110;
    //    _delay_ms(200);
    //    PORTD = 0b11111111;
    //    _delay_ms(200);
    //    PORTD = 0b01111110;
    //    _delay_ms(200);
    //    PORTD = 0b00111100;
    //    _delay_ms(200);
    // }
   //  while(1)
   //  {
   //      PORTD = 0x00;
   //      // 포문에 AND와 OR을 이용해 합쳐졌다가 빠져나가는 패턴을 만들 수 있다.
   //      for(uint8_t i = 0; i < 4; i++)
   //      {
   //          PORTD |= ((0x10 << i) | (0x08 >> i));
   //          _delay_ms(200);
   //      }

   //      for (uint8_t i =7; i >= 4; i --)
   //      {
   //          PORTD &= ~((0x01 <<i)|(0x80 >>i));
   //          _delay_ms(200);
   //      }
   //  }

   // while(1)
   // {
   //      PORTD = 0x00;
   //      //위 코드를 응용하여 패턴에 합쳐지는 특징을 빼고 만들 수 있다.
   //      for(uint8_t i = 0; i < 4; i++)
   //      {
   //          PORTD = ((0x10 << i) | (0x08 >> i));
   //          _delay_ms(200);
   //      }

   //      for (uint8_t i =7; i >= 4; i --)
   //      {
   //          PORTD = ((0x01 <<i)|(0x80 >>i));
   //          _delay_ms(200);
   //      }
   //  }
   //  while(1)
   //  {
   //  PORTD = 0x00;
   //  for(uint8_t i = 0; i < 7; i++)
   //  {
   //      //원하는 모양을 배열에 저장하여 원하는만큼 찍어낼 수 있다.
   //      PORTD = LED_Array[i];
   //      _delay_ms(200);
   //  }
   //  }
// }

/**
 * @brief 함수호출을 통한 LED제어
 * 
 */

// void ledInit();
// void ledOn();
// void ledOff();
// void ledRightShift();
// void ledLeftShift();

//  int main()
// {
//     ledInit();
//     while(1)
//     {
//         // ledOn();
//         // _delay_ms(200);
//         // ledOff();
//         // _delay_ms(200);
//         PORTD = 0x01;
//         _delay_ms(200);
//         ledRightShift();
//         ledLeftShift();


//     }
// }
//  void ledInit() // LED 초기화 함수
//  {
//     DDRD = 0xff;
//  }

//   void ledOn() // LED 켜는 함수
//  {
//     PORTD = 0xff;
//  }

//  void ledOff() // LED 끄는 함수
//  {
//     PORTD = 0x00;
//  }

//  void ledRightShift()
//  {
//     for(uint8_t i = 1; i < 8; i ++)
//     {
//         PORTD = 0x01 << i;
//         _delay_ms(200);
//     }
//  }

//  void ledLeftShift()
//  {
//     for(uint8_t i = 7; i > 0; i--)
//     {
//         PORTD = 0x01 << i;
//         _delay_ms(200);
//     }
//  }



#define LED_DDR DDRD
#define LED_PORT PORTD



// 함수 원형선언
// void GPIO_Output(uint8_t data);
// void ledInit();
// void ledLeftShift(uint8_t *data);
// void ledRightShift(uint8_t *data);




// int main()
// {
//    apInit();
//    apMain();
   
//    while(1)
//    {

//    }

// }

// // led.c ->
// // LED 포트 레지스터에 데이터를 출력하는 함수
// void GPIO_Output(uint8_t data)
// {
//    LED_PORT = data;
// }

// //LED 포트 레지스터를 출력모드로 설정하는 함수
// void ledInit()
// {
//    LED_DDR = 0xFF;

// }

// // LED 데이터를 좌측으로 이동하는 함수
// void ledLeftShift(uint8_t *data)
// {
//    *data = (*data >> 7) | (*data << 1);   // LED 데이터를 좌측으로 1 이동
//    GPIO_Output(*data);                    // 이동된 데이터를 LED포트 레지스터 출력
// }

// // LED 데이터를 우측으로 이동하는 함수
// void ledRightShift(uint8_t *data)
// {
//    *data = (*data << 7) | (*data >> 1);
//    GPIO_Output(*data);
// }



// int main()
// {
//    DDRD = 0xff;
   
//    DDRG &= ~(1 << 2);   // DDRG의 2번핀을 입력으로 설정
//    DDRG &= ~(1 << 3);   // DDRG의 3번핀을 입력으로 설정
//    DDRG &= ~(1 << 4);   // DDRG의 4번핀을 입력으로 설정
//    DDRG &= ~(1 << DDRG2);


//    while(1)
//    {
//       if(!(PING & (1 << PING2)))
//       {
//          PORTD = 0xff;
//       }
//       else if(!(PING & (1 << PING3)))
//       {      
//          PORTD = 0x00;
//          for(uint8_t i = 0; i < 4; i++)
//          {   
//          PORTD |= ((0x10 << i) | (0x08 >> i));
//          _delay_ms(200);
//          }
//          for (uint8_t i =7; i >= 4; i --)
//          {
//          PORTD &= ~((0x01 <<i)|(0x80 >>i));
//          _delay_ms(200);
//          }
//       }      
//       else if(!(PING & (1 << PING4)))
//       {
//          for(uint8_t i = 0; i < 8; i++)
//          {
//             PORTD = (0x01 << i);
//             _delay_ms(200);
//          }
//          for(uint8_t i = 7; i >= 0; i--)
//          {
//             PORTD = (0x01 << i);
//             _delay_ms(200);
//          }
//       }
//       else
//       {
//          PORTD = 0x00;
//       }
//    }
// }

// int main()
// {
//    // apInit();
//    // apMain();

//    // FND 연결된 포트
//    DDRA = 0xff;
//    DDRB = 0xff;
//    DDRC = 0xff;

//    uint8_t findNumber[] = 
//    {
//       0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x27, 0x7f, 0x67
//    };

//    int count = 0;


//    while(1)
//    {
//       PORTA = findNumber[count];
//       count = (count + 1) % 10;
//       PORTC = 0x00;
//       PORTB = 0x3f;
//       _delay_ms(500);
//    }


// }

// ISR(INT6_vect)    //Falling
// {
//    PORTD ^= 0xFF;
// }

// ISR(INT7_vect)    //Rising
// {
//    PORTD = 0xff;
// }

// int main()
// {  

//    // apInit();
//    // apMain();

//    //어셈블리어
//    sei();
//    // SREG |= (1 << 7);

//    // EICRB = 0xE0;
//    EICRB |= (1 << ISC71)|(1 << ISC70);   // INT7 : Rising Edge
//    EICRB |= (1 << ISC60);                // INT6 : Falling Edge
//    // EIMSK = 0xC0;
//    EIMSK |= (1 << INT7)|(1 << INT6);     //INT7, INT6 Interrupt Enable

//    DDRD = 0xff;      // LED bar Output setting
//    PORTD = 0x00;

//    DDRE = 0x00;

//    while (1)
//    {
      
//    }
   
// }



 /**
  * @brief CTC 모드에 대한
  * 
  */

// int main()
// {

//    // apInit();
//    // apMain();
   
//    // DDRB = 0xff;         // PB4로 출력 할꺼니까...
//    DDRB |= (1 << PB4);     // PB4만 출력

//    // TCCR0 = 0x1C;
//    TCCR0 |= (1 << COM00) | (1 << WGM01) | (1 << CS02) | (1 << CS00);

//    OCR0 = 249; // 구한 값

//    while(1)
//    {
      // while((TIFR & 0x02) == 0);
      // TIFR = 0x02;
      // OCR0 = 249;
         
      
//    }
   
   
// }

/**
 * @brief 8bit Timer/ Counter : Nomal Mode
 * 특징중에 하나가 특정핀이 아닌 일반핀에서 구형파 발생.
 * 250Hz 구형파 생성
 * 분주비 : 128분주
 * 2ms 마다 토글 시키면 250Hz 발생 (주기는 4ms 이니까)
 * 16MHz = 0. 000 000 0625 (62.5ns)
 * 128분주 하면 => 0.000 008 됨
 * 0.002 = 0.000 002 * N (카운트 개수)
 * 대충 계산하면 .... count를 250개 하면 됨.
 * 그래서 256 - 250은 6 이므로
 * TCNT 값을 6부터 시작하면 됨.
 */


// int main()
// {

//    DDRD |= (1 << 0);          // PORTD0 에서 출력
//    PORTD &= ~(1 << 0);        // PORTD0 LOW로 출발

//    // Normal Mode, 128분주
//    TCCR0 |= (1 << CS02 ) | (1 << CS00);

//    TCNT0 = 6;

//    while(1)
//    {
      // while((TIFR & 0x01) == 0);
      // PORTD = ~PORTD;
      // TCNT0 = 6;
      // TIFR = 0x01;      //clear

//    }
// }

/**
 * @brief Fast PWM Mode
 * 
 * 논인버티 모드
 * 분주비 256
 * 클럭 예상: 244.14 Hz
 * OCR 값을 변경 해보자...
 * 
 */


// main()
// {

//    DDRB |= (1 << PB4);

//    // Fast PWM, 비반전 , 256분주
//    TCCR0 |= (1 << WGM00) | (1 << COM01) | (1 << WGM01) | (1 << CS02) | (1 << CS01);

//    OCR0 = 127;



//    while(1)
//    {
//       for(uint8_t i = 0; i < 255; i++)
//       {
//          OCR0 = i;
//          _delay_ms(10);
//       }
//    }


// }

/**
 * @brief 과제 1 PWM으로 선풍기 제작
 * 
 * 버튼 3개 이용
 * 버튼1 : 정지
 * 버튼2 : 1단 (50% 속도)
 * 버튼3 : 2단 (100% 속도)
 * 
 */

// int main()
// {
//    apInit();
//    apMain();

//    while(1)
//    {

//    }
// }

/**
 * @brief  16비트 타이머/카운터 past PWM
 * 
 * 64분주 , 100Hz 주파수 생성
 * 계산 결과 -> TOP : 2499
 * 
 */

//  int main()
//  {

//    DDRB |= (1 << PB5);        //PWM 신호가 나갈 PORT 출력 선언

//    TCCR1A |= (1 << COM1A1) | (1 << WGM11);
//    TCCR1B |= (1 << WGM13) | (1 << WGM12) | (1 << CS11) | (1 << CS10);
//    // TCCR1C |=

//    ICR1 = 2499;

//    OCR1A = 625;      // 25%      1250 -> 약 50%,   1875 -> 약 75% width


//    while(1)
//    {
//       for(uint16_t i = 0; i < 2499; i++)
//       {
//          OCR1A = i;
//          _delay_ms(5);
//       }
//    }
//  }

// int main()
// {
//       apInit();
//       apMain();

//       while (1)
//       {
            
//       }
      
// }

/**
 * @brief 
 * 
 */



//   int main()
//  {

//    DDRB |= (1 << PB5);        //PWM 신호가 나갈 PORT 출력 선언

//    TCCR1A |= (1 << COM1A1) | (1 << WGM11);
//    TCCR1B |= (1 << WGM13) | (1 << WGM12) | (1 << CS11) | (1 << CS10);
//    // TCCR1C |=

//    ICR1 = 4999;

   


//    while(1)
//    {
//       OCR1A = 250;
//       _delay_ms(1000);
//       OCR1A = 375;
//       _delay_ms(1000);
//       OCR1A = 500;
//       _delay_ms(1000);

      
//    }
//  }

int main()
{
      apInit();
      apMain();

      while(1)
      {

      }

}