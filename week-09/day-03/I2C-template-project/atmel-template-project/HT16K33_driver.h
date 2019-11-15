#ifndef HT16K33_DRIVER_H_
#define HT16K33_DRIVER_H_

#include <stdint.h>

#define LED_ADDRESS     0b11100000
#define LED_OSC_ON      0b00100001
#define LED_OSC_OFF     0b00100000
#define LED_DISPLAY_ON  0b10000001

void start_LED_osc();
void draw_shape(uint8_t data[]);
void clear_display();
void update_display();



#endif /* HT16K33_DRIVER_H_ */