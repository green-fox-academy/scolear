#include <stdio.h>
#include <stdint.h>

// Use the Computer struct, give values to the fields and print them out in the main!
// Use the Notebook struct, give values to the fields and print them out in the main!

struct Computer {
    float cpu_speed_GHz;
    int ram_size_GB;
    int bits;
};

typedef struct {
    float cpu_speed_GHz;
    int ram_size_GB;
    int bits;
} Notebook;

int main()
{
    struct Computer HAL;
    HAL.cpu_speed_GHz = 20.5;
    HAL.ram_size_GB = 100;
    HAL.bits = 128;

    printf("CPU: %.2f\n", HAL.cpu_speed_GHz);
    printf("RAM: %d\n", HAL.ram_size_GB);
    printf("bits: %d\n", HAL.bits);

    Notebook HP;
    HP.cpu_speed_GHz = 1.9;
    HP.ram_size_GB = 4;
    HP.bits = 64;

    printf("CPU: %.2f\n", HP.cpu_speed_GHz);
    printf("RAM: %d\n", HP.ram_size_GB);
    printf("bits: %d\n", HP.bits);

    return 0;
}