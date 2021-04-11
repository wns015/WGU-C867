#pragma once
#include "degree.h"
#include <iostream>
#include <string>

using namespace std;

class Student
{
private:
	//Requirement D1
	string studentID;
	string firstName;
	string lastName;
	string email;
	int age;
	int DaysIC[3];
	string dProgram;
	DegreeProgram degreeprogram;

public:
	//Requirement D2a
	string getID() const;
	string getFirst() const;
	string getLast() const;
	string getEmail() const;
	int getAge() const;
	int getDaysIC1() const;
	int getDaysIC2() const;
	int getDaysIC3() const;
	DegreeProgram getDegree() const;

	//Requirement D2b
	void setID(string enterID);
	void setFirst(string enterFirst);
	void setLast(string enterLast);
	void setEmail(string enterEmail);
	void setAge(int enterAge);
	void setDaysIC(int enterDaysIC1, int enterDaysIC2, int enterDaysIC3);
	void setDegree(DegreeProgram enterDegree);
	
	//Requirement D2d
	Student(string studentID, string firstName, string lastName, string email, int age, int DaysIC1, int DaysIC2, int DaysIC3, DegreeProgram degreeprogram);
	~Student();

	//Requirement D2e
	void Print() const;
};