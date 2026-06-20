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
#include "utils/Reports.h"

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
vector<Person *> persons;
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

void clearScreen()
{
#ifdef _WIN32
    system("cls");

#else
    system("clear");
#endif
}

void header(string title)
{
    cout << YELLOW << "===========================================" << RESET << endl;
    cout << BOLD << CYAN << " " << title << RESET << endl;
    cout << YELLOW << "===========================================" << RESET << endl;
}

void pause()
{
    cout << " " << GREEN << "Press Enter to Continue...." << RESET;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

int getMenuChoice()
{
    int choice;
    cout << BOLD << GREEN << "Enter your Selection = " << RESET;
    cin >> choice;

    if (cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return -1;
    }
    return choice;
}

// Loading all the data from the CSV Files

// Loading the Courses and Enrollment Files
void loadCourses()
{
    ifstream file(COURSE_FILE);
    if (!file.is_open())
        return;
    while (file.peek() != EOF && file.good())
    {
        Course c;
        c.loadFromCSV(file);
        if (!file.fail())
        {
            courses.push_back(c);
        }
    }
}

void loadEnrollments()
{
    ifstream file(ENROLLMENT_FILE);

    if (!file.is_open())
        return;
    while (file.peek() != EOF && file.good())
    {
        Enrollment e;
        e.loadFromCSV(file);
        if (!file.fail())
        {
            enrollments.push_back(e);
        }
    }
}

// Loading All the Person files including Student, Staff and Faculty

void loadPersons()
{
    for (Person *p : persons)
        delete p;
    persons.clear();

    ifstream sFile(STUDENT_FILE);
    if (sFile.is_open())
    {
        while (sFile.peek() != EOF && sFile.good())
        {
            Student *s = new Student();
            s->loadFromCSV(sFile);

            if (!sFile.fail())
                persons.push_back(s);
            else
                delete s;
        }
        sFile.close();
    }

    ifstream fFile(FACULTY_FILE);
    if (fFile.is_open())
    {
        while (fFile.peek() != EOF && fFile.good())
        {
            Faculty *f = new Faculty();
            f->loadFromCSV(fFile);
            if (fFile.fail())
                persons.push_back(f);
            else
                delete f;
        }

        fFile.close();
    }

    ifstream stFile(STAFF_FILE);
    if (stFile.is_open())
    {
        while (stFile.peek() != EOF && stFile.good())
        {
            Staff *st = new Staff();
            st->loadFromCSV(stFile);
            if (stFile.fail())
                persons.push_back(st);
            else
                delete st;
        }
        stFile.close();
    }
}

// Loading the Library Files
void loadBooks()
{
    ifstream file(BOOK_FILE);
    if (!file.is_open())
        return;
    while (file.peek() != EOF && file.good())
    {
        Book b;
        b.loadFromCSV(file);
        if (!file.fail())
            books.push_back(b);
    }
}

void loadJournals()
{
    ifstream file(JOURNAL_FILE);
    if (!file.is_open())
        return;
    while (file.peek() != EOF && file.good())
    {
        Journal j;
        j.loadFromCSV(file);
        if (!file.fail())
            journals.push_back(j);
    }
}

// Loading Hostel Files

void loadHostelBlocks()
{
    ifstream file(HOSTEL_FILE);
    if (!file.is_open())
        return;
    while (file.peek() != EOF && file.good())
    {
        HostelBlock block;
        block.loadFromCSV(file);
        if (!file.fail())
            hostelManager.addBlock(block);
    }
}

// Loading Fees & Invoices

void loadFees()
{
    ifstream file(FEE_FILE);
    if (!file.is_open())
        return;
    while (file.peek() != EOF && file.good())
    {
        FeeRecord f;
        f.loadFromCSV(file);
        if (!file.fail())
            fees.push_back(f);
    }
}

void loadInvoices()
{
    ifstream file(INVOICE_FILE);
    if (!file.is_open())
        return;
    while (file.peek() != EOF && file.good())
    {
        Invoice in;
        in.loadFromCSV(file);
        if (!file.fail())
            invoices.push_back(in);
    }
}

void loadAllData()
{
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

void saveCourses()
{
    ofstream file(COURSE_FILE);
    for (Course &c : courses)
        c.saveToCSV(file);
}

void saveEnrollments()
{
    ofstream file(ENROLLMENT_FILE);
    for (Enrollment &e : enrollments)
        e.saveToCSV(file);
}

// For the Person (Staff, Student, Faculty ) ones

void savePersons()
{
    ofstream sFile(STUDENT_FILE);
    ofstream stFile(STAFF_FILE);
    ofstream fFile(FACULTY_FILE);

    for (Person *p : persons)
    {
        if (!p)
            continue;

        Student *s = dynamic_cast<Student *>(p);
        if (s)
        {
            s->saveInCSV(sFile);
            continue;
        }

        Faculty *f = dynamic_cast<Faculty *>(p);
        if (f)
        {
            s->saveInCSV(fFile);
            continue;
        }

        Staff *st = dynamic_cast<Staff *>(p);
        if (st)
        {
            st->saveInCSV(stFile);
            continue;
        }
    }
}

// For Books

void saveBooks()
{
    ofstream file(BOOK_FILE);
    for (Book &b : books)
        b.saveToCSV(file);
}

void saveJournals()
{
    ofstream file(JOURNAL_FILE);
    for (Journal &j : journals)
        j.saveToCSV(file);
}

// For Hostel

void saveHostelBlocks()
{
    ofstream file(HOSTEL_FILE);
    for (HostelBlock &block : hostelManager.getBlocks())
    {
        block.saveInCSV(file);
    }
}

// For Fee Records
void saveFees()
{
    ofstream file(FEE_FILE);
    for (FeeRecord &f : fees)
        f.saveInCSV(file);
}

void saveInvoices()
{
    ofstream file(INVOICE_FILE);
    for (Invoice &in : invoices)
        in.saveInCSV(file);
}

void saveAllData()
{
    saveCourses();
    saveEnrollments();
    savePersons();
    saveBooks();
    saveJournals();
    saveHostelBlocks();
    saveFees();
    saveInvoices();
}

void cleanPersons()
{
    for (Person *p : persons)
        delete p;
    persons.clear();
}
// For Acedemic System
void academicMenu()
{
    int choice;
    do
    {
        clearScreen();
        header("ACADEMIC MANAGEMENT SYSTEMS");
        cout << GREEN << " [1] Add Course\n";
        cout << " [2] View All Courses\n";
        cout << " [3] Search Course by Code\n";
        cout << " [4] Delete Course by Code\n";
        cout << " [5] Add Enrollment\n";
        cout << " [6] View All Enrollments\n";
        cout << " [7] Search Enrollment by Student ID\n";
        cout << " [8] Delete Enrollment by ID\n"
             << RESET;
        cout << RED << " [0] Return to Main Terminal\n"
             << RESET;
        cout << CYAN << "--------------------------------------------------------=" << RESET << endl;
        choice = getMenuChoice();

        if (choice == 1)
        {
            clearScreen();
            header("Add New Course Structure");
            Course c;
            try
            {
                c.input();
                courses.push_back(c);
                cout << GREEN << "\nCourse registered successfully\n"
                     << RESET;
            }
            catch (exception &e)
            {
                cout << RED << "Error: " << e.what() << RESET << endl;
            }
        }
        else if (choice == 2)
        {
            clearScreen();
            header("View Course Directory");
            Reports::generateCourseReport(courses);
        }
        else if (choice == 3)
        {
            clearScreen();
            header("Find  Course Code");
            cout << "Enter target Course Code: ";
            string code;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, code);
            bool found = false;
            for (Course &c : courses)
            {
                if (c.matchesCode(code))
                {
                    c.display();
                    found = true;
                }
            }
            if (!found)
                cout << RED << "Active profile code matching reference not found.\n"
                     << RESET;
        }
        else if (choice == 4)
        {
            clearScreen();
            header("Delete Course Entry");
            cout << "Enter Course Code to delete: ";
            string code;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, code);
            bool found = false;
            for (size_t i = 0; i < courses.size(); i++)
            {
                if (courses[i].matchesCode(code))
                {
                    courses.erase(courses.begin() + i);
                    cout << GREEN << "Target entry systematically cleared.\n"
                         << RESET;
                    found = true;
                    break;
                }
            }
            if (!found)
                cout << RED << "Match not found.\n"
                     << RESET;
        }
        else if (choice == 5)
        {
            clearScreen();
            header("Add Student Enrollment Link");
            Enrollment e;
            try
            {
                e.input();
                enrollments.push_back(e);
                cout << GREEN << "\n Enrollment registered successfully\n"
                     << RESET;
            }
            catch (exception &ex)
            {
                cout << RED << "Registration Blocked: " << ex.what() << RESET << endl;
            }
        }
        else if (choice == 6)
        {
            clearScreen();
            header("View Academic Enrollments");
            Reports::generateEnrollmentReport(enrollments);
        }
        else if (choice == 7)
        {
            clearScreen();
            header("Track Enrollment with Student ID");
            cout << "Enter Numeric Student ID: ";
            int sid;
            cin >> sid;
            bool found = false;
            for (Enrollment &e : enrollments)
            {
                if (e.matchesStudentId(sid))
                {
                    e.display();
                    found = true;
                }
            }
            if (!found)
                cout << RED << "No active link data found under tracking ID.\n"
                     << RESET;
        }
        else if (choice == 8)
        {
            clearScreen();
            header("Delete Enrollment Registry");
            cout << "Enter unique Enrollment ID to drop: ";
            int eid;
            cin >> eid;
            bool found = false;
            for (size_t i = 0; i < enrollments.size(); i++)
            {
                if (enrollments[i].matchesEnrollmentId(eid))
                {
                    enrollments.erase(enrollments.begin() + i);
                    cout << GREEN << "Student trace purged from class matrix.\n"
                         << RESET;
                    found = true;
                    break;
                }
            }
            if (!found)
                cout << RED << "Link ID trace not registered.\n"
                     << RESET;
        }

        if (choice != 0)
            pause();
    } while (choice != 0);
}

// For the Personnel Menu here
void personnelMenu()
{
    int choice;
    do
    {
        clearScreen();
        header("PERSONNEL MANAGEMENT SYSTEM");
        cout << GREEN << " [1] Add New Personnel Record (Student/Faculty/Staff)\n";
        cout << " [2] View All Personnel\n";
        cout << " [3] Search by ID\n";
        cout << " [4] Delete Personnel Record\n"
             << RESET;
        cout << RED << " [0] Return to Main Menu\n"
             << RESET;
        cout << CYAN << "--------------------------------------------------------=" << RESET << endl;
        choice = getMenuChoice();

        if (choice == 1)
        {
            clearScreen();
            header("Add New Personnel Record");
            cout << YELLOW << "Select Personnel Type:\n"
                 << RESET;
            cout << " [0] Student\n"
                 << " [1] Faculty\n"
                 << " [2] Staff\n\n";
            cout << " Enter your choice (0-2): ";
            int typeChoice;
            cin >> typeChoice;

            if (cin.fail() || typeChoice < 0 || typeChoice > 2)
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << RED << "😠 Invalid Choice. Please Try Again\n"
                     << RESET;
                pause();
                continue;
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            Person *p = nullptr;
            if (typeChoice == 0)
                p = new Student();
            else if (typeChoice == 1)
                p = new Faculty();
            else if (typeChoice == 2)
                p = new Staff();

            if (p != nullptr)
            {
                try
                {
                    p->input();
                    persons.push_back(p);
                    cout << GREEN << "\n☑️ Record Added Successfully!\n"
                         << RESET;
                }
                catch (exception &e)
                {
                    cout << RED << "Runtime Allocation Error: " << e.what() << RESET << endl;
                    delete p;
                }
            }
        }
        else if (choice == 2)
        {
            clearScreen();
            header("All Personnel Records");
            if (persons.empty())
            {
                cout << YELLOW << "😞 No Personnel Records Found.\n"
                     << RESET;
            }
            else
            {
                cout << BOLD << GREEN << "Personnel Records:\n"
                     << RESET;
                cout << "=========================================================\n";
                for (Person *p : persons)
                {
                    if (p)
                    {
                        p->display();
                        cout << CYAN << "---------------------------------------------------------\n"
                             << RESET;
                    }
                }
            }
        }
        else if (choice == 3)
        {
            clearScreen();
            header("Search Personnel Record");
            cout << "Enter Personnel ID: ";
            int id;
            cin >> id;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            bool found = false;
            for (Person *p : persons)
            {
                if (p && p->matchesID(id))
                {
                    cout << "\n"
                         << GREEN << "😎 Record Found:" << RESET << "\n";
                    p->display();
                    found = true;
                }
            }
            if (!found)
                cout << RED << "💔 Record Not Found\n"
                     << RESET;
        }
        else if (choice == 4)
        {
            clearScreen();
            header("Delete Personnel Record");
            cout << "Enter ID to Delete: ";
            int id;
            cin >> id;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            bool found = false;
            for (size_t i = 0; i < persons.size(); i++)
            {
                if (persons[i] && persons[i]->matchesID(id))
                {
                    delete persons[i];
                    persons.erase(persons.begin() + i);
                    cout << GREEN << "🥳 Record Deleted Successfully.\n"
                         << RESET;
                    found = true;
                    break;
                }
            }
            if (!found)
                cout << RED << "❌ Record Not Found.\n"
                     << RESET;
        }

        if (choice != 0)
            pause();
    } while (choice != 0);
}
// library meanu
void libraryMenu()
{
    int choice;
    do
    {
        clearScreen();
        header("LIBRARY MANAGMENT SYSTEM");
        cout << GREEN << " [1] Print New Book\n";
        cout << " [2] View Full Book Catalog\n";
        cout << " [3] Look up Book by Author Profile\n";
        cout << " [4] Delete Book Entry \n";
        cout << " [5] Register Research Journal Asset\n";
        cout << " [6] View Research Journal Inventory\n";
        cout << " [7] Find Journals with Title Query\n";
        cout << " [8] Delete Journal Entry with Title Reference\n"
             << RESET;
        cout << RED << " [0] Return to Main Terminal\n"
             << RESET;
        cout << CYAN << "--------------------------------------------------------=" << RESET << endl;
        choice = getMenuChoice();

        if (choice == 1)
        {
            clearScreen();
            header("Book Form Created");
            Book b;
            try
            {
                b.input();
                books.push_back(b);
                cout << GREEN << "\n Book asset successfully Added\n"
                     << RESET;
            }
            catch (exception &e)
            {
                cout << RED << "Error: " << e.what() << RESET << endl;
            }
        }
        else if (choice == 2)
        {
            clearScreen();
            header("Available Books Assets");
            Reports::generateBookReport(books);
        }
        else if (choice == 3)
        {
            clearScreen();
            header("Look Up Books via Aurthor Profile");
            cout << "Enter complete Author name : ";
            string author;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, author);
            bool found = false;
            for (Book &b : books)
            {
                if (b.matchesAuthor(author))
                {
                    b.display();
                    found = true;
                }
            }
            if (!found)
                cout << RED << " Catalog contains no tracks of field value.\n"
                     << RESET;
        }
        else if (choice == 4)
        {
            clearScreen();
            header("Del Book Index");
            cout << "Enter target Book Number: ";
            string isbn;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, isbn);
            bool found = false;
            for (size_t i = 0; i < books.size(); i++)
            {
                if (books[i].matchesISBN(isbn))
                {
                    books.erase(books.begin() + i);
                    cout << GREEN << " Inventory asset row removed .\n"
                         << RESET;
                    found = true;
                    break;
                }
            }
            if (!found)
                cout << RED << " Missing validation key.\n"
                     << RESET;
        }
        else if (choice == 5)
        {
            clearScreen();
            header(" Research Journalist Asset");
            Journal j;
            try
            {
                j.input();
                journals.push_back(j);
                cout << GREEN << "\n Entry locked into database.\n"
                     << RESET;
            }
            catch (exception &e)
            {
                cout << RED << "Error: " << e.what() << RESET << endl;
            }
        }
        else if (choice == 6)
        {
            clearScreen();
            header("View INV Of Academic Journals");
            Reports::generateJournalReport(journals);
        }
        else if (choice == 7)
        {
            clearScreen();
            header("Track Journalest Tital");
            cout << "Enter exact Journal Name: ";
            string name;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, name);
            bool found = false;
            for (Journal &j : journals)
            {
                if (j.matchesJournalName(name))
                {
                    j.display();
                    found = true;
                }
            }
            if (!found)
                cout << RED << "Name of Journal lookup failure.\n"
                     << RESET;
        }
        else if (choice == 8)
        {
            clearScreen();
            header("Delete Journal Registry Line");
            cout << "Enter journal name string: ";
            string name;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, name);
            bool found = false;
            for (size_t i = 0; i < journals.size(); i++)
            {
                if (journals[i].matchesJournalName(name))
                {
                    journals.erase(journals.begin() + i);
                    cout << GREEN << "Entry is completely erased.\n"
                         << RESET;
                    found = true;
                    break;
                }
            }
            if (!found)
                cout << RED << "String trace not matched \n"
                     << RESET;
        }

        if (choice != 0)
            pause();
    } while (choice != 0);
}

void hostelMenu()
{
    int choice;
    do
    {
        clearScreen();
        header("HOSTEL MANAGEMENT SYSTEM");
        cout << GREEN << " [1] Add New Hostel Block\n";
        cout << " [2] View All Hostel Blocks & Rooms\n";
        cout << " [3] Search Hostel Block\n";
        cout << " [4] Remove Hostel Block\n";
        cout << " [5] Add Room to Hostel Block\n" <<RESET;
        cout << RED << " [0] Back to Main Meni\n"
             << RESET;
        cout << CYAN << "--------------------------------------------------------=" << RESET << endl;
        choice = getMenuChoice();

        if (choice == 1)
        {
            clearScreen();
            header("Add Hostel Block");
            HostelBlock block;
            try
            {
                block.input();
                hostelManager.addBlock(block);
                cout << GREEN << "\n Hostel Block Added Successfully!\n"
                     << RESET;
            }
            catch (exception &e)
            {
                cout << RED << "Error: " << e.what() << RESET << endl;
            }
        }
        else if (choice == 2)
        {
            clearScreen();
            header("View Hostel Blocks");
            vector<HostelBlock> &blocks = hostelManager.getBlocks();
            if (blocks.empty())
            {
                cout << YELLOW << "No Hostel Blocks Available 👊\n"
                     << RESET;
            }
            else
            {
                for (HostelBlock &block : blocks)
                {
                    cout << "\n"
                         << BOLD << MAGENTA << "Hostel Block Details:" << RESET << endl;
                    block.display();
                    cout << YELLOW << "Rooms in this Block:" << RESET << endl;
                    block.displayRooms();
                    cout << CYAN << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
                         << RESET;
                }
            }
        }
        else if (choice == 3)
        {
            clearScreen();
            header("Search Hostel Block");
            cout << "Enter Block Name: ";
            string name;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, name);
            hostelManager.searchBlock(name);
        }
        else if (choice == 4)
        {
            clearScreen();
            header("Delete Hostel Block");
            cout << "Enter Block Name to Delete: ";
            string name;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, name);
            hostelManager.removeBlock(name);
        }
        else if (choice == 5)
        {
            clearScreen();
            header("Add Room to Hostel Block");
            vector<HostelBlock> &blocks = hostelManager.getBlocks();
            if (blocks.empty())
            {
                cout << RED << "No Hostel Block exist. Create a Block First\n" << RESET;
            }
            else
            {
                cout << "Enter Block Name: ";
                string name;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                getline(cin, name);

                bool found = false;
                for (HostelBlock &block : blocks)
                {
                    if (block.getBlockName() == name)
                    {
                        Room room;
                        try
                        {
                            room.input();
                            block.addRoom(room);
                            cout << GREEN << "\n Room Added Successfully!\n"
                                 << RESET;
                        }
                        catch (exception &e)
                        {
                            cout << RED << "Error Occured: " << e.what() << RESET << endl;
                        }
                        found = true;
                        break;
                    }
                }
                if (!found)
                    cout << RED << "Hostel Block Not Found.\n"
                         << RESET;
            }
        }

        if (choice != 0)
            pause();
    } 
    while (choice != 0);
}
