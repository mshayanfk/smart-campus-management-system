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

void Faculty::saveInCSV(ofstream &csvOutputFile) {

    if (!csvOutputFile.is_open()) {
        throw runtime_error("File not opened for writing");
    }

    csvOutputFile << id << "," << name << "," <<
    age << "," << contact << "," << isActive << ","
    << type << "," << department << "," << specialization << ","
    << offRoom << "," << course << "," << experience << ","
    << salary << endl;
}

void Faculty::loadFromCSV(ifstream &csvInputFile) {
    string line;

    if (!getline(csvInputFile, line))
    return;

    stringstream sh(line);
    string temp;

    getline(sh, temp, ',');
    id = stoi(temp);

    getline(sh, name, ',');

    getline(sh, temp, ',');
    age = stoi(temp);

    getline(sh, contact, ',');

    getline(sh, temp, ',');
    isActive = stoi(temp);

    getline(sh, temp, ',');
    type = (PersonType)stoi(temp);

    getline(sh, department, ',');
    getline(sh, specialization, ',');
    getline(sh, offRoom, ',');
    getline(sh, course, ',');

    getline(sh, temp, ',');
    experience = stoi(temp);

    getline(sh, temp, ',');
    salary = stod(temp);

}

void Faculty::setDepartment(string getDepartment) {
    this->department = department;
}

void Faculty::setSpecialization(string specialization) {
    this->specialization = specialization;
}

void Faculty::setRoom(string offRoom) {
    this->offRoom = offRoom;
}

void Faculty::setCourse(string course) {
    this->course = course;
}

void Faculty::setExperience(int experience) {
    this->experience = experience;
}

void Faculty::setSalary(double salary) {
    this->salary = salary;
}


string Faculty::getDepartment() const {
    return department;
}

string Faculty::getSpecialization() const {
    return specialization;
}

string Faculty::getRoom() const {
    return offRoom;
}

string Faculty::getCourse() const {
    return course;
}

int Faculty::getExperience() const {
    return experience;
}

double Faculty::getSalary() const {
    return salary;
}