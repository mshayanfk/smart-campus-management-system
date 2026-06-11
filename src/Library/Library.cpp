#include "Library.h"
#include <sstream>
#include <iomanip>
#include <stdexcept>

using namespace std;
Library::Library()
{
    bookId = 0;
    bookTitle = "";
    author = "";
    category = "";
    quantity = 0;
    issueDate = "";
    returnDate = "";
    isAvailable = true;
}
Library::~Library()
{
}
void Library::input()
{
    cout << "\n===== ENTER BOOK DETAILS =====\n";
    cout << "Enter Book ID = ";
    cin >> bookId;
    cin.ignore();
    cout << "Enter Book Title";
    cin >> bookId;
    cin.ignore();
    cout << "Enter Book Title:";
    getline(cin, bookTitle);
    cout << "Enter Author Name:";
    getline(cin, author);
    cout << "Enter category:";
    getline(cin, category);
    cout << "Enter Quantity:";
    cin >> quantity;
    cin.ignore();
    cout << "Enter the Issue Date:";
    getline(cin, issueDate);
    cout << "Enter the Return Date:";
    getline(cin, returnDate);

    isAvailable = true;
}
void Library::display() const
{
    cout << "\n=====================================\n";
    cout << "          LIBRARY RECORD             \n";
    cout << "=====================================\n";

    cout << left << setw(20) << "Book Id:" << bookId << endl;
    cout << left << setw(20) << "Title:" << bookTitle << "\n";
    cout << left << setw(20) << "Aurthor:" << author << endl;
    cout << left << setw(20) << "Category:" << category << endl;
    cout << left << setw(20) << "Quantity:" << quantity << endl;
    cout << left << setw(20) << "Issue Date:" << issueDate << endl;
    cout << left << setw(20) << "Return date:" << returnDate << endl;

    cout << left << setw(20) << "Availability:" << (isAvailable ? "Available" : "Unavailable") << endl;

    cout << "=====================================\n";
}
void Library::saveToCSV(ofstream &outputFile)
{
    if (!outputFile.is_open())
    {
        throw runtime_error("FIle not open ");
    }
    outputFile << bookId << ","
               << bookTitle << "," << author << "," << category << ","
               << quantity << "," << issueDate << "," << returnDate << ","
               << isAvailable << endl;
}
void Library::loadFromCSV(ifstream &inputFile)
{
    string line;
    if (!getline(inputFile, line))
        return;
    stringstream ss(line);
    string temp;

    getline(ss, temp, ',');
    bookId = stoi(temp);

    getline(ss, bookTitle, ',');
    getline(ss, author, ',');
    getline(ss, category, ',');
    getline(ss, temp, ',');
    quantity = stoi(temp);
    getline(ss, issueDate, ',');
    getline(ss, returnDate, ',');

    getline(ss, temp, ',');
    isAvailable = stoi(temp);
}
void Library::setData(
    int bookId,
    string bookTitle,
    string author,
    string category,
    int quantity,
    string issueDate,
    string returnDate,
    bool availability
){
    this->bookId=bookId;
    this->bookTitle=bookTitle;
    this->author=author;
    this->category = category;
    this->quantity=quantity;
    this->issueDate=issueDate;
    this->returnDate=returnDate;
    this->isAvailable=availability;
}

void Library::setBookId(int bookId) {
    this->bookId = bookId;
}

void Library::setBookTitle(string bookTitle){
    this->bookTitle = bookTitle;
}
void Library::setAuthor(string author){
    this->author=author;

}
void Library::setCategory(string category){
    this->category=category;

}
void Library::setQuantity(int quantity){
    this->quantity = quantity;
}
void Library::setIssueDate(string issueDate){
    this->issueDate = issueDate;
}
void Library::setReturnDate(string returnDate){
    this->returnDate=returnDate;
}
void Library::setAvailability(bool availability){
    this->isAvailable=availability;
}


int Library::getBookId() const{
    return bookId;
}
string Library::getBookTitle() const{
    return bookTitle;
}
string Library::getCategory() const{
  return category;
}
int Library::getQuantity() const{
    return quantity;
}
string Library::getIssueDate() const{
return issueDate;

}
string Library::getReturnDate() const{
    return returnDate;

}
bool Library::getAvailability() const{
    return isAvailable;
}
bool Library::matchesBookId(int serachBookId) const{
    return bookId==serachBookId;
}
bool Library::matchesBookTitle(string searchTitle) const{
    return bookTitle== searchTitle;
}
bool Library::matchesAuthor(string searchAuthor) const{
    return author==searchAuthor;
}