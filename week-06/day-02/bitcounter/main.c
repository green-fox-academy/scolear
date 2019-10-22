
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

int count_ones(uint8_t byte) {

    int count = (byte & 0x80 ? 1 : 0) +
                (byte & 0x40 ? 1 : 0) +
                (byte & 0x20 ? 1 : 0) +
                (byte & 0x10 ? 1 : 0) +
                (byte & 0x08 ? 1 : 0) +
                (byte & 0x04 ? 1 : 0) +
                (byte & 0x02 ? 1 : 0) +
                (byte & 0x01 ? 1 : 0);

    return count;
}

int count_zeros(uint8_t byte) {

    int count = (byte & 0x80 ? 0 : 1) +
                (byte & 0x40 ? 0 : 1) +
                (byte & 0x20 ? 0 : 1) +
                (byte & 0x10 ? 0 : 1) +
                (byte & 0x08 ? 0 : 1) +
                (byte & 0x04 ? 0 : 1) +
                (byte & 0x02 ? 0 : 1) +
                (byte & 0x01 ? 0 : 1);

    return count;
}

int main() {
    /* 1.
     * Write a function called CountOnes which takes a byte returns
     * with the number of one bits in it.
     * E.g. byte = 0b1101 => returns with 3
     */

    uint8_t testbyte = 0b01101101;
    printf("%d\n", count_ones(testbyte));
    printf("%d\n", count_zeros(testbyte));

    /* 2.
     * Write a function called CountZeros which takes a byte returns
     * with the number of zero bits in it.
     * E.g. byte = 0b1000 => returns with 3
     */

    return 0;
}