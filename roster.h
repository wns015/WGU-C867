#pragma once
#include <iostream>
#include <string>
#include "student.h"
#include "degree.h"

using namespace std;

class Roster
{
private:
	//E and E1 Roster class and array of pointers
	Student* classRosterArray[5];

	string studentID;
	string firstName;
	string lastName;
	string email;
	int age;
	int daysic1;
	int daysic2;
	int daysic3;
	DegreeProgram degProgram;

public:
	
	//Requirement E2, E2a, E2b, and E3a function for creating student objects, parsing data and adding data to classRosterArray
	void parseAndAdd();

	//Requirement E3b
	void remove(string SID);
	
	//Requirement E3c
	void PrintRoster() const;
	
	//Requirement E3d
	void printAvDaysIC(string SID);
	
	//Requirement E3e
	void printInvalidEmails() const;

	//Requirement E3f
	void printByDeg(DegreeProgram degreeprogram);

	//Roster default constructor with deconstructor
	Roster();
	~Roster();
};