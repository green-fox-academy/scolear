#include "HT16K33_driver.h"
#include "TC74_driver.h"

// Right digits:
uint8_t digit_0[8] = {0x00, 0xc0, 0xa0, 0xa0, 0xa0, 0xa0, 0xa0, 0xe0};
uint8_t digit_1[8] = {0x00, 0xc0, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80};
uint8_t digit_2[8] = {0x00, 0x60, 0x80, 0x80, 0x80, 0x40, 0x20, 0xe0};
uint8_t digit_3[8] = {0x00, 0xe0, 0x80, 0x80, 0x80, 0xe0, 0x80, 0xe0};
uint8_t digit_4[8] = {0x00, 0xa0, 0xa0, 0xa0, 0xa0, 0xe0, 0x80, 0x80};
uint8_t digit_5[8] = {0x00, 0xe0, 0x20, 0x20, 0x20, 0xe0, 0x80, 0x60};
uint8_t digit_6[8] = {0x00, 0xc0, 0x20, 0x20, 0x20, 0xe0, 0xa0, 0xe0};
uint8_t digit_7[8] = {0x00, 0xe0, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80};
uint8_t digit_8[8] = {0x00, 0xc0, 0xa0, 0xa0, 0xa0, 0xe0, 0xa0, 0xe0};
uint8_t digit_9[8] = {0x00, 0xc0, 0xa0, 0xa0, 0xa0, 0xe0, 0x80, 0x80};

uint8_t *digits[10] = {digit_0, digit_1, digit_2, digit_3, digit_4, digit_5, digit_6, digit_7, digit_8, digit_9};

void LED_matrix_init()
{
    uint8_t welcome_shape[8] = {0x00, 0x2e, 0x6a, 0xaa, 0xaa, 0xaa, 0xaa, 0xae};
    
    start_LED_osc();
    draw_shape(welcome_shape);
    turn_on_display();
    _delay_ms(1000);
}

void start_LED_osc()
{
    TWI_start();
    TWI_write(LED_ADDRESS);             // send out slave address + W
    TWI_write(LED_OSC_ON);              // turn led oscillator ON command
    TWI_stop();
}

void stop_LED_osc()
{
    TWI_start();
    TWI_write(LED_ADDRESS);
    TWI_write(LED_OSC_OFF);
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

void turn_on_display()
{
        TWI_start();
        TWI_write(LED_ADDRESS);
        TWI_write(LED_DISPLAY_ON);
        TWI_stop();
}

void display_temperature(uint8_t temperature) 
{
    uint8_t right_digit = temperature % 10;
    uint8_t left_digit = (temperature / 10) % 10;
    
    uint8_t left_d[8];
    uint8_t final_shape[8];

    for (int i = 0; i < 8; i++)
    {
        left_d[i] = digits[left_digit][i] >> 4;
        
        final_shape[i] = left_d[i] | digits[right_digit][i];
    }
    draw_shape(final_shape);
}