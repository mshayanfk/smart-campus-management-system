#ifndef LIBRARYITEM_H
#define LIBRARYITEM_H

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class LibraryItem {

private:
    int itemId;
    string title;
    string category;
    string publisher;
    int publicationYear;
    bool isAvailable;

public:

    // Constructor
    LibraryItem();

    // Destructor
    ~LibraryItem();

    // Core Functions
    void input();

    void display() const;

    // File Handling
    void saveToCSV(std::ofstream &outputFile);

    void loadFromCSV(std::ifstream &inputFile);

    // Utility Function
    void setData(
        int itemId,
        string title,
        string category,
        string publisher,
        int publicationYear,
        bool availability
    );

    // Setters
    void setTitle(string title);

    void setCategory(string category);

    void setPublisher(string publisher);

    void setPublicationYear(int publicationYear);

    void setAvailability(bool availability);

    // Getters
    int getItemId() const;

    string getTitle() const;

    string getCategory() const;

    string getPublisher() const;

    int getPublicationYear() const;

    bool getAvailability() const;

    // Search Helpers
    bool matchesItemId(int searchItemId) const;

    bool matchesTitle(string searchTitle) const;

    bool matchesCategory(string searchCategory) const;
};

#endif