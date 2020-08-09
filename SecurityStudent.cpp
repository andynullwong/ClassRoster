#include "SecurityStudent.h"
#include <iostream>

SecurityStudent::SecurityStudent()
{
	setDegreeProgram(DegreeProgram::SECURITY);
}

SecurityStudent::SecurityStudent(string studentId, string firstName, string lastName, string emailAddress, int age, int* daysInCourse, DegreeProgram degreeProgram)
{
	setStudentId(studentId);
	setFirstName(firstName);
	setLastName(lastName);
	setEmailAddress(emailAddress);
	setAge(age);
	setDaysInCourse(daysInCourse);
	setDegreeProgram(DegreeProgram::SECURITY);
}

DegreeProgram SecurityStudent::getDegreeProgram()
{
	return DegreeProgram::SECURITY;
}

void SecurityStudent::setDegreeProgram(DegreeProgram degreeProgram) {
	this->degreeProgram = DegreeProgram::SECURITY;
}

void SecurityStudent::print()
{
	this->Student::print();
	cout << left << "Degree Program: SECURITY\n";
}

SecurityStudent::~SecurityStudent() {
	Student::~Student();
}