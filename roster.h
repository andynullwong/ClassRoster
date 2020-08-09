#pragma once
#include "student.h"
using std::string;

class Roster
{
public:
	int rosterSize;
	int capacity;
	Student** classRosterArray;

	Roster();
	Roster(int capacity);
	void parseStudentDataThenAdd(string studentData);
	void add(string studentId, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);
	void remove(string studentId);
	void printAll();
	void printAverageDaysInCourse(string studentId);
	void printInvalidEmails();
	void printByDegreeProgram(DegreeProgram degreeProgram);

	~Roster();
};

