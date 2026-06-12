#ifndef ROOM_H
#define ROOM_H
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Room {
    private:

    int roomNumber;
    string roomType;
    int capacity;
    bool isOccupied;
    double roomRent;
    string occupantName;

    public:

    Room();
    ~Room();

    void input();
    void display() const;

    void saveInCSV(ofstream &csvOutputFile) const;
    void loadFromCSV(ifstream &csvInputFile);

     void setData(
        int roomNumber,
        string roomType,
        int capacity,
        bool isOccupied,
        double roomRent,
        string occupantName
    );

    void setRoomNumber(int roomNumber);
    void setRoomType(string roomType);
    void setCapacity(int capacity);
    void setOccupied(bool isOccupied);
    void setRoomRent(double roomRent);
    void setOccupantName(string occupantName);

    int getRoomNumber() const;
    string getRoomType() const;
    int getCapacity() const;
    bool getOccupied() const;
    double getRoomRent() const;
    string  getOccupantName() const;
    
    bool matchesRoomNumber(int searchNumber) const;
    
};

#endif