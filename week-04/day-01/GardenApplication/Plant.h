
#ifndef GARDENAPPLICATION_PLANT_H
#define GARDENAPPLICATION_PLANT_H

#include <string>

class Plant {
public:

    Plant(std::string color);

    void waterPlant(float amount);
    bool needsWater();

    std::string getDetailedInfo();
    std::string getInfo();

protected:
    float _waterlevel;
    float _effectivity;
    float _waterNeeds;

    std::string _color;
    std::string _type;

};


#endif //GARDENAPPLICATION_PLANT_H
