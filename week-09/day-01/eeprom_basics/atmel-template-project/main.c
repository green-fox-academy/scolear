#define F_CPU 16000000

#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>
#include "STDIO_lib.h"
#include <avr/interrupt.h>

#include <avr/eeprom.h>
#include <stdint.h>

// TODO:
/*
	1) leave everything uncommented! Write the other TODOs first, then run the program.
		On the serial port you can see the default values of the variables
	2) Now uncomment the "READ_FROM_EEPROM" definition. This will enable EEPROM read at startup.
		you will see random numbers on UART, because you just read uninitialized data from the EEPROM
	3) Now comment out the READ_FROM_EEPROM definition, and uncomment the other one
		On the serial port you can see the default values of the variables
	4) Now uncomment the "READ_FROM_EEPROM" definition, and comment out the other one
		you will see the defaults numbers, which were loaded from the EEPROM
*/
#define READ_FROM_EEPROM
//#define WRITE_DEFAULTS_TO_EEPROM

uint8_t var_8bit = 8;
uint16_t var_16bit = 16;
uint32_t var_32bit = 32;
float var_float = 3.14;
uint8_t array[] = {1,2,3,4,5,6};

// TODO:
// Define the EEPROM memory addresses for the variables
#define var_8bit_address 0x00
#define var_16bit_address 0x01
#define var_32bit_address 0x03
#define var_float_address 0x07
#define var_array_address 0x0C

void init() {
    // Initialize the UART interface with 115200 baud/sec
    STDIO_init();

#ifdef WRITE_DEFAULTS_TO_EEPROM
    // TODO: write the default values of the variables to the EEPROM
    eeprom_update_byte((uint8_t*)var_8bit_address, var_8bit);
    eeprom_update_word((uint16_t*)var_16bit_address, var_16bit);
    eeprom_update_dword((uint32_t*)var_32bit_address, var_32bit);
    eeprom_update_float((float*)var_float_address, var_float);
    eeprom_update_block ((const void *) array, (void *) var_array_address, sizeof(array));
#endif

#ifdef READ_FROM_EEPROM
    // TODO: read the values from the EEPROM to the variables
    var_8bit = eeprom_read_byte((uint8_t*)var_8bit_address);
    var_16bit = eeprom_read_word((uint16_t*)var_16bit_address);
    var_32bit = eeprom_read_dword((uint32_t*)var_32bit_address);
    var_float = eeprom_read_float((float*)var_float_address);
    eeprom_read_block ((void *) array, (const void *) var_array_address, sizeof(array)) ;
#endif
}

int main(void)
{
	char buffer[32];
	init();
	sei();
	
	printf("System initialized\n");
	
    // TODO:

    // Print out the variables
    // printf can't print out floating point numbers (float) by deafault :(
    // Just don't care, it's okay
    printf("var_8bit\t%d\n", var_8bit);
    printf("var_16bit\t%d\n", var_16bit);
    printf("var_32bit\t%ld\n", var_32bit);
    printf("var_float\t%f\n", var_float);
    printf("array\t");
    for(uint8_t i = 0; i < sizeof(array); i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    
    
	while (1)
	{
		gets(buffer);
		puts(buffer);
	}
}

