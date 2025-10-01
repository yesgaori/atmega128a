#include "./i2c_lcd.h"


uint8_t I2C_LCD_DATA;


void LCD_Data4Bit(uint8_t data)
{
    I2C_LCD_DATA = (I2C_LCD_DATA & 0x0f) | (data & 0xf0);     // 상위 4비트 추출해서 1차로 보냄
    LCD_EnablePin();
    I2C_LCD_DATA = (I2C_LCD_DATA & 0x0f) | ((data & 0x0f) << 4);
    LCD_EnablePin();
}


void LCD_EnablePin()
{
    I2C_LCD_DATA &= ~(1 << LCD_E);                    // LOW로 설정
    I2C_TxByte(LCD_DEV_ADDRESS, I2C_LCD_DATA);

    I2C_LCD_DATA |= (1 << LCD_E);                     // HIGH로 설정
    I2C_TxByte(LCD_DEV_ADDRESS, I2C_LCD_DATA);

    I2C_LCD_DATA &= ~(1 << LCD_E);                    // LOW로 설정
    I2C_TxByte(LCD_DEV_ADDRESS, I2C_LCD_DATA);
    _delay_us(1600);                                // 데이터 나갈 시간 확보
}

void LCD_WriteCommand(uint8_t command)
{
    I2C_LCD_DATA &= ~(1 << LCD_RS);                  // RS핀을 LOW로 설정해서 명령어모드
    I2C_LCD_DATA &= ~(1 << LCD_RW);                  // RS핀을 LOW로 설정해서 명령어모드
    LCD_Data4Bit(command);                              // 명령어 데이터를 데이터핀에 출력

}

void LCD_WriteDate(char charData)
{
    I2C_LCD_DATA |= (1 << LCD_RS);                  // RS핀을 LOW로 설정해서 명령어모드
    I2C_LCD_DATA &= ~(1 << LCD_RW);                  // RS핀을 LOW로 설정해서 명령어모드
    LCD_Data4Bit(charData);                             // 명령어 데이터를 데이터핀에 출력

}

void LCD_GotoXY(uint8_t row, uint8_t col)
{
    col %= 16;                                      // 열을 16으로 제한
    row %= 2;                                       // 행을 2로 제한

    uint8_t address = (0x40 * row) + col;
    uint8_t command = 0x80 + address;
    LCD_WriteCommand(command);
}

void LCD_WriteString(char *string)
{
    for(uint8_t i = 0; i < string[i]; i++)
    {
        LCD_WriteDate(string[i]);
    }
}

void LCD_WriteStringXY(uint8_t row, uint8_t col, char *string)
{
    LCD_GotoXY(row, col);
    LCD_WriteString(string);
}

void LCD_BackLightOn()
{
    I2C_LCD_DATA |= (1 << LCD_BACKLIGHT);
    I2C_TxByte(LCD_DEV_ADDRESS, I2C_LCD_DATA);
}

void LCD_Init()
{
    I2C_Init();

    _delay_ms(20);                                  // 쉬었다 보냈다 쉬었다 보냈다 보냈다 디스플레이off 디스플레이clear *디스플레이on(봐야하니까.끼워넣음) 엔트리모드
    LCD_WriteCommand(0x03);
    _delay_ms(5);
    LCD_WriteCommand(0x03);
    _delay_ms(5);
    LCD_WriteCommand(0x03);

    LCD_WriteCommand(0x02);
    LCD_WriteCommand(COMMAND_4_BIT_MODE);

    LCD_WriteCommand(COMMAND_DISPLAY_OFF);
    LCD_WriteCommand(COMMAND_DISPLAY_CLEAR);
    LCD_WriteCommand(COMMAND_DISPLAY_ON);
    LCD_WriteCommand(COMMAND_ENTRY_MODE);
    LCD_BackLightOn();

}

