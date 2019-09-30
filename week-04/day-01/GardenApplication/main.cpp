#include <iostream>
#include "Garden.h"
#include "Plant.h"
#include "Flower.h"
#include "Tree.h"

int main() {

    Flower flo1("Yellow");
    Flower flo2("Blue");

    Tree tree1("Purple");
    Tree tree2("Orange");

    Garden gar;

    gar.addPlant(&flo1);
    gar.addPlant(&flo2);
    gar.addPlant(&tree1);
    gar.addPlant(&tree2);
    gar.printDetailedInfo();

    gar.printInfo();

    gar.waterGarden(40);

    gar.printInfo();

    gar.waterGarden(70);

    gar.printInfo();

    gar.printDetailedInfo();

    return 0;
}