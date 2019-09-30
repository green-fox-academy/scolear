//
// Created by scolear on 2019. 09. 30..
//

#ifndef GREENFOX_MENTOR_H
#define GREENFOX_MENTOR_H

#include "Person.h"

enum class Level {
    JUNIOR,
    INTERMEDIATE,
    SENIOR
};

class Mentor : public Person {
public:
    Mentor(std::string name, int age, Gender gender, Level level);
    Mentor();

    virtual void introduce();
    virtual void getGoal();
    std::string getLevel();

private:
    Level _level;
};


#endif //GREENFOX_MENTOR_H
