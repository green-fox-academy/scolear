
#include <iostream>
#include "Scanner.h"

Scanner::Scanner(int x) : _speed(x) {}

void Scanner::scan() {
    std::cout << "I am scanning a document " << _speed << " ppm.\n";
}
