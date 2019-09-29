//
// Created by scolear on 2019. 09. 29..
//

#ifndef PREXERCISE_PERSON_H
#define PREXERCISE_PERSON_H


#include <string>

enum class Gender {
    MALE,
    FEMALE
};

class Person {
public:
    Person(const std::string name, int age, Gender gender);
    Person();

    void introduce();
    void getGoal();

private:
    std::string _name;
    int _age;
    Gender _gender;
};


#endif //PREXERCISE_PERSON_H
