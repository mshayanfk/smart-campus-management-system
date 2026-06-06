#include "LibraryItem.h"

#include <sstream>
#include <iomanip>
#include <stdexcept>

using namespace std;

LibraryItem::LibraryItem() {
    itemId = 0;
    title = "";
    category = "";
    publisher = "";
    publicationYear = 0;
    isAvailable = true;
}

LibraryItem::~LibraryItem() {
}

void LibraryItem::input() {

    cout << "\n===== ENTER LIBRARY ITEM DETAILS =====\n";

    cout << "Enter Item ID: ";
    cin >> itemId;

    cin.ignore();

    cout << "Enter Title: ";
    getline(cin, title);

    cout << "Enter Category: ";
    getline(cin, category);

    cout << "Enter Publisher: ";
    getline(cin, publisher);

    cout << "Enter Publication Year: ";
    cin >> publicationYear;

    if (publicationYear < 0) {
        throw runtime_error("Invalid publication year!");
    }

    isAvailable = true;
}

void LibraryItem::display() const {

    cout << "\n=====================================\n";
    cout << "         LIBRARY ITEM INFO          \n";
    cout << "=====================================\n";

    cout << left << setw(20) << "Item ID:" << itemId << endl;
    cout << left << setw(20) << "Title:" << title << endl;
    cout << left << setw(20) << "Category:" << category << endl;
    cout << left << setw(20) << "Publisher:" << publisher << endl;
    cout << left << setw(20) << "Publication Year:" << publicationYear << endl;

    cout << left << setw(20) << "Availability:"
         << (isAvailable ? "Available" : "Unavailable")
         << endl;

    cout << "=====================================\n";
}

void LibraryItem::saveToCSV(ofstream &outputFile) {

    if (!outputFile.is_open()) {
        throw runtime_error("File not open for writing!");
    }

    outputFile << itemId << ","
               << title << ","
               << category << ","
               << publisher << ","
               << publicationYear << ","
               << isAvailable
               << endl;
}

void LibraryItem::loadFromCSV(ifstream &inputFile) {

    string line;

    if (!getline(inputFile, line))
        return;

    stringstream ss(line);
    string temp;

    getline(ss, temp, ',');
    itemId = stoi(temp);

    getline(ss, title, ',');

    getline(ss, category, ',');

    getline(ss, publisher, ',');

    getline(ss, temp, ',');
    publicationYear = stoi(temp);

    getline(ss, temp, ',');
    isAvailable = stoi(temp);
}

void LibraryItem::setData(
    int itemId,
    string title,
    string category,
    string publisher,
    int publicationYear,
    bool availability
) {
    this->itemId = itemId;
    this->title = title;
    this->category = category;
    this->publisher = publisher;
    this->publicationYear = publicationYear;
    this->isAvailable = availability;
}

void LibraryItem::setTitle(string title) {
    this->title = title;
}

void LibraryItem::setCategory(string category) {
    this->category = category;
}

void LibraryItem::setPublisher(string publisher) {
    this->publisher = publisher;
}

void LibraryItem::setPublicationYear(int publicationYear) {
    this->publicationYear = publicationYear;
}

void LibraryItem::setAvailability(bool availability) {
    this->isAvailable = availability;
}

int LibraryItem::getItemId() const {
    return itemId;
}

string LibraryItem::getTitle() const {
    return title;
}

string LibraryItem::getCategory() const {
    return category;
}

string LibraryItem::getPublisher() const {
    return publisher;
}

int LibraryItem::getPublicationYear() const {
    return publicationYear;
}

bool LibraryItem::getAvailability() const {
    return isAvailable;
}

bool LibraryItem::matchesItemId(int searchItemId) const {
    return itemId == searchItemId;
}

bool LibraryItem::matchesTitle(string searchTitle) const {
    return title == searchTitle;
}

bool LibraryItem::matchesCategory(string searchCategory) const {
    return category == searchCategory;
}