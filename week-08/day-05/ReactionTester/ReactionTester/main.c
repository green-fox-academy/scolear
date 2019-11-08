#include <avr/io.h>
#include <avr/interrupt.h>
#define F_CPU 16000000
#include <util/delay.h>

// todo : define interrupts

ISR(INT0_vect)
{
    PORTC ^= 0b00100000;    //turn red led on
}

ISR(INT1_vect)
{
    //game
}

void LED_init()
{
    DDRC |= 0b00100111;
    PINC |= 0b11111111;
}

void BUTTON_init()
{
    //PCICR |= 0b00000011;
    //PCMSK0 |= 1 << 0;
    //PCMSK1 |= 1 << 0;
    
    EIMSK |= 0b00000011;    // enable external interrupts
    EICRA |= 0b00001010;    // external interrupt modes
    
    
}

void init()
{
    LED_init();
    BUTTON_init();
    
    sei();
}


int main(void)
{
    init();
    
    while (1) 
    {
        
    }
}

