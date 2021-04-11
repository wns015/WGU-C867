#include<iostream>
#include<string>
#include "student.h"

using namespace std;

//full constructor for student class and destructor
Student::Student(string studentID, string firstName, string lastName, string email, int age, int DaysIC1, int DaysIC2, int DaysIC3, DegreeProgram degreeprogram)
{
    this->studentID = studentID;
    this->firstName = firstName;
    this->lastName = lastName;
    this->email = email;
    this->age = age;
    this->DaysIC[0] = DaysIC1;
    this->DaysIC[1] = DaysIC2;
    this->DaysIC[2] = DaysIC3;
    this->degreeprogram = degreeprogram;
}

Student::~Student()
{
    return;
}


//Mutators for data

void Student::setID(string enterID)
{
    studentID = enterID;
}

void Student::setFirst(string enterFirst)
{
    firstName = enterFirst;
}

void Student::setLast(string enterLast)
{
    lastName = enterLast;
}

void Student::setEmail(string enterEmail)
{
    email = enterEmail;
}

void Student::setAge(int enterAge)
{
    age = enterAge;
}

void Student::setDaysIC(int enterDaysIC1, int enterDaysIC2, int enterDaysIC3)
{
    DaysIC[0] = enterDaysIC1;
    DaysIC[1] = enterDaysIC2;
    DaysIC[2] = enterDaysIC3;
}

void Student::setDegree(DegreeProgram enterDegree)
{
    DegreeProgram degreeprogram = enterDegree;
}


//Accessors for data

string Student::getID() const
{
    return studentID;
}
string Student::getFirst() const
{
    return firstName;
}
string Student::getLast() const
{
    return lastName;
}
string Student::getEmail() const
{
    return email;
}
int Student::getAge() const
{
    return age;
}
int Student::getDaysIC1() const
{
    return DaysIC[0];
}
int Student::getDaysIC2() const
{
    return DaysIC[1];
}
int Student::getDaysIC3() const
{
    return DaysIC[2];
}
DegreeProgram Student::getDegree() const
{
    return degreeprogram;
}



//Print() function
void Student::Print() const
{
   
    cout << "Student ID: " << getID() << "\t";
    cout << "First Name: " << getFirst() << "\t";
    cout << "Last Name: " << getLast() << "\t";
    cout << "Email: " << getEmail() << "\t";
    cout << "Age: " << getAge() << "\t";
    cout << "Days in Course: {" << getDaysIC1() << ", " << getDaysIC2() << ", " << getDaysIC3() << "}\t";
    cout << "Degree Program: ";
    if (getDegree() == DegreeProgram::SECURITY)
    {
        cout << "SECURITY";
    }
    else if (getDegree() == DegreeProgram::NETWORK)
    {
        cout << "NETWORK";
    }
    else if (getDegree() == DegreeProgram::SOFTWARE)
    {
        cout << "SOFTWARE";
    }
    cout << endl;
    
}
