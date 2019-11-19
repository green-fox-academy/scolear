#include <avr/interrupt.h>
#include <avr/io.h>
#define F_CPU 16000000
#include <util/delay.h>

uint8_t brighten = 1;

ISR(PCINT0_vect)
{
    brighten = !brighten;
}

typedef enum pwm_type {
    FAST_PWM,
    PHASE_CORRECT
} pwm_t;

void timer0_init(pwm_t type)
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
    // Compare_value depending on incoming duty cycle percentage
    OCR0A = duty * 255 / 100;
}

void init()
{
    pwm_t type = FAST_PWM;
    //pwm_t type = PHASE_CORRECT;
    timer0_init(type);
    
    PCMSK0 |= 1 << PCINT7;
    PCICR |= 1 << PCIE0;
    
    sei();
}

int main(void)
{
    init();
    
    uint8_t duty = 0;
    
    while (1) 
    {
        set_duty(duty);
        _delay_ms(100);
        if (brighten) {
            if (duty < 100)
            {
                duty += 5;
            }
        } else {
            if (duty > 0)
            {
                duty -= 5;
            }
        }
    }
}

