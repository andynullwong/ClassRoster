#include <string>
#include "roster.h"

int main() {
	const string studentData[] =
	{
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Andy,Wong,awong24@wgu.edu,28,11,22,33,SOFTWARE"
	};

	const int studentDataLength = (sizeof(studentData) / sizeof(studentData[0]));

	//F1:  Print out to the screen, via your application, the course title, the programming language used, your WGU student ID, and your name.
	cout << "Scripting and Programming - Applications - C867\n"
		<< "Language: C++\n"
		<< "WGU Student ID: 001349684\n"
		<< "Name: Andy Wong\n\n";

	//F2: Create an instance of the Roster class called classRoster.
	Roster* classRoster = new Roster(studentDataLength);

	//F3: Add each student to classRoster.
	for (int i = 0; i < studentDataLength; i++) {
		classRoster->parseStudentDataThenAdd(studentData[i]);
	}

	//F4: Convert the following pseudo code to complete the rest of the main() function:

	//F4 A: classRoster.printAll();
	cout << "Printing All Data from Class Roster\n";
	classRoster->printAll();
	cout << "\n";

	//F4 B: classRoster.printInvalidEmails();
	classRoster->printInvalidEmails();
	cout << "\n";

	//F4 C: loop through classRosterArray -> classRoster.printAverageDaysInCourse(/*current_object's student id*/);
	cout << "Average Days for All Students\n";
	for (int i = 0; i < studentDataLength; i++) {
		string currentStudentId = classRoster->classRosterArray[i]->getStudentId();
		classRoster->printAverageDaysInCourse(currentStudentId);
	}
	cout << "\n";

	//F4 D: classRoster.printByDegreeProgram(SOFTWARE);
	cout << "Printing all students in SOFTWARE Program\n";
	classRoster->printByDegreeProgram(DegreeProgram::SOFTWARE);
	cout << "\n";

	//F4 E: classRoster.remove("A3");
	cout << "Removing Student with ID A3";
	classRoster->remove("A3");
	cout << "\n";

	//F4 F: classRoster.printAll();
	cout << "Printing All Data from Class Roster after removing A3\n";
	classRoster->printAll();
	cout << "\n";

	//F4 G: classRoster.remove("A3");
	cout << "\n";
	cout << "Trying to remove Student with ID A3, will throw error\n";
	classRoster->remove("A3");

	return 0;
}