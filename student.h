#pragma once
#include <string>
#include "degree.h"
#include <iostream>
using namespace std;

class Student
{
protected:
	string studentId;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int* daysInCourse;
	DegreeProgram degreeProgram;
	
public:
	const static int daysInCourseLength = 3;
	int rosterLength = 5;

	//Constructors
	Student();
	Student(string studentId,string firstName,string lastName,string emailAddress,int age,int* daysInCourse,DegreeProgram degreeProgram);

	//Getters
	string getStudentId();
	string getFirstName();
	string getLastName();
	string getEmailAddress();
	int getAge();
	int* getDaysInCourse();
	virtual DegreeProgram getDegreeProgram() = 0;

	//Setters
	void setStudentId(string studentId);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmailAddress(string emailAddress);
	void setAge(int age);
	void setDaysInCourse(int daysInCourse[]);
	virtual void setDegreeProgram(DegreeProgram degreeProgram) = 0;

	virtual void print() = 0;

	~Student();
};

