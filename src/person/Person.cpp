#include "Person.h"

#include <sstream>
#include <stdexcept>
#include <iomanip>
using namespace std;

int Person::nextID = 1;

Person::Person() {
    id = nextID++;
    name = "";
    age = 0;
    contact = "";
    isActive = true;
    type = STUDENT;
}

Person::~Person() {}

void Person::input() {
    cout << "---------- ENTER THE PERSON DETAILS ----------" << endl;
    cin.ignore();

    cout << "Enter Your Name = ";
    getline(cin, name);

    cout << "Enter your Age = ";
    cin >> age;

    if (age <= 0 || age > 100) {
        throw runtime_error("Age Should be in Between 1 & 100");
    }

    cin.ignore();

    cout << "Enter your Personal Contact Number";
    getline(cin, contact);

    int choice;

    cout << "Enter your Type (0 = Student, 1 = Staff, 2 = Faculty) = ";
    cin >> choice;

    type = (PersonType)choice;

    isActive = true;

}

void Person::display() const {

    cout << "==============================" << endl;
    cout << "          PERSON INFO         " << endl;
    cout << "==============================" << endl;

    cout << left << setw(20) << "ID = " << id << endl;
    cout << left << setw(20) << "Person Name = " << name << endl;
    cout << left << setw(20) << "Person Age = " << age << endl;
    cout << left << setw(20) << "Contact Number = " <<  contact << endl;
    cout << left << setw(20) <<  "Enter Your Type = ";

    if (type == STUDENT)
    cout << "Student " << endl;
    
    else if (type == FACULTY)
    cout << "Faculty " << endl;

    else cout << "Staff " << endl;

    cout << left << setw(20) << "Status = " << (isActive ? "Active" : "InActive") << endl;

    cout << "============================" << endl;

}

void Person::saveInCSV(ofstream &csvOutputFile) {

    if  (!csvOutputFile.is_open()) {
        throw runtime_error("File not Opened for Writing");
    }

    csvOutputFile << id << "," << name << ","
                << age << "," << contact << ","
           << isActive << "," << type << endl;
}

void Person::loadFromCSV(ifstream &csvInputFile) {

    string line; // this line will store all the csv load 

    if (!getline(csvInputFile, line))
    return;

    stringstream ss(line);
    string temp;

    getline(ss, temp, ',');
    id = stoi(temp);

    getline(ss, name, ',');

    getline(ss, temp, ',');
    age = stoi(temp);

    getline(ss, contact, ',');

    getline(ss, temp, ',');
    isActive = stoi(temp);

    getline(ss, temp, ',');
    type = (PersonType)stoi(temp);

}

void Person::setData(
    int id,
    string name, 
    int age,
    string contact,
    bool status,
    PersonType type
)

{
    this->id = id;
    this->name = name;
    this-> age = age;
    this->contact = contact;
    this->isActive = status;
    this->type = type;
}

void Person::setName(string name) {
    this->name = name;
}

void Person::setAge(int age) {
    this->age = age;
}

void Person::setContact(string contact) {
    this->contact = contact;
}

void Person::setStatus(bool status) {
    this->isActive = status;
}

void Person::setType(PersonType type) {
    this->type = type;
}


int Person::getId() const {
    return id;
}

string Person::getName() const {
    return name;
}

int Person::getAge() const {
    return age;
}

string Person::getContact() const {
    return contact;
}

bool Person::getStatus() const {
    return isActive;
}

PersonType Person::getType() const {
    return type;
}

bool Person::matchesID(int searchTheID) const {
    return id == searchTheID;
}