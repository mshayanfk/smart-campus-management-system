#include "Reports.h"
using namespace std;

void Reports::generatePersonReport(vector<Person> &persons) {

    cout << "========= PERSON REPORT =========";

    if (persons.empty()) {
        cout << "No Person Records Found"; 
        return;
    }

    for (Person &p : persons) {
        p.display();
    }
}

void Reports::generateCourseReport(vector<Course> &courses) {

    cout << "========= COURSE REPORT ========";

    if (courses.empty()) {
        cout << "No Course Records Found";
        return;
    }

    for (Course &c : courses) {
        c.display();
    }
}

void Reports::generateEnrollmentReport(vector<Enrollment> &enrollments) {

    cout << "======= ENROLLMENT REPORT =======";

    if (enrollments.empty()) {
        cout << "No Enrollment Records Found";
        return;
    }

    for (Enrollment &e : enrollments) {
        e.display();
    }
}

void Reports::generateRoomReport(vector<Room> &rooms) {

    cout << "======== ROOM REPORT ========";

    if (rooms.empty()) {
        cout << "No Room Records Found";
        return;
    }

    for (Room &r : rooms) {
        r.display();
    }
}

void Reports::generateHostelBlockReport(vector<HostelBlock> &blocks) {

    cout << "======== HOSTEL BLOCK REPORT =========";

    if (blocks.empty()) {
        cout << "No Hostel Block Records Found";
        return;
    }

    for (HostelBlock &b : blocks) {
        b.display();
    }
}

void Reports::generateBookReport(vector<Book> &books) {

    cout << "======== BOOK REPORT ========";

    if (books.empty()) {
        cout << "No Book Records Found";
        return;
    }

    for (Book &b : books) {
        b.display();
    }
}

void Reports::generateJournalReport(vector<Journal> &journals) {

    cout << "======== JOURNAL REPORT =====";

    if (journals.empty()) {
        cout << "No Journal Records Found\n";
        return;
    }

    for (Journal &j : journals) {
        j.display();
    }
}

void Reports::generateLibraryReport(vector<Library> &libraryItems) {

    cout << "========= LIBRARY REPORT ========";

    if (libraryItems.empty()) {
        cout << "No Library Records Found";
        return;
    }

    for (Library &l : libraryItems) {
        l.display();
    }
}

void Reports::generateFeeReport(vector<FeeRecord> &fees) {

    cout << "======== FEE REPORT =======";

    if (fees.empty()) {
        cout << "No Fee Records Found";
        return;
    }

    for (FeeRecord &f : fees) {
        f.display();
    }
}

void Reports::generateInvoiceReport(vector<Invoice> &invoices) {

    cout << "======== INVOICE REPORT ========";

    if (invoices.empty()) {
        cout << "No Invoice Records Found";
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

    cout << "============== SYSTEM SUMMARY ==============" << endl;
    
    cout << "Persons = " << persons.size() << endl;
    cout << "Courses = " << courses.size() << endl;
    cout << "Enrollments = " << enrollments.size() << endl;
    cout << "Rooms = " << rooms.size() << endl;
    cout << "Hostel Blocks = " << blocks.size() << endl;
    cout << "Books = " << books.size() << endl;
    cout << "Journals = " << journals.size() << endl;
    cout << "Library Items = " << libraryItems.size() << endl;
    cout << "Fee Records = " << fees.size() << endl;
    cout << "Invoices = " << invoices.size() << endl;
}