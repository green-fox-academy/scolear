#include <avr/io.h>
#include <avr/interrupt.h>
#define F_CPU 16000000
#include <util/delay.h>

#include "pwm.h"

uint8_t counter = 0;
const uint8_t cntr_max = 30;
uint8_t brighten = 1;

ISR(TIMER2_OVF_vect)
{
    counter++;

    if (counter >= cntr_max)
    {
        brighten = !brighten;
        counter = 0;
    }
}


void init()
{
    // pwm_t type = FAST_PWM;
    pwm_t type = PHASE_CORRECT;
    timer0_init(type);
    
    sei();
    timer1_init();
}

int main(void)
{
    init();
    
    uint8_t duty = 0;
    
    while (1) 
    {
        set_duty(duty);
        _delay_ms(100);
        
        if (brighten)
        {
            duty += 5;
            
            if (duty >= 100)
            {
                duty = 100;
            }
        }
        else
        {
            duty -= 5;
            if (duty <= 0)
            {
                duty = 0;
            }
        }
    }
}

