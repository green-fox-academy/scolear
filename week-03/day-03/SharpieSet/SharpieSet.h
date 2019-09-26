#ifndef SHARPIESET_SHARPIESET_H
#define SHARPIESET_SHARPIESET_H


#include <vector>
#include "Sharpie.h"

class SharpieSet {

public:
    SharpieSet();

    void addSharpie(Sharpie* sharpie);

    Sharpie *getSharpie(int x);
    int countUsable();
    int countTotal();
    void removeTrash();

private:
    std::vector<Sharpie*> _sharpies;
};


#endif //SHARPIESET_SHARPIESET_H
