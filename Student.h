#ifndef COURSE_ENROLMENT_STUDENT_H
#define COURSE_ENROLMENT_STUDENT_H
#include <iostream>
#include "Enrollment.h"
#include <vector>
using namespace std;
class Enrollment;

class Student {
private:
    string name;
    vector<Enrollment*> enrollments;
public:
    explicit Student(string studentName);
    void addEnrollment(Enrollment* enrollment);
    const string getStudentName() const;
    vector<Enrollment*>& getEnrollments();
    void setStudentName(string &studentName);
    void displayCourses();

};


#endif //COURSE_ENROLMENT_STUDENT_H
