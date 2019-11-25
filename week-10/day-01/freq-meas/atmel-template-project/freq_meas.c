#include <avr/io.h>
#include <stdint.h>
#include <avr/interrupt.h>
#include "freq_meas.h"

volatile uint8_t overflow_counter = 0;
volatile uint16_t timer_value_1;
volatile uint16_t timer_value_2;
volatile counting_state_t state = FIRST;
int64_t g_timer_diff = 0;

ISR(TIMER1_OVF_vect)
{
    overflow_counter++;
}

ISR(TIMER1_CAPT_vect)
{
    switch (state)
    {
        case FIRST :
            
            timer_value_1 = ICR1;
            state = SECOND;
            break;
        case SECOND :
            timer_value_2 = ICR1;
            g_timer_diff = overflow_counter * 65535 + timer_value_2 - timer_value_1;
            state = FIRST;
            break;
    }
    overflow_counter = 0;
}

void freq_meas_init()
{
	/**************
	 * TC1 CONFIG *
	 **************/
	// TODO:
	// Configure the TC1 timer properly :)
    
    TCCR1B |= (1 << ICES1) | (1 << 1) | (1 << ICNC1);
    
    TIMSK1 |= (1 << ICIE1) | (1 << TOIE1);
    
}

// TODO:
// Write this function. It returns the measured frequency in Hz
float get_freq()
{
    double period = 0.0000005 * g_timer_diff;
    float freq = 1 / period;
    return period;
}