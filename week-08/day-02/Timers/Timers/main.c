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
    // Create a variable which will be a counter variable, initialize it with 0.
    uint8_t counter = 0;
    // This will be the maximal value of our counter
    const uint8_t cntr_max = 30;

    // Your task is to create about 1Hz flashing LED with the TC0 timer.
    // Use the counter variable, cntr_max and the overflow flag as a hint.

    init();

    while (1)
    {
        // If TC0 counter overflow occurred (TOV0 flag is set) toggle the LED and write "1" to that flag
        // (this will clear it, it's confusing, but this is how it works)
        if (TIFR0 & 0x01)
        {
            counter++;
            TIFR0 |= 1 << 0;
        }

        if (counter >= cntr_max)
        {
            PINB = 1 << PINB5;
            counter = 0;
        }
    }
}