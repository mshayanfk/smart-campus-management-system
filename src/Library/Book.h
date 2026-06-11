#ifndef BOOK_H
#define BOOK_H

#include "LibraryItem.h"

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Book : public LibraryItem
{

private:
    string author;
    string isbn;
    int totalPages;
    string edition;

public:
    Book();

    ~Book();

    void input();

    void display() const;

    void saveToCSV(std::ofstream &outputFile) const;

    void loadFromCSV(std::ifstream &inputFile);

    void setData(
        string author,
        string isbn,
        int totalPages,
        string edition);

    void setAuthor(string author);

    void setISBN(string isbn);

    void setTotalPages(int totalPages);

    void setEdition(string edition);

    string getAuthor() const;

    string getISBN() const;

    int getTotalPages() const;

    string getEdition() const;

    bool matchesAuthor(string searchAuthor) const;

    bool matchesISBN(string searchISBN) const;
};

#endif