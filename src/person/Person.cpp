#include <Person.h>

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

    if (!age) return;

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
