#ifndef ENROLLMENT_H
#define ENROLLMENT_H

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Enrollment {

private:
    int enrollmentId;
    int studentId;
    string courseCode;
    string semester;
    string session;
    string enrollmentDate;
    string grade;
    bool isActive;

public:
    // Constructor
    Enrollment();

    // Destructor
    ~Enrollment();

    // Core Functions
    void input();

    void display() const;

    // File Handling
    void saveToCSV(std::ofstream &outputFile);

    void loadFromCSV(std::ifstream &inputFile);

    // Utility Function
    void setData(
        int enrollmentId,
        int studentId,
        string courseCode,
        string semester,
        string session,
        string enrollmentDate,
        string grade,
        bool status
    );

    // Setters
    void setStudentId(int studentId);

    void setCourseCode(string courseCode);

    void setSemester(string semester);

    void setSession(string session);

    void setEnrollmentDate(string enrollmentDate);

    void setGrade(string grade);

    void setStatus(bool status);

    // Getters
    int getEnrollmentId() const;

    int getStudentId() const;

    string getCourseCode() const;

    string getSemester() const;

    string getSession() const;

    string getEnrollmentDate() const;

    string getGrade() const;

    bool getStatus() const;

    // Search Helpers
    bool matchesEnrollmentId(int searchId) const;

    bool matchesStudentId(int searchStudentId) const;

    bool matchesCourseCode(string searchCourseCode) const;
};

#endif