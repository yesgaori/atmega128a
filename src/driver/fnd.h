#include "../common/def.h"

#define FND_DATA_DDR    DDRB
#define FND_DATA_PORT   PORTB
#define FND_SELECT_DDR  DDRC
#define FND_SELECT_PORT PORTC

void FND_Display(uint16_t data);

void FND_ShiftDisplay(uint16_t data, uint16_t position);