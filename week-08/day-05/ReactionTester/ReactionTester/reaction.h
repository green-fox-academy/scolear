
#ifndef REACTION_H_
#define REACTION_H_

typedef enum game_state {
    STANDBY,
    COUNTDOWN,
    GAME
} game_state;

void LED_init();
void BUTTON_init();
void standby(game_state state);

void turn_LED_off();
void RGB_BLUE_on();
void RGB_RED_on();
void RGB_GREEN_on();

void start_timer0();
void stop_timer0();

void start_timer2();
void stop_timer2();

#endif /* REACTION_H_ */