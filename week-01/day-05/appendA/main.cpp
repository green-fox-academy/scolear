#include <iostream>
#include <string>


int main(int argc, char* args[]) {

    // - Create an array variable named `animals`
    //   with the following content: `["koal", "pand", "zebr"]`
    // - Add all elements an `"a"` at the end

    std::string animals[] = {"koal", "pand", "zebr"};

    for (int i = 0; i < 3; ++i) {
        animals[i].append("a");
        std::cout << animals[i] << std::endl;
    }


    return 0;
}