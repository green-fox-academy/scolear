#include <iostream>

// argc az argumentumok szama, a masik pedig az argumentumok.
// argv[0] mindig az abszolut eleresi utvonala a programnak

void commit(){
    std::cout << "changes commited" << std::endl;
}

int main(int argc, char* argv[]) {

    std::cout << "argc:" << argc << std::endl;

    for (int i = 1; i < argc; ++i) {
        std::cout << argv[i] << std::endl;
    }

    if (std::string(argv[1]) == "commit") {
        commit();
    }

    return 0;
}