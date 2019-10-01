#include <iostream>
#include <vector>
#include "Copier.h"
#include "Printer3D.h"

int main() {

    // Create a vector that holds Printer* objects
    // Fill the vector with 3 Printer2D, 2 Printer3D and 1 copier.
    // Iterate through the vector and invoke print function on all of them.

    std::vector<Printer*> printers;

    printers.push_back(new Printer2D(10, 10));
    printers.push_back(new Printer2D(10, 10));
    printers.push_back(new Printer2D(10, 10));
    printers.push_back(new Printer3D(10, 10, 39));
    printers.push_back(new Printer3D(10, 10, 39));
    printers.push_back(new Copier(10, 12, 15));

    for (Printer* pr : printers) {
        pr->print();
    }

    // Create a vector that holds Scanner* objects
    // Fill the vector with 2 Scanner and 2 Copier objects.
    // Iterate through the vector and invoke scan function on all of them

    std::vector<Scanner*> scanners;

    scanners.push_back(new Scanner(19));
    scanners.push_back(new Scanner(23));
    scanners.push_back(new Copier(10, 12, 15));
    scanners.push_back(new Copier(10, 12, 15));

    for (Scanner* sc : scanners) {
        sc->scan();
    }

    // Create a Copier object and invoke copy function on it.

    Copier c(10, 10, 14);
    c.copy();

    return 0;
}