#include "freq_meas.h"
#include <avr/io.h>
#include <stdio.h>
#include <avr/interrupt.h>
#include <STDIO_lib.h>

#ifndef F_CPU
#define F_CPU 16000000UL
#endif
#include <util/delay.h>

#define LED_DDR			DDRB
#define LED_DDR_POS		DDRB5
#define LED_PIN			PINB
#define LED_PIN_POS		PINB5
#define LED_PORT		PORTB
#define LED_PORT_POS	PORTB5

void system_init()
{
    LED_DDR |= 1 << LED_DDR_POS;
    freq_meas_init();
    STDIO_init();
    sei();
}

int main(void)
{

    // Don't forget to call the init function :)
    system_init();

    // Try printf
    printf("Startup...\n");

    // Infinite loop
    while (1) {
        // Generating an about 1Hz signal on the LED pin.
        // The printf call will also take some time, so this won't be exactly 1Hz.
        LED_PORT |= 1 << LED_PORT_POS;
        _delay_ms(500);
        LED_PORT &= ~(1 << LED_PORT_POS);
        _delay_ms(500);
        printf("%f Hz\n", get_freq());
    }
}