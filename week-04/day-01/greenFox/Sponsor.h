//
// Created by scolear on 2019. 09. 30..
//

#ifndef GREENFOX_SPONSOR_H
#define GREENFOX_SPONSOR_H


#include "Person.h"

class Sponsor : public Person {
public:

    Sponsor();
    Sponsor(std::string name, int age, Gender gender, std::string company);

    void hire();
    void getGoal();
    void introduce();

private:
    std::string _company;
    int _hiredStudents;

};


#endif //GREENFOX_SPONSOR_H
