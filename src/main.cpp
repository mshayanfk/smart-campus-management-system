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
}

