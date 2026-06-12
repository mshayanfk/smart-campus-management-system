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
    void setSection(string section);
    void setGPA(float gpa);

    string getRegNo() const;
    string getDepartment() const;
    string getSemester() const;
    string getSection() const;
    float getGPA() const;
    string getAchievement() const;
};

#endif