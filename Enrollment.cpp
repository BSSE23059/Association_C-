#include "Enrollment.h"

Enrollment::Enrollment(Student *enrollStudent, Course *enrollCourse) {
    this->student = enrollStudent;
    this->course = enrollCourse;
    this->attendance = 0;
    this->attendanceRecord = new char[enrollCourse->getNumOfLectures()];
}

Student *Enrollment::getStudent() {
    return student;
}

Course *Enrollment::getCourse() {
    return course;
}

void Enrollment::enroll(Student *enrollStudent,Course *enrollCourse) {
    Enrollment* enrollment = new Enrollment(enrollStudent,enrollCourse);
    enrollStudent->addEnrollment(enrollment);
    enrollCourse->addEnrollment(enrollment);
}

void Enrollment::markAttendance(char status) {
    if(attendance >= 0 && attendance < course->getNumOfLectures()){
        attendanceRecord[attendance] = status;
        attendance += 1;
    } else {
        cout << "All Lectures have been marked." << endl;
    }
}

void Enrollment::showAttendance() {
    cout << "===================================================================" << endl;
    cout << "       Attendance of " << student->getStudentName() << " in " << course->getCourseTitle() << endl;
    cout << "===================================================================" << endl;
    for(int attend=0;attend<attendance;attend++){
        cout << "Status of Lecture " << attend + 1 << " : " << attendanceRecord[attend] << endl;
    }

}

void Enrollment::generateAttendanceReports() {
    int attendedLectures = 0;
    int totalLectures = course->getNumOfLectures();
    for(int status=0;status<attendance;status++){
        if(attendanceRecord[status] == 'P'){
            attendedLectures+=1;
        }
    }
    int absents = totalLectures - attendedLectures;
    float attendancePercentage = float(attendedLectures)/float(totalLectures) * 100;
    cout << "=============================================" << endl;
    cout << "                   Reports                   " << endl;
    cout << "=============================================" << endl;
    cout << "Total Lectures :" << totalLectures << endl;
    cout << "Attended Lectures :" << attendedLectures << endl;
    cout << "Absents :" << absents << endl;
    cout << "Attendance Percentage :" << attendancePercentage << "%" << endl;
}