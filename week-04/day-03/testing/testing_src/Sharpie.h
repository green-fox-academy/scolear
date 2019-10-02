
#ifndef SHARPIE_SHARPIE_H
#define SHARPIE_SHARPIE_H

#include <string>

class Sharpie {
public:
    Sharpie(std::string color, float width);
    void use();
    int getInkAmount();
private:
    std::string _color;
    float _width;
    int _inkAmount;
};

#endif //SHARPIE_SHARPIE_H
