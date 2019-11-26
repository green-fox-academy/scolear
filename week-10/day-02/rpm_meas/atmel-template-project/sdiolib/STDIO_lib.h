/*
 * STDIO_lib.h
 *
 * Created: 10/15/2019 10:40:09 AM
 *  Author: Kazy
 */ 


#ifndef STDIO_LIB_H_
#define STDIO_LIB_H_

#include <stdio.h>

void STDIO_init();
int STDIO_send_character(char character, FILE *stream);
int STDIO_get_character(FILE *stream);
int STDIO_is_buffer_empty();

#endif /* STDIO_LIB_H_ */