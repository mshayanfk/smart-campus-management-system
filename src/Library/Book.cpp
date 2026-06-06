#include "Book.h"

#include <sstream>
#include <iomanip>
#include <stdexcept>

using namespace std;

Book::Book()
{
    author = "";
    isbn = "";
    totalPages = 0;
    edition = "";
}

Book::~Book()
{
}

void Book::input()
{

    LibraryItem::input();

    cout << "\n===== ENTER BOOK DETAILS =====\n";

    cin.ignore();

    cout << "Enter Author: ";
    getline(cin, author);

    cout << "Enter ISBN: ";
    getline(cin, isbn);

    cout << "Enter Total Pages: ";
    cin >> totalPages;

    if (totalPages <= 0)
    {
        throw runtime_error("Invalid number of pages!");
    }

    cin.ignore();

    cout << "Enter Edition: ";
    getline(cin, edition);
}

void Book::display() const
{

    LibraryItem::display();

    cout << left << setw(20) << "Author:" << author << endl;
    cout << left << setw(20) << "ISBN:" << isbn << endl;
    cout << left << setw(20) << "Pages:" << totalPages << endl;
    cout << left << setw(20) << "Edition:" << edition << endl;

    cout << "=====================================\n";
}

void Book::saveToCSV(ofstream &outputFile)
{

    if (!outputFile.is_open())
    {
        throw runtime_error("File not open for writing!");
    }

    outputFile << author << ","
               << isbn << ","
               << totalPages << ","
               << edition
               << endl;
}

void Book::loadFromCSV(ifstream &inputFile)
{

    string line;

    if (!getline(inputFile, line))
        return;

    stringstream ss(line);
    string temp;

    getline(ss, author, ',');

    getline(ss, isbn, ',');

    getline(ss, temp, ',');
    totalPages = stoi(temp);

    getline(ss, edition, ',');
}

void Book::setData(
    string author,
    string isbn,
    int totalPages,
    string edition)
{
    this->author = author;
    this->isbn = isbn;
    this->totalPages = totalPages;
    this->edition = edition;
}

void Book::setAuthor(string author)
{
    this->author = author;
}

void Book::setISBN(string isbn)
{
    this->isbn = isbn;
}

void Book::setTotalPages(int totalPages)
{
    this->totalPages = totalPages;
}

void Book::setEdition(string edition)
{
    this->edition = edition;
}

string Book::getAuthor() const
{
    return author;
}

string Book::getISBN() const
{
    return isbn;
}

int Book::getTotalPages() const
{
    return totalPages;
}

string Book::getEdition() const
{
    return edition;
}

bool Book::matchesAuthor(string searchAuthor) const
{
    return author == searchAuthor;
}

bool Book::matchesISBN(string searchISBN) const
{
    return isbn == searchISBN;
}