#include "Journal.h"

#include <sstream>
#include <iomanip>
#include <stdexcept>

using namespace std;

Journal::Journal()
{
    journalName = "";
    volume = 0;
    issueNumber = 0;
    editor = "";
}

Journal::~Journal()
{
}

void Journal::input()
{

    LibraryItem::input();

    cout << "\n===== ENTER JOURNAL DETAILS =====\n";

    cin.ignore();

    cout << "Enter Journal Name: ";
    getline(cin, journalName);

    cout << "Enter Volume Number: ";
    cin >> volume;

    if (volume <= 0)
    {
        throw runtime_error("Invalid volume number!");
    }

    cout << "Enter Issue Number: ";
    cin >> issueNumber;

    if (issueNumber <= 0)
    {
        throw runtime_error("Invalid issue number!");
    }

    cin.ignore();

    cout << "Enter Editor Name: ";
    getline(cin, editor);
}

void Journal::display() const
{

    LibraryItem::display();

    cout << left << setw(20) << "Journal Name:" << journalName << endl;
    cout << left << setw(20) << "Volume:" << volume << endl;
    cout << left << setw(20) << "Issue Number:" << issueNumber << endl;
    cout << left << setw(20) << "Editor:" << editor << endl;

    cout << "=====================================\n";
}

void Journal::saveToCSV(ofstream &outputFile) const {

    if (!outputFile.is_open())
    {
        throw runtime_error("File not open for writing!");
    }

    outputFile << journalName << ","
               << volume << ","
               << issueNumber << ","
               << editor
               << endl;
}

void Journal::loadFromCSV(ifstream &inputFile)
{

    string line;

    if (!getline(inputFile, line))
        return;

    stringstream ss(line);
    string temp;

    getline(ss, journalName, ',');

    getline(ss, temp, ',');
    volume = stoi(temp);

    getline(ss, temp, ',');
    issueNumber = stoi(temp);

    getline(ss, editor, ',');
}

void Journal::setData(
    string journalName,
    int volume,
    int issueNumber,
    string editor)
{
    this->journalName = journalName;
    this->volume = volume;
    this->issueNumber = issueNumber;
    this->editor = editor;
}

void Journal::setJournalName(string journalName)
{
    this->journalName = journalName;
}

void Journal::setVolume(int volume)
{
    this->volume = volume;
}

void Journal::setIssueNumber(int issueNumber)
{
    this->issueNumber = issueNumber;
}

void Journal::setEditor(string editor)
{
    this->editor = editor;
}

string Journal::getJournalName() const
{
    return journalName;
}

int Journal::getVolume() const
{
    return volume;
}

int Journal::getIssueNumber() const
{
    return issueNumber;
}

string Journal::getEditor() const
{
    return editor;
}

bool Journal::matchesJournalName(string searchJournalName) const
{
    return journalName == searchJournalName;
}

bool Journal::matchesEditor(string searchEditor) const
{
    return editor == searchEditor;
}