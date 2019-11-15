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
    uint8_t shape[8] = {0x02, 0x3c, 0xa4, 0x24, 0x3c, 0x04, 0x05, 0x44};
    
    start_LED_osc();

    draw_shape(shape);
        
    update_display();
    
    while (1) 
    {    
        temperature = read_temperature(TC_ADDRESS);
        printf("Current temperature of sensor: %d\n", temperature);
        _delay_ms(500);
    }
}