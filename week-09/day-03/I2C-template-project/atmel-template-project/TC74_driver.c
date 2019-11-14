#include <avr/io.h>
#include <string.h>
#include <stdint.h>
#include "TC74_driver.h"

void TWI_init(void)
{
    // TODO:
    // Set Prescaler to 4
    TWSR |= 1 << 0;

    // TODO:
    // Set SCL frequency = 16000000 / (16 + 2 * 48 * 4) = 40Khz
    //So set the correct register to 0x30
    TWBR = 0x30;

    // TODO
    //Enable TWI
    TWCR = 1 << TWEN;
}

void TWI_start(void)
{
    //Send start signal
    TWCR = (1<<TWINT) | (1<<TWSTA) | (1<<TWEN);

    // Wait for TWINT Flag set. This indicates that
    //the START condition has been transmitted.
    while (!(TWCR & (1<<TWINT)));
}

void TWI_stop(void)
{
    //Send stop signal
    TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWSTO);
    while((TWCR & (1<<TWSTO)));
}

uint8_t TWI_read_ack(void)
{
    //TODO
    //Read byte with ACK
    //Wait for TWINT Flag set. This indicates that
    //the DATA has been transmitted, and ACK/
    //NACK has been received.
    while (!(TWCR & (1<<TWINT)));
    
    // return status register (without prescaler bits):
    return TWSR & 0b11111000;
}


uint8_t TWI_read_nack(void)
{
    //TODO
    //Read byte with NACK
    //Wait for TWINT Flag set. This indicates that
    //the DATA has been transmitted, and ACK/
    //NACK has been received.

}

void TWI_write(uint8_t u8data)
{
    //Load DATA into TWDR Register. Clear TWINT
    //bit in TWCR to start transmission of data.
    //Wait for TWINT Flag set. This indicates that
    //the DATA has been transmitted, and ACK/
    //NACK has been received.
    TWDR = u8data;
    TWCR = (1<<TWINT) | (1<<TWEN);
    
    while (!(TWCR & (1<<TWINT)));
}

//TODO
//Write a function that communicates with the TC74A0.
//The function need to be take the address of the ic as a parameter.
//datasheet: http://ww1.microchip.com/downloads/en/DeviceDoc/21462D.pdf
//And returns with the temperature.

uint8_t read_temperature(uint8_t slave_address) 
{
    uint8_t temp;
    
    TWI_start();
    slave_address = (slave_address << 1) + TC_WRITE;    // add write bit to address
    TWI_write(slave_address);                           // send out slave address + W
    
    TWI_read_ack();
    
    TWI_write(0x00);                                    // send out command of READ_TEMPERATURE
    
    TWI_read_ack();
    
    TWI_start();
    
    slave_address |= TC_READ;
    
    TWI_write(slave_address);
    temp = TWDR;
    TWI_read_ack();
    TWI_stop();
    
    return temp;
}



//TODO Advanced:
//Calculate the average of the last 16 data, and returns with that.
//TODO Advanced+:
//Select the outstanding (false data) before average it.
//These data don't needed, mess up your datas, get rid of it.
