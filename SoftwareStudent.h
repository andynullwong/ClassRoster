#pragma once
#include "student.h"

class SoftwareStudent :
    public Student
{
public:
    SoftwareStudent();
    SoftwareStudent(string studentId, string firstName, string lastName, string emailAddress, int age, int* daysInCourse, DegreeProgram degreeProgram);

    DegreeProgram getDegreeProgram();

    void setDegreeProgram(DegreeProgram degreeProgram);

    void print();

    ~SoftwareStudent();
};
