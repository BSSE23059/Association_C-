
#include "Student.h"


Student::Student(std::string studentName) {
    this->name = studentName;
}

void Student::addEnrollment(Enrollment *enrollment) {
    enrollments.push_back(enrollment);
}

const string Student::getStudentName() const {
    return name;
}

vector<Enrollment *> &Student::getEnrollments() {
    return enrollments;
}

void Student::setStudentName(string &studentName) {
    this->name = studentName;
}

void Student::displayCourses() {
    cout << "=============================================" << endl;
    cout << "       Courses of " << name << endl;
    cout << "=============================================" << endl;
    for(const auto& course : enrollments){
        cout << course->getCourse()->getCourseTitle() << endl;
    }
}