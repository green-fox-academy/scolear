#include <avr/io.h>
#define F_CPU 16000000
#include <util/delay.h>

int main(void)
{
	
	DDRB = 1 << 5;
	
    while (1) 
    {
		if (!(PINB & (1<<PINB7))) {
			PORTB = 1 << 5;
			_delay_ms(250);
			PORTB = 0 << 5;
			_delay_ms(250);	
		} else {
			PORTB = 0 << 5;
		}
    }
}

