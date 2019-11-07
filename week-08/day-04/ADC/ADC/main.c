#include <avr/io.h>
#define F_CPU 16000000
#include <util/delay.h>

typedef enum pwm_type {
    FAST_PWM,
    PHASE_CORRECT
} pwm_t;

void timer0_init(pwm_t type)
{
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
    DDRD |= 1 << DDRD6;
}

void set_duty(uint8_t duty_byte)
{
    // Compare_value depending on incoming duty cycle percentage
    OCR0A = duty_byte;
}

void init()
{
    ADMUX |= 1 << 5;        // left adjusted result
    ADCSRA |= 0b11100000;
    ADCSRB |= 0;
}

int main(void)
{
    init();
    timer0_init(PHASE_CORRECT);
    
    uint8_t result;
    uint8_t result2;
    uint16_t combination_result;
    
    while (1)
    {
        result = ADCL;
        result2 = ADCH;
        // combination_result = ((uint16_t) result2 << 8) | result;

        set_duty(result2);
        _delay_ms(100);
    }
}