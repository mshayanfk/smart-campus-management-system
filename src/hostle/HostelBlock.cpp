#include "HostelBlock.h"

#include <iostream>
#include <sstream>
#include <stdexcept>
#include <iomanip>
using namespace std;

HostelBlock::HostelBlock() {
    blockName = "";
    wardenName = "";
    totalRooms = 0;
}

HostelBlock::~HostelBlock() {}

void HostelBlock::input() {

    cout << CYAN << "=======================================" << endl;
    cout << "-------  HOSTEL BLOCK INFORMATION -----" << endl;
    cout << "=======================================" << endl << RESET;

    cin.ignore();

    cout << GREEN << "Enter Block Name = ";
    getline(cin, blockName);

    cout << "Enter Warden Name = ";
    getline(cin, wardenName);

    cout << "Enter Total Rooms = " << RESET;
    cin >> totalRooms;

    if (totalRooms <= 0) {
        throw runtime_error("Invalid Number of Rooms");
    }
}

void HostelBlock::display() const {

    cout << CYAN << "=====================================" << endl;
    cout << "-------- HOSTEL BLOCK DETAILS -------" << endl;
    cout << "=====================================" << endl << RESET;

    cout << left << GREEN << setw(25) << "Block Name = " << blockName << endl;
    cout << left << setw(25) << "Warden Name = " << wardenName << endl;
    cout << left << setw(25) << "Total Rooms = " << totalRooms << endl;
    cout << left << setw(25) << "Rooms Added = " << rooms.size() << endl << RESET;

    cout << BOLD << CYAN << "=========================================" << endl << RESET;
}


void HostelBlock::addRoom(const Room &room) {
    rooms.push_back(room);
}

void HostelBlock::displayRooms() const {
    
    if (rooms.empty()) {
        cout << "No Rooms Available in the Block" << endl;
        return;
    }

    cout << BOLD << CYAN << "============ ROOM LIST ================" << endl << RESET;

    for (const Room &room : rooms) {
        room.display();
    }
}

void HostelBlock::saveInCSV(ofstream &csvOutputFile) const {

    if (!csvOutputFile.is_open()) {
        throw runtime_error("File not Opened for Writing");
    }

    csvOutputFile << blockName << "," << wardenName << ","
    << totalRooms << endl;
}

void HostelBlock::loadFromCSV(ifstream &csvInputFile) {
    string line;

    if (!getline(csvInputFile, line))
    return;

    stringstream sh(line);
    string temp;

    getline(sh, blockName, ',');
    getline(sh, wardenName, ',');

    getline(sh, temp, ',');
    totalRooms = stoi(temp);
}

void HostelBlock::setData(string blockName, 
    string wardenName, 
    int totalRooms
)

{
    this->blockName  = blockName;
    this->wardenName = wardenName;
    this->totalRooms = totalRooms;
}

void HostelBlock::setBlockName(string blockName) {
    this->blockName = blockName;
}

void HostelBlock::setWardenName(string wardenName) {
    this->wardenName = wardenName;
}

void HostelBlock::setTotalRooms(int totalRooms) {
    this->totalRooms = totalRooms;
}

string HostelBlock::getBlockName() const {
    return blockName;
}

string HostelBlock::getWardenName() const {
    return wardenName;
}

int HostelBlock::getTotalRooms() const {
    return totalRooms;
}

vector<Room>& HostelBlock::getRooms() {
    return rooms;
}

bool HostelBlock::matchesBlockName(string searchName) const {
    return blockName == searchName;
}