
#include <avr/io.h>
#include <stdio.h>

void init()
{
    ADCSRA |= 0b11100000;
    ADCSRB |= 0;
    
    DDRD |= 1 << DDRD6;
}

int main(void)
{
    init();
    
    uint8_t result;
    uint8_t result2;
    
    uint16_t combination_result;
    
    while (1) 
    {
        result = ADCL;
        result2 = ADCH;
        combination_result = ((uint16_t) result2 << 8) | result;
    }
}

