#include "Room.h"

#include <iostream>
#include <iomanip>
#include <sstream>
#include <stdexcept>
using namespace std;

Room::Room() {
    roomNumber = 0;
    roomType = "";
    capacity = 0;
    isOccupied = false;
    roomRent = 0.0;
    occupantName = "";
    
}

Room::~Room() {}

void Room::input() {

    cout << "========================================" << endl;
    cout << "----------- Room Information -----------" << endl;
    cout << "========================================" << endl;

    cout << "Enter the Room Number = ";
    cin >> roomNumber;

    if (roomNumber <= 0) {
        throw runtime_error("Invalid Number");
    }

    cin.ignore();

    cout << "Enter your Room Type (Single/Double/Triple) = ";
    getline(cin, roomType);

    cout << "Enter Room Capacity = ";
    cin >> capacity;

    if (capacity <= 0) {
        throw runtime_error("Invalid Capacity");
    }

    if (capacity > 3) {
        throw runtime_error("Room is Already Full");
    }

    cout << "Enter your Room Rent = ";
    cin >> roomRent;

    if (roomRent < 0) {
        throw runtime_error("Invalid Room Rent");
    }

    cout << "Is Your Room Occupied? (1 = Yes, 0 = No) = ";
    cin >> isOccupied;

    cin.ignore();

    if (!isOccupied) {
        cout << "Enter Occupant Name = ";
        getline(cin, occupantName);
    }
    
    else {
        occupantName = "";
    }
}


void Room::display() const {

    cout << "========================================" << endl;
    cout << "------------- ROOM DETAILS -------------" << endl;
    cout << "========================================" << endl;

    cout << left << setw(25) << "Room Number = " << roomNumber << endl;
    cout << left << setw(25) << "Room Type = " << roomType << endl;
    cout << left << setw(25) << "Capacity = " << capacity << endl;
    cout << left << setw(25) << "Room Rent = " << roomRent << endl;
    cout << left << setw(25) << "Status = " << (isOccupied ? "Occupied" : "Available") << endl;
    cout << left << setw(25) << "Occupant Name = " << (occupantName.empty() ? "None" : occupantName) << endl;

    cout << "=========================================" << endl;
}

void Room::saveInCSV(ofstream &csvOutputFile) {

    if (!csvOutputFile.is_open()) {
        throw runtime_error("File not Opened for Writing");
    }

    csvOutputFile << roomNumber << "," << roomType << ","
    <<  capacity << "," << isOccupied << "," << roomRent << ","
    << occupantName << endl;

}

void Room::loadFromCSV(ifstream &csvInputFile) {
    string line;

    if (!getline(csvInputFile, line))
    return;

    stringstream sh(line);
    string temp;

    getline(sh, temp, ',');
    roomNumber = stoi(temp);

    getline(sh, roomType, ',');

    getline(sh, temp, ',');
    capacity = stoi(temp);

    getline(sh, temp, ',');
    isOccupied = stoi(temp);

    getline(sh, temp, ',');
    roomRent = stoi(temp);

    getline(sh, occupantName, ',');
}

void Room::setRoomNumber(int roomNumber) {
    this->roomNumber = roomNumber;
}

void Room::setRoomType(string roomType) {
    this->roomType = roomType;
}

void Room::setCapacity(int capacity) {
    this->capacity = capacity;
}

void Room::setOccupied(bool isOccupied) {
    this->isOccupied = isOccupied;
}

void Room::setRoomRent(double roomRent) {
    this->roomRent = roomRent;
}

void Room::setOccupantName(string occupantName) {
    this->occupantName = occupantName;
}

int Room::getRoomNumber() const {
    return roomNumber;
}

string Room::getRoomType() const {
    return roomType;
}

int Room::getCapacity() const {
    return capacity;
}

bool Room::getOccupied() const {
    return isOccupied;
}

double Room::getRoomRent() const {
    return roomRent;
}

string Room::getOccupantName() const {
    return occupantName;
}