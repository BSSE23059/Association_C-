#include <iostream>
#include "Course.h"
#include "Student.h"
#include "Enrollment.h"
using namespace std;

int main() {

    int choice;
    char stop;
    vector<Student*> students;
    vector<Course*> courses;
    do{
        system("clear");
        cout << "=====================================================" << endl;
        cout << "                  Course Enrolment                   " << endl;
        cout << "=====================================================" << endl;
        cout << "1. Add Students." << endl;
        cout << "2. Add Courses." << endl;
        cout << "3. Enroll." << endl;
        cout << "4. Enrolled Courses." << endl;
        cout << "5. Enrolled Students." << endl;
        cout << "6. Display Courses." << endl;
        cout << "7. Mark Attendance." << endl;
        cout << "8. Show Attendance." << endl;
        cout << "9. Generate Attendance Reports." << endl;
        cout << "Enter your choice :";
        cin >> choice;
        try {
            switch (choice) {
                case 1: {
                    string name;
                    cout << "Enter name of student :";
                    cin.ignore();
                    getline(cin, name);
                    auto *student = new Student(name);
                    students.push_back(student);
                    break;
                }
                case 2: {
                    string title;
                    int lectures;
                    cout << "Enter the title of the course :";
                    cin.ignore();
                    getline(cin, title);
                    cout << "Enter number of lectures for " << title << " :";
                    cin >> lectures;
                    auto *course = new Course(title, lectures);
                    courses.push_back(course);
                    break;
                }
                case 3: {
                    string studentName, courseTitle;
                    bool studentFound = false;
                    bool courseFound = false;
                    cout << "Enter name of student :";
                    cin.ignore();
                    getline(cin, studentName);
                    findStudent:
                    for (const auto &student: students) {
                        if (student->getStudentName() == studentName) {
                            cout << "Student Found." << endl;
                            studentFound = true;
                            cout << "Enter the course title :";
                            getline(cin, courseTitle);
                            findCourse:
                            for (const auto &course: courses) {
                                if (course->getCourseTitle() == courseTitle) {
                                    cout << "Course Found." << endl;
                                    courseFound = true;
                                    bool alreadyEnrolled = false;
                                    for (const auto &enrolledStudent: course->getEnrollments()) {
                                        if (enrolledStudent->getStudent()->getStudentName() == studentName) {
                                            alreadyEnrolled = true;
                                            break;
                                        }
                                    }
                                    if (alreadyEnrolled) {
                                        cout << "Student is already enrolled in this course, Please enter "
                                                "the course title again :";
                                        getline(cin, courseTitle);
                                        goto findCourse;
                                    } else {
                                        Enrollment::enroll(student, course);
                                        cout << student->getStudentName() << " has been enrolled in "
                                             << course->getCourseTitle() << endl;
                                    }
                                }
                            }
                            if (!courseFound) {
                                cout << "Course not found,Enter the course title again :";
                                getline(cin, courseTitle);
                                goto findCourse;
                            }
                        }
                    }
                    if (!studentFound) {
                        cout << "Student Not found, Enter name of student again :";
                        getline(cin, studentName);
                        goto findStudent;
                    }
                    break;
                }
                case 4: {
                    string studentName;
                    cout << "Enter name of student :";
                    cin.ignore();
                    getline(cin, studentName);
                    for (auto &student: students) {
                        if (student->getStudentName() == studentName) {
                            student->displayCourses();
                        }
                    }
                    break;
                }
                case 5: {
                    string courseTitle;
                    cout << "Enter title of Course :";
                    cin.ignore();
                    getline(cin, courseTitle);
                    for (auto &course: courses) {
                        if (course->getCourseTitle() == courseTitle) {
                            course->displayStudents();
                        }
                    }
                    break;
                }
                case 6: {
                    cout << "==============================" << endl;
                    cout << "            Courses           " << endl;
                    cout << "==============================" << endl;
                    for (const auto &course: courses) {
                        cout << course->getCourseTitle() << endl;
                    }
                    break;
                }
                case 7: {
                    string studentName, courseTitle;
                    char attendanceStatus;
                    bool courseFound = false;
                    cout << "Enter the course title :";
                    cin.ignore();
                    getline(cin, courseTitle);
                    findCourseAgain:
                    for (const auto &course : courses) {
                        if(course->getCourseTitle() == courseTitle){
                            courseFound = true;
                            for(const auto& student : course->getEnrollments()){
                                cout << "Mark attendance of " << student->getStudent()->getStudentName()
                                << " (A/P):";
                                cin >> attendanceStatus;
                                student->markAttendance(attendanceStatus);
                            }
                        }
                    }
                    if(!courseFound){
                        cout << "Course " << courseTitle << " not found, Please enter course title again :";
                        getline(cin, courseTitle);
                        goto findCourseAgain;
                    }
                    break;

                }
                case 8: {
                    string studentName, courseTitle;
                    bool studentFound = false;
                    bool courseFound = false;
                    cout << "Enter the student name :";
                    cin.ignore();
                    getline(cin, studentName);
                    findStudentAgain:
                    for (const auto &student : students) {
                        if (student->getStudentName() == studentName) {
                            studentFound = true;
                            cout << "Enter the course title :";
                            getline(cin, courseTitle);
                            findCourseAgainOnce:
                            for(const auto& course : student->getEnrollments()){
                                if(course->getCourse()->getCourseTitle() == courseTitle){
                                    courseFound = true;
                                    course->showAttendance();
                                }
                            }
                            if(!courseFound){
                                cout << "Course " << courseTitle << " not found, Please enter course title again :";
                                getline(cin,courseTitle);
                                goto findCourseAgainOnce;
                            }
                        }
                    }
                    if(!studentFound){
                        cout << "Student " << studentName << " not found, Please enter student name again :";
                        getline(cin,studentName);
                        goto findStudentAgain;
                    }
                    break;
                }
                case 9:{
                    string studentName, courseTitle;
                    bool studentFound = false;
                    bool courseFound = false;
                    cout << "Enter the student name :";
                    cin.ignore();
                    getline(cin, studentName);
                    cout << "Enter the course title :";
                    getline(cin, courseTitle);
                    searchStudent:
                    for (const auto &student : students) {
                        if (student->getStudentName() == studentName) {
                            studentFound = true;
                            searchCourse:
                            for(const auto& course : student->getEnrollments()){
                                if(course->getCourse()->getCourseTitle() == courseTitle){
                                    courseFound = true;
                                    course->generateAttendanceReports();
                                }
                            }
                            if(!courseFound){
                                cout << "Course " << courseTitle << " not found, Please enter course title again :";
                                getline(cin,courseTitle);
                                goto searchCourse;
                            }
                        }
                    }
                    if(!studentFound){
                        cout << "Student " << studentName << " not found, Please enter student name again :";
                        getline(cin,studentName);
                        goto searchStudent;
                    }
                    break;
                }

                default: {
                    cout << "Invalid Input, Please enter a valid input...." << endl;
                    break;
                }
            }
        }catch (exception &e){
            cout << "ERROR :" << e.what() << endl;
        }
        cout << "Do you want to continue(Y/N) :";
        cin >> stop;
    }while(stop == 'y' || stop == 'Y');

    return 0;
}
