#ifndef COURSE_ENROLMENT_COURSE_H
#define COURSE_ENROLMENT_COURSE_H
#include <iostream>
#include <vector>
#include "Enrollment.h"
using namespace std;
class Enrollment;

class Course {
private:
    string title;

    int noOfLectures;
    vector<Enrollment*> enrollments;
public:
    Course(string courseTitle,int lectures);
    void addEnrollment(Enrollment* enrollment);
    const string getCourseTitle() const;
    int getNumOfLectures();
    vector<Enrollment*>& getEnrollments();
    void setCourseTitle(string &courseTitle);
    void setNumOfLectures(int lectures);
    void displayStudents();
};


#endif //COURSE_ENROLMENT_COURSE_H
