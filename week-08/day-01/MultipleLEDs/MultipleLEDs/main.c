#include <avr/io.h>
#define F_CPU 16000000
#include <util/delay.h>


int main(void)
{
	DDRB = 0b00011110;
	
    while (1) 
    {
		PORTB = 0b00011110;
		_delay_ms(500);
		PORTB = 0b00000000;
		_delay_ms(500);
    }
}

