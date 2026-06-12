#include "Enrollment.h"

#include <sstream>
#include <iomanip>
#include <stdexcept>
using namespace std;

Enrollment::Enrollment()
{
    enrollmentId = 0;
    studentId = 0;
    courseCode = "";
    semester = "";
    session = "";
    enrollmentDate = "";
    grade = "";
    isActive = true;
}
Enrollment::~Enrollment()
{
}
void Enrollment::input()
{
    cout << "\n===== ENTER ENROLLMENT DETAILS =====\n";
    cout << "Enter Enrollenemt ID:";
    cin >> enrollmentId;
    cout << "Enter Student ID:";
    cin >> studentId;
    cin.ignore();

    cout << "Enter the Course Code:";
    getline(cin, courseCode);
    cout << "Enter the Semester:";
    getline(cin, semester);
    cout << "Enter Grade: ";
    getline(cin, grade);
    isActive = true;
}
void Enrollment::display() const
{
    cout << "\n=====================================\n";
    cout << "         ENROLLMENT DETAILS          \n";
    cout << "=====================================\n";
    cout << left << setw(20) << "Enrollment ID:" << enrollmentId << endl;
    cout << left << setw(20) << "Student ID:" << studentId << endl;
    cout << left << setw(20) << "Course Code:" << courseCode << endl;
    cout << left << setw(20) << "Semester:" << semester << endl;
    cout << left << setw(20) << "Enrollement:" << enrollmentDate << endl;
    cout << left << setw(20) << "Grade:" << grade << endl;

    cout << left << setw(20) << "Status:" << (isActive ? "Active" : "Is not Active") << endl;
    cout << "=====================================\n";
}
void Enrollment::saveToCSV(ofstream &outputFile)
{
    if (!outputFile.is_open())
    {
        throw runtime_error("File not open for writing");
    }
    outputFile << enrollmentId << "," << studentId << "," << courseCode << "," << semester << "," << session << "," << enrollmentDate << "," << grade << "," << isActive << "\n";
}
void Enrollment::loadFromCSV(ifstream &inputFile)
{
    string line;
    if (!getline(inputFile, line))
        return;
    stringstream ss(line);
    string temp;
    getline(ss, temp, ',');
    enrollmentId = stoi(temp);
    getline(ss, temp, ',');
    studentId = stoi(temp);
    getline(ss, courseCode, ',');
    getline(ss, semester, ',');
    getline(ss, session, ',');
    getline(ss, enrollmentDate, ',');
    getline(ss, grade, ',');
    getline(ss, temp, ',');
    isActive = stoi(temp);
}
void Enrollment::setData(
    int enrollmentId,
    int studentId,
    string courseCode,
    string semester,
    string session,
    string enrollmentDate,
    string grade,
    bool status)
{
    this->enrollmentId = enrollmentId;
    this->studentId = studentId;
    this->courseCode = courseCode;
    this->semester = semester;
    this->grade = grade;
    this->isActive = status;
}
void Enrollment::setStudentId(int studentId)
{
    this->studentId = studentId;
}
void Enrollment::setCourseCode(string courseCode)
{
    this->courseCode = courseCode;
}
void Enrollment::setSemester(string semester)
{
    this->semester = semester;
}
void Enrollment::setSession(string session)
{
    this->session = session;
}
void Enrollment::setEnrollmentDate(string enrollmentDate)
{
    this->enrollmentDate = enrollmentDate;
}
void Enrollment::setGrade(string grade)
{
    this->grade = grade;
}
void Enrollment::setStatus(bool status)
{
    this->isActive = status;
}
int Enrollment::getEnrollmentId() const{
    return enrollmentId;
}
int Enrollment::getStudentId() const{
    return studentId;
}
string Enrollment::getCourseCode() const{
    return courseCode;
}
string Enrollment::getSemester() const{
    return semester;
}
string Enrollment::getEnrollmentDate() const{
    return enrollmentDate;

}
string Enrollment::getGrade() const{
    return grade;
}
bool Enrollment::getStatus() const{
    return isActive;
}
bool Enrollment::matchesEnrollmentId(int searchId) const{
    return enrollmentId==searchId;
}
bool Enrollment::matchesStudentId(int searchstudentId) const{
    return studentId==searchstudentId;
}
bool Enrollment::matchesCourseCode(string searchCourseCode) const{
    return courseCode==searchCourseCode;
}
