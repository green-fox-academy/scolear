#ifndef _FREQ_MEAS_H
#define _FREQ_MEAS_H

typedef enum counting_state {
    FIRST,
    SECOND
} counting_state_t;

void freq_meas_init();
float get_freq();

#endif // _FREQ_MEAS_H