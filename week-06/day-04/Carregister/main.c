#include <string.h>
#include <stdio.h>

/* Write a car register!
 * You should store the following data in a structure, called "car":
 *  - the manufacturer's name (which is shorter than 256 characters)
 *  - the price of the car (in euros, stored as a floating point number)
 *  - the year of manufacture
 *  - the type of the transmission (as a custom type, see below)
 *
 * You should store the transmission type in an enumeration ("transmission"),
 * the valid types are:
 *  - manual
 *  - automatic
 *  - CVT
 *  - semi-automatic
 *  - dual-clutch
 *
 * The "car"-s are stored in an array.
 *
 * Write the following functions:
 *  - get_older_cars_than(struct car* array, int array_length, int age)
 *      - it returns the count of the older cars than "age"
 *  - get_transmission_count(struct car* array, int array_length, enum transmission trnsm)
 *      - it returns the count of cars which has "trnsm" transmission
 */

#define CURRENT_YEAR 2019

enum transmission{
    MANUAL,
    AUTOMATIC,
    CVT,
    SEMIAUTO,
    DUAL
};

typedef struct car {
    char manufacturer[256];
    float price;
    int year;
    enum transmission trnsm;
} car_t, *car_p;

int get_older_cars_than (car_t* array, int array_length, int age) {
    int count = 0;
    for (int i = 0; i < array_length; ++i) {
        if (CURRENT_YEAR - array[i].year > age) {
            count++;
        }
    }
    return count;
}

int get_transmission_count(struct car* array, int array_length, enum transmission trnsm) {
    int count = 0;
    for (int i = 0; i < array_length; ++i) {
        if (array[i].trnsm == trnsm) {
            count++;
        }
    }
    return count;
}

int main()
{
    car_t Kamion = {"Ford", 125.5f, 1979, DUAL};
    car_t Kocsi = {"Audi", 2995, 2010, AUTOMATIC};
    car_t Kocsi2 = {"Fiat", 12000, 1910, MANUAL};
    car_t cars[] = {Kamion, Kocsi, Kocsi2};
    int cars_length = sizeof(cars) / sizeof(cars[0]);
    int age = 10;

    int older_cars = get_older_cars_than(cars, cars_length, age);
    printf("Cars older than %d years: %d\n", age, older_cars);

    int manual_cars = get_transmission_count(cars, cars_length, MANUAL);
    printf("Manual cars: %d\n", manual_cars);

    return 0;
}