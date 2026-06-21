#include "Reports.h"
using namespace std;

void Reports::generatePersonReport(vector<Person*> &persons) {

    cout << BOLD << CYAN <<"========= PERSON REPORT =========" << RESET << endl;
        cout << endl;


    if (persons.empty()) {
        cout << left << RED << setw(20) << "No Person Records Found" <<endl << RESET; 
        return;
    }

    for (Person* &p : persons) {
        p->display();
    }
}

void Reports::generateCourseReport(vector<Course> &courses) {

    cout << BOLD << CYAN << "========= COURSE REPORT ========" <<RESET <<endl;
    cout << endl;

    if (courses.empty()) {
        cout << left << RED << setw(20) << "No Course Records Found" <<endl << RESET;
        return;
    }

    for (Course &c : courses) {
        c.display();
    }
}

void Reports::generateEnrollmentReport(vector<Enrollment> &enrollments) {

    cout << BOLD << CYAN << "======= ENROLLMENT REPORT =======" << RESET << endl;
        cout << endl;


    if (enrollments.empty()) {
        cout << left << RED << setw(20) << "No Enrollment Records Found" << endl << RESET;
        return;
    }

    for (Enrollment &e : enrollments) {
        e.display();
    }
}

void Reports::generateRoomReport(vector<Room> &rooms) {

    cout << BOLD << CYAN << "======== ROOM REPORT ========" << RESET << endl;
        cout << endl;


    if (rooms.empty()) {
        cout << left << RED << setw(20) << "No Room Records Found" << RESET << endl; 
        return;
    }

    for (Room &r : rooms) {
        r.display();
    }
}

void Reports::generateHostelBlockReport(vector<HostelBlock> &blocks) {

    cout << BOLD << CYAN << "======== HOSTEL BLOCK REPORT =========" << RESET << endl;
        cout << endl;


    if (blocks.empty()) {
        cout << left << RED << setw(20) << "No Hostel Block Records Found" << RESET << endl;
        return;
    }

    for (HostelBlock &b : blocks) {
        b.display();
    }
}

void Reports::generateBookReport(vector<Book> &books) {

    cout << BOLD << CYAN << "======== BOOK REPORT ========" << endl << RESET;
        cout << endl;


    if (books.empty()) {
        cout << left << RED << setw(20) << "No Book Records Found" << RESET << endl;
        return;
    }

    for (Book &b : books) {
        b.display();
    }
}

void Reports::generateJournalReport(vector<Journal> &journals) {

    cout << BOLD << CYAN << "======== JOURNAL REPORT =====" << RESET << endl;
        cout << endl;


    if (journals.empty()) {
        cout << left << RED << setw(20) << "No Journal Records Found\n" << RESET << endl;
        return;
    }

    for (Journal &j : journals) {
        j.display();
    }
}

void Reports::generateLibraryReport(vector<Library> &libraryItems) {

    cout << BOLD << CYAN << "========= LIBRARY REPORT ========" << RESET << endl;
        cout << endl;


    if (libraryItems.empty()) {
        cout << left << RED << setw(20) << "No Library Records Found" << RESET << endl;
        return;
    }

    for (Library &l : libraryItems) {
        l.display();
    }
}

void Reports::generateFeeReport(vector<FeeRecord> &fees) {

    cout << BOLD << CYAN << "======== FEE REPORT =======" << RESET << endl;
        cout << endl;


    if (fees.empty()) {
        cout << left << RED << setw(20) << "No Fee Records Found" << RESET << endl;
        return;
    }

    for (FeeRecord &f : fees) {
        f.display();
    }
}

void Reports::generateInvoiceReport(vector<Invoice> &invoices) {

    cout << BOLD << CYAN << "======== INVOICE REPORT ========" << RESET << endl;
        cout << endl;


    if (invoices.empty()) {
        cout << left << RED << setw(20) << "No Invoice Records Found" << RESET << endl;
        return;
    }

    for (Invoice &i : invoices) {
        i.display();
    }
}

void Reports::generateSystemSummary(
    vector<Person> &persons,
    vector<Course> &courses,
    vector<Enrollment> &enrollments,
    vector<Room> &rooms,
    vector<HostelBlock> &blocks,
    vector<Book> &books,
    vector<Journal> &journals,
    vector<Library> &libraryItems,
    vector<FeeRecord> &fees,
    vector<Invoice> &invoices
) {

    cout << BOLD << CYAN << "=========================================== " << endl << RESET;
    cout << BOLD << CYAN << "============== SYSTEM SUMMARY ==============" << endl << RESET;
    cout << BOLD << CYAN << "=========================================== " << endl << RESET;    
    
    cout << GREEN << "Persons = " << persons.size() << endl;
    cout << "Courses = " << courses.size() << endl;
    cout << "Enrollments = " << enrollments.size() << endl;
    cout << "Rooms = " << rooms.size() << endl;
    cout << "Hostel Blocks = " << blocks.size() << endl;
    cout << "Books = " << books.size() << endl;
    cout << "Journals = " << journals.size() << endl;
    cout << "Library Items = " << libraryItems.size() << endl;
    cout << "Fee Records = " << fees.size() << endl;
    cout << "Invoices = " << invoices.size() << endl << RESET;
}