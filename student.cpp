#include "student.h"
#include "roster.h"

Student::Student() {
    this->studentId = "";
    this->firstName = "";
    this->lastName = "";
    this->emailAddress = "";
    this->age = -99;
    this->daysInCourse = new int[daysInCourseLength];
    for (int i = 0; i < daysInCourseLength; i++) this->daysInCourse[i] = 0;
}

Student::Student(string studentId, string firstName, string lastName, string emailAddress, int age, int* daysInCourse, DegreeProgram degreeProgram)
{
    setStudentId(studentId);
    setFirstName(firstName);
    setLastName(lastName);
    setEmailAddress(emailAddress);
    setAge(age);
    setDaysInCourse(daysInCourse);
}

string Student::getStudentId()
{
    return studentId;
}

string Student::getFirstName()
{
    return firstName;
}

string Student::getLastName()
{
    return lastName;
}

string Student::getEmailAddress()
{
    return emailAddress;
}

int Student::getAge()
{
    return age;
}

int* Student::getDaysInCourse()
{
    return daysInCourse;
}

void Student::setStudentId(string studentId)
{
    this->studentId = studentId;
}

void Student::setFirstName(string firstName)
{
    this->firstName = firstName;
}

void Student::setLastName(string lastName)
{
    this->lastName = lastName;
}

void Student::setEmailAddress(string emailAddress)
{
    this->emailAddress = emailAddress;
}

void Student::setAge(int age)
{
    this->age = age;
}

void Student::setDaysInCourse(int daysInCourse[])
{
    for (int i = 0; i < daysInCourseLength; i++) {
        this->daysInCourse[i] = daysInCourse[i];
    }
}

void Student::print()
{
		cout << left << "ID:" << getStudentId() << "\t";
		cout << left << "First Name:" << firstName << "\t";
		cout << left << "Last Name:" << lastName << "\t";
		cout << left << "Email:" << emailAddress << "\t";
		cout << left << "Age:" << age << "\t";
		cout << left << "daysInCourse: {" 
            << daysInCourse[0] << ", "
            << daysInCourse[1] << ", "
            << daysInCourse[2] << "}"
            << "\t";
}

Student::~Student()
{
}

