#include "Staff.h"

#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <sstream> 
using namespace std;

Staff::Staff() {
    department = "";
    role = "";
    shift = "";
    salary = 0.0;

    type = STAFF;
}

Staff::~Staff() {

}

void Staff::input() {

    Person::input();

    cin.ignore();
    
    cout << "--------------------------------------------------" << endl;
    cout << "=============== ENTER STAFF DETALS ===============" << endl;
    cout << "--------------------------------------------------" << endl;

    cout << "Enter the Department = ";
    getline(cin, department);

    cout << "Enter your Role in the Department = ";
    getline(cin, role);

    cout << "Enter your Shift (Morning/Evening/Night) = ";
    getline(cin, shift);

    cout << "Enter your Salary = ";
    cin >> salary;

    if (salary < 0) {
        throw runtime_error("Invalid Input Of Salary");
    }
}

void Staff::display() const {

    Person::display();

    cout << "=========== STAFF DETAILS =============" << endl;

    cout << left << setw(20) << "Department = " << department << endl;
    cout << left << setw(20) << "Role = " << role << endl;
    cout << left << setw(20) << "Shift = " << shift << endl;
    cout << left << setw(20) << "Salary = " << salary << endl;

    cout << "------------------------------------------" << endl;

}

void Staff::saveInCSV(ofstream &csvOutputFile) {

    if (!csvOutputFile.is_open()) {
        throw runtime_error("File Not opened for writing");
    }

    csvOutputFile << id << "," << name << ","
    << age << "," << contact << ","
    << isActive << "," << type << ","
    << department << "," << role << ","
     << "," << shift << "," 
    << salary << "," << endl;
}

void Staff::loadFromCSV(ifstream &csvInputFile) {
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
    getline(sh, role, ',');
    getline(sh, shift, ',');

    getline(sh, temp, ',');
    salary = stod(temp);

}

void Staff::setDepartment(string department) {
    this->department = department;
}

void Staff::setRole(string role) {
    this->role = role;
}

void Staff::setShift(string shift) {
    this->shift = shift;
}

void Staff::setSalary(double salary) {
    this->salary = salary;
}

string Staff::getDepartment() const {
    return department;
}

string Staff::getRole() const {
    return role;
}

string Staff::getShift() const {
    return shift;
}

double Staff::getSalary() const {
    return salary;
}