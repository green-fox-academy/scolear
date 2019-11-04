#include <avr/io.h>
#define F_CPU 16000000
#include <util/delay.h>

void blink_at_1_Hz()
{
	PORTB = 0b00011110;
	_delay_ms(500);
	PORTB = 0b00000000;
	_delay_ms(500);
}

void knight_rider()
{
	for (int i = 1; i < 5; i++)
	{
		PORTB = 1 << i;
		_delay_ms(150);
	}
	for (int j = 3; j > 1; j--)
	{
		PORTB = 1 << j;
		_delay_ms(150);
	}
}

int main(void)
{
	DDRB = 0b00011110;
	
    while (1) 
    {
		//blink_at_1_Hz();
		knight_rider();
    }
}

