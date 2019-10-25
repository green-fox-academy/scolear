#include <stdio.h>
#include <stdint.h>

/*
 * 1. Create a struct which represents a person:
 * - name (max 64 characters)
 * - age (integer)
 * - height in meters (floating point)
 */

typedef struct person {
    char name[20];
    int age;
    float height;
} person_t;

void print_person_data (person_t* person) {
    printf("Name: %s\nAge: %d\nHeight: %.2f\n", person->name, person->age, person->height);
}

int main() {

    /*
     * 2. Create a person struct, fill it with some data and write it out to a binary file.
     *    Read it back to another struct variable and compare them. Are they equal?
     */

    /*
     * 3. Create an array which holds 10 person strcut.
     *    Fill them with some data and write out the array to a binary file.
     *    Read it back to another array and compare the array content to the first one. Are they equal?
     */

    person_t some_guy = {"Derek", 74, 1.4f};

    FILE* outfile;
    FILE* infile;

    outfile = fopen("../person.dat", "wb");
    fwrite(&some_guy, sizeof(person_t), 1, outfile);
    fclose(outfile);

    person_t the_same_guy;

    infile = fopen("../person.dat", "rb");
    fread(&the_same_guy, sizeof(person_t), 1, infile);
    fclose(infile);

    print_person_data(&some_guy);
    print_person_data(&the_same_guy);

    person_t some_guy2 = {"Jani", 7, 0.4f};
    person_t some_guy3 = {"Joel", 23, 1.5f};
    person_t some_guy4 = {"Buck", 22, 1.9f};
    person_t some_guy5 = {"Azul", 54, 1.6f};

    person_t people[] = {some_guy, some_guy2, some_guy3, some_guy4, some_guy5};
    int size_of_people = sizeof(people) / sizeof(people[0]);

    // writing dat file:
    outfile = fopen("../persons.dat", "wb");
    for (int i = 0; i < size_of_people; ++i) {
        fwrite(&people[i], sizeof(person_t), 1, outfile);
    }
    fclose(outfile);

    // reading dat file:
    person_t people2[size_of_people];

    infile = fopen("../persons.dat", "rb");
    for (int i = 0; i < size_of_people; ++i) {
        fread(&people2[i], sizeof(person_t), 1, infile);
    }
    fclose(infile);

    // comparing people to people2:
    for (int j = 0; j < size_of_people; ++j) {
        print_person_data(&people[j]);
        print_person_data(&people2[j]);
    }

    return 0;
}