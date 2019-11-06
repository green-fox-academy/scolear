#include "pwm.h"
#include <avr/io.h>

void timer_init()
{
    DDRD = 1 << DDRD6;      // set pd6 as output
    
    TCCR0A = 0b10000011;
    TCCR0B = 0b00000010;
}

void set_duty(uint8_t duty)
{
    OCR0A = duty * 255 / 100;
}