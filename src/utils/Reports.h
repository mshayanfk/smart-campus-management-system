#ifndef REPORTS_H
#define REPORTS_H

#include "../Course/Course.h"
#include "../Course/Enrollment.h"
#include "../Library/Book.h"
#include "../Library/Journal.h"
#include "../Library/Library.h"
#include "../hostle/Room.h"
#include "../hostle/HostelBlock.h"
#include "../Finance/FeeRecord.h"
#include "../Finance/Invoice.h"
#include "../person/Person.h"

using namespace std;

class Reports {

public:

    static void generatePersonReport(vector<Person*> &persons);

    static void generateCourseReport(vector<Course> &courses);

    static void generateEnrollmentReport(vector<Enrollment> &enrollments);

    static void generateRoomReport(vector<Room> &rooms);

    static void generateHostelBlockReport(vector<HostelBlock> &blocks);

    static void generateBookReport(vector<Book> &books);

    static void generateJournalReport(vector<Journal> &journals);

    static void generateLibraryReport(vector<Library> &libraryItems);

    static void generateFeeReport(vector<FeeRecord> &fees);

    static void generateInvoiceReport(vector<Invoice> &invoices);

    static void generateSystemSummary(
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
    );
};

#endif