#ifndef FEERECORD_H
#define FEERECORD_H
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class FeeRecord {
    private:

    int feeID;
    int studentID;
    string studentName;
    string feeType;
    string dueDate;
    double amount;
    bool isPaid;
    
    public:
    FeeRecord();
    ~FeeRecord();

    void input();
    void display() const;

    void saveInCSV(ofstream &csvOutputFile) const;
    void loadFromCSV(ifstream &csvInputFile);

    void setFeeID(int feeID);
    void setStudentID(int studentID);
    void setStudentName(string studentName);
    void setFeeType(string feeType);
    void setDueDate(string dueDate);
    void setAmount(double amount);
    void setPaid(bool isPaid);

    int getFeeID() const;
    int getStudentID() const;
    string getStudentName() const;
    string getFeeType() const;
    string getDueDate() const;
    double getAmount() const;
    bool getPaid() const;
};

#endif