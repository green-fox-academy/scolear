//
// Created by scolear on 2019. 09. 30..
//

#include <iostream>
#include "Person.h"

Person::Person(const std::string name, int age, Gender gender) : _name(name), _age(age), _gender(gender) {}

Person::Person() : _name("Jane Doe"), _age(30), _gender(Gender::FEMALE) {}

void Person::getGoal() {
    std::cout << "My goal is: live for the moment!";
}

void Person::introduce() {
    std::cout << "Hi, I'm " << _name << ", a " << _age << " old " << (_gender == Gender::MALE ? "male" : "female" ) << std::endl;
}