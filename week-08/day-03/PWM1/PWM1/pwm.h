
#ifndef PWM_H_
#define PWM_H_

#include <stdint.h>

typedef enum pwm_type {
    FAST_PWM,
    PHASE_CORRECT
} pwm_t;


void timer0_init(pwm_t type);
void timer1_init();
void set_duty(uint8_t duty);


#endif /* PWM_H_ */