#include "./fnd.h"


// void FND_Display(uint16_t data)
// {
//     static uint8_t position = 0;
//     uint8_t fndData[10] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x27, 0x7f, 0x67};
    
//     switch(position)    //현재 출력할 자리에 따라서 해당 자리의 FND를 출력
//     {
//         case 0:
//             // 첫번째 자리 출력을 위해서는 0번핀 LOW, 1, 2, 3핀은 HIGH
//             FND_SELECT_PORT &= ~(1 << 0);                   // digit 1 : ON
//             FND_SELECT_PORT |= (1 << 1)|(1 << 2)|(1 << 3);  // digit 2, 3, 4 :OFF

//             // 입력된 데이터의 천의 자리를 구해서 해당 FND에 데이터 값을 출력
//             FND_DATA_PORT = fndData[data/1000];
//             break;
//         case 1:
//             // 두번째 자리 출력을 위해서는 1번핀 LOW, 0, 2, 3핀은 HIGH
//             FND_SELECT_PORT &= ~(1 << 1);                   // digit 2 : ON
//             FND_SELECT_PORT |= (1 << 0)|(1 << 2)|(1 << 3);  // digit 1, 3, 4 :OFF

//             // 입력된 데이터의 천의 자리를 구해서 해당 FND에 데이터 값을 출력
//             FND_DATA_PORT = fndData[data/100%10];
//             break;
//         case 2:
//             // 세번째 자리 출력을 위해서는 2번핀 LOW, 0, 1, 3핀은 HIGH
//             FND_SELECT_PORT &= ~(1 << 2);                   // digit 3 : ON
//             FND_SELECT_PORT |= (1 << 0)|(1 << 1)|(1 << 3);  // digit 1, 2, 4 :OFF

//             // 입력된 데이터의 천의 자리를 구해서 해당 FND에 데이터 값을 출력
//             FND_DATA_PORT = fndData[data/10%10];
//             break;
//         case 3:
//             // 네번째 자리 출력을 위해서는 3번핀 LOW, 0, 1, 2핀은 HIGH
//             FND_SELECT_PORT &= ~(1 << 3);                   // digit 4 : ON
//             FND_SELECT_PORT |= (1 << 0)|(1 << 1)|(1 << 2);  // digit 1, 2, 3 :OFF

//             // 입력된 데이터의 천의 자리를 구해서 해당 FND에 데이터 값을 출력
//             FND_DATA_PORT = fndData[data%10];
//             break;   
//     }
//     position++;                     // 다음 자리로 이동하기 위해 ++ 함
//     position = position % 4;        // 4자리를 출력한 후에 다시 첫번쨰 자리로 돌아가기 위해 position % 4한 값을 저장
// }


// 입력값을 옆으로 계속 밀어넣는 함수

// void FND_ShiftDisplay(uint16_t data, uint16_t position)
// {
//     position = 0;
//     uint8_t fndData[10] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x27, 0x7f, 0x67};
    
//     switch(position)    //현재 출력할 자리에 따라서 해당 자리의 FND를 출력
//     {
//         case 0:
//             // 첫번째 자리 출력을 위해서는 0번핀 LOW, 1, 2, 3핀은 HIGH
//             FND_SELECT_PORT &= ~(1 << 0);                   // digit 1 : ON
//             FND_SELECT_PORT |= (1 << 1)|(1 << 2)|(1 << 3);  // digit 2, 3, 4 :OFF

//             // 입력된 데이터의 천의 자리를 구해서 해당 FND에 데이터 값을 출력
//             FND_DATA_PORT = fndData[data/1000];
//             break;
//         case 1:
//             // 두번째 자리 출력을 위해서는 1번핀 LOW, 0, 2, 3핀은 HIGH
//             FND_SELECT_PORT &= ~(1 << 1);                   // digit 2 : ON
//             FND_SELECT_PORT |= (1 << 0)|(1 << 2)|(1 << 3);  // digit 1, 3, 4 :OFF

//             // 입력된 데이터의 천의 자리를 구해서 해당 FND에 데이터 값을 출력
//             FND_DATA_PORT = fndData[data/100%10];
//             break;
//         case 2:
//             // 세번째 자리 출력을 위해서는 2번핀 LOW, 0, 1, 3핀은 HIGH
//             FND_SELECT_PORT &= ~(1 << 2);                   // digit 3 : ON
//             FND_SELECT_PORT |= (1 << 0)|(1 << 1)|(1 << 3);  // digit 1, 2, 4 :OFF

//             // 입력된 데이터의 천의 자리를 구해서 해당 FND에 데이터 값을 출력
//             FND_DATA_PORT = fndData[data/10%10];
//             break;
//         case 3:
//             // 네번째 자리 출력을 위해서는 3번핀 LOW, 0, 1, 2핀은 HIGH
//             FND_SELECT_PORT &= ~(1 << 3);                   // digit 4 : ON
//             FND_SELECT_PORT |= (1 << 0)|(1 << 1)|(1 << 2);  // digit 1, 2, 3 :OFF

//             // 입력된 데이터의 천의 자리를 구해서 해당 FND에 데이터 값을 출력
//             FND_DATA_PORT = fndData[data%10];
//             break;   
//     }
//     position++;                     // 다음 자리로 이동하기 위해 ++ 함
//     position = position % 4;        // 4자리를 출력한 후에 다시 첫번쨰 자리로 돌아가기 위해 position % 4한 값을 저장
// }