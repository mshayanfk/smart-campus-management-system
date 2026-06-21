#include "Invoice.h"

#include <iostream>
#include <iomanip>
#include <sstream>
#include <stdexcept>

using namespace std;

Invoice::Invoice() {
    invoiceID = 0;
    issueDate = "";
    totalAmount = 0.0;
    paidAmount = 0.0;
    remainingAmount = 0.0;
}

Invoice::~Invoice() {

}


void Invoice::input() {

    cout << BOLD << CYAN << "\n=========================================" << endl;
    cout << "            INVOICE ENTRY               " << endl;
    cout << "=========================================" << endl << RESET;

    cout << GREEN << "Enter Invoice ID: ";
    cin >> invoiceID;

    if (invoiceID <= 0) {
        throw runtime_error("Invalid Invoice ID!");
    }

    cin.ignore();

    cout << "Enter Issue Date (DD-MM-YYYY): ";
    getline(cin, issueDate);

    cout << "Enter Total Amount: ";
    cin >> totalAmount;

    if (totalAmount < 0) {
        throw runtime_error("Invalid Total Amount!");
    }

    cout << "Enter Paid Amount: " << RESET;
    cin >> paidAmount;

    if (paidAmount < 0 || paidAmount > totalAmount) {
        throw runtime_error("Invalid Paid Amount!");
    }

    remainingAmount = totalAmount - paidAmount;
}


void Invoice::generateInvoice(const FeeRecord &record) {

    feeRecord = record;

    totalAmount = record.getAmount();

    paidAmount = record.getPaid() ? record.getAmount() : 0;

    remainingAmount = totalAmount - paidAmount;
}


void Invoice::display() const {

    cout << BOLD << CYAN << "\n=========================================" << endl;
    cout << "             INVOICE DETAILS            " << endl;
    cout << "=========================================" << endl << RESET;

    cout << left << GREEN << setw(20) << "Invoice ID:" << invoiceID << endl;
    cout << left << setw(20) << "Issue Date:" << issueDate << endl << RESET;

    cout << BOLD << CYAN << "\n----------- FEE INFO -----------" << endl << RESET;

    cout << left << GREEN << setw(20) << "Student ID:" << feeRecord.getStudentID() << endl;
    cout << left << setw(20) << "Student Name:" << feeRecord.getStudentName() << endl;
    cout << left << setw(20) << "Fee Type:" << feeRecord.getFeeType() << endl;
    cout << left << setw(20) << "Fee Amount:" << feeRecord.getAmount() << endl << RESET;

    cout << BOLD << CYAN << "\n----------- PAYMENT -----------" << endl << RESET;

    cout << left << GREEN << setw(20) << "Total Amount:" << totalAmount << endl;
    cout << left << setw(20) << "Paid Amount:" << paidAmount << endl;
    cout << left << setw(20) << "Remaining:" << remainingAmount << endl << RESET;

    cout << BOLD << CYAN << "=========================================" << endl << RESET;
}


void Invoice::printReceipt() const {

    cout << BOLD << CYAN << "\n************** OFFICIAL RECEIPT **************" << endl << RESET;

    cout << GREEN << "Invoice ID   : " << invoiceID << endl;
    cout << "Issue Date   : " << issueDate << endl << RESET;

    cout << CYAN << "--------------------------------------------" << endl << RESET;

    cout << GREEN << "Student ID   : " << feeRecord.getStudentID() << endl;
    cout << "Student Name : " << feeRecord.getStudentName() << endl;
    cout << "Fee Type     : " << feeRecord.getFeeType() << endl << RESET;

    cout << CYAN << "--------------------------------------------" << endl << RESET;

    cout << GREEN << "Total Amount : " << totalAmount << endl;
    cout << "Paid Amount  : " << paidAmount << endl;
    cout << "Remaining    : " << remainingAmount << endl << RESET;

    cout << BOLD << CYAN << "********************************************" << endl << RESET;
}


void Invoice::saveInCSV(ofstream &csvOutputFile) const {

    if (!csvOutputFile.is_open()) {
        throw runtime_error("File not open for writing!");
    }

    csvOutputFile << invoiceID << "," << issueDate << ","
    << feeRecord.getFeeID() << "," << feeRecord.getStudentID() << ","
    << totalAmount << "," << paidAmount << ","
    << remainingAmount << endl;
}


void Invoice::loadFromCSV(ifstream &csvInputFile) {

    string line;

    if (!getline(csvInputFile, line))
        return;

    stringstream ss(line);
    string temp;

    getline(ss, temp, ',');
    invoiceID = stoi(temp);

    getline(ss, issueDate, ',');

     getline(ss, temp, ',');
    feeRecord.setFeeID(stoi(temp));

    getline(ss, temp, ',');
    feeRecord.setStudentID(stoi(temp));

    getline(ss, temp, ',');
    feeRecord.setStudentName(temp);

    getline(ss, temp, ',');
    feeRecord.setFeeType(temp);

    getline(ss, temp, ',');
    feeRecord.setDueDate(temp);

    getline(ss, temp, ',');
    feeRecord.setAmount(stod(temp));

    getline(ss, temp, ',');
    feeRecord.setPaid(stod(temp));

    getline(ss, temp, ',');
    totalAmount = stod(temp);

    getline(ss, temp, ',');
    paidAmount = stod(temp);

    getline(ss, temp, ',');
    remainingAmount = stod(temp);
}


void Invoice::setInvoiceID(int invoiceID) {
    this->invoiceID = invoiceID;
}

void Invoice::setIssueDate(string issueDate) {
    this->issueDate = issueDate;
}

void Invoice::setFeeRecord(FeeRecord record) {
    this->feeRecord = record;
}

void Invoice::setAmount(double paidAmount) {
    this->paidAmount = paidAmount;
    this->remainingAmount = totalAmount - paidAmount;
}


int Invoice::getInvoiceID() const {
    return invoiceID;
}

string Invoice::getIssueDate() const {
    return issueDate;
}

FeeRecord Invoice::getFeeRecord() const {
    return feeRecord;
}

double Invoice::getTotalAmount() const {
    return totalAmount;
}

double Invoice::getPaidAmount() const {
    return paidAmount;
}

double Invoice::getRemainingAmount() const {
    return remainingAmount;
}