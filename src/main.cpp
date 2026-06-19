#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <limits>
#include <cstdlib>

// Header files for the Person Folder

#include "person/Person.h"
#include "person/Student.h"
#include "person/Staff.h"
#include "person/Faculty.h"

// Header files for the Library Folder

#include "Library/Book.h"
#include "Library/Journal.h"
#include "Library/LibraryItem.h"
#include "Library/Library.h"

// Header files for the Hostle Folder

#include "hostle/Room.h"
#include "hostle/HostelBlock.h"
#include "hostle/HostelManager.h"

// Header files for the Finance Folder

#include "Finance/FeeRecord.h"
#include "Finance/Invoice.h"

// Header files for the Course Folder

#include "Course/Course.h"
#include "Course/Enrollment.h"
using namespace std;

const string RESET = "\033[0m";
const string BOLD = "\033[1m";
const string CYAN = "\033[36m";
const string GREEN = "\033[32m";
const string YELLOW = "\033[33m";
const string RED = "\033[31m";
const string MAGENTA = "\033[35m";

vector<Course> courses;
vector<Enrollment> enrollments;
vector<Person*> persons;
vector<Book> books;
vector<Journal> journals;
HostelManager hostelManager;
vector<FeeRecord> fees;
vector<Invoice> invoices;

const string COURSE_FILE = "courses.csv";
const string ENROLLMENT_FILE = "enrollment.csv";
const string STUDENT_FILE = "students.csv";
const string FACULTY_FILE = "faculty.csv";
const string STAFF_FILE = "staff.csv";
const string BOOK_FILE = "books.csv";
const string JOURNAL_FILE = "journals.csv";
const string HOSTEL_FILE = "hostel_blocks.csv";
const string FEE_FILE = "fees.csv";
const string INVOICE_FILE = "invoices.csv";

void clearScreen() {
#ifdef _WIN32
    system("cls");

#else
    system("clear");
#endif
}

void header(string title) {
    cout << YELLOW << "===========================================" << RESET << endl;
    cout << BOLD << CYAN << " " << title << RESET << endl;
    cout << YELLOW << "===========================================" << RESET << endl;
}

void pause() {
    cout << " " << GREEN << "Press Enter to Continue...." << RESET;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

int getMenuChoice() {
    int choice;
    cout << BOLD << GREEN << "Enter your Selection = " << RESET;
    cin >> choice;

    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return -1;
    }
    return choice;
}

// Loading all the data from the CSV Files

// Loading the Courses and Enrollment Files
void loadCourses() {
    ifstream file(COURSE_FILE);
    if(!file.is_open()) return;
    while(file.peek() != EOF && file.good()) {
        Course c;
        c.loadFromCSV(file);
        if(!file.fail()) {
            courses.push_back(c);
        }
    }
}

void loadEnrollments() {
    ifstream file(ENROLLMENT_FILE);

    if(!file.is_open()) return;
    while(file.peek() != EOF && file.good()) {
        Enrollment e;
        e.loadFromCSV(file);
        if (!file.fail()) {
            enrollments.push_back(e);
        }
    }
}

// Loading All the Person files including Student, Staff and Faculty

void loadPersons() {
    for(Person* p : persons) delete p;
    persons.clear();

    ifstream sFile(STUDENT_FILE);
    if (sFile.is_open()) {
    while(sFile.peek() != EOF && sFile.good()) {
        Student* s = new Student();
        s->loadFromCSV(sFile);

        if (!sFile.fail()) persons.push_back(s);
        else delete s;
       }
       sFile.close();
    }



    ifstream fFile(FACULTY_FILE);
    if (fFile.is_open()) {
        while(fFile.peek() != EOF && fFile.good()) {
            Faculty* f = new Faculty();
            f->loadFromCSV(fFile);
            if (fFile.fail()) persons.push_back(f);
            else delete f;
        }

        fFile.close();
    }


    ifstream stFile(STAFF_FILE);
    if (stFile.is_open()) {
        while(stFile.peek() != EOF && stFile.good()) {
            Staff* st = new Staff();
            st->loadFromCSV(stFile);
            if (stFile.fail()) persons.push_back(st);
            else delete st;
        }
        stFile.close();
    }
}

// Loading the Library Files
void loadBooks() {
    ifstream file(BOOK_FILE);
    if(!file.is_open()) return;
    while(file.peek() != EOF && file.good()) {
        Book b;
        b.loadFromCSV(file);
        if(!file.fail()) books.push_back(b);
    }
}

void loadJournals() {
    ifstream file(JOURNAL_FILE);
    if(!file.is_open()) return;
    while(file.peek() != EOF && file.good()) {
        Journal j;
        j.loadFromCSV(file);
        if (!file.fail()) journals.push_back(j);
    }
}

// Loading Hostel Files

void loadHostelBlocks() {
    ifstream file(HOSTEL_FILE);
    if(!file.is_open()) return;
    while(file.peek() != EOF && file.good()) {
        HostelBlock block;
        block.loadFromCSV(file);
        if(!file.fail()) hostelManager.addBlock(block);
    }
}

// Loading Fees & Invoices

void loadFees() {
    ifstream file(FEE_FILE);
    if(!file.is_open()) return;
    while(file.peek() != EOF && file.good()) {
        FeeRecord f;
        f.loadFromCSV(file);
        if (!file.fail()) fees.push_back(f);
    }
}

void loadInvoices() {
    ifstream file(INVOICE_FILE);
    if(!file.is_open()) return;
    while(file.peek() != EOF && file.good()) {
        Invoice in;
        in.loadFromCSV(file);
        if (!file.fail()) invoices.push_back(in);
    }
}

void loadAllData() {
    loadCourses();
    loadEnrollments();
    loadPersons();
    loadBooks();
    loadJournals();
    loadHostelBlocks();
    loadFees();
    loadInvoices();
}

// Now Saving all the Data
// Saving the Course Files

void saveCourses() {
    ofstream file(COURSE_FILE);
    for(Course &c : courses)
    c.saveToCSV(file);
}

void saveEnrollments() {
    ofstream file(ENROLLMENT_FILE);
    for(Enrollment &e : enrollments)
    e.saveToCSV(file);
}

// For the Person (Staff, Student, Faculty ) ones

void savePersons() {
    ofstream sFile(STUDENT_FILE);
    ofstream stFile(STAFF_FILE);
    ofstream fFile(FACULTY_FILE);

    for (Person* p : persons) {
        if (!p) continue;

        Student* s = dynamic_cast<Student*>(p);
        if (s) {
            s->saveInCSV(sFile);
            continue;
        }

        Faculty* f = dynamic_cast<Faculty*>(p);
        if (f) {
            s->saveInCSV(fFile);
            continue;
        }

        Staff * st = dynamic_cast<Staff *>(p);
        if (st) {
            st->saveInCSV(stFile);
            continue;
        }
    }

}

// For Books

void saveBooks() {
    ofstream file(BOOK_FILE);
    for(Book &b : books)
    b.saveToCSV(file);
}

void saveJournals() {
    ofstream file(JOURNAL_FILE);
    for (Journal &j : journals)
    j.saveToCSV(file);
}

// For Hostel

void saveHostelBlocks() {
    ofstream file(HOSTEL_FILE);
    for(HostelBlock &block : hostelManager.getBlocks()) {
        block.saveInCSV(file);
    }
}

// For Fee Records 
void saveFees() {
    ofstream file(FEE_FILE);
    for (FeeRecord &f : fees)
    f.saveInCSV(file);
}

void saveInvoices() {
    ofstream file(INVOICE_FILE);
    for (Invoice &in : invoices)
    in.saveInCSV(file);
}

void saveAllData() {
    saveCourses();
    saveEnrollments();
    savePersons();
    saveBooks();
    saveJournals();
    saveHostelBlocks();
    saveFees();
    saveInvoices();
}
 
void cleanPersons() {
    for(Person*p : persons)
    delete p;
    persons.clear();
}
