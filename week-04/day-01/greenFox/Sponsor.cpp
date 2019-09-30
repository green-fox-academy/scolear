
#include <iostream>
#include "Sponsor.h"

Sponsor::Sponsor(std::string name, int age, Gender gender, std::string company) :  Person(name, age, gender), _company(company){
    _hiredStudents = 0;
}

Sponsor::Sponsor() : Person("Jane Doe", 30, Gender::FEMALE), _company("Google"), _hiredStudents(0) {}


void Sponsor::hire() {
    _hiredStudents++;
}

void Sponsor::getGoal() {
    std::cout << "My goal is: Hire brilliant junior software developers.";
}

void Sponsor::introduce() {
    std::cout << "Hi, I'm " << _name << ", a " << _age << " old " << (_gender == Gender::MALE ? "male" : "female" )
              << " who represents " << _company << " and hired " << _hiredStudents << " students so far." << std::endl;
}