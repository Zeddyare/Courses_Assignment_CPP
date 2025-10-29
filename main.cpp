
#include "courseFunc.h"
#include <string>
#include <iostream>
#include <exception>

using namespace std;


int main () {


    cout << "Student Courses Program" << endl;
    cout <<"\n===================================================\n\n" << endl;

    Student other;
    bool running = true;

    string name;
    cout << "Create Student: ";
    getline(cin, name);
    Student s = Student(name);

    string select;
    while (running) {
        cout << "Menu: \n" << endl;
        cout << "1) Set student's name\n"
        << "2) Add course to student\n"
        << "3) Remove a course from student\n"
        << "4) Output student information\n"
        << "5) Clear student information\n"
        << "6) Create copy from existing student\n"
        << "7) Assign student to existing record\n"
        << "8) Show other student\n"
        << "9) Exit\n"
        << "Choice: ";

        if (!getline(cin, select)) break;
        try {
            int choice = stoi(select);

            switch (choice) {
                case 1: {
                    string name;
                    cout << "Enter name: ";
                    getline(cin, name);
                    s.setName(name);
                    break;
                }
                case 2: {
                    string course;
                    cout << "Enter Course (add): ";
                    getline(cin, course);
                    cout << s.addCourse(course);
                    break;
                }
                case 3: {
                    string course;
                    cout << "Enter Course (remove): ";
                    getline(cin, course);
                    cout << s.removeCourse(course);
                    break;
                }
                case 4: {
                    s.outputInfo();
                    cout << s;
                    break;
                }
                case 5: {
                    s.reset();
                    break;
                }
                case 6: {
                    Student copy(s);
                    cout << "Original student: " << s;
                    cout << "Copy student: " << copy;
                    break;
                }
                case 7: {
                    other = s;
                    cout << "Original student: " << s;
                    cout << "Assigned student: " << other;
                    break;
                }
                case 8: {
                    cout << other << endl;
                    break;
                }
                case 9: {
                    running = false;
                    break;
                }
                default: {
                    cout << "Invalid Choice." << endl;
                    break;
                }
            }
        } catch (...) {
            cout << "Invalid entry type, please try again" << endl;
            continue;
        }
    }
    return 0;
}

