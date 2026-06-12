#ifndef REPORTS_H
#define REPORTS_H

#include <iostream>
#include <vector>

#include "Course.h"
#include "Enrollment.h"

#include "Book.h"
#include "Journal.h"
#include "Library.h"

#include "Room.h"
#include "HostelBlock.h"

#include "FeeRecord.h"
#include "Invoice.h"

#include "Person.h"

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