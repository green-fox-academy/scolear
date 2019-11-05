#include <avr/io.h>

void init()
{
    // Set the prescaler to 1024 division. See at the TC0 control register in the datasheet!
    // With this you also set the clock source to CLK_io and you will also turn on the timer!
    TCCR0B |= 0b00000101;
    // Set the PB5 LED pin to output
    DDRB |= 1 << 5;
}

int main(void)
{
    // Don't forget to call the init function!
    init();

    while (1)
    {
        // If TC0 counter overflow occurred (TOV0 flag is set) toggle the LED and write "1" to that flag
        // (this will clear it, it's confusing, but this is how it works)
        if (TIFR0 & 0x01)
        {
            TIFR0 &= 0 << 0;
            PORTB = 1 << PORTB5;
        }
        PORTB = 0 << PORTB5;
    }
}