#ifndef STAFF_H
#define STAFF_H

#include "Person.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Staff : public Person {
    
    private:
    string department;
    string role;
    string shift;
    double salary;

    public:
    Staff();
    ~Staff();



    void input() override;
    void display() const override;

    void saveInCSV(std::ofstream &csvOutputFile) override;
    void loadFromCSV(std::ifstream &csvInputFile) override;

    void setDepartment(string department);
    void setRole(string role);
    void setShift(string shift);
    void setSalary(double salary);
    
    string getDepartment() const;
    string getRole() const;
    string getShift() const;
    double getSalary() const;
};

#endif