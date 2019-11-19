#include <avr/io.h>			// This header contains the definitions for the io registers
#include <stdint.h>
#include <stdio.h>
#include <avr/interrupt.h>
#include <stdbool.h>
#include "circbuff.h"

#define F_CPU	16000000	// This definition tells to _delay_ms() that the CPU runs at 16MHz
#include <util/delay.h>		// This header contains the _delay_ms() function


#define RX_CIRC_BUFF_LEN 25
//TODO: Create the circular buffer with the length of RX_CIRC_BUFF_LEN


ISR(USART_RX_vect) {
    //TODO:
    // Put received character into the circular buffer

    //TODO:
    // Increment the write ptr
    // Be aware that the write ptr might point to the end of the buffer.
    // In this case you have to set it back to the start of the buffer
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

    // Initialize circular buffer pointers, they should point to the head of the buffer
//todo
    // Enable interrupts globally
    sei();
}

void UART_SendCharacter(char character) {
    //TODO:
    // Write this function, which can send a character through UART will polling method
    // See page 247 of the datasheet for hints, be aware that the code in the datasheet has a problem :)

    //TODO:
    // Wait for empty USART buffer register

    //TODO:
    // Put data to USART buffer register
}

char UART_GetCharacter() {
    //TODO:
    // Wait for data in the circular buffer, this can be detected if the write and read pointers are pointing to the same memory block

    //TODO:
    // Save the data to a temporary variable

    //TODO:
    // Increment the read ptr
    // Be aware that the read ptr might point to the end of the buffer.
    // In this case you have to set it back to the start of the buffer

    //TODO:
    // Return the read character
}

int main(void) {
    char buffer[255];

    //Don't forget to call the init function :)
    UART_Init();

    // Setting up STDIO input and output buffer
    // You don't have to understand this!
    //----- START OF STDIO IO BUFFER SETUP
    FILE UART_output = FDEV_SETUP_STREAM(UART_SendCharacter, NULL, _FDEV_SETUP_WRITE);
    stdout = &UART_output;
    FILE UART_input = FDEV_SETUP_STREAM(NULL, UART_GetCharacter, _FDEV_SETUP_READ);
    stdin = &UART_input;
    //----- END OF STDIO IO BUFFER SETUP

    // Try printf
    printf("Startup...\r\n");

    // Loop that runs forever
    while (1) {
        // With gets and puts create a loopback, use the buffer variable!
        gets(buffer);
        _delay_ms(500);
        puts(buffer);
        _delay_ms(500);
    }
}