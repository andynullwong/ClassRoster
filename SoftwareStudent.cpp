#include "SoftwareStudent.h"
#include <iostream>

SoftwareStudent::SoftwareStudent()
{
	setDegreeProgram(DegreeProgram::SOFTWARE);
}

SoftwareStudent::SoftwareStudent(string studentId, string firstName, string lastName, string emailAddress, int age, int* daysInCourse, DegreeProgram degreeProgram)
{
	setStudentId(studentId);
	setFirstName(firstName);
	setLastName(lastName);
	setEmailAddress(emailAddress);
	setAge(age);
	setDaysInCourse(daysInCourse);
	setDegreeProgram(DegreeProgram::SOFTWARE);
}

DegreeProgram SoftwareStudent::getDegreeProgram()
{
	return DegreeProgram::SOFTWARE;
}

void SoftwareStudent::setDegreeProgram(DegreeProgram degreeProgram) {
	this->degreeProgram = DegreeProgram::SOFTWARE;
}

void SoftwareStudent::print()
{
	this->Student::print();
	cout << left << "Degree Program: SOFTWARE\n";
}

SoftwareStudent::~SoftwareStudent() {
	Student::~Student();
}