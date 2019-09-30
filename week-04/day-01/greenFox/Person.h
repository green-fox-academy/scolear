//
// Created by scolear on 2019. 09. 30..
//

#ifndef GREENFOX_PERSON_H
#define GREENFOX_PERSON_H

#include <string>

enum class Gender {
    MALE,
    FEMALE
};

class Person {
public:
    Person(const std::string name, int age, Gender gender);
    Person();

    virtual void introduce();
    virtual void getGoal();

protected:
    int _age;
    Gender _gender;
    std::string _name;
};


#endif //GREENFOX_PERSON_H
