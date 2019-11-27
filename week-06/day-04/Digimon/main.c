/* Digimon database!
 * You should store the following data in a structure
 *  - the name of the digimon (which is shorter than 128 characters)
 *  - the age of the digimon (in years)
 *  - the health of the digimon (between 0-100)
 *  - the name of the tamer (which is shorter than 256 characters)
 *  - the digivolution level of the digimon (as a custom type, see below)
 *
 * You should store the digivolution level in an enumeration
 * the valid digivolution levels are:
 *  - baby
 *  - in-training
 *  - rookie
 *  - champion
 *  - ultimate
 *  - mega
 *
 * The digimons are stored in an array.
 *
 * Write the following functions:
 * 1) Get minimum health index
 *      - parameters:
 *          - array
 *          - array length
 *      - it returns the index of the minimal health digimon in the "array"
 * 2) Get same digivolution level count
 *      - parameters:
 *          - array
 *          - array length
 *          - digivolution level
 *      - it returns the count of digimons which are at "digivolution level"
 * 3) Get same tamer count
 *      - parameters:
 *          - array
 *          - array length
 *          - tamer name
 *      - it returns the count of the digimons which have the same tamer as "tamer name"
 * 4) Get average health of the same tamer
 *      - parameters:
 *          - array
 *          - array length
 *          - tamer name
 *      - it returns the average health of the digimons which have the same tamer as "tamer name"
 *
 * Don't forget to handle invalid inputs (NULL pointers, invalid values etc.)
 */

#include <stdio.h>

typedef enum level {
    BABY,
    IN_TRAINING,
    ROOKIE,
    CHAMPION,
    ULTIMATE,
    MEGA
} Level;

typedef struct digimon {
    char *name;
    int age;
    int health;
    char *tamer;
    Level level;
} digimon_t;

int get_minimum_health_index (digimon_t array[], int array_size)
{
    int min = array[0].health;
    int min_index = 0;

    for (int i = 0; i < array_size; ++i) {
        if (array[i].health < min) {
            min = array[i].health;
            min_index = i;
        }
    }
    return min_index;
}

int get_digivolution_level_count (digimon_t array[], int array_size, Level level) {
    int count = 0;
    for (int i = 0; i < array_size; ++i) {
        if (array[i].level == level) {
            count++;
        }
    }
    return count;
}

int get_same_tamer_count (digimon_t array[], int array_size, const char *tamer)
{
    int count = 0;
    for (int i = 0; i < array_size; ++i) {
        if (array[i].tamer == tamer) {
            count++;
        }
    }
    return count;
}

float get_tamer_avg_health (digimon_t array[], int array_size, const char *tamer)
{
    float sum = 0;

    for (int i = 0; i < array_size; ++i) {
        if (array[i].tamer == tamer) {
            sum += array[i].health;
        }
    }
    return sum / array_size;
}

int main()
{
    digimon_t digimons[] = {{"Bulba", 23, 58, "Joe", ROOKIE},
                            {"Liu", 52, 28, "Glue", IN_TRAINING},
                            {"Hala", 230, 8, "Joe", ROOKIE},
                            {"Bul", 12, 14, "Joe", BABY},
                            {"Aru", 129, 89, "Glue", MEGA}};

    int digimons_size = sizeof(digimons) / sizeof(digimons[0]);

    printf("Minimum health index: %d\n", get_minimum_health_index(digimons, digimons_size));
    printf("Digivolution_level_count: %d\n", get_digivolution_level_count(digimons, digimons_size, ROOKIE));
    printf("Same tamer count: %d\n", get_same_tamer_count(digimons, digimons_size, "Joe"));
    printf("Same tamer avghealth: %.2f\n", get_tamer_avg_health(digimons, digimons_size, "Joe"));

    return 0;
}