#include <avr/io.h>
#include <stdint.h>
#include <avr/interrupt.h>

uint8_t counter = 0;
const uint8_t cntr_max = 30;

// Write here the interrupt handler function. The vector name starts with TIMER ;). Use Ctrl+Space to find the proper vector name!
// Do the same thing in the interrupt handler as before.
// This time you don't have to do anything with the flags, the MCU does it automatically.

ISR(TIMER0_OVF_vect)
{
    counter++;

    if (counter >= cntr_max)
    {
        PINB = 1 << PINB5;
        counter = 0;
    }
} 

void manual_overflow_counter(uint8_t* counter, uint8_t counter_max)
{
    // If TC0 counter overflow occurred (TOV0 flag is set) toggle the LED and write "1" to that flag
    // (this will clear it, it's confusing, but this is how it works)

    if (TIFR0 & 0x01)
    {
        (*counter)++;
        TIFR0 |= 1 << 0;
    }

    if (*counter >= counter_max)
    {
        PINB = 1 << PINB5;
        *counter = 0;
    }
}

void init()
{
    // Set the prescaler to 1024 division. See at the TC0 control register in the datasheet!
    // With this you also set the clock source to CLK_io and you will also turn on the timer!
    TCCR0B |= 0b00000101;
    // Set the PB5 LED pin to output
    DDRB |= 1 << 5;
    // Enable the TC0 overflow interrupt
    TIMSK0 |= 1 << 0; 
    // Enable the interrupts globally
    sei();
}

int main(void)
{
    init();

    while (1)
    {
    }
}