#include <iostream>
#include "Aircraft.h"
#include "Carrier.h"
#include "F16.h"
#include "F35.h"

int main() {

    F16 plane1;
    F16 plane2;
    F16 plane3;
    F16 plane4;

    F35 plane5;
    F35 plane6;
    F35 plane7;
    F35 plane8;

    Carrier Behemoth(500, 1000);
    Carrier Azure(200, 2000);

    Behemoth.addPlane(&plane1);
    Behemoth.addPlane(&plane2);
    Behemoth.addPlane(&plane3);
    Behemoth.addPlane(&plane4);
    Behemoth.addPlane(&plane5);
    Behemoth.addPlane(&plane6);
    Behemoth.addPlane(&plane7);
    Behemoth.addPlane(&plane8);

    Behemoth.fill();
    Azure.fill();
    std::cout << Behemoth.getStatus() << std::endl;

    Behemoth.fight(&Azure);

    std::cout << Azure.getStatus() << std::endl;

    return 0;
}