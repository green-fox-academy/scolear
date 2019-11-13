#include "TC74_driver.h"
#include "STDIO_lib.h"
#include <avr/io.h>
#include <stdio.h>
#include <avr/interrupt.h>

#define F_CPU 16000000UL
#include <avr/delay.h>

#define LED_DDR			DDRB
#define LED_DDR_POS		DDRB5
#define LED_PIN			PINB
#define LED_PIN_POS		PINB5
#define LED_PORT		PORTB
#define LED_PORT_POS	PORTB5

void system_init()
{
    //TODO
    // Call the TWI driver init function

    // SDIO lib is initialed with 115200 baud rate with 8N1 settings
    STDIO_init();
    // Interrupts must be enabled as STDIO lib uses interrupts for receive
    sei();
}

int main(void)
{
    // Don't forget to call the init function :)
    system_init();

    printf("System initialized\n");

    // Infinite loop
    while (1) {
        //TODO
        //Write the temperature frequently.

        //TODO
        //Advanced: Don't use delay, use timer.

        //TODO
        //Blink the led to make sure the code is running

    }
}
