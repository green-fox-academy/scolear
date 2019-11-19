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
	for (int i = 1; i < 5; i++) {
		PORTB = 1 << i;
		_delay_ms(150);
	}
	
	for (int j = 3; j > 1; j--)	{
		PORTB = 1 << j;
		_delay_ms(150);
	}
}

void knight_rider_circular(uint8_t direction_flag)
{
	if (direction_flag) {
		for (int i = 1; i < 5; i++) {
			PORTB = 1 << i;
			_delay_ms(150);
		}
	} else {
		for (int i = 4; i > 0; i--) {
			PORTB = 1 << i;
			_delay_ms(150);
		}
	}
}

int main(void)
{
	DDRB = 0b00011110;
	uint8_t direction = 1;
	
    while (1)
    {
		//blink_at_1_Hz();
		//knight_rider();
		
		if ((PINC & (1<<PINC5))) {
			_delay_ms(10);
			if (direction) {
				direction = 0;
			} else {
				direction = 1;
			}
		}
		
		knight_rider_circular(direction);
    }
}

