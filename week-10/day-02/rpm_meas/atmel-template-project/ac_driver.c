#include <avr/io.h>
#include "ac_driver.h"
#include "freq_meas.h"

void ac_driver_init()
{
	/*************
	 * AC CONFIG *
	 *************/
	// TODO:
	// Disable the digital input buffers on AN0 and AN1 to reduce power consumption.
	// See the DIDR1 register description for more info.
    DIDR1 |= (1 << AIN1D) | (1 << AIN0D);
	// TODO:
	// Connect the AC output to the AC0 pin.
	// The datasheet if screwed up. It says "Analog Comparator Control and Status Register C", meanwhile the name of this register is "ACSR0",
	// but in the avr/io.g header this register can be reached with the "ACSRB" macro.
    ACSRB |= (1 << 0);
	// TODO:
	// Configure the rest settings properly :)
	// AC output connected to TC1 input capture
    
    //ACSR |= (1 << ACIC);
    //ADCSRB |= (1 << ACME);
    
    ADCSRA = (1 << ADATE);
    ACSR = (1 << ACO) |(1 << ACIC) | (1 << ACIS1);
    ADCSRB = (1 << 6) | (1 << 1);
    
}

// TODO:
// Write this function. It returns the measured rotation speed in RPM
float get_rpm()
{
    return get_freq()/7.00;
}