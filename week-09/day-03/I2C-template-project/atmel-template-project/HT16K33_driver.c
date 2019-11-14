#include "HT16K33_driver.h"
#include "TC74_driver.h"

void start_LED_osc()
{
    TWI_start();
    TWI_write(LED_ADDRESS);             // send out slave address + W
    TWI_write(LED_OSC_ON);              // turn led oscillator ON command
    TWI_stop();
}