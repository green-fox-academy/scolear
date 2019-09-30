#ifndef GREENFOX_STUDENT_H
#define GREENFOX_STUDENT_H

#include "Person.h"

class Student : public Person {
public:
    Student(std::string name, int age, Gender gender, std::string previousOrganization);
    Student();

    void introduce();
    void getGoal();
    void skipDays(int);

private:
    std::string _previousOrganization;
    int _skippedDays;

};


#endif //GREENFOX_STUDENT_H
