#ifndef LIBRARY_H
#define LIBRARY_H

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Library
{

private:
    int bookId;
    string bookTitle;
    string author;
    string category;
    int quantity;
    string issueDate;
    string returnDate;
    bool isAvailable;

public:
    Library();

    ~Library();

    void input();

    void display() const;

    void saveToCSV(std::ofstream &outputFile);

    void loadFromCSV(std::ifstream &inputFile);

    void setData(
        int bookId,
        string bookTitle,
        string author,
        string category,
        int quantity,
        string issueDate,
        string returnDate,
        bool availability);

    void setBookTitle(string bookTitle);

    void setAuthor(string author);

    void setCategory(string category);

    void setQuantity(int quantity);

    void setIssueDate(string issueDate);

    void setReturnDate(string returnDate);

    void setAvailability(bool availability);

    int getBookId() const;

    string getBookTitle() const;

    string getAuthor() const;

    string getCategory() const;

    int getQuantity() const;

    string getIssueDate() const;

    string getReturnDate() const;

    bool getAvailability() const;

    bool matchesBookId(int searchBookId) const;

    bool matchesBookTitle(string searchTitle) const;

    bool matchesAuthor(string searchAuthor) const;
};

#endif