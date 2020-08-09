#pragma once
#include "student.h"
#include <string>
#include "degree.h"

class SecurityStudent :
    public Student
{
public:
    SecurityStudent();
    SecurityStudent(string studentId, string firstName, string lastName, string emailAddress, int age, int* daysInCourse, DegreeProgram degreeProgram);

    DegreeProgram getDegreeProgram();

    void setDegreeProgram(DegreeProgram degreeProgram);

    void print();

    ~SecurityStudent();
};
