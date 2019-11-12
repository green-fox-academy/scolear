  
  #include <avr/io.h>
  #include <stdint.h>
  #include <stdio.h>
  #include <avr/interrupt.h>
  #include <string.h>
  //#include <STDIO_lib.h>

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

program_state_t state;

ISR(PCINT0_vect){
    PORTB ^= 1 << PORTB5;
}

ISR(USART_RX_vect) {
    switch (UDR0) {
        case 't': state = LED_PUSHBUTTON; break;
        case 'b': state = LED_BLINKER; break;
        case 'o': state = TURN_LED_ON; break;
        case 'f': state = TURN_LED_OFF; break;
    }
}

void UART_Init() {
    //TODO:
    // Write this function
    // See the datasheet on page 246 for hints and table 25-9.

    // At first set the baud rate to 9600
    // The CPU clock frequency is 16MHz
    UBRR0 = 103;

    // Set the following frame format: 8N1
    // It's set by default to 8N1

    // Enable TX
    UCSR0B |= 1 << 3;

    // Enable RX
    UCSR0B |= 1 << 4;

    // Enable RX interrupt
    UCSR0B |= 1 << 7;

}

void UART_SendCharacter(char character)
{
    // Write this function, which can send a character through UART will polling method
    // See page 247 of the datasheet for hints, be aware that the code in the datasheet has a problem :)
    //---------------------------------
    //TODO:
    // Wait for empty buffer
    while (!(UCSR0A & (1 << UDRE0)))
    ;
    //TODO:
    // Put data to buffer
    UDR0 = character;
}

char UART_GetCharacter()
{
    // Write this function, which waits for a character and returns when one is received
    // See page 249 of the datasheet for hints, be aware that the code in the datasheet has a problem :)
    //---------------------------------
    //TODO:
    // Wait for data received
    while (!(UCSR0A & (1 << RXC0)))
    ;
    //TODO:
    // Get data from buffer
    return UDR0;
}

void init() {
    // Initialize the UART interface with 115200 baud/sec
    //STDIO_init();
    
    UART_Init();

    // Initialize the LED pin
    DDRB |= 1 << DDRB5;

    PCICR |= 1 << PCIE0;
    
    sei();
}

int main(void)
{
	// SDIO lib is initialed with 115200 baud rate with 8N1 settings
    
    // Setting up STDIO input and output buffer
    // You don't have to understand this!
    //----- START OF STDIO IO BUFFER SETUP
    FILE UART_output = FDEV_SETUP_STREAM(UART_SendCharacter, NULL, _FDEV_SETUP_WRITE);
    stdout = &UART_output;
    FILE UART_input = FDEV_SETUP_STREAM(NULL, UART_GetCharacter, _FDEV_SETUP_READ);
    stdin = &UART_input;
    //----- END OF STDIO IO BUFFER SETUP
    
	// Don't forget to call the Init() function :)
	init();
    printf("System initialized\n");

	// TODO:
	// Initialize the state to LED blinker mode
    state = LED_BLINKER;
    
    char buffer[32];
    
	// Infinite loop
	while (1) {

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
                PORTB = 0;
                break;
        }            
	}
}

