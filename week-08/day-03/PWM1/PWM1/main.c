#include <avr/io.h>
#define F_CPU 16000000
#include <util/delay.h>
#include "pwm.h"

void init()
{
    // pwm_t type = FAST_PWM;
    pwm_t type = PHASE_CORRECT;
    timer_init(type);
}

int main(void)
{
    init();
    
    uint8_t duty = 0;
    
    while (1) 
    {
        set_duty(duty);
        _delay_ms(100);
        duty += 2;
        
        if (duty >= 100)
        {
            duty = 0;
        }
        
    }
}

