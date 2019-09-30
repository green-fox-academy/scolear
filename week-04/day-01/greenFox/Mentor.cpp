#include <iostream>
#include "Mentor.h"

Mentor::Mentor(const std::string name, int age, Gender gender, Level level) : Person(name, age, gender), _level(level){}

Mentor::Mentor() : Person("Jane Doe", 30, Gender::FEMALE), _level(Level::INTERMEDIATE) {}

void Mentor::introduce() {
    std::cout << "Hi, I'm " << _name << ", a " << _age << " old " << (_gender == Gender::MALE ? "male " : "female " )  << getLevel() << " mentor." << std::endl;
}

void Mentor::getGoal() {
    std::cout << "My goal is: Educate brilliant junior software developers." << std::endl;
}

std::string Mentor::getLevel() {
    switch (_level) {
        case Level::JUNIOR :
            return "junior";
        case Level::INTERMEDIATE :
            return "intermediate";
        case Level::SENIOR:
            return "senior";
    }
}