#include <avr/io.h>
#include <stdint.h>
#include <avr/interrupt.h>

// Create an application which changes the LED brightness by switching it on/off
// regularly for different length of time.
// How does it works? Let's say that you turn on the LED for 100us and off for
// 900us and you repeat this pattern. Your eyes are not so fast, so it will
// percieve that on average the LED is turned on for 10% of the time, so it is
// 10% bright.

// To achieve this behavior you should configure the timer to overflow with
// about 240Hz frequency. You should use the Output Compare A Match Interrupt
// and the Overflow Interrupt to implement the behavior!

//TIMER0 COMPA 
//TIMER0 OVF 
// OCR0A -- output compare A

ISR(TIMER0_COMPA_vect)
{
    PORTB = 0 << PORTB5;
}

ISR(TIMER0_OVF_vect)
{
    PORTB = 1 << PORTB5;
}

void init()
{
    TCCR0B |= 0b00000101; // start clock with 1024 prescaling
    
    TIMSK0 |= 1 << 0; // overflow interrupt enable
    TIMSK0 |= 1 << 1; // output compare enable
    sei();
    
    OCR0A = 10;
    
    DDRB |= 1 << 5;
}

int main(void)
{
    init();

    while (1)
    {
        
    }
}