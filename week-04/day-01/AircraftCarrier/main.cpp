#include <iostream>
#include "Aircraft.h"
#include "Carrier.h"
#include "F16.h"
#include "F35.h"

int main() {

    F16 plane1;

    Carrier Behemoth(500, 1000);

    Behemoth.addPlane(&plane1);

    return 0;
}