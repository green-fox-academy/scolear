#include <string.h>
#include "asciigen.h"

int main(int argc, char *argv[]) {
/*
    if (argc == 1) {
        print_usage();
    } else {
        // deal_with_arguments(argc, argv);
        char* bmp_path = argv[1];

        FILE* bmp_file = fopen(bmp_path, "rb");

        char* argument = argv[2];

        if (strcmp(argument, "-size") != 0) {
            print_size(bmp_file);
        }

    }
*/
    FILE* input = fopen("../assets/T.bmp", "rb");
    if (!input) return -1;

    print_size(input);
    print_width(input);
    print_height(input);

    return 0;
}