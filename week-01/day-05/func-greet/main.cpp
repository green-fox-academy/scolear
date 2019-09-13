#include <iostream>
#include <string>

void greet(std::string);

int main(int argc, char* args[]) {

    // - Create a string variable named `al` and assign the value `Green Fox` to it
    // - Create a function called `greet` that greets it's input parameter
    // - Greeting is printing e.g. `Greetings dear, Green Fox`
    // - Greet `al`

    std::string al = "Green Fox";

    greet(al);

    return 0;
}

void greet(std::string greetee) {
    std::cout << "Greetings dear, " << greetee << std::endl;
}