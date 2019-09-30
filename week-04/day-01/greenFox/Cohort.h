//
// Created by scolear on 2019. 09. 30..
//

#ifndef GREENFOX_COHORT_H
#define GREENFOX_COHORT_H


#include <string>
#include <vector>
#include "Student.h"
#include "Mentor.h"

class Cohort {
private:
    std::string _name;
    std::vector<Student*> _students;
    std::vector<Mentor*> _mentors;

};


#endif //GREENFOX_COHORT_H