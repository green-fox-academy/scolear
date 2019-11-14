// Multiple inclusion guard
#ifndef _TC74_DRIVER_H
#define _TC74_DRIVER_H

#include <stdint.h>

#define TC_WRITE	0
#define TC_READ		1

//Define the TC74A0 address
#define TC_ADDRESS 0b01001000

#define START           0x08
#define REPEATED_START  0x10
#define SLA_W_ACK       0x18
#define SLA_W_NACK      0x20
#define DATA_ACK        0x28
#define DATA_NACK       0x30

void TWI_init(void);
void TWI_start(void);
void TWI_write(uint8_t u8data);
void TWI_stop(void);
uint8_t TWI_read_nack(void);
uint8_t TWI_read_ack(void);

int8_t read_temperature(uint8_t slave_address);

#endif // _TC74_DRIVER_H