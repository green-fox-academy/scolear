#include "TC74_driver.h"
#include "HT16K33_driver.h"
#include "STDIO_lib.h"
#include <avr/io.h>
#include <stdio.h>
#include <avr/interrupt.h>

#define F_CPU 16000000UL
#include <util/delay.h>

void system_init()
{
    TWI_init();
    // SDIO lib is initialized with 115200 baud rate with 8N1 settings
    STDIO_init();
    sei();
}

int main(void)
{
    volatile uint8_t temperature;
    
    system_init();
    LED_matrix_init();
    printf("System initialized\n");
    
    while (1) 
    {    
        temperature = read_temperature(TC_ADDRESS);
        printf("Current temperature of sensor: %d\n", temperature);
        
        display_temperature(temperature);
        _delay_ms(1000);
    }
}