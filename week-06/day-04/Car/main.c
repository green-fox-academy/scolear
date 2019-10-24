#include <stdio.h>

// Write a function that takes a car as an argument and prints all it's stats
// If the car is a Tesla it should not print it's gas level

enum car_type {VOLVO, TOYOTA, LAND_ROVER, TESLA};

struct car {
    enum car_type type;
    double km;
    double gas;
};

char *tostring (enum car_type type) {
    switch (type) {
        case VOLVO : return "Volvo";
        case TOYOTA : return "Toyota";
        case LAND_ROVER : return "Land Rover";
        case TESLA : return "Tesla";
        default: return "Undefined";
    }
}

void print_stats (struct car car) {

    printf("Type: %s\n", tostring(car.type));
    printf("Km: %.2lf\n", car.km);
    if (car.type != TESLA)
        printf("Gas: %.2lf\n", car.gas);
}

int main()
{
    struct car autocska = {VOLVO, 123, 456};
    struct car autocska2 = {TESLA, 123, 456};

    print_stats(autocska);
    print_stats(autocska2);

    return 0;
}