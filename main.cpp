#include<iostream>
#include<string>
#include "roster.h"
#include "student.h"

using namespace std;

int main()
{
    

    //Requirement F1 course and student information
    cout << "Scripting and Programming - Applications" << endl;
    cout << "C++" << endl;
    cout << "Student ID: #002821442" << endl;
    cout << "Worun Sukhtipyaroge" << endl;

    //Requirement F2 and F3 creating classRoster and adding each student to it
    Roster classRoster;
    classRoster.parseAndAdd();
    
    //Requirement F4 with extra endl for readability
    classRoster.PrintRoster();
    cout << endl;

    classRoster.printInvalidEmails();
    cout << endl;

    //looping through each student
    string SID[5] = { "A1", "A2", "A3", "A4", "A5" };
    for (int i = 0; i < 5; i++)
    {
        cout << "Student " << SID[i] << ": ";
        classRoster.printAvDaysIC(SID[i]);
    }
    cout << endl;

    classRoster.printByDeg(DegreeProgram::SOFTWARE);
    cout << endl;

    classRoster.remove("A3");
    cout << endl;
    
    classRoster.PrintRoster();
    cout << endl;
    
    classRoster.remove("A3");
    cout << endl;

    return 0;

    
}