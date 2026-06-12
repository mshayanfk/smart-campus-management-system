#ifndef INVOICE_H
#define INVOICE_H

#include "FeeRecord.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Invoice {
    private:

    int invoiceID;
    string issueDate;
    FeeRecord feeRecord;
    double totalAmount;
    double paidAmount;
    double remainingAmount;

    public:
    Invoice();

    ~Invoice();

    void input();
    void display() const;

    void generateInvoice(const FeeRecord &record);

    void saveInCSV(ofstream &csvOutputFile) const;
    void loadFromCSV(ifstream &csvInputFile);

    void printReceipt() const;

    void setInvoiceID(int invoiceID);
    void setIssueDate(string issueDate);
    void setFeeRecord(FeeRecord record);
    void setAmount(double paidAmount);

    int getInvoiceID() const;
    string getIssueDate() const;
    FeeRecord getFeeRecord() const;
    double getTotalAmount() const;
    double getPaidAmount() const;
    double getRemainingAmount() const;
};

#endif