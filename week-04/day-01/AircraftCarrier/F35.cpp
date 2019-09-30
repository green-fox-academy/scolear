//
// Created by scolear on 2019. 09. 30..
//

#include "F35.h"

F35::F35() : Aircraft() {
    _maxAmmo = 12;
    _baseDamage = 50;
    _type = "F35";
    _isPriority = true;
}