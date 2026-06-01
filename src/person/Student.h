#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Student : public Person {
    private:
    string registrationNo;
    string department;
    string semester;
    string section;
    float gpa;
    string achievement;

    public:
    Student();

    ~Student();

    void input() override;
    void display() const override;

    void saveInCSV(std::ofstream &csvOutputFile);
    void loadFromCSV(std::ifstream &csvInputFile);

    void setRegNo(string registrationNo);
    void setDepartment(string department);
    void setSemester(string semester);
    void setSecttion(string section);
    void setCGPA(float cgpa);
    void setAchievement(string achievement);

    string getRegNo() const;
    string getDepartment() const;
    string getSemester() const;
    string getSecttion() const;
    float getCGPA() const;
    string getAchievement() const;
};

#endif