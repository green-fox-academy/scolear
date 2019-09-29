//
// Created by scolear on 2019. 09. 29..
//

#ifndef PREXERCISE_STUDENT_H
#define PREXERCISE_STUDENT_H


#include <string>

class Student {
public:
    Student(const std::string name, int age, const std::string gender, std::string previousOrganization);
    Student();

    void introduce();
    void getGoal();
    void skipDays(int);

private:
    std::string _name;
    int _age;
    std::string _gender;
    std::string _previousOrganization;
    int _skippedDays;
};


#endif //PREXERCISE_STUDENT_H
