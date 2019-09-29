//
// Created by scolear on 2019. 09. 29..
//

#include <iostream>
#include "Mentor.h"

void Mentor::introduce() {
    std::cout << "Hi, I'm " << _name << ", a " << _age << " old " << _gender  << _level << " mentor " << std::endl;
}

void Mentor::getGoal() {
    std::cout << "My goal is: Educate brilliant junior software developers!";
}

Mentor::Mentor(const std::string name, int age, const std::string gender, std::string level) : _name(name), _age(age), _gender(gender), _level(level){

}

Mentor::Mentor() : _name("Jane Doe"), _age(30), _gender("female"), _level("intermediate") {}