#include "roster.h"
#include "NetworkStudent.h"
#include "SecurityStudent.h"
#include "SoftwareStudent.h"

/* Previous Step E2 and E3, not longer needed due to F2 and F3
int main() {
	const string studentData[] =
	{
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Andy,Wong,awong24@wgu.edu,28,11,22,33,SOFTWARE"
	};
	Roster classRosterArray;
	for (int i = 0; i < sizeof(studentData) / sizeof(studentData[0]); i++) {
		classRosterArray.parseStudentDataThenAdd(studentData[i]);
	}
	return 0;
}
*/

Roster::Roster() {
	this->capacity = 5;
	this->rosterSize = 0;
	this->classRosterArray = nullptr;
}

Roster::Roster(int capacity) {
	this->capacity = capacity;
	this->rosterSize = 0;
	this->classRosterArray = new Student*[capacity];
}

void Roster::parseStudentDataThenAdd(string studentData)
{
	//Parsing Student ID
	int leftPointer = 0;
	int rightPointer = studentData.find(",", leftPointer);
	string studentId = studentData.substr(leftPointer, rightPointer - leftPointer);

	//Parsing First Name
	leftPointer = rightPointer + 1;
	rightPointer = studentData.find(",", leftPointer);
	string firstName = studentData.substr(leftPointer, rightPointer - leftPointer);

	//Parsing Last Name
	leftPointer = rightPointer + 1;
	rightPointer = studentData.find(",", leftPointer);
	string lastName = studentData.substr(leftPointer, rightPointer - leftPointer);

	//Parsing Email Address
	leftPointer = rightPointer + 1;
	rightPointer = studentData.find(",", leftPointer);
	string emailAddress = studentData.substr(leftPointer, rightPointer - leftPointer);

	//Parsing Age
	leftPointer = rightPointer + 1;
	rightPointer = studentData.find(",", leftPointer);
	int age = stoi(studentData.substr(leftPointer, rightPointer - leftPointer));

	//Parsing daysInCourse1
	leftPointer = rightPointer + 1;
	rightPointer = studentData.find(",", leftPointer);
	int daysInCourse1 = stoi(studentData.substr(leftPointer, rightPointer - leftPointer));

	//Parsing daysInCourse2
	leftPointer = rightPointer + 1;
	rightPointer = studentData.find(",", leftPointer);
	int daysInCourse2 = stoi(studentData.substr(leftPointer, rightPointer - leftPointer));

	//Parsing daysInCourse3
	leftPointer = rightPointer + 1;
	rightPointer = studentData.find(",", leftPointer);
	int daysInCourse3 = stoi(studentData.substr(leftPointer, rightPointer - leftPointer));

	//Parsing DegreeProgram
	leftPointer = rightPointer + 1;
	rightPointer = studentData.find(",", leftPointer);
	string degreeName = studentData.substr(leftPointer, rightPointer - leftPointer);
	DegreeProgram degreeProgram{};
	if (degreeName == "SECURITY") {
		degreeProgram = DegreeProgram::SECURITY;
	}
	else if (degreeName == "NETWORK") {
		degreeProgram = DegreeProgram::NETWORK;
	}
	else if (degreeName == "SOFTWARE") {
		degreeProgram = DegreeProgram::SOFTWARE;
	}
	this->add(studentId, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);
}

void Roster::add(string studentId, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram)
{
	int daysInCourse[] = { daysInCourse1, daysInCourse2, daysInCourse3 };

	if (degreeProgram == DegreeProgram::NETWORK) {
		classRosterArray[rosterSize] = new NetworkStudent(studentId, firstName, lastName, emailAddress, age, daysInCourse, degreeProgram);
	}
	else if (degreeProgram == DegreeProgram::SECURITY) {
		classRosterArray[rosterSize] = new SecurityStudent(studentId, firstName, lastName, emailAddress, age, daysInCourse, degreeProgram);
	}
	else {
		classRosterArray[rosterSize] = new SoftwareStudent(studentId, firstName, lastName, emailAddress, age, daysInCourse, degreeProgram);
	}
	rosterSize++;
}

void Roster::remove(string studentId)
{
	bool found = false;
	for (int i = 0; i < rosterSize; i++) {
		if (this->classRosterArray[i]->getStudentId() == studentId) {
			found = true;
			delete this->classRosterArray[i];
			this->classRosterArray[i] = this->classRosterArray[rosterSize - 1];
			rosterSize--;
		}
	}
	if (found == false) {
		cout << "Student not found\n";
	}
}

void Roster::printAll()
{
	for (int i = 0; i < this->rosterSize; i++) {
		classRosterArray[i]->print();
	}
}

void Roster::printAverageDaysInCourse(string studentId)
{
	bool found = false;
	for (int i = 0; i < rosterSize; i++) {
		if (this->classRosterArray[i]->getStudentId() == studentId) {
			found = true;
			int* dayPtr = classRosterArray[i]->getDaysInCourse();
			cout << "Student ID: " << studentId << " Avg Days: " << (dayPtr[0] + dayPtr[1] + dayPtr[2]) / 3.0 << "\n";
		}
	}
	if (found == false) {
		cout << "Student not found\n";
	}
}

void Roster::printInvalidEmails()
{
	cout << "Invalid Emails:\n";
	for (int i = 0; i < rosterSize; i++) {
		string currentEmail = classRosterArray[i]->getEmailAddress();
		if ((currentEmail.find("@") == string::npos) || currentEmail.find(".") == string::npos || currentEmail.find(' ') != string::npos) {
			cout << currentEmail << " is invalid\n";
		}
	}
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram)
{
	cout << "Displaying students in selected degree program:\n";
	for (int i = 0; i < rosterSize; i++) {
		if (this->classRosterArray[i]->getDegreeProgram() == degreeProgram) {
			this->classRosterArray[i]->print();
		}
	}
}

Roster::~Roster() {
	//F5: Implement the destructor to release the memory that was allocated dynamically in Roster.
	for (int i = 0; i < capacity; i++) {
		delete this->classRosterArray[i];
	}
	delete this;
}
