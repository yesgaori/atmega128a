#include"../common/def.h"

#define LED_DDR         DDRD
#define LED_PORT        PORTD
#define BUTTON_DDR      DDRG
#define BUTTON_PIN      PING
#define BUTTON_ON       2
#define BUTTON_OFF      3
#define BUTTON_TOGGLE   4

enum {PUSHED, RELEASED};
enum {NO_ACT, ACT_PUSH, ACT_RELEASE};

// enum{               // enum은 배열은 아니고 순서대로 정수를 할당한다
//     Sunday,     
//     Monday,
//     Tuesday,
//     Wendsday,
//     Thursday,
//     Friday,
//     Saturday
// };

typedef struct button
{
    volatile uint8_t *ddr;
    volatile uint8_t *pin;
    uint8_t btnPin;
    uint8_t prevState; // 이전상태
}BUTTON;


void buttonInit(BUTTON *button, volatile uint8_t *ddr, volatile uint8_t *pin, uint8_t pinNum);
uint8_t buttonGetState(BUTTON *button);
