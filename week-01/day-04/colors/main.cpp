#include <iostream>
#include <string>

int main(int argc, char* args[]) {

    // - Create a two dimensional array
    //   which can contain the different shades of specified colors
    // - In `colors[0]` store the shades of green:
    //   `"lime", "forest green", "olive", "pale green", "spring green"`
    // - In `colors[1]` store the shades of red:
    //   `"orange red", "red", "tomato"`
    // - In `colors[2]` store the shades of pink:
    //   `"orchid", "violet", "pink", "hot pink"`

    int numColors = 3;
    int maxLength = 5;

    std::string colors[numColors][maxLength];

    // I hate how manual this is:
    
    colors[0][0] = "lime";
    colors[0][1] = "forest-green";
    colors[0][2] = "olive";
    colors[0][3] = "pale-green";
    colors[0][4] = "spring-green";

    colors[1][0] = "orange-red";
    colors[1][1] = "red";
    colors[1][2] = "tomato";

    colors[2][0] = "orchid";
    colors[2][1] = "violet";
    colors[2][2] = "pink";
    colors[2][3] = "hot-pink";

    for (int i = 0; i < numColors; ++i) {
            for (int j = 0; j < maxLength; ++j) {
                std::cout << colors[i][j] << " ";
            }
            std::cout << std::endl;
    }

    return 0;
}