#include "TC74_driver.h"
#include "HT16K33_driver.h"
#include "STDIO_lib.h"
#include <avr/io.h>
#include <stdio.h>
#include <avr/interrupt.h>

#define F_CPU 16000000UL
#include <util/delay.h>

#define INT_DELAY 100

volatile int8_t global_bias = 0;

ISR(INT0_vect)
{
    printf("Lowering bias\n");
    global_bias--;
    _delay_ms(INT_DELAY);
}

ISR(INT1_vect)
{
    global_bias++;
    _delay_ms(INT_DELAY);
}

ISR(PCINT0_vect)
{
    global_bias = 0;
}

void button_init()
{
    EIMSK |= 0b00000011;    // enable external interrupts
    EICRA |= 0b00001010;    // external interrupt modes: falling edge
    
    PCMSK0 |= 1 << PCINT0;
    PCICR |= 1 << PCIE0;
}

void system_init()
{
    TWI_init();
    // SDIO lib is initialized with 115200 baud rate with 8N1 settings
    STDIO_init();
    button_init();
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
        temperature += global_bias;
        printf("Current temperature of sensor: %d\n", temperature);
        
        display_temperature(temperature);
        _delay_ms(1000);
    }
}