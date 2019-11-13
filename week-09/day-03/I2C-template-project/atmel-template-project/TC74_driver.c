#include <avr/io.h>
#include <string.h>
#include <stdint.h>
#include "TC74_driver.h"

void TWI_init(void)
{
    // TODO:
    // Set Prescaler to 4


    // TODO:
    // Set SCL frequency = 16000000 / (16 + 2 * 48 * 4) = 40Khz
    //So set the correct register to 0x30


    // TODO
    //Enable TWI

}

void TWI_start(void)
{
    //Send start signal
    TWCR0 = (1<<TWINT) | (1<<TWSTA) | (1<<TWEN);

    // Wait for TWINT Flag set. This indicates that
    //the START condition has been transmitted.
    while (!(TWCR0 & (1<<TWINT)));

}

void TWI_stop(void)
{
    //Send stop signal
    TWCR0 = (1<<TWINT) | (1<<TWEN) | (1<<TWSTO);
}

uint8_t TWI_read_ack(void)
{
    //TODO
    //Read byte with ACK
    //Wait for TWINT Flag set. This indicates that
    //the DATA has been transmitted, and ACK/
    //NACK has been received.

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
    TWDR0 = u8data;
    TWCR0 = (1<<TWINT) | (1<<TWEN);
    
    while (!(TWCR0 & (1<<TWINT)));

}

//TODO
//Write a function that communicates with the TC74A0.
//The function need to be take the address of the ic as a parameter.
//datasheet: http://ww1.microchip.com/downloads/en/DeviceDoc/21462D.pdf
//And returns with the temperature.


//TODO Advanced:
//Calculate the average of the last 16 data, and returns with that.
//TODO Advanced+:
//Select the outstanding (false data) before average it.
//These data don't needed, mess up your datas, get rid of it.
