#include <avr/io.h>
#include <avr/interrupt.h>
#include <time.h>
#include <stdint.h>
#define F_CPU 16000000
#include <util/delay.h>

#include "reaction.h"

void start_game();
void restart_game();

uint8_t counter = 0;
const uint8_t cntr_max = 30;
int countdown_counter = 0;
int random_time_ms = 4000;
game_state gamestate = STANDBY;

ISR(INT0_vect)
{
    if (gamestate == STANDBY)
    {
        start_game();
    }
}

ISR(INT1_vect)
{
    // reaction trigger
    if (gamestate == COUNTDOWN) {
        RGB_BLUE_on();
        stop_timer2();
        _delay_ms(3000);
        restart_game();
    } else if (gamestate == GAME && countdown_counter < 500) {
        RGB_GREEN_on();
        stop_timer2();
        _delay_ms(3000);
        restart_game();
    } else if (gamestate == GAME && countdown_counter >= 500) {
        RGB_RED_on();
        stop_timer2();
        _delay_ms(3000);
        restart_game();
    }
}

ISR(TIMER0_OVF_vect)
{
     counter++;

     if (counter >= cntr_max)
     {
         PORTC ^= 0b00100000;    // red LED blinking
         counter = 0;
     }
}

ISR(TIMER2_OVF_vect)
{
    countdown_counter++;
    
    if (gamestate == COUNTDOWN && countdown_counter >= random_time_ms)
    {
        // times up, light up led, reset timer;
        PORTC = 0b11011111;
        countdown_counter = 0;
        gamestate = GAME;
    }
}

void start_game()
{
    stop_timer0();
    turn_LED_off();
    random_time_ms = (rand() % 7000) + 1000;
    gamestate = COUNTDOWN;
    start_timer2();
}

void restart_game()
{
    stop_timer0();
    turn_LED_off();
    gamestate = STANDBY;
    counter = 0;
    countdown_counter = 0;
}

void init()
{
    srand(time(NULL));
    
    LED_init();
    BUTTON_init();
    
    sei();
}

int main(void)
{
    init();
    
    while (1) 
    {
        standby(gamestate);
    }
}