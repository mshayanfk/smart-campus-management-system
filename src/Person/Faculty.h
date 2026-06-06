#ifndef FACULTY_H
#define FACULTY_H

#include "Person.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Faculty : public Person {
    private:
    string department;
    string specialization;
    string offRoom;
    string course;
    int experience;
    double salary;

    public:
    Faculty();

    ~Faculty();

    void input() override;
    void display() const override;

    void saveInCSV(std::ofstream &csvOutputFile) override;
    void loadFromCSV(std::ifstream &csvInputFile) override;

    void setDepartment(string department);
    void setSpecialization(string specialization);
    void setRoom(string offRoom);
    void setCourse(string course);
    void setExperience(int experience);
    void setSalary(double salary);

    string getDepartment() const;
    string getSpecialization() const;
    string getRoom() const;
    string getCourse() const;
    int getExperience() const;
    double getSalary() const;
};

#endif