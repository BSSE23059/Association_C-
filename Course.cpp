#include "Course.h"

Course::Course(std::string courseTitle, int lectures) {
    this->title = courseTitle;
    this->noOfLectures = lectures;
}

void Course::addEnrollment(Enrollment *enrollment) {
    enrollments.push_back(enrollment);
}

const string Course::getCourseTitle() const {
    return title;
}

vector<Enrollment *> &Course::getEnrollments() {
    return enrollments;
}

int Course::getNumOfLectures() {
    return noOfLectures;
}

void Course::setCourseTitle(std::string &courseTitle) {
    this->title = courseTitle;
}

void Course::setNumOfLectures(int lectures) {
    this->noOfLectures = lectures;
}

void Course::displayStudents() {
    cout << "====================================================" << endl;
    cout << "       Students enrolled in " << title << endl;
    cout << "====================================================" << endl;
    for(const auto& student : enrollments){
        cout << student->getStudent()->getStudentName() << endl;
    }
}

