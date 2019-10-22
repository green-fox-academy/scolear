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

int main() {
    /*
     * Write a function called SetBit which takes a byte and a bit position
     * and sets the bit of byte in the specified bit position to 1.
     * E.g. byte = 0b1100, bit position = 1 => returns with 0b1110
     */

    uint8_t test = 0b00101100;
    PrintBinary(test);

    test = set_bit(test, 1);
    PrintBinary(test);

    /*
     * Write a function called ClearBit which takes a byte and a bit position
     * and clears the bit of byte in the specified bit position to 0.
     * E.g. byte = 0b1100, bit position = 2 => returns with 0b1000
     */

    test = clear_bit(test, 2);
    PrintBinary(test);

    return 0;
}