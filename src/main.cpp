#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <limits>
#include <stdexcept>

#include "Person.h"
#include "Student.h"
#include "Faculty.h"
#include "Staff.h"
#include "Course.h"
#include "Enrollment.h"
#include "FeeRecord.h"
#include "Invoice.h"
#include "Room.h"
#include "HostelBlock.h"
#include "HostelManager.h"
#include "Library.h"
#include "LibraryItem.h"
#include "Book.h"
#include "Journal.h"
#include "Reports.h"

using namespace std;

// ─────────────────────────────────────────────
//  Global Data Stores
// ─────────────────────────────────────────────
vector<Student> students;
vector<Faculty> facultyList;
vector<Staff> staffList;
vector<Course> courses;
vector<Enrollment> enrollments;
vector<FeeRecord> feeRecords;
vector<Invoice> invoices;
vector<Room> rooms;
HostelManager hostelManager;
vector<Book> books;
vector<Journal> journals;
vector<Library> libraryItems;

// ─────────────────────────────────────────────
//  Utility Helpers
// ─────────────────────────────────────────────
void clearInput()
{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void pauseScreen()
{
    cout << "\nPress Enter to continue...";
    clearInput();
    cin.get();
}

void printHeader(const string &title)
{
    cout << "\n╔══════════════════════════════════════╗" << endl;
    cout << "║  " << left << setw(36) << title << "║" << endl;
    cout << "╚══════════════════════════════════════╝" << endl;
}

// ─────────────────────────────────────────────
//  CSV File Names
// ─────────────────────────────────────────────
const string FILE_STUDENTS = "students.csv";
const string FILE_FACULTY = "faculty.csv";
const string FILE_STAFF = "staff.csv";
const string FILE_COURSES = "courses.csv";
const string FILE_ENROLLMENTS = "enrollments.csv";
const string FILE_FEES = "fees.csv";
const string FILE_INVOICES = "invoices.csv";
const string FILE_ROOMS = "rooms.csv";
const string FILE_HOSTEL = "hostel_blocks.csv";
const string FILE_BOOKS = "books.csv";
const string FILE_JOURNALS = "journals.csv";
const string FILE_LIBRARY = "library.csv";

// ─────────────────────────────────────────────
//  Save / Load All
// ─────────────────────────────────────────────
void saveAllData()
{
    try
    {
        {
            ofstream f(FILE_STUDENTS);
            for (auto &s : students)
                s.saveInCSV(f);
        }
        {
            ofstream f(FILE_FACULTY);
            for (auto &fa : facultyList)
                fa.saveInCSV(f);
        }
        {
            ofstream f(FILE_STAFF);
            for (auto &st : staffList)
                st.saveInCSV(f);
        }
        {
            ofstream f(FILE_COURSES);
            for (auto &c : courses)
                c.saveToCSV(f);
        }
        {
            ofstream f(FILE_ENROLLMENTS);
            for (auto &e : enrollments)
                e.saveToCSV(f);
        }
        {
            ofstream f(FILE_FEES);
            for (auto &fr : feeRecords)
                fr.saveInCSV(f);
        }
        {
            ofstream f(FILE_INVOICES);
            for (auto &inv : invoices)
                inv.saveInCSV(f);
        }
        {
            ofstream f(FILE_ROOMS);
            for (auto &r : rooms)
                r.saveInCSV(f);
        }
        {
            ofstream f(FILE_HOSTEL);
            hostelManager.saveInCSV(f);
        }
        {
            ofstream f(FILE_BOOKS);
            for (auto &b : books)
                b.saveToCSV(f);
        }
        {
            ofstream f(FILE_JOURNALS);
            for (auto &j : journals)
                j.saveToCSV(f);
        }
        {
            ofstream f(FILE_LIBRARY);
            for (auto &l : libraryItems)
                l.saveToCSV(f);
        }
        cout << "✔ All data saved successfully." << endl;
    }
    catch (const exception &e)
    {
        cerr << "Save error: " << e.what() << endl;
    }
}

void loadAllData()
{
    try
    {
        {
            ifstream f(FILE_STUDENTS);
            while (f.peek() != EOF)
            {
                Student s;
                s.loadFromCSV(f);
                if (f)
                    students.push_back(s);
            }
        }
        {
            ifstream f(FILE_FACULTY);
            while (f.peek() != EOF)
            {
                Faculty fa;
                fa.loadFromCSV(f);
                if (f)
                    facultyList.push_back(fa);
            }
        }
        {
            ifstream f(FILE_STAFF);
            while (f.peek() != EOF)
            {
                Staff st;
                st.loadFromCSV(f);
                if (f)
                    staffList.push_back(st);
            }
        }
        {
            ifstream f(FILE_COURSES);
            while (f.peek() != EOF)
            {
                Course c;
                c.loadFromCSV(f);
                if (f)
                    courses.push_back(c);
            }
        }
        {
            ifstream f(FILE_ENROLLMENTS);
            while (f.peek() != EOF)
            {
                Enrollment e;
                e.loadFromCSV(f);
                if (f)
                    enrollments.push_back(e);
            }
        }
        {
            ifstream f(FILE_FEES);
            while (f.peek() != EOF)
            {
                FeeRecord fr;
                fr.loadFromCSV(f);
                if (f)
                    feeRecords.push_back(fr);
            }
        }
        {
            ifstream f(FILE_INVOICES);
            while (f.peek() != EOF)
            {
                Invoice inv;
                inv.loadFromCSV(f);
                if (f)
                    invoices.push_back(inv);
            }
        }
        {
            ifstream f(FILE_ROOMS);
            while (f.peek() != EOF)
            {
                Room r;
                r.loadFromCSV(f);
                if (f)
                    rooms.push_back(r);
            }
        }
        {
            ifstream f(FILE_HOSTEL);
            hostelManager.loadFromCSV(f);
        }
        {
            ifstream f(FILE_BOOKS);
            while (f.peek() != EOF)
            {
                Book b;
                b.loadFromCSV(f);
                if (f)
                    books.push_back(b);
            }
        }
        {
            ifstream f(FILE_JOURNALS);
            while (f.peek() != EOF)
            {
                Journal j;
                j.loadFromCSV(f);
                if (f)
                    journals.push_back(j);
            }
        }
        {
            ifstream f(FILE_LIBRARY);
            while (f.peek() != EOF)
            {
                Library l;
                l.loadFromCSV(f);
                if (f)
                    libraryItems.push_back(l);
            }
        }
        cout << "✔ All data loaded successfully." << endl;
    }
    catch (const exception &e)
    {
        cerr << "Load error: " << e.what() << endl;
    }
}

// ─────────────────────────────────────────────
//  Student Menu
// ─────────────────────────────────────────────
void studentMenu()
{
    int choice;
    do
    {
        printHeader("STUDENT MANAGEMENT");
        cout << " 1. Add Student\n";
        cout << " 2. Display All Students\n";
        cout << " 3. Search Student by ID\n";
        cout << " 4. Delete Student\n";
        cout << " 0. Back\n";
        cout << "Choice: ";
        cin >> choice;
        clearInput();

        if (choice == 1)
        {
            try
            {
                Student s;
                s.input();
                students.push_back(s);
                cout << "✔ Student added." << endl;
            }
            catch (const exception &e)
            {
                cerr << "Error: " << e.what() << endl;
            }
        }
        else if (choice == 2)
        {
            if (students.empty())
            {
                cout << "No students found.\n";
            }
            else
                for (auto &s : students)
                    s.display();
        }
        else if (choice == 3)
        {
            int id;
            cout << "Enter Student ID: ";
            cin >> id;
            clearInput();
            bool found = false;
            for (auto &s : students)
                if (s.matchesID(id))
                {
                    s.display();
                    found = true;
                    break;
                }
            if (!found)
                cout << "Student not found.\n";
        }
        else if (choice == 4)
        {
            int id;
            cout << "Enter Student ID to delete: ";
            cin >> id;
            clearInput();
            for (auto it = students.begin(); it != students.end(); ++it)
            {
                if (it->matchesID(id))
                {
                    students.erase(it);
                    cout << "✔ Student deleted.\n";
                    break;
                }
            }
        }
        if (choice != 0)
            pauseScreen();
    } while (choice != 0);
}

// ─────────────────────────────────────────────
//  Faculty Menu
// ─────────────────────────────────────────────
void facultyMenu()
{
    int choice;
    do
    {
        printHeader("FACULTY MANAGEMENT");
        cout << " 1. Add Faculty\n";
        cout << " 2. Display All Faculty\n";
        cout << " 3. Search Faculty by ID\n";
        cout << " 4. Delete Faculty\n";
        cout << " 0. Back\n";
        cout << "Choice: ";
        cin >> choice;
        clearInput();

        if (choice == 1)
        {
            try
            {
                Faculty fa;
                fa.input();
                facultyList.push_back(fa);
                cout << "✔ Faculty added." << endl;
            }
            catch (const exception &e)
            {
                cerr << "Error: " << e.what() << endl;
            }
        }
        else if (choice == 2)
        {
            if (facultyList.empty())
                cout << "No faculty found.\n";
            else
                for (auto &fa : facultyList)
                    fa.display();
        }
        else if (choice == 3)
        {
            int id;
            cout << "Enter Faculty ID: ";
            cin >> id;
            clearInput();
            bool found = false;
            for (auto &fa : facultyList)
                if (fa.matchesID(id))
                {
                    fa.display();
                    found = true;
                    break;
                }
            if (!found)
                cout << "Faculty not found.\n";
        }
        else if (choice == 4)
        {
            int id;
            cout << "Enter Faculty ID to delete: ";
            cin >> id;
            clearInput();
            for (auto it = facultyList.begin(); it != facultyList.end(); ++it)
            {
                if (it->matchesID(id))
                {
                    facultyList.erase(it);
                    cout << "✔ Faculty deleted.\n";
                    break;
                }
            }
        }
        if (choice != 0)
            pauseScreen();
    } while (choice != 0);
}

// ─────────────────────────────────────────────
//  Staff Menu
// ─────────────────────────────────────────────
void staffMenu()
{
    int choice;
    do
    {
        printHeader("STAFF MANAGEMENT");
        cout << " 1. Add Staff\n";
        cout << " 2. Display All Staff\n";
        cout << " 3. Search Staff by ID\n";
        cout << " 4. Delete Staff\n";
        cout << " 0. Back\n";
        cout << "Choice: ";
        cin >> choice;
        clearInput();

        if (choice == 1)
        {
            try
            {
                Staff st;
                st.input();
                staffList.push_back(st);
                cout << "✔ Staff added." << endl;
            }
            catch (const exception &e)
            {
                cerr << "Error: " << e.what() << endl;
            }
        }
        else if (choice == 2)
        {
            if (staffList.empty())
                cout << "No staff found.\n";
            else
                for (auto &st : staffList)
                    st.display();
        }
        else if (choice == 3)
        {
            int id;
            cout << "Enter Staff ID: ";
            cin >> id;
            clearInput();
            bool found = false;
            for (auto &st : staffList)
                if (st.matchesID(id))
                {
                    st.display();
                    found = true;
                    break;
                }
            if (!found)
                cout << "Staff not found.\n";
        }
        else if (choice == 4)
        {
            int id;
            cout << "Enter Staff ID to delete: ";
            cin >> id;
            clearInput();
            for (auto it = staffList.begin(); it != staffList.end(); ++it)
            {
                if (it->matchesID(id))
                {
                    staffList.erase(it);
                    cout << "✔ Staff deleted.\n";
                    break;
                }
            }
        }
        if (choice != 0)
            pauseScreen();
    } while (choice != 0);
}

// ─────────────────────────────────────────────
//  Course Menu
// ─────────────────────────────────────────────
void courseMenu()
{
    int choice;
    do
    {
        printHeader("COURSE MANAGEMENT");
        cout << " 1. Add Course\n";
        cout << " 2. Display All Courses\n";
        cout << " 3. Search Course by Code\n";
        cout << " 4. Delete Course\n";
        cout << " 0. Back\n";
        cout << "Choice: ";
        cin >> choice;
        clearInput();

        if (choice == 1)
        {
            try
            {
                Course c;
                c.input();
                courses.push_back(c);
                cout << "✔ Course added." << endl;
            }
            catch (const exception &e)
            {
                cerr << "Error: " << e.what() << endl;
            }
        }
        else if (choice == 2)
        {
            if (courses.empty())
                cout << "No courses found.\n";
            else
                for (auto &c : courses)
                    c.display();
        }
        else if (choice == 3)
        {
            string code;
            cout << "Enter Course Code: ";
            getline(cin, code);
            bool found = false;
            for (auto &c : courses)
                if (c.matchesCode(code))
                {
                    c.display();
                    found = true;
                    break;
                }
            if (!found)
                cout << "Course not found.\n";
        }
        else if (choice == 4)
        {
            string code;
            cout << "Enter Course Code to delete: ";
            getline(cin, code);
            for (auto it = courses.begin(); it != courses.end(); ++it)
            {
                if (it->matchesCode(code))
                {
                    courses.erase(it);
                    cout << "✔ Course deleted.\n";
                    break;
                }
            }
        }
        if (choice != 0)
            pauseScreen();
    } while (choice != 0);
}

// ─────────────────────────────────────────────
//  Enrollment Menu
// ─────────────────────────────────────────────
void enrollmentMenu()
{
    int choice;
    do
    {
        printHeader("ENROLLMENT MANAGEMENT");
        cout << " 1. Add Enrollment\n";
        cout << " 2. Display All Enrollments\n";
        cout << " 3. Search by Enrollment ID\n";
        cout << " 4. Search by Student ID\n";
        cout << " 5. Search by Course Code\n";
        cout << " 0. Back\n";
        cout << "Choice: ";
        cin >> choice;
        clearInput();

        if (choice == 1)
        {
            try
            {
                Enrollment e;
                e.input();
                enrollments.push_back(e);
                cout << "✔ Enrollment added." << endl;
            }
            catch (const exception &e)
            {
                cerr << "Error: " << e.what() << endl;
            }
        }
        else if (choice == 2)
        {
            if (enrollments.empty())
                cout << "No enrollments found.\n";
            else
                for (auto &e : enrollments)
                    e.display();
        }
        else if (choice == 3)
        {
            int id;
            cout << "Enter Enrollment ID: ";
            cin >> id;
            clearInput();
            bool found = false;
            for (auto &e : enrollments)
                if (e.matchesEnrollmentId(id))
                {
                    e.display();
                    found = true;
                }
            if (!found)
                cout << "Not found.\n";
        }
        else if (choice == 4)
        {
            int id;
            cout << "Enter Student ID: ";
            cin >> id;
            clearInput();
            bool found = false;
            for (auto &e : enrollments)
                if (e.matchesStudentId(id))
                {
                    e.display();
                    found = true;
                }
            if (!found)
                cout << "Not found.\n";
        }
        else if (choice == 5)
        {
            string code;
            cout << "Enter Course Code: ";
            getline(cin, code);
            bool found = false;
            for (auto &e : enrollments)
                if (e.matchesCourseCode(code))
                {
                    e.display();
                    found = true;
                }
            if (!found)
                cout << "Not found.\n";
        }
        if (choice != 0)
            pauseScreen();
    } while (choice != 0);
}

// ─────────────────────────────────────────────
//  Fee & Invoice Menu
// ─────────────────────────────────────────────
void feeMenu()
{
    int choice;
    do
    {
        printHeader("FEE & INVOICE MANAGEMENT");
        cout << " 1. Add Fee Record\n";
        cout << " 2. Display All Fee Records\n";
        cout << " 3. Generate Invoice from Fee Record\n";
        cout << " 4. Display All Invoices\n";
        cout << " 5. Print Receipt (by Invoice ID)\n";
        cout << " 0. Back\n";
        cout << "Choice: ";
        cin >> choice;
        clearInput();

        if (choice == 1)
        {
            try
            {
                FeeRecord fr;
                fr.input();
                feeRecords.push_back(fr);
                cout << "✔ Fee record added." << endl;
            }
            catch (const exception &e)
            {
                cerr << "Error: " << e.what() << endl;
            }
        }
        else if (choice == 2)
        {
            if (feeRecords.empty())
                cout << "No fee records found.\n";
            else
                for (auto &fr : feeRecords)
                    fr.display();
        }
        else if (choice == 3)
        {
            int feeID;
            cout << "Enter Fee ID to generate invoice from: ";
            cin >> feeID;
            clearInput();
            bool found = false;
            for (auto &fr : feeRecords)
            {
                if (fr.getFeeID() == feeID)
                {
                    Invoice inv;
                    cout << "Enter Invoice ID: ";
                    cin >> feeID;
                    clearInput();
                    inv.setInvoiceID(feeID);
                    string date;
                    cout << "Enter Issue Date (DD-MM-YYYY): ";
                    getline(cin, date);
                    inv.setIssuDate(date);
                    inv.generateInvoice(fr);
                    invoices.push_back(inv);
                    cout << "✔ Invoice generated." << endl;
                    inv.display();
                    found = true;
                    break;
                }
            }
            if (!found)
                cout << "Fee record not found.\n";
        }
        else if (choice == 4)
        {
            if (invoices.empty())
                cout << "No invoices found.\n";
            else
                for (auto &inv : invoices)
                    inv.display();
        }
        else if (choice == 5)
        {
            int id;
            cout << "Enter Invoice ID: ";
            cin >> id;
            clearInput();
            bool found = false;
            for (auto &inv : invoices)
                if (inv.getInvoiceID() == id)
                {
                    inv.printReceipt();
                    found = true;
                    break;
                }
            if (!found)
                cout << "Invoice not found.\n";
        }
        if (choice != 0)
            pauseScreen();
    } while (choice != 0);
}

// ─────────────────────────────────────────────
//  Hostel Menu
// ─────────────────────────────────────────────
void hostelMenu()
{
    int choice;
    do
    {
        printHeader("HOSTEL MANAGEMENT");
        cout << " 1. Add Hostel Block\n";
        cout << " 2. Display All Blocks\n";
        cout << " 3. Search Block by Name\n";
        cout << " 4. Add Room (standalone)\n";
        cout << " 5. Display All Rooms\n";
        cout << " 0. Back\n";
        cout << "Choice: ";
        cin >> choice;
        clearInput();

        if (choice == 1)
        {
            try
            {
                HostelBlock block;
                block.input();
                hostelManager.addBlock(block);
                cout << "✔ Block added." << endl;
            }
            catch (const exception &e)
            {
                cerr << "Error: " << e.what() << endl;
            }
        }
        else if (choice == 2)
        {
            hostelManager.displayAllBlocks();
        }
        else if (choice == 3)
        {
            string name;
            cout << "Enter Block Name: ";
            getline(cin, name);
            hostelManager.searchBlock(name);
        }
        else if (choice == 4)
        {
            try
            {
                Room r;
                r.input();
                rooms.push_back(r);
                cout << "✔ Room added." << endl;
            }
            catch (const exception &e)
            {
                cerr << "Error: " << e.what() << endl;
            }
        }
        else if (choice == 5)
        {
            if (rooms.empty())
                cout << "No rooms found.\n";
            else
                for (auto &r : rooms)
                    r.display();
        }
        if (choice != 0)
            pauseScreen();
    } while (choice != 0);
}

// ─────────────────────────────────────────────
//  Library Menu
// ─────────────────────────────────────────────
void libraryMenu()
{
    int choice;
    do
    {
        printHeader("LIBRARY MANAGEMENT");
        cout << " 1. Add Book\n";
        cout << " 2. Add Journal\n";
        cout << " 3. Add Library Item\n";
        cout << " 4. Display All Books\n";
        cout << " 5. Display All Journals\n";
        cout << " 6. Display All Library Items\n";
        cout << " 7. Search Book by Author\n";
        cout << " 8. Search Book by ISBN\n";
        cout << " 0. Back\n";
        cout << "Choice: ";
        cin >> choice;
        clearInput();

        if (choice == 1)
        {
            try
            {
                Book b;
                b.input();
                books.push_back(b);
                cout << "✔ Book added." << endl;
            }
            catch (const exception &e)
            {
                cerr << "Error: " << e.what() << endl;
            }
        }
        else if (choice == 2)
        {
            try
            {
                Journal j;
                j.input();
                journals.push_back(j);
                cout << "✔ Journal added." << endl;
            }
            catch (const exception &e)
            {
                cerr << "Error: " << e.what() << endl;
            }
        }
        else if (choice == 3)
        {
            try
            {
                Library l;
                l.input();
                libraryItems.push_back(l);
                cout << "✔ Library item added." << endl;
            }
            catch (const exception &e)
            {
                cerr << "Error: " << e.what() << endl;
            }
        }
        else if (choice == 4)
        {
            if (books.empty())
                cout << "No books found.\n";
            else
                for (auto &b : books)
                    b.display();
        }
        else if (choice == 5)
        {
            if (journals.empty())
                cout << "No journals found.\n";
            else
                for (auto &j : journals)
                    j.display();
        }
        else if (choice == 6)
        {
            if (libraryItems.empty())
                cout << "No library items found.\n";
            else
                for (auto &l : libraryItems)
                    l.display();
        }
        else if (choice == 7)
        {
            string author;
            cout << "Enter Author Name: ";
            getline(cin, author);
            bool found = false;
            for (auto &b : books)
                if (b.matchesAuthor(author))
                {
                    b.display();
                    found = true;
                }
            if (!found)
                cout << "No books by that author.\n";
        }
        else if (choice == 8)
        {
            string isbn;
            cout << "Enter ISBN: ";
            getline(cin, isbn);
            bool found = false;
            for (auto &b : books)
                if (b.matchesISBN(isbn))
                {
                    b.display();
                    found = true;
                    break;
                }
            if (!found)
                cout << "Book not found.\n";
        }
        if (choice != 0)
            pauseScreen();
    } while (choice != 0);
}

// ─────────────────────────────────────────────
//  Reports Menu
// ─────────────────────────────────────────────
void reportsMenu()
{
    // Build Person vectors for Reports (polymorphic version not available, so pass each)
    int choice;
    do
    {
        printHeader("REPORTS");
        cout << " 1. Student Report\n";
        cout << " 2. Course Report\n";
        cout << " 3. Enrollment Report\n";
        cout << " 4. Room Report\n";
        cout << " 5. Hostel Block Report\n";
        cout << " 6. Book Report\n";
        cout << " 7. Journal Report\n";
        cout << " 8. Library Report\n";
        cout << " 9. Fee Report\n";
        cout << "10. Invoice Report\n";
        cout << "11. System Summary\n";
        cout << " 0. Back\n";
        cout << "Choice: ";
        cin >> choice;
        clearInput();

        // Build combined Person vector for summary
        vector<Person> persons;
        for (auto &s : students)
            persons.push_back(s);
        for (auto &fa : facultyList)
            persons.push_back(fa);
        for (auto &st : staffList)
            persons.push_back(st);

        if (choice == 1)
            Reports::generatePersonReport(persons);
        else if (choice == 2)
            Reports::generateCourseReport(courses);
        else if (choice == 3)
            Reports::generateEnrollmentReport(enrollments);
        else if (choice == 4)
            Reports::generateRoomReport(rooms);
        else if (choice == 5)
            Reports::generateHostelBlockReport(hostelManager.getBlocks());
        else if (choice == 6)
            Reports::generateBookReport(books);
        else if (choice == 7)
            Reports::generateJournalReport(journals);
        else if (choice == 8)
            Reports::generateLibraryReport(libraryItems);
        else if (choice == 9)
            Reports::generateFeeReport(feeRecords);
        else if (choice == 10)
            Reports::generateInvoiceReport(invoices);
        else if (choice == 11)
            Reports::generateSystemSummary(
                persons, courses, enrollments, rooms,
                hostelManager.getBlocks(), books, journals,
                libraryItems, feeRecords, invoices);

        if (choice != 0)
            pauseScreen();
    } while (choice != 0);
}

// ─────────────────────────────────────────────
//  Main Menu
// ─────────────────────────────────────────────
void mainMenu()
{
    int choice;
    do
    {
        printHeader("UNIVERSITY MANAGEMENT SYSTEM");
        cout << " 1. Student Management\n";
        cout << " 2. Faculty Management\n";
        cout << " 3. Staff Management\n";
        cout << " 4. Course Management\n";
        cout << " 5. Enrollment Management\n";
        cout << " 6. Fee & Invoice Management\n";
        cout << " 7. Hostel Management\n";
        cout << " 8. Library Management\n";
        cout << " 9. Reports\n";
        cout << "10. Save All Data\n";
        cout << "11. Load All Data\n";
        cout << " 0. Exit\n";
        cout << "Choice: ";
        cin >> choice;
        clearInput();

        switch (choice)
        {
        case 1:
            studentMenu();
            break;
        case 2:
            facultyMenu();
            break;
        case 3:
            staffMenu();
            break;
        case 4:
            courseMenu();
            break;
        case 5:
            enrollmentMenu();
            break;
        case 6:
            feeMenu();
            break;
        case 7:
            hostelMenu();
            break;
        case 8:
            libraryMenu();
            break;
        case 9:
            reportsMenu();
            break;
        case 10:
            saveAllData();
            pauseScreen();
            break;
        case 11:
            loadAllData();
            pauseScreen();
            break;
        case 0:
            cout << "\nSaving data before exit...\n";
            saveAllData();
            cout << "Goodbye!\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
            pauseScreen();
        }
    } while (choice != 0);
}

// ─────────────────────────────────────────────
//  Entry Point
// ─────────────────────────────────────────────
int main()
{
    cout << "╔══════════════════════════════════════════╗" << endl;
    cout << "║   UNIVERSITY MANAGEMENT SYSTEM  v1.0    ║" << endl;
    cout << "╚══════════════════════════════════════════╝" << endl;

    cout << "\nLoading saved data...\n";
    loadAllData();

    mainMenu();

    return 0;
}