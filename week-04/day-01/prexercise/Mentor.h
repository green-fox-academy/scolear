//
// Created by scolear on 2019. 09. 29..
//

#ifndef PREXERCISE_MENTOR_H
#define PREXERCISE_MENTOR_H


#include <string>

class Mentor {
public:
    Mentor(const std::string name, int age, const std::string gender, std::string level);
    Mentor();

    void introduce();
    void getGoal();

private:
    std::string _level;
    std::string _name;
    int _age;
    std::string _gender;
};
};


#endif //PREXERCISE_MENTOR_H
