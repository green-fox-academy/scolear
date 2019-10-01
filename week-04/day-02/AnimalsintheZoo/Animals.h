#ifndef ANIMALSINTHEZOO_ANIMALS_H
#define ANIMALSINTHEZOO_ANIMALS_H


#include <string>

class Animals {
public:
    Animals(std::string name);
    std::string getName();
    virtual std::string breed() = 0;
protected:
    int _age;
    std::string _name;
};


#endif //ANIMALSINTHEZOO_ANIMALS_H
