#include "HT16K33_driver.h"
#include "TC74_driver.h"

void start_LED_osc()
{
    TWI_start();
    TWI_write(LED_ADDRESS);             // send out slave address + W
    TWI_write(LED_OSC_ON);              // turn led oscillator ON command
    TWI_stop();
}

void draw_shape(uint8_t data[])
{
    //clear_display();
    uint8_t buff = 0;
    
    TWI_start();
    TWI_write(LED_ADDRESS);
    TWI_write(0b00000000);
    
    for (int i = 0; i < 8; i++)
    {
        buff = (data[i] >> 1) | (data[i] << 7);
        TWI_write(buff);
        TWI_write(0);
    }
    TWI_stop();
}

void clear_display()
{
    TWI_start();
    TWI_write(LED_ADDRESS);
    TWI_write(0b00000000);
    
    for (int i = 0; i < 16; i++)
    {
        TWI_write(0x00);
    }
    TWI_stop();
}

void update_display()
{
        TWI_start();
        TWI_write(LED_ADDRESS);
        TWI_write(LED_DISPLAY_ON);
        TWI_stop();
}