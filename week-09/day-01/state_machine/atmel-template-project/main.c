  
  #include <avr/io.h>
  #include <stdint.h>
  #include <stdio.h>
  #include <avr/interrupt.h>
  #include <string.h>
  #include <STDIO_lib.h>

  #define F_CPU 16000000
  #include <util/delay.h>
  
  // TODO:
/* Create an enum type which represents the following program states:
	- LED blinker mode
	- LED-Pushbutton mode
	- LED on mode
	- LED off mode
*/

typedef enum program_state {
    LED_BLINKER,
    LED_PUSHBUTTON,
    TURN_LED_ON,
    TURN_LED_OFF
} program_state_t;

ISR(PCINT0_vect){
    PORTB ^= 1 << PORTB5;
}

int readline(int readch, char *buffer, int len)
{
    static int pos = 0;
    int rpos;
    
    if (readch > 0) {
        switch (readch) {
            case '\n': // Ignore new-lines
            break;
            case '\r': // Return on CR
            rpos = pos;
            pos = 0;  // Reset position index ready for next time
            return rpos;
            default:
            if (pos < len-1) {
                buffer[pos++] = readch;
                buffer[pos] = 0;
            }
        }
    }
    // No end of line has been found, so return -1.
    return -1;
}

void init() {
    // Initialize the UART interface with 115200 baud/sec
    STDIO_init();

    // Initialize the LED pin
    DDRB |= 1 << DDRB5;

    PCICR |= 1 << PCIE0;
    
    sei();
}

int main(void)
{
	// SDIO lib is initialed with 115200 baud rate with 8N1 settings
	// Don't forget to call the Init() function :)
	init();
    printf("System initialized\n");

	// TODO:
	// Create a variable with your custom program state type enum
    program_state_t state;
	// TODO:
	// Initialize the state to LED blinker mode
    state = LED_BLINKER;
    
    char buffer[32];
    
	// Infinite loop
	while (1) {
    	// TODO:
    	// Check the UART input buffer. If it's not empty process the string in it,
    	// maybe it is a command!
        
        //if (readline(getchar(), buffer, 32) > 0) {
            //if(strcmp(buffer, "button!\r\n") == 1) state = LED_PUSHBUTTON;
           // }
                                                  
        //if (gets(buffer) != 0)
        //{
          //  puts(buffer);
        //}
        
    	// TODO:
    	// Do the tasks based on the state, hint: use switch-case
        switch (state) {
            case LED_BLINKER :
                PCMSK0 = 0;
                PINB = 1 << PINB5;
                _delay_ms(250);
                break;
            case LED_PUSHBUTTON :
                PCMSK0 |= 1 << PCINT7;
                break;
            case TURN_LED_ON :
                PCMSK0 = 0;
                PORTB |= 1 << PORTB5;
                break;
            case TURN_LED_OFF :
                PCMSK0 = 0;
                PINB = 0;
                break;
        }            
	}
}

