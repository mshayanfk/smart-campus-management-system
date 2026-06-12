#ifndef HOSTELBLOCK_H
#define HOSTELBLOCK_H
#include "Room.h"

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

class HostelBlock
{
private:
    string blockName;
    string wardenName;
    int totalRooms;

    vector<Room> rooms;

public:
    HostelBlock();
    ~HostelBlock();

    void input();
    void display() const;

    void addRoom(const Room &room);
    void displayRooms() const;

    void saveInCSV(ofstream &csvOutputFile) const;
    void loadFromCSV(ifstream &csvInputFile);

    void setData(string blockName, 
    string wardenName, 
    int totalRooms);

    void setBlockName(string blockName);
    void setWardenName(string wardenName);
    void setTotalRooms(int totalRooms);

    string getBlockName() const;
    string getWardenName() const;
    int getTotalRooms() const;

    vector<Room> &getRooms();

    bool matchesBlockName(string searchName) const;
};
#endif