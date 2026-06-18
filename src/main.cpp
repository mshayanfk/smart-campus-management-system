#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <limits>

#include "Course/Course.h"
#include "Course/Enrollment.h"
#include "person/Person.h"
#include "person/Student.h"
#include "person/Faculty.h"
#include "person/Staff.h"
#include "Library/Book.h"
#include "Library/Journal.h"
#include "hostle/Room.h"
#include "hostle/HostelBlock.h"
#include "hostle/HostelManager.h"
#include "Finance/FeeRecord.h"
#include "Finance/Invoice.h"
#include "utils/Reports.h"

using namespace std;

/* =========================================================
   GLOBAL DATA  (simple, one container per type)
   ========================================================= */
vector<Course> courses;
vector<Enrollment> enrollments;
vector<Person*> persons;        // Student*, Faculty*, Staff*
vector<Book> books;
vector<Journal> journals;
HostelManager hostelManager;    // blocks + rooms live inside this
vector<FeeRecord> fees;
vector<Invoice> invoices;

/* =========================================================
   FILE NAMES
   ========================================================= */
const string COURSE_FILE     = "courses.csv";
const string ENROLLMENT_FILE = "enrollment.csv";
const string STUDENT_FILE    = "students.csv";
const string FACULTY_FILE    = "faculty.csv";
const string STAFF_FILE      = "staff.csv";
const string BOOK_FILE       = "books.csv";
const string JOURNAL_FILE    = "journals.csv";
const string HOSTEL_FILE     = "hostel_blocks.csv";
const string FEE_FILE        = "fees.csv";
const string INVOICE_FILE    = "invoices.csv";

/* =========================================================
   SMALL HELPERS
   ========================================================= */

// Waits for the user to press Enter so the screen doesn't
// jump straight back to the menu.
void pause() {
    cout << "\nPress Enter to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

// If the user types letters instead of a number, this clears
// the bad input so the program doesn't get stuck in a loop.
int getMenuChoice() {
    int choice;
    cin >> choice;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return -1;
    }
    return choice;
}

/* =========================================================
   LOAD DATA FROM CSV FILES (called once at startup)
   ========================================================= */
void loadCourses() {
    ifstream file(COURSE_FILE);
    if (!file.is_open()) return;
    while (file.peek() != EOF) {
        Course c;
        c.loadFromCSV(file);
        courses.push_back(c);
    }
}

void loadEnrollments() {
    ifstream file(ENROLLMENT_FILE);
    if (!file.is_open()) return;
    while (file.peek() != EOF) {
        Enrollment e;
        e.loadFromCSV(file);
        enrollments.push_back(e);
    }
}

void loadPersons() {
    ifstream sFile(STUDENT_FILE);
    while (sFile.is_open() && sFile.peek() != EOF) {
        Student* s = new Student();
        s->loadFromCSV(sFile);
        persons.push_back(s);
    }

    ifstream fFile(FACULTY_FILE);
    while (fFile.is_open() && fFile.peek() != EOF) {
        Faculty* f = new Faculty();
        f->loadFromCSV(fFile);
        persons.push_back(f);
    }

    ifstream stFile(STAFF_FILE);
    while (stFile.is_open() && stFile.peek() != EOF) {
        Staff* st = new Staff();
        st->loadFromCSV(stFile);
        persons.push_back(st);
    }
}

void loadBooks() {
    ifstream file(BOOK_FILE);
    if (!file.is_open()) return;
    while (file.peek() != EOF) {
        Book b;
        b.loadFromCSV(file);
        books.push_back(b);
    }
}

void loadJournals() {
    ifstream file(JOURNAL_FILE);
    if (!file.is_open()) return;
    while (file.peek() != EOF) {
        Journal j;
        j.loadFromCSV(file);
        journals.push_back(j);
    }
}

void loadHostelBlocks() {
    ifstream file(HOSTEL_FILE);
    if (!file.is_open()) return;
    while (file.peek() != EOF) {
        HostelBlock block;
        block.loadFromCSV(file);
        hostelManager.addBlock(block);
    }
}

void loadFees() {
    ifstream file(FEE_FILE);
    if (!file.is_open()) return;
    while (file.peek() != EOF) {
        FeeRecord f;
        f.loadFromCSV(file);
        fees.push_back(f);
    }
}

void loadInvoices() {
    ifstream file(INVOICE_FILE);
    if (!file.is_open()) return;
    while (file.peek() != EOF) {
        Invoice inv;
        inv.loadFromCSV(file);
        invoices.push_back(inv);
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

/* =========================================================
   SAVE DATA TO CSV FILES (called once before exit)
   ========================================================= */
void saveCourses() {
    ofstream file(COURSE_FILE);
    for (Course &c : courses) c.saveToCSV(file);
}

void saveEnrollments() {
    ofstream file(ENROLLMENT_FILE);
    for (Enrollment &e : enrollments) e.saveToCSV(file);
}

void savePersons() {
    ofstream sFile(STUDENT_FILE);
    ofstream fFile(FACULTY_FILE);
    ofstream stFile(STAFF_FILE);

    for (Person* p : persons) {
        if (p->getType() == STUDENT) {
            Student* s = dynamic_cast<Student*>(p);
            if (s) s->saveInCSV(sFile);
        } else if (p->getType() == FACULTY) {
            Faculty* f = dynamic_cast<Faculty*>(p);
            if (f) f->saveInCSV(fFile);
        } else if (p->getType() == STAFF) {
            Staff* st = dynamic_cast<Staff*>(p);
            if (st) st->saveInCSV(stFile);
        }
    }
}

void saveBooks() {
    ofstream file(BOOK_FILE);
    for (Book &b : books) b.saveToCSV(file);
}

void saveJournals() {
    ofstream file(JOURNAL_FILE);
    for (Journal &j : journals) j.saveToCSV(file);
}

void saveHostelBlocks() {
    ofstream file(HOSTEL_FILE);
    for (HostelBlock &block : hostelManager.getBlocks()) {
        block.saveInCSV(file);
    }
}

void saveFees() {
    ofstream file(FEE_FILE);
    for (FeeRecord &f : fees) f.saveInCSV(file);
}

void saveInvoices() {
    ofstream file(INVOICE_FILE);
    for (Invoice &inv : invoices) inv.saveInCSV(file);
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

// Free the memory used by Student/Faculty/Staff objects before exiting
void cleanupPersons() {
    for (Person* p : persons) delete p;
    persons.clear();
}

/* =========================================================
   ACADEMIC MENU  (Course + Enrollment)
   ========================================================= */
void academicMenu() {
    int choice;
    do {
        cout << "\n===== ACADEMIC MANAGEMENT =====\n";
        cout << "1. Add Course\n";
        cout << "2. View All Courses\n";
        cout << "3. Search Course by Code\n";
        cout << "4. Delete Course by Code\n";
        cout << "5. Add Enrollment\n";
        cout << "6. View All Enrollments\n";
        cout << "7. Search Enrollment by Student ID\n";
        cout << "8. Delete Enrollment by ID\n";
        cout << "0. Back to Main Menu\n";
        cout << "Enter your choice = ";
        choice = getMenuChoice();

        if (choice == 1) {
            Course c;
            try {
                c.input();
                courses.push_back(c);
                cout << "Course added successfully!\n";
            } catch (exception &e) {
                cout << "Error: " << e.what() << endl;
            }
        }
        else if (choice == 2) {
            Reports::generateCourseReport(courses);
        }
        else if (choice == 3) {
            cout << "Enter Course Code = ";
            string code;
            cin.ignore();
            getline(cin, code);
            bool found = false;
            for (Course &c : courses) {
                if (c.matchesCode(code)) { c.display(); found = true; }
            }
            if (!found) cout << "No course found with that code.\n";
        }
        else if (choice == 4) {
            cout << "Enter Course Code to delete = ";
            string code;
            cin.ignore();
            getline(cin, code);
            bool found = false;
            for (size_t i = 0; i < courses.size(); i++) {
                if (courses[i].matchesCode(code)) {
                    courses.erase(courses.begin() + i);
                    cout << "Course deleted!\n";
                    found = true;
                    break;
                }
            }
            if (!found) cout << "No course found with that code.\n";
        }
        else if (choice == 5) {
            Enrollment e;
            try {
                e.input();
                enrollments.push_back(e);
                cout << "Enrollment added successfully!\n";
            } catch (exception &ex) {
                cout << "Error: " << ex.what() << endl;
            }
        }
        else if (choice == 6) {
            Reports::generateEnrollmentReport(enrollments);
        }
        else if (choice == 7) {
            cout << "Enter Student ID = ";
            int sid;
            cin >> sid;
            bool found = false;
            for (Enrollment &e : enrollments) {
                if (e.matchesStudentId(sid)) { e.display(); found = true; }
            }
            if (!found) cout << "No enrollment found for that Student ID.\n";
        }
        else if (choice == 8) {
            cout << "Enter Enrollment ID to delete = ";
            int eid;
            cin >> eid;
            bool found = false;
            for (size_t i = 0; i < enrollments.size(); i++) {
                if (enrollments[i].matchesEnrollmentId(eid)) {
                    enrollments.erase(enrollments.begin() + i);
                    cout << "Enrollment deleted!\n";
                    found = true;
                    break;
                }
            }
            if (!found) cout << "No enrollment found with that ID.\n";
        }
        else if (choice != 0) {
            cout << "Invalid choice!\n";
        }

        if (choice != 0) pause();
    } while (choice != 0);
}

/* =========================================================
   PERSONNEL MENU  (Student / Faculty / Staff)
   ========================================================= */
void personnelMenu() {
    int choice;
    do {
        cout << "\n===== PERSONNEL MANAGEMENT =====\n";
        cout << "1. Add Person\n";
        cout << "2. View All Persons\n";
        cout << "3. Search Person by ID\n";
        cout << "4. Delete Person by ID\n";
        cout << "0. Back to Main Menu\n";
        cout << "Enter your choice = ";
        choice = getMenuChoice();

        if (choice == 1) {
            cout << "Select Type (1 = Student, 2 = Faculty, 3 = Staff) = ";
            int type;
            cin >> type;

            Person* p = nullptr;
            if (type == 1) p = new Student();
            else if (type == 2) p = new Faculty();
            else if (type == 3) p = new Staff();

            if (p == nullptr) {
                cout << "Invalid type!\n";
            } else {
                try {
                    p->input();
                    persons.push_back(p);
                    cout << "Person added successfully!\n";
                } catch (exception &e) {
                    cout << "Error: " << e.what() << endl;
                    delete p;
                }
            }
        }
        else if (choice == 2) {
            Reports::generatePersonReport(persons);
        }
        else if (choice == 3) {
            cout << "Enter ID = ";
            int id;
            cin >> id;
            bool found = false;
            for (Person* p : persons) {
                if (p->matchesID(id)) { p->display(); found = true; }
            }
            if (!found) cout << "No person found with that ID.\n";
        }
        else if (choice == 4) {
            cout << "Enter ID to delete = ";
            int id;
            cin >> id;
            bool found = false;
            for (size_t i = 0; i < persons.size(); i++) {
                if (persons[i]->matchesID(id)) {
                    delete persons[i];
                    persons.erase(persons.begin() + i);
                    cout << "Person deleted!\n";
                    found = true;
                    break;
                }
            }
            if (!found) cout << "No person found with that ID.\n";
        }
        else if (choice != 0) {
            cout << "Invalid choice!\n";
        }

        if (choice != 0) pause();
    } while (choice != 0);
}

/* =========================================================
   LIBRARY MENU  (Book / Journal)
   ========================================================= */
void libraryMenu() {
    int choice;
    do {
        cout << "\n===== LIBRARY MANAGEMENT =====\n";
        cout << "1. Add Book\n";
        cout << "2. View All Books\n";
        cout << "3. Search Book by Author\n";
        cout << "4. Delete Book by ISBN\n";
        cout << "5. Add Journal\n";
        cout << "6. View All Journals\n";
        cout << "7. Search Journal by Name\n";
        cout << "8. Delete Journal by Name\n";
        cout << "0. Back to Main Menu\n";
        cout << "Enter your choice = ";
        choice = getMenuChoice();

        if (choice == 1) {
            Book b;
            try {
                b.input();
                books.push_back(b);
                cout << "Book added successfully!\n";
            } catch (exception &e) {
                cout << "Error: " << e.what() << endl;
            }
        }
        else if (choice == 2) {
            Reports::generateBookReport(books);
        }
        else if (choice == 3) {
            cout << "Enter Author Name = ";
            string author;
            cin.ignore();
            getline(cin, author);
            bool found = false;
            for (Book &b : books) {
                if (b.matchesAuthor(author)) { b.display(); found = true; }
            }
            if (!found) cout << "No book found by that author.\n";
        }
        else if (choice == 4) {
            cout << "Enter ISBN to delete = ";
            string isbn;
            cin.ignore();
            getline(cin, isbn);
            bool found = false;
            for (size_t i = 0; i < books.size(); i++) {
                if (books[i].matchesISBN(isbn)) {
                    books.erase(books.begin() + i);
                    cout << "Book deleted!\n";
                    found = true;
                    break;
                }
            }
            if (!found) cout << "No book found with that ISBN.\n";
        }
        else if (choice == 5) {
            Journal j;
            try {
                j.input();
                journals.push_back(j);
                cout << "Journal added successfully!\n";
            } catch (exception &e) {
                cout << "Error: " << e.what() << endl;
            }
        }
        else if (choice == 6) {
            Reports::generateJournalReport(journals);
        }
        else if (choice == 7) {
            cout << "Enter Journal Name = ";
            string name;
            cin.ignore();
            getline(cin, name);
            bool found = false;
            for (Journal &j : journals) {
                if (j.matchesJournalName(name)) { j.display(); found = true; }
            }
            if (!found) cout << "No journal found with that name.\n";
        }
        else if (choice == 8) {
            cout << "Enter Journal Name to delete = ";
            string name;
            cin.ignore();
            getline(cin, name);
            bool found = false;
            for (size_t i = 0; i < journals.size(); i++) {
                if (journals[i].matchesJournalName(name)) {
                    journals.erase(journals.begin() + i);
                    cout << "Journal deleted!\n";
                    found = true;
                    break;
                }
            }
            if (!found) cout << "No journal found with that name.\n";
        }
        else if (choice != 0) {
            cout << "Invalid choice!\n";
        }

        if (choice != 0) pause();
    } while (choice != 0);
}

/* =========================================================
   HOSTEL MENU  (HostelBlock + Room)
   ========================================================= */
void hostelMenu() {
    int choice;
    do {
        cout << "\n===== HOSTEL MANAGEMENT =====\n";
        cout << "1. Add Hostel Block\n";
        cout << "2. View All Blocks (with Rooms)\n";
        cout << "3. Search Block by Name\n";
        cout << "4. Delete Block by Name\n";
        cout << "5. Add Room to a Block\n";
        cout << "0. Back to Main Menu\n";
        cout << "Enter your choice = ";
        choice = getMenuChoice();

        if (choice == 1) {
            HostelBlock block;
            try {
                block.input();
                hostelManager.addBlock(block);
                cout << "Hostel Block added successfully!\n";
            } catch (exception &e) {
                cout << "Error: " << e.what() << endl;
            }
        }
        else if (choice == 2) {
            vector<HostelBlock> &blocks = hostelManager.getBlocks();
            if (blocks.empty()) {
                cout << "No Hostel Blocks Found.\n";
            } else {
                for (HostelBlock &block : blocks) {
                    block.display();
                    block.displayRooms();
                }
            }
        }
        else if (choice == 3) {
            cout << "Enter Block Name = ";
            string name;
            cin.ignore();
            getline(cin, name);
            hostelManager.searchBlock(name);
        }
        else if (choice == 4) {
            cout << "Enter Block Name to delete = ";
            string name;
            cin.ignore();
            getline(cin, name);
            hostelManager.removeBlock(name);
        }
        else if (choice == 5) {
            vector<HostelBlock> &blocks = hostelManager.getBlocks();
            if (blocks.empty()) {
                cout << "No Hostel Blocks Available! Add a block first.\n";
            } else {
                cout << "Enter Block Name = ";
                string name;
                cin.ignore();
                getline(cin, name);

                bool found = false;
                for (HostelBlock &block : blocks) {
                    if (block.getBlockName() == name) {
                        Room room;
                        try {
                            room.input();
                            block.addRoom(room);
                            cout << "Room added successfully!\n";
                        } catch (exception &e) {
                            cout << "Error: " << e.what() << endl;
                        }
                        found = true;
                        break;
                    }
                }
                if (!found) cout << "No block found with that name.\n";
            }
        }
        else if (choice != 0) {
            cout << "Invalid choice!\n";
        }

        if (choice != 0) pause();
    } while (choice != 0);
}

/* =========================================================
   FINANCE MENU  (FeeRecord + Invoice)
   ========================================================= */
void financeMenu() {
    int choice;
    do {
        cout << "\n===== FINANCE MANAGEMENT =====\n";
        cout << "1. Add Fee Record\n";
        cout << "2. View All Fee Records\n";
        cout << "3. Search Fee Record by Student ID\n";
        cout << "4. Delete Fee Record by Fee ID\n";
        cout << "5. Generate Invoice from Fee Record\n";
        cout << "6. View All Invoices\n";
        cout << "7. Print Invoice Receipt\n";
        cout << "8. Delete Invoice\n";
        cout << "0. Back to Main Menu\n";
        cout << "Enter your choice = ";
        choice = getMenuChoice();

        if (choice == 1) {
            FeeRecord f;
            try {
                f.input();
                fees.push_back(f);
                cout << "Fee Record added successfully!\n";
            } catch (exception &e) {
                cout << "Error: " << e.what() << endl;
            }
        }
        else if (choice == 2) {
            Reports::generateFeeReport(fees);
        }
        else if (choice == 3) {
            cout << "Enter Student ID = ";
            int sid;
            cin >> sid;
            bool found = false;
            for (FeeRecord &f : fees) {
                if (f.matchesStudentID(sid)) { f.display(); found = true; }
            }
            if (!found) cout << "No fee record found for that Student ID.\n";
        }
        else if (choice == 4) {
            cout << "Enter Fee ID to delete = ";
            int fid;
            cin >> fid;
            bool found = false;
            for (size_t i = 0; i < fees.size(); i++) {
                if (fees[i].matchesFeeID(fid)) {
                    fees.erase(fees.begin() + i);
                    cout << "Fee Record deleted!\n";
                    found = true;
                    break;
                }
            }
            if (!found) cout << "No fee record found with that ID.\n";
        }
        else if (choice == 5) {
            cout << "Enter Fee ID = ";
            int fid;
            cin >> fid;

            bool found = false;
            for (FeeRecord &f : fees) {
                if (f.matchesFeeID(fid)) {
                    Invoice inv;
                    int invID;
                    string date;

                    cout << "Enter Invoice ID = ";
                    cin >> invID;
                    cin.ignore();
                    cout << "Enter Issue Date (DD-MM-YYYY) = ";
                    getline(cin, date);

                    inv.setInvoiceID(invID);
                    inv.setIssueDate(date);
                    inv.generateInvoice(f);

                    invoices.push_back(inv);
                    cout << "Invoice generated successfully!\n";
                    found = true;
                    break;
                }
            }
            if (!found) cout << "No fee record found with that ID.\n";
        }
        else if (choice == 6) {
            Reports::generateInvoiceReport(invoices);
        }
        else if (choice == 7) {
            cout << "Enter Invoice ID = ";
            int invID;
            cin >> invID;
            bool found = false;
            for (Invoice &inv : invoices) {
                if (inv.getInvoiceID() == invID) {
                    inv.printReceipt();
                    found = true;
                    break;
                }
            }
            if (!found) cout << "No invoice found with that ID.\n";
        }
        else if (choice == 8) {
            cout << "Enter Invoice ID to delete = ";
            int invID;
            cin >> invID;
            bool found = false;
            for (size_t i = 0; i < invoices.size(); i++) {
                if (invoices[i].getInvoiceID() == invID) {
                    invoices.erase(invoices.begin() + i);
                    cout << "Invoice deleted!\n";
                    found = true;
                    break;
                }
            }
            if (!found) cout << "No invoice found with that ID.\n";
        }
        else if (choice != 0) {
            cout << "Invalid choice!\n";
        }

        if (choice != 0) pause();
    } while (choice != 0);
}

/* =========================================================
   REPORTS MENU
   ========================================================= */
void reportsMenu() {
    int choice;
    do {
        cout << "\n===== REPORTS =====\n";
        cout << "1. Person Report\n";
        cout << "2. Course Report\n";
        cout << "3. Enrollment Report\n";
        cout << "4. Book Report\n";
        cout << "5. Journal Report\n";
        cout << "6. Hostel Block Report\n";
        cout << "7. Fee Report\n";
        cout << "8. Invoice Report\n";
        cout << "9. Full System Summary\n";
        cout << "0. Back to Main Menu\n";
        cout << "Enter your choice = ";
        choice = getMenuChoice();

        if (choice == 1) Reports::generatePersonReport(persons);
        else if (choice == 2) Reports::generateCourseReport(courses);
        else if (choice == 3) Reports::generateEnrollmentReport(enrollments);
        else if (choice == 4) Reports::generateBookReport(books);
        else if (choice == 5) Reports::generateJournalReport(journals);
        else if (choice == 6) Reports::generateHostelBlockReport(hostelManager.getBlocks());
        else if (choice == 7) Reports::generateFeeReport(fees);
        else if (choice == 8) Reports::generateInvoiceReport(invoices);
        else if (choice == 9) {
            int totalRooms = 0;
            for (HostelBlock &block : hostelManager.getBlocks()) {
                totalRooms += block.getRooms().size();
            }
            cout << "\n===== SYSTEM SUMMARY =====\n";
            cout << "Persons      = " << persons.size() << endl;
            cout << "Courses      = " << courses.size() << endl;
            cout << "Enrollments  = " << enrollments.size() << endl;
            cout << "Hostel Blocks= " << hostelManager.getBlocks().size() << endl;
            cout << "Rooms        = " << totalRooms << endl;
            cout << "Books        = " << books.size() << endl;
            cout << "Journals     = " << journals.size() << endl;
            cout << "Fee Records  = " << fees.size() << endl;
            cout << "Invoices     = " << invoices.size() << endl;
        }
        else if (choice != 0) {
            cout << "Invalid choice!\n";
        }

        if (choice != 0) pause();
    } while (choice != 0);
}

/* =========================================================
   MAIN MENU
   ========================================================= */
void mainMenu() {
    int choice;
    do {
        cout << "\n=========================================\n";
        cout << "   SMART CAMPUS MANAGEMENT SYSTEM\n";
        cout << "=========================================\n";
        cout << "1. Academic Management\n";
        cout << "2. Personnel Management\n";
        cout << "3. Library Management\n";
        cout << "4. Hostel Management\n";
        cout << "5. Finance Management\n";
        cout << "6. Reports\n";
        cout << "0. Save & Exit\n";
        cout << "=========================================\n";
        cout << "Enter your choice = ";
        choice = getMenuChoice();

        if (choice == 1) academicMenu();
        else if (choice == 2) personnelMenu();
        else if (choice == 3) libraryMenu();
        else if (choice == 4) hostelMenu();
        else if (choice == 5) financeMenu();
        else if (choice == 6) reportsMenu();
        else if (choice == 0) cout << "Saving data...\n";
        else {
            cout << "Invalid choice!\n";
            pause();
        }
    } while (choice != 0);
}

/* =========================================================
   PROGRAM START
   ========================================================= */
int main() {
    // Flush cout after every print so prompts always show up
    // before the program waits for input.
    cout << unitbuf;

    loadAllData();
    mainMenu();
    saveAllData();
    cleanupPersons();

    cout << "All data saved successfully. Goodbye!\n";
    return 0;
}