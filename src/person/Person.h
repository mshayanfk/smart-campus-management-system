#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

enum PersonType {
    STUDENT,
    FACULTY,
    STAFF
};

class Person {
    protected:

    static int nextID;
    int id;
    string name;
    int age;
    string contact;
    bool isActive;
    PersonType type;

    public:
    Person(); 
    virtual ~Person();

    virtual void input();
    virtual void display() const;

    // This part is for the File Handling

    virtual void saveInCSV(std::ofstream &csvOutputFile);
    virtual void loadFromCSV(std::ifstream &csvInputFile);

    void setData(
        int id,
        string name,
        int age,
        string contact,
        bool status,
        PersonType type
    );

    // Setters

    void setName(string name);
    void setAge(int age);
    void setContact(string contact);
    void setStatus(bool status);
    void setType(PersonType type);

    // Getters

    int getId() const;
    string getName() const;
    int getAge() const;
    string getContact() const;
    bool getStatus() const;
    PersonType getType() const;

    bool matchesID(int searchTheID) const;
};

#endif