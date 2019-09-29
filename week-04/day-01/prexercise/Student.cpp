//
// Created by scolear on 2019. 09. 29..
//

#include <iostream>
#include "Student.h"

Student::Student(const std::string name, int age, const std::string gender, std::string previousOrganization) : _name(name), _age(age), _gender(gender), _previousOrganization(previousOrganization) {

    _skippedDays = 0;

}

Student::Student() : _name("Jane Doe"), _age(30), _gender("female"), _previousOrganization("The School Of Life"), _skippedDays(0) {

}

void Student::skipDays(int x) {
    _skippedDays += x;
}

void Student::getGoal() {
    std::cout << "My goal is: Be a junior software developer!";
}

void Student::introduce() {
    std::cout << "Hi, I'm " << _name << ", a " << _age << " old " << _gender << " from " << _previousOrganization << " who skipped " << _skippedDays << " from the course already." << std::endl;

}
