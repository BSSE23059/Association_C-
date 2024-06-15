#ifndef COURSE_ENROLMENT_ENROLLMENT_H
#define COURSE_ENROLMENT_ENROLLMENT_H
#include <iostream>
#include "Student.h"
#include "Course.h"
using namespace std;

class Course;
class Student;

class Enrollment {
private:
    Student *student;
    Course *course;
    int attendance;
    char* attendanceRecord;
public:
    Enrollment(Student *enrollStudent,Course *enrollCourse);
    Student* getStudent();
    Course* getCourse();
    static void enroll(Student *enrollStudent,Course *enrollCourse);
    void markAttendance(char status);
    void showAttendance();
    void generateAttendanceReports();
};

#endif //COURSE_ENROLMENT_ENROLLMENT_H