#include <avr/io.h>
#define F_CPU 16000000
#include <util/delay.h>
#include "pwm.h"

void init()
{
    timer_init();
}

int main(void)
{
    init();
    
    uint8_t duty = 255 / 4;
    
    while (1) 
    {
        set_duty(duty);
        _delay_ms(100);
        duty += 5;
        
        if (duty >= 100)
        {
            duty = 0;
        }
        
    }
}

