#include "./i2c.h"


void I2C_Init()
{
    I2C_DDR |= (1 << I2C_SCL) | (1 << I2C_SDA);         // SCL, SDA 출력
    TWBR = 72;      // 100KHz
    // 32 -> 200KHz
    // 12 -> 400KHz
}

void I2C_Start()
{
    // TWINT : 인터럽트 플래그 클리어 
    // TWSTA : 스타트 조건 세팅
    // TWEN  : I2C 쓰겠다
    TWCR = (1 << TWINT) | (1 << TWSTA) | (1 << TWEN);       // sample code

    // TWINT 는 소프트웨어로 클리어 하고
    // 하드웨어적으로 다시 1이 될떄까지 대기 (스타트 조건 완료되기까지 대기)
    while(!(TWCR & (1 << TWINT)));
}

void I2C_Stop()
{
    // TWINT : 
    // TWEN  : Enable
    // TWSTO : stop 조건 생성
    TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWSTO);
}

void I2C_TxData(uint8_t data)               // I2C를 이용해서 1Byte 전송
{
    TWDR = data;

    TWCR = (1 << TWINT) | (1 << TWEN);      // 데이터 전송이 시작되고

    while(!(TWCR & (1 << TWINT)));
}

void I2C_TxByte(uint8_t devAddRW, uint8_t data)
{
    I2C_Start();
    I2C_TxData(devAddRW);
    I2C_TxData(data);
    I2C_Stop();
}