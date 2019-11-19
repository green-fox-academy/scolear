
#include <avr/io.h>
#include <avr/interrupt.h>
#include "reaction.h"

void LED_init()
{
    DDRC |= 0b00100111;
    PINC |= 0b11111111;     // LEDs are wired from cathode, so we start with high state
}

void BUTTON_init()
{
    // Using external interrupts instead:
    EIMSK |= 0b00000011;    // enable external interrupts
    EICRA |= 0b00001010;    // external interrupt modes
}

void standby(game_state state)
{
    switch (state) {
        case STANDBY: start_timer0(); break;
        case GAME: stop_timer0(); break;
        case COUNTDOWN: stop_timer0(); break;
    }
}

void turn_LED_off()
{
    PORTC = 0b11111111;
}

void start_timer0()
{
    TCCR0B |= 0b00000101;
    TIMSK0 |= 1 << 0;
}

void stop_timer0()
{
    TCCR0B = 0;
    TIMSK0 = 0;
}

void start_timer2()
{
    TCCR2B |= 0b00000101;
    TIMSK2 |= 1 << 0;
}

void stop_timer2()
{
    TCCR2B = 0;
    TIMSK2 = 0;
}

void RGB_BLUE_on()
{
    PORTC ^= 0b00000100;
}

void RGB_RED_on()
{
    PORTC ^= 0b00000001;
}

void RGB_GREEN_on()
{
    PORTC ^= 0b00000010;
}