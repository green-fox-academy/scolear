#include "pwm.h"
#include <avr/io.h>

void timer_init(pwm_t type)
{
    DDRD = 1 << DDRD6;      // set pd6 as output
    
    switch (type) {
        case FAST_PWM:
            TCCR0A = 0b10000011;    // FAST PWM MODE
            TCCR0B = 0b00000010;    // CLK start and mode
            break;
        case PHASE_CORRECT:
            TCCR0A = 0b10000001;    // PHASE Correct PWM MODE
            TCCR0B = 0b00000010;    //
            break;    
    }
}

void set_duty(uint8_t duty)
{
    // Compare value depending on incoming duty cycle percentage
    OCR0A = duty * 255 / 100;
}