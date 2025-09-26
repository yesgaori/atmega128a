
#include "./led.h"

// void ledInit(LED *led)  // 매개변수가 포인터로 선언되었기 때문에 주소값을 받아야 함.
// {
//    // DDRD = 0xff;     // 예전 방식
//    // 구조체를 정의했기 때문에 아래와 같이 가능 !!!
//    // 사용할 포트에 대해서 DDR레지스터를 출력으로 설정해야 함.

//    *(led->port - 1) |= (1 << led->pinNumber);
   
//    // led->port - 1 // PORT 주소를 던지면 DDR주소가 됨
//    // led->port - 1 을 한 값(주소) -> *를 붙혀서 가리키는 곳을 값을 변경함
//    // *(led->port - 1)

//    // led->pinNumber <<< 이거는 핀번호를 얘기할거임 (이건 값이 ... 포인터 아님)


// }

// void ledOn(LED *led)
// {
//    // 이번에는 포트에 1을 써야 출력이 됨.
//    *(led->port) |= (1 << led->pinNumber);
// }

// void ledOff(LED *led)
// {
//    // 이번에는 포트에 0을 써야 출력이 안됨
//    // 해당핀에 0을 씀
//    *(led->port) &= ~(1 << led->pinNumber);
// }

// void ledLeftShift(LED *led)
// {
   
//    for(uint8_t i = 0; i < 8; i++)
//    {
//       *(led->port) = 1 << i;
//       _delay_ms(200);
//    }
// }

















// led.c ->
// LED 포트 레지스터에 데이터를 출력하는 함수
void GPIO_Output(uint8_t data)
{
   LED_PORT = data;
}

//LED 포트 레지스터를 출력모드로 설정하는 함수
void ledInit()
{
   LED_DDR = 0xFF;

}

// LED 데이터를 좌측으로 이동하는 함수
void ledLeftShift(uint8_t *data)
{
   *data = (*data >> 7) | (*data << 1);   // LED 데이터를 좌측으로 1 이동
   GPIO_Output(*data);                    // 이동된 데이터를 LED포트 레지스터 출력
}

// LED 데이터를 우측으로 이동하는 함수
void ledRightShift(uint8_t *data)
{
   *data = (*data << 7) | (*data >> 1);
   GPIO_Output(*data);
}