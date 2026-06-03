#include "Faculty.h"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <stdexcept>

using namespace std;

Faculty::Faculty() {
    department = "";
    specialization = "";
    offRoom = "";
    course = "";
    experience = 0;
    salary = 0.0;

    type = FACULTY;
}

Faculty::~Faculty() {}

void Faculty::input() {
    Person::input();

    cin.ignore();

    cout << "============================================" << endl;
    cout << "------------ FACULTY INFORMATION -----------" << endl;
    cout << "============================================" << endl;

    cout << "Enter the Department = ";
    getline(cin, department);

    cout << "Enter your Specialization = ";
    getline(cin, specialization);

    cout << "Enter your Course = ";
    getline(cin, course);

    cout << "Enter your Office Number = ";
    getline(cin, offRoom);

    cout << "Enter your Experience = ";
    cin >> experience;

    if (experience < 0) {
        throw runtime_error("You Entered Invalid Experience");
    }

    if (experience > 3) {
        cout << "Good Boy";
    }

    else if (experience > 5) {
        cout << "Master";
    }

    else if (experience > 10) {
        cout << "Hacker";
    }

    cout << "Enter your Salary = ";
    cin >> salary;

    if (salary < 0) {
        throw runtime_error("Invalid Salary");
        cout << "You can't be that Poor Bro";
    }
}

void Faculty::display() const {
    Person::display();

    cout << "==========================================" << endl;
    cout << "              FACULTY DETAILS             " << endl;
    cout << "==========================================" << endl;

    cout << left << setw(25) << "Department = " << department << endl;
    
    cout << left << setw(25) << "Specialization = " << specialization << endl;

    cout << left << setw(25) << "Office Room = " << offRoom << endl;
    
    cout << left << setw(25) << "Course = " << course << endl;

    cout << left << setw(25) << "xpeerience = " << experience << endl;

    cout << left << setw(25) << "Salary = " << salary << endl;

    cout << "=================================================" << endl;

}