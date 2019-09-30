//
// Created by scolear on 2019. 09. 30..
//

#include "Student.h"
#include <iostream>

Student::Student(const std::string name, int age, Gender gender, std::string previousOrganization) : Person(name, age, gender), _previousOrganization(previousOrganization) {

    _skippedDays = 0;

}

Student::Student() : Person("Jane Doe", 30, Gender::FEMALE), _previousOrganization("The School Of Life"), _skippedDays(0) {

}

void Student::skipDays(int x) {
    _skippedDays += x;
}

void Student::getGoal() {
    std::cout << "My goal is: Be a junior software developer!" << std::endl;
}

void Student::introduce() {
    std::cout << "Hi, I'm " << _name << ", a " << _age << " old " << (_gender == Gender::MALE ? "male" : "female" ) << " from " << _previousOrganization << " who skipped " << _skippedDays << " days from the course already." << std::endl;

}