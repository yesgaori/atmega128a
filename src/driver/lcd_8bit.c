// #include "./lcd_8bit.h"




// void LCD_Data(uint8_t data)
// {
//     LCD_DATA_PORT = data;                           // 데이터 핀에 데이터 출력
// }

// void LCD_WritePin()
// {
//     LCD_RW_PORT &= ~(1 << LCD_RW);                  // RW핀을 LOW로 설정해서 쓰기모드 진입
// }

// // 만약에 Read라면 ...
// // void LCD_ReadPin()
// // {
// //     LCD_RW_PORT |= (1 << LCD_RW);
// // }

// void LCD_EnablePin()
// {
//     LCD_E_PORT &= ~(1 << LCD_E);                    // LOW로 설정
//     LCD_E_PORT |= (1 << LCD_E);                     // HIGH로 설정
//     LCD_E_PORT &= ~(1 << LCD_E);                    // LOW로 설정
//     _delay_us(1600);                                // 데이터 나갈 시간 확보
// }

// void LCD_WriteCommand(uint8_t command)
// {
//     LCD_RS_PORT &= ~(1 << LCD_RS);                  // RS핀을 LOW로 설정해서 명령어모드
//     LCD_WritePin();                                 // 쓰기모드 진입
//     LCD_Data(command);                              // 명령어 데이터를 데이터핀에 출력
//     LCD_EnablePin();                                // LCD에 동작신호를 전송
// }

// void LCD_WriteData(char charData)
// {
//     LCD_RS_PORT |= (1 << LCD_RS);                   // High로 설정 해서 데이터 모드
//     LCD_WritePin();                                 // 쓰기모드 진입
//     LCD_Data(charData);                             // 명령어 데이터를 데이터핀에 출력
//     LCD_EnablePin();                                // LCD에 동작신호를 전송
// }

// void LCD_GotoXY(uint8_t row, uint8_t col)
// {
//     col %= 16;                                      // 열을 16으로 제한
//     row %= 2;                                       // 행을 2로 제한

//     uint8_t address = (0x40 * row) + col;
//     uint8_t command = 0x80 + address;
//     LCD_WriteCommand(command);
// }

// void LCD_WriteString(char *string)
// {
//     for(uint8_t i = 0; i < string[i]; i++)
//     {
//         LCD_WriteData(string[i]);
//     }
// }

// void LCD_WriteStringXY(uint8_t row, uint8_t col, char *string)
// {
//     LCD_GotoXY(row, col);
//     LCD_WriteString(string);
// }

// void LCD_Init()
// {
//     LCD_DATA_DDR = 0xff;                            // PORTF 출력 설정
//     LCD_RS_DDR |= (1 << LCD_RS);
//     LCD_RW_DDR |= (1 << LCD_RW);
//     LCD_E_DDR |= (1 << LCD_E);

//     _delay_ms(20);                                  // 쉬었다 보냈다 쉬었다 보냈다 보냈다 디스플레이off 디스플레이clear *디스플레이on(봐야하니까.끼워넣음) 엔트리모드
//     LCD_WriteCommand(COMMAND_8_BIT_MODE);
//     _delay_ms(5);
//     LCD_WriteCommand(COMMAND_8_BIT_MODE);
//     _delay_ms(5);
//     LCD_WriteCommand(COMMAND_8_BIT_MODE);

//     LCD_WriteCommand(COMMAND_8_BIT_MODE);
//     LCD_WriteCommand(COMMAND_DISPLAY_OFF);
//     LCD_WriteCommand(COMMAND_DISPLAY_CLEAR);
//     LCD_WriteCommand(COMMAND_DISPLAY_ON);
//     LCD_WriteCommand(COMMAND_ENTRY_MODE);

// }