#include "NetworkStudent.h"
#include <iostream>

NetworkStudent::NetworkStudent()
{
	setDegreeProgram(DegreeProgram::NETWORK);
}

NetworkStudent::NetworkStudent(string studentId, string firstName, string lastName, string emailAddress, int age, int* daysInCourse, DegreeProgram degreeProgram)
{
	setStudentId(studentId);
	setFirstName(firstName);
	setLastName(lastName);
	setEmailAddress(emailAddress);
	setAge(age);
	setDaysInCourse(daysInCourse);
	setDegreeProgram(DegreeProgram::NETWORK);
}

DegreeProgram NetworkStudent::getDegreeProgram()
{
	return DegreeProgram::NETWORK;
}

void NetworkStudent::setDegreeProgram(DegreeProgram degreeProgram) {
	this->degreeProgram = DegreeProgram::NETWORK;
}

void NetworkStudent::print()
{
	this->Student::print();
	cout << left << "Degree Program: NETWORK\n";
}

NetworkStudent::~NetworkStudent() {
	Student::~Student();
}