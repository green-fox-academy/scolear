
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

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

void PrintBinaryArray(uint8_t* bytearray, uint32_t bytes) {
    for (int i = 0; i < bytes; ++i) {
        printf("%c%c%c%c %c%c%c%c | ",
               (bytearray[i] & 0x80 ? '1' : '0'),
               (bytearray[i] & 0x40 ? '1' : '0'),
               (bytearray[i] & 0x20 ? '1' : '0'),
               (bytearray[i] & 0x10 ? '1' : '0'),
               (bytearray[i] & 0x08 ? '1' : '0'),
               (bytearray[i] & 0x04 ? '1' : '0'),
               (bytearray[i] & 0x02 ? '1' : '0'),
               (bytearray[i] & 0x01 ? '1' : '0'));
    }
    printf("\n");
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

uint8_t is_odd(uint8_t byte) {
    uint8_t ret;
    ret = byte & 0x01 ? 1 : 0;
    return ret;
}

uint8_t rotate_right(uint8_t byte, char amount) {

    for (int i = 0; i < amount; i++) {
        if(is_odd(byte)) {
            byte = byte >> 1;
            byte = set_bit(byte, 7);
        } else {
            byte = byte >> 1;
        }
    }
    return byte;
}

uint8_t rotate_left(uint8_t byte, char amount) {

    for (int i = 0; i < amount; i++) {
        if((byte & 0x80 ? 1 : 0)) {
            byte = byte << 1;
            byte = set_bit(byte, 0);
        } else {
            byte = byte << 1;
        }
    }
    return byte;
}


void array_rotator(void *ptr, uint32_t bytes, uint32_t rotation_count, uint8_t right) {
    /* This function should rotate the ptr buffer bits by rotation_count to left or right direction.
     * The rotation direction is right if the right parameter is positive, left otherwise.
     * E.g. ptr ->  |   0xAA    |    0x55   |    0x23   |
     *              | 1010 1010 | 0101 0101 | 0010 0011 |
     * array_rotator(ptr, 3, 2, 1) result is:
     *              |   0xEA    |    0x95   |    0x48   |
     *              | 1110 1010 | 1001 0101 | 0100 1000 |
     */
    uint8_t *byte_ptr = (uint8_t*)ptr;
    uint8_t *shifted = (uint8_t*) malloc(bytes * sizeof(uint8_t));

    if (right) {

        for (int k = 0; k < rotation_count; ++k) {

            // right rotation, 1 step:
            for (int i = 0; i < bytes; ++i) {
                shifted[i] = is_odd(byte_ptr[i]);
                byte_ptr[i] = rotate_right(byte_ptr[i], 1);
            }

            // applying the shifted bits to the next element:
            for (int j = 0; j < bytes; ++j) {
                if (j == 0) {
                    if (shifted[bytes - 1]) {
                        byte_ptr[j] = set_bit(byte_ptr[j], 7);
                    } else {
                        byte_ptr[j] = clear_bit(byte_ptr[j], 7);
                    }
                } else {
                    if (shifted[j - 1]) {
                        byte_ptr[j] = set_bit(byte_ptr[j], 7);
                    } else {
                        byte_ptr[j] = clear_bit(byte_ptr[j], 7);
                    }
                }
            }
            PrintBinaryArray(byte_ptr, bytes);
        }
    }

    free(shifted);
}

int main() {
 /*   *//* 1.
     * Write a function called RotateRight which takes a byte and a number
     * and rotates the bits of byte in right direction number times.
     * It should return with the result.
     * E.g. byte = 0b1000000, number = 1 => returns 0b01000000
     * E.g. byte = 0b1000001, number = 2 => returns 0b01100000
     *//*

    uint8_t testbyte = 0b10000001;
    testbyte = rotate_right(testbyte, 10);

    *//* 2.
     * Write a function called RotateLeft which takes a byte and a number
     * and rotates the bits of byte in left direction number times.
     * It should return with the result.
     * E.g. byte = 0b1000000, number = 1 => returns 0b00000001
     * E.g. byte = 0b1000001, number = 2 => returns 0b00000110
     *//*

    uint8_t testbyte2 = 0b10000001;
    testbyte = rotate_left(testbyte2, 10);
*/

    // Array rotator driver:

    uint8_t array[] = {0xAA, 0x55, 0x23};
    uint32_t array_size = sizeof(array) / sizeof(array[0]);
    uint32_t rotation_count = 2;

    PrintBinaryArray(array, array_size);

    array_rotator(array, array_size, 62, 1);

    PrintBinaryArray(array, array_size);

    return 0;
}