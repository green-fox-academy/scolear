#include <avr/io.h>
#define F_CPU 16000000
#include <util/delay.h>

void blinkingLED() 
{
	// Make the green user LED flash with a frequency of 4 Hz (blink 4 times per second) while the user pushbutton is pressed.
	// If the button is not pressed the LED should not be lit.
	
	if (!(PINB & (1<<PINB7))) {
		PORTB = 1 << 5;
		_delay_ms(250);
		PORTB = 0 << 5;
		_delay_ms(250);
		} else {
		PORTB = 0 << 5;
	}
}

void toggleLED(uint8_t *ON)
{
	//Toggle the green user LED with the user button.
	//A push should turn on the LED if it is turned off and it should turn the LED off if it's already turned on.
	
	if (!(PINB & (1<<PINB7))) {
		_delay_ms(200);
		if (*ON) {
			PORTB = 0 << 5;
			*ON = 0;
			} else {
			PORTB = 1 << 5;
			*ON = 1;
		}
	}
}

void blocking(uint8_t *flag)
{
	// Make the green user LED flash with a frequency of 2 Hz but do not start until the user button is pushed.
	// Once it is pushed the LED should be blinking forever.
	
	if (*flag) {
		PORTB = 1 << 5;
		_delay_ms(250);
		PORTB = 0 << 5;
		_delay_ms(250);
	} else {
		if (!(PINB & (1<<PINB7))) {
			*flag = 1;
		}
	}
}

void counterToggle(uint8_t *limit)
{
	if (!(PINB & (1<<PINB7))) {
		_delay_ms(250);
		(*limit)++;
	}
	
	if (*limit >= 5) {
		PORTB = 1 << 5;
	}
}

int main(void)
{
	
	DDRB = 1 << 5;
	
	uint8_t ON = 0;
	uint8_t counter = 0;
	
    while (1)
    {
		//blinkingLED();
		
		//toggleLED(&ON);
		
		//blocking(&ON);
		
		counterToggle(&counter);
		
    }
}

