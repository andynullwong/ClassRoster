#pragma once
#include "student.h"

class NetworkStudent :
    public Student
{
public:
    NetworkStudent();
    NetworkStudent(string studentId, string firstName, string lastName, string emailAddress, int age, int* daysInCourse, DegreeProgram degreeProgram);
    
    DegreeProgram getDegreeProgram();

    void setDegreeProgram(DegreeProgram degreeProgram);
    
    void print();

    ~NetworkStudent();
};
