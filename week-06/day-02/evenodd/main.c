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

int is_even(uint8_t byte) {
    int ret;
    ret = byte & 0x01 ? 0 : 1;
    return ret;
}

int is_odd(uint8_t byte) {
    int ret;
    ret = byte & 0x01 ? 1 : 0;
    return ret;
}

int main() {

    /* 1.
     * Write a function called IsEven which takes a byte and returns with true
     * if byte is even. Use only bitwise operators!
     */

    /* 2.
     * Write a function called IsOdd which takes a byte and returns with true
     * if byte is odd. Use only bitwise operators!
     */

    uint8_t testbyte = 0b00000010;

    if (is_even(testbyte)) {
        printf("Testbyte is even.");
    } else if (is_odd(testbyte)) {
        printf("Testbyte is odd.");
    } else {
        printf("Something is not quite right.");
    }

    return 0;
}