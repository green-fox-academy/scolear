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

int main() {

    int k = 123;
    int b = 0b01111011;
    int h = 0x7b;

    printf("%d\n", k);
    printf("%x\n", k);
    PrintBinary(k);
    printf("%x\n", b);
    printf("%d\n", h);

    int result = 0b01110 & 0b1001;
    PrintBinary(result);
    int result2 = 0b01110 | 0b1001;
    PrintBinary(result2);
    int result3 = 0b01110 ^ 0b1001;
    PrintBinary(result3);
    int result4 = 0b01110;

    result = ~0b1110;
    PrintBinary(result);
    result = 0b1110 >> 2;
    PrintBinary(result);
    result = 0b1110 << 2;
    PrintBinary(result);

    int var = 5;
    printf("%d\n", var * 2);
    printf("%d\n", var << 1);
    printf("%d\n", var * 4);
    printf("%d\n", var << 2);
    printf("%d\n", var * 8);
    printf("%d\n", var << 3);

    // changing one bit with a mask:
    char byte =               0b00001100;
    char byteWithBit = byte | 0b00100000;
    //                      | 0b00101100;
    PrintBinary(byteWithBit);

    return 0;
}