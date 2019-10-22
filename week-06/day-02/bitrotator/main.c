
#include <stdio.h>
#include <stdint.h>

void PrintBinary(uint8_t byte) {
    printf("%c%c%c%c %c%c%c%c\n",
           (byte & 0x80 ? '1' : '0'),
           (byte & 0x40 ? '1' : '0'),
           (byte & 0x20 ? '1' : '0'),
           (byte & 0x10 ? '1' : '0'),
           (byte & 0x08 ? '1' : '0'),
           (byte & 0x04 ? '1' : '0'),
           (byte & 0x02 ? '1' : '0'),
           (byte & 0x01 ? '1' : '0'));
}

uint8_t set_bit(uint8_t byte, char bit) {

    uint8_t bitmask = 0b00000001 << bit;

    return byte | bitmask;
}

uint8_t clear_bit(uint8_t byte, char bit) {

    uint8_t bitmask = 0b00000001 << bit;

    bitmask = ~bitmask;

    return byte & bitmask;
}

uint8_t toggle_bit(uint8_t byte, char bit) {

    uint8_t bitmask = 0b00000001 << bit;

    return byte ^ bitmask;
}

int is_odd(uint8_t byte) {
    int ret;
    ret = byte & 0x01 ? 1 : 0;
    return ret;
}

uint8_t rotate_right(uint8_t byte, char amount) {

    for (int i = 0; i < amount; i++) {
        if(is_odd(byte)) {
            byte = byte >> 1;
            byte = set_bit(byte, 7);
            PrintBinary(byte);
        } else {
            byte = byte >> 1;
            PrintBinary(byte);
        }
    }
    return byte;
}

uint8_t rotate_left(uint8_t byte, char amount) {

    for (int i = 0; i < amount; i++) {
        if((byte & 0x80 ? 1 : 0)) {
            byte = byte << 1;
            byte = set_bit(byte, 0);
            PrintBinary(byte);
        } else {
            byte = byte << 1;
            PrintBinary(byte);
        }
    }
    return byte;
}

int main() {
    /* 1.
     * Write a function called RotateRight which takes a byte and a number
     * and rotates the bits of byte in right direction number times.
     * It should return with the result.
     * E.g. byte = 0b1000000, number = 1 => returns 0b01000000
     * E.g. byte = 0b1000001, number = 2 => returns 0b01100000
     */

    uint8_t testbyte = 0b10000001;
    testbyte = rotate_right(testbyte, 10);

    /* 2.
     * Write a function called RotateLeft which takes a byte and a number
     * and rotates the bits of byte in left direction number times.
     * It should return with the result.
     * E.g. byte = 0b1000000, number = 1 => returns 0b00000001
     * E.g. byte = 0b1000001, number = 2 => returns 0b00000110
     */

    uint8_t testbyte2 = 0b10000001;
    testbyte = rotate_left(testbyte2, 10);

    return 0;
}