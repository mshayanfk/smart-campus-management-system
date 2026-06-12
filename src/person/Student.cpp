#include "Student.h"
#include <sstream>
#include <iomanip>
#include <stdexcept>
#include <limits>
using namespace std;

Student::Student() {
    registrationNo = "";
    department = "";
    semester = "";
    section = "";
    gpa = 0.0;
    achievement = "";

    type = STUDENT;
}

Student::~Student() {}

void Student::input() {

    Person::input();

    cin.ignore(numeric_limits<streamsize>::max(), '\n');


    cout << "-----------------------------------------" <<  endl;
    cout << "========== ENTER STUDENT DETAILS ========" << endl;
    cout << "-----------------------------------------" << endl;

    cout << "Enter your Registration Number = ";
    getline(cin, registrationNo);

    cout << "Enter your Department = ";
    getline(cin, department);

    cout << "Enter your Semester = ";
    getline(cin, semester);

    cout << "Enter your Section = ";
    getline(cin, section);

    cout << "Enter Your GPA = ";
    cin >> gpa;

    if (cin.fail()) {
        throw runtime_error("Invalid GPA input");
    }

    if (gpa < 0.0 || gpa > 4.0) {
        throw runtime_error("Invalid GPA");
    }
 
}

void Student::display() const {
    Person::display();

    cout << "========== STUDENT DETAILS ==========" << endl;

    cout << left << setw(25) << 
    "Registration Number = " << registrationNo << endl;

    cout << left << setw(25) <<
    "Department = " << department << endl;

    cout << left << setw(25) <<
    "Semester = " << semester << endl;

    cout << left << setw(25) <<
    "Section = " << section << endl;

    cout << left << setw(25) << 
    "GPA = " << gpa <<  endl;

    cout << left << setw(25) <<
    "Achievement = " <<  achievement << endl;

    cout << "=================================" << endl;

}

void Student::saveInCSV(ofstream &csvOutputFile) {
    if (!csvOutputFile.is_open()) {
        throw runtime_error("File not opened for Writing");
    }

    csvOutputFile << id << "," << name << ","
                  << age << "," << contact << ","
                 << isActive << "," << type << ","
                 << registrationNo << "," << department << ","
                 << section << "," << gpa << endl;
                       
}

void Student::loadFromCSV(ifstream &csvInputFile) {
    string line;

    if(!getline(csvInputFile, line))
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

    getline(sh, registrationNo, ',');
    getline(sh, department, ',');
    getline(sh, semester, ',');
    getline(sh, section, ',');

    getline(sh, temp, ',');
    gpa =  stof(temp);
}

string Student::getAchievement() const {

    if (gpa >= 3.8) {
         return "Scholarship Acquired";
    }

    else if(gpa >= 3.5) {
        return "Outstanding Student";
    }

    else if (gpa >= 3.0) {
        return "Good Academic Result";
    }

    else if (gpa >= 2.5) {
        return "Good Boy";
    }

    else if (gpa >= 2.0) {

        return "Try Hard";
    }

    else {

    return "Skill Issue";

    }
}

void Student::setRegNo(string registrationNo) {
    this->registrationNo = registrationNo;
}

void Student::setDepartment(string department) {
    this->department = department;
}

void Student::setSemester(string semester) {
    this->semester = semester;
}

void Student::setSection(string section) {
    this->section = section;
}

void Student::setGPA(float gpa) {
    this->gpa = gpa;
}

string Student::getRegNo() const {
    return registrationNo;
}

string Student::getDepartment() const {
    return department;
}

string Student::getSemester() const {
    return semester;
}

string Student::getSection() const {
    return section;
}

float Student::getGPA() const {
    return gpa;
}

