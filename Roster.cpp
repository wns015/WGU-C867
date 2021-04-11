#include<iostream>
#include<string>
#include "roster.h"

using namespace std;

//Requirement A
const string studentData[] =
{ "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY", "A5,Worun,Sukhtipyaroge,wsukhti@wgu.edu,37,14,20,15,SOFTWARE" };



//Requirement E2, E2a, E2b, and E3a
void Roster::parseAndAdd()
{
	for (int i = 0; i < 5; i++)
	{
		size_t rhs = studentData[i].find(",");
		string studentID = studentData[i].substr(0, rhs);

		size_t lhs = rhs + 1;
		rhs = studentData[i].find(",", lhs);
		string firstName = studentData[i].substr(lhs, rhs - lhs);

		lhs = rhs + 1;
		rhs = studentData[i].find(",", lhs);
		string lastName = studentData[i].substr(lhs, rhs - lhs);

		lhs = rhs + 1;
		rhs = studentData[i].find(",", lhs);
		string email = studentData[i].substr(lhs, rhs - lhs);

		lhs = rhs + 1;
		rhs = studentData[i].find(",", lhs);
		int age = stoi(studentData[i].substr(lhs, rhs - lhs));

		lhs = rhs + 1;
		rhs = studentData[i].find(",", lhs);
		int DaysIC1 = stoi(studentData[i].substr(lhs, rhs - lhs));

		lhs = rhs + 1;
		rhs = studentData[i].find(",", lhs);
		int DaysIC2 = stoi(studentData[i].substr(lhs, rhs - lhs));

		lhs = rhs + 1;
		rhs = studentData[i].find(",", lhs);
		int DaysIC3 = stoi(studentData[i].substr(lhs, rhs - lhs));


		lhs = rhs + 1;
		rhs = studentData[i].find_last_of("\0");
		if (studentData[i].substr(lhs, rhs - lhs) == "SECURITY")
		{
			degProgram = DegreeProgram::SECURITY;
		}
		else if (studentData[i].substr(lhs, rhs - lhs) == "NETWORK")
		{
			degProgram = DegreeProgram::NETWORK;
		}
		if (studentData[i].substr(lhs, rhs - lhs) == "SOFTWARE")
		{
			degProgram = DegreeProgram::SOFTWARE;
		}
		classRosterArray[i] = new Student(studentID, firstName, lastName, email, age, DaysIC1, DaysIC2, DaysIC3, degProgram);
	};
}

//Requirement E3b
void Roster::remove(string SID)
{
	int found = 0;
	for (int i = 0; i < 5; i++)
	{
		if (classRosterArray[i]->getID().find(SID) != std::string::npos)
		{
			classRosterArray[i]->setID(" ");
			classRosterArray[i]->setFirst(" ");
			classRosterArray[i]->setLast(" ");
			classRosterArray[i]->setEmail(" ");
			classRosterArray[i]->setAge(0);
			classRosterArray[i]->setDaysIC(0,0,0);
			classRosterArray[i]->setDegree(DegreeProgram::NA);

			found = 1;
			cout << "Student " << SID << " removed." << endl;
		}
	}	

	if (found == 0)
	{
		cout << "No student found." << endl;
	}
	
}

//Requirement E3c
void Roster::PrintRoster() const
{
	for (int i = 0; i < 5; i++)
	{
		if (classRosterArray[i]->getID().find(" ") == std::string::npos)
		{
			classRosterArray[i]->Print();
		}
	}
}

//Requirement E3d
void Roster::printAvDaysIC(string SID)
{
	int found = 0;
	for (int i = 0; i < 5; i++)
	{
		if (classRosterArray[i]->getID().find(SID) != std::string::npos)
		{
			int total = classRosterArray[i]->getDaysIC1() + classRosterArray[i]->getDaysIC2() + classRosterArray[i]->getDaysIC3();
			cout << "Average days in course: ";
			cout << total / 3 << endl;
			found = 1;
		}
	}
	if (found != 1)
		{
			cout << "No student found. Try again" << endl;
		}
	
}

//Requirement E3e
void Roster::printInvalidEmails() const
{
	cout << "Invalid emails:" << endl;
	for (int i = 0; i < 5; i++)
	{
		if (classRosterArray[i]->getEmail().find(' ') != std::string::npos || classRosterArray[i]->getEmail().find('@') == std::string::npos || classRosterArray[i]->getEmail().find('.') == std::string::npos)
		{
			cout << classRosterArray[i]->getEmail() << endl;
		}
	}
	cout << endl;
}

//Requirement E3f
void Roster::printByDeg(DegreeProgram degreeprogram)
{
	for (int i = 0; i < 5; i++)
	{
		if (classRosterArray[i]->getDegree() == degreeprogram)
		{
			classRosterArray[i]->Print();
		}
	}
}

//Default Roster constructor and destructor
Roster::Roster()
{ 
	return;
}

//Requirement F5 Destructor
Roster::~Roster()
{
	return;
}
