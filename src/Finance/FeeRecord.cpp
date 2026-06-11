#include "FeeRecord.h"

#include <iostream>
#include <sstream>
#include <iomanip>
#include <stdexcept>
using namespace std;

FeeRecord::FeeRecord() {
    feeID = 0;
    studentID = 0;
    studentName = "";
    feeType = "";
    dueDate = "";
    amount = 0.0;
    isPaid = false;
}

FeeRecord::~FeeRecord() {}

void FeeRecord::input() {

    cout << "===========================================" << endl;
    cout << "------------- FEE RECORD ENTRY ------------" << endl;
    cout << "===========================================" << endl;

    cout << "Enter The Fee ID = ";
    cin >> feeID;

    if (feeID <= 0) {
        throw runtime_error("Invalid Fee ID!");
    }

    cout << "Enter the Student ID = ";
    cin >> studentID;

    if (studentID <= 0) {
        throw runtime_error("Invalid Student ID!");
    }

    cin.ignore();

    cout << "Enter the Student Name = ";
    getline(cin, studentName);

    cout << "Enter the Fee Type (Hostel/Transport/Tuition) = ";
    getline(cin, feeType);

    cout << "Enter the Due Date (DD-MM--YYYY) = ";
    getline(cin, dueDate);

    cout << "Enter the Amount = ";
    cin >> amount;

    if (amount < 0) {
        throw runtime_error("Entered Invalid Amount!");
    }

    cout << "Is Ur Fee Paid! (1 = Yes, 0 = No) = ";
    cin >> isPaid;
}

void FeeRecord::display() const {
    
    cout << "=====================================" << endl;
    cout << "--------- FEE RECORD DETAILS --------" << endl;
    cout << "=====================================" << endl;

    cout << left << setw(25) << "Fee ID = " << feeID << endl;
    cout << left << setw(25) << "Student ID = " << studentID << endl;
    cout << left << setw(25) << "Student Name = " << studentName << endl;
    cout << left << setw(25) << "Fee Type = " << feeType << endl;
    cout << left << setw(25) << "Due Date of Fee = " << dueDate << endl;
    cout << left << setw(25) << "Fee Amount = " << amount << endl;
    cout << left << setw(25) << "Status = " << (isPaid ? "Paid" : "UnPaid") << endl;

    cout << "==========================================" << endl;
} 


void FeeRecord::saveInCSV(ofstream &csvOutputFile) const {

    if (!csvOutputFile.is_open()) {
        throw runtime_error("File not Opened for Writing");
    }

    csvOutputFile << feeID << "," << studentID << "," 
    << studentName << "," << feeType << "," << dueDate
    << "," << amount << "," << isPaid << endl;
}


void FeeRecord::loadFromCSV(ifstream &csvInputFile) {
    string line;

    if (!getline(csvInputFile, line))
    return;

    stringstream sh(line);
    string temp;

    getline(sh, temp, ',');
    feeID = stoi(temp);

    getline(sh, temp, ',');
    studentID = stoi(temp);

    getline(sh, studentName, ',');
    getline(sh, feeType, ',');
    getline(sh, dueDate, ',');

    getline(sh, temp, ',');
    amount = stod(temp);

    getline(sh, temp, ',');
    isPaid = stoi(temp);
}

void FeeRecord::setData(
    int feeID,
    int studentID,
    string studentName,
    string feeType,
    string dueDate,
    double amount,
    bool isPaid
)

{
    this->feeID       = feeID;
    this->studentID   = studentID;
    this->studentName = studentName;
    this->feeType     = feeType;
    this->dueDate     = dueDate;
    this->amount      = amount;
    this->isPaid      = isPaid;
}


void FeeRecord::setFeeID(int feeID) {
    this->feeID = feeID;
}

void FeeRecord::setStudentID(int studentID) {
    this->studentID = studentID;
}

void FeeRecord::setStudentName(string studentName) {
    this->studentName = studentName;
}

void FeeRecord::setFeeType(string feeType) {
    this->feeType = feeType;
}

void FeeRecord::setDueDate(string dueDate) {
    this->dueDate = dueDate;
}

void FeeRecord::setAmount(double amount) {
    this->amount = amount;
}

void FeeRecord::setPaid(bool isPaid) {
    this->isPaid = isPaid;
}


int FeeRecord::getFeeID() const {
    return feeID;
}

int FeeRecord::getStudentID() const {
    return studentID;
}

string FeeRecord::getStudentName() const {
    return studentName;
}

string FeeRecord::getFeeType() const {
    return feeType;
}

string FeeRecord::getDueDate() const {
    return dueDate;
}

double FeeRecord::getAmount() const {
    return amount;
}

bool FeeRecord::getPaid() const {
    return isPaid;
}

bool FeeRecord::matchesFeeID(int searchID) const {
    return feeID == searchID;
}

bool FeeRecord::matchesStudentID(int searchID) const {
    return studentID == searchID;
}