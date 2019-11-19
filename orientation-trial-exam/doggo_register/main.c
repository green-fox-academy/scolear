#include <stdio.h>

typedef enum dog_size {
    SMALL,
    MEDIUM,
    BIG,
    LARGE
} dog_size_t;

typedef struct dog {
    char *name;
    int age;
    double weight;
    dog_size_t size;
} dog_t;

char* get_oldest(dog_t* dogs, int number_of_dogs)
{
    int oldest = dogs[0].age;
    char* oldest_name = dogs[0].name;

    for (int i = 1; i < number_of_dogs; ++i) {
        if (dogs[i].age > oldest) {
            oldest = dogs[i].age;
            oldest_name = dogs[i].name;
        }
    }
    return oldest_name;
}

int get_size_count(dog_t* dogs, int number_of_dogs, dog_size_t size)
{
    int count = 0;
    for (int i = 0; i < number_of_dogs; ++i) {
        if (dogs[i].size == size) count++;
    }
    return count;
}

int main()
{
    dog_t dogs[] = { {"SAMU", 8, 16.5, MEDIUM},
                     {"ANNA", 2, 4, SMALL},
                     {"BELA", 3, 11, MEDIUM},
                     {"FOXY", 6, 23, BIG},
                     {"MAX", 1, 7, MEDIUM},
                     {"DANNY", 11, 33, LARGE}
    };

    int size_of_pack = sizeof(dogs) / sizeof(dogs[0]);

    printf("oldest dog: %s\n", get_oldest(dogs, size_of_pack));
    printf("Dogs with size MEDIUM: %d\n", get_size_count(dogs, size_of_pack, MEDIUM));

    return 0;
}