#ifndef COURSE_H
#define COURSE_H
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Course
{
private:
    string courseCode;
    string courseName;
    string semester;
    int creditHours;
    string department;
    bool isActive;

public:
    Course();

    ~Course();
    void input();
    void display() const;
    void saveToCSV(std::ofstream &outputFile);
    void loadFromCSV(std::ifstream &inputFile);
    void setData(

        string courseCode,
        string courseName,
        int credithours,
        string department,
        string semester,
        bool status);

    void setCourseCode(string courseCode);
    void setCourseName(string courseName);
    void setSemester(string semester);
    void setCourseCreditHours(int creditHours);
    void setDepartment(string department);
    void setStatus(bool status);

    string getCourseCode() const;
    string getCourseName() const;
    string getSemester() const;
    int getCreditHours() const;
    string getDepartment() const;
    bool getStatus() const;

    bool matchesCode(string searchCode) const;
};
#endif
