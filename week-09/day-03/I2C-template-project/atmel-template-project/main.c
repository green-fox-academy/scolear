#include "TC74_driver.h"
#include "HT16K33_driver.h"
#include "STDIO_lib.h"
#include <avr/io.h>
#include <stdio.h>
#include <avr/interrupt.h>

#define F_CPU 16000000UL
#include <util/delay.h>

#define LED_DDR			DDRB
#define LED_DDR_POS		DDRB5
#define LED_PIN			PINB
#define LED_PIN_POS		PINB5
#define LED_PORT		PORTB
#define LED_PORT_POS	PORTB5

void system_init()
{
    // Call the TWI driver init function
    TWI_init();
    // SDIO lib is initialed with 115200 baud rate with 8N1 settings
    STDIO_init();
    // Interrupts must be enabled as STDIO lib uses interrupts for receive
    sei();
}

int main(void)
{
    system_init();
    printf("System initialized\n");
    
    volatile int8_t temperature; 
    
    start_LED_osc();
    TWI_start();
    TWI_write(LED_ADDRESS);
    TWI_write(0b00000001);
    TWI_write(0b00000001);
    TWI_write(0b00000001);
    TWI_stop();
    TWI_start();
    TWI_write(LED_ADDRESS);
    TWI_write(LED_DISPLAY_ON);
    TWI_write(LED_OSC_OFF);
    TWI_stop();
    
    while (1) 
    {    
        temperature = read_temperature(TC_ADDRESS);
        printf("Current temperature of sensor: %d\n", temperature);
        _delay_ms(500);
    }
}