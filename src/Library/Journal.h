#ifndef JOURNAL_H
#define JOURNAL_H

#include "LibraryItem.h"

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Journal : public LibraryItem
{

private:
    string journalName;
    int volume;
    int issueNumber;
    string editor;

public:
    Journal();

    ~Journal();

    void input();

    void display() const;

    void saveToCSV(std::ofstream &outputFile);

    void loadFromCSV(std::ifstream &inputFile);

    void setData(
        string journalName,
        int volume,
        int issueNumber,
        string editor);

    void setJournalName(string journalName);

    void setVolume(int volume);

    void setIssueNumber(int issueNumber);

    void setEditor(string editor);

    string getJournalName() const;

    int getVolume() const;

    int getIssueNumber() const;

    string getEditor() const;

    bool matchesJournalName(string searchJournalName) const;

    bool matchesEditor(string searchEditor) const;
};

#endif