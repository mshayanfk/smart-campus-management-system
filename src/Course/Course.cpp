#include "Course.h"

#include <iostream>
#include <sstream>
#include <iomanip>
#include <stdexcept>
using namespace std;

Course::Course()
{
    courseCode = "";
    courseName = "";
    creditHours = 0;
    department = "";
    semester = "";
    isActive = true;
}
Course::~Course()
{
}
void Course::input()
{
    cout << "\n ==== Enter Course Details ==== \n";
    cout << "Enter the course code";
    getline(cin, courseCode);

    cout << "Enter the course name ";
    getline(cin, courseName);
    cout << "Enter the credit hours";
    cin >> creditHours;

    if (creditHours <= 0 || creditHours > 6)
    {
        throw runtime_error("invalid credit hours!");
    }
    cin.ignore();
    cout << "Enter the department ";
    getline(cin, department);
    cout << "Enter the semester season ";
    getline(cin, semester);
    isActive = true;
}
void Course::display() const
{
    cout << "\n=================================\n";
    cout << "           COURSE INFO           \n";
    cout << "=================================\n";
    cout << left << setw(18) << "Course Codde:" << courseCode << "\n";
    cout << left << setw(18) << "Course Name:" << courseName << "\n";
    cout << left << setw(18) << "Credit hours:" << creditHours << "\n";
    cout << left << setw(18) << "Departmnt:" << department << "\n";
    cout << left << setw(18) << "Semester:" << semester << "\n";
    cout << left << setw(18) << "Status:" << (isActive ? "Active" : "Inactive") << "\n";
    cout << "=================================\n";
}
void Course::saveToCSV(ofstream &outputFile){
    if(!outputFile.is_open()){
        throw runtime_error("File not open for writing");

    }
    outputFile<<courseCode<<","<<courseName<<","
    <<creditHours<<","<<department<<","<<semester<<","<<
    isActive<<"\n";
}
void Course::loadFromCSV(ifstream &inputFile){
    string line;
    if(!getline(inputFile,line))return;
    stringstream ss(line);

    string temp;
    getline(ss,courseCode,',');
    getline(ss,courseName,',');
    getline(ss,temp,',');
    creditHours=stoi(temp);
    getline(ss,department,',');
    getline(ss,semester,',');
    getline(ss,temp,',');
    isActive=stoi(temp);

}
void Course::setData(
    string  courseCode,
    string courseName,
    int creditHours,
    string department,
    string semester,
    bool status
){

    this->courseCode = courseCode;
    this->courseName = courseName;
    this->creditHours = creditHours;
    this->department = department;
    this->semester = semester;
    this->isActive = status;

}

void Course::setCourseCode(string courseCode) {
    this->courseCode = courseCode;
}
void Course::setCourseName(string courseName) {
    this->courseName = courseName;
}
void Course::setCourseCreditHours(int creditHours) {
    this->creditHours = creditHours;
}
void Course::setDepartment(string department) {
    this->department = department;
}
void Course::setSemester(string semester) {
    this->semester = semester;
}
void Course::setStatus(bool status) {
    this->isActive = status;
}
string Course::getCourseCode() const{
    return courseCode;
}
string Course::getCourseName() const{
    return courseName;
}
int Course::getCreditHours() const{
    return creditHours;
}

string Course::getDepartment() const {
    return department;
}

string Course::getSemester() const{
    return semester;
}
bool Course::getStatus() const{
    return isActive;
}

bool Course::matchesCode(string searchCode) const{
    return courseCode==searchCode;
}
