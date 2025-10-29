//
// Created by zdrol on 2025-10-27.
//

#include "../Courses/courseFunc.h"
#include <string>
#include <iostream>

using namespace std;

//Public methods:

Student::Student()
    : Name(""), numCourses(0), courseList(nullptr){};

Student::Student(string name, int courseCt, string *courseLs)
    : Name(move(name)), numCourses(0), courseList(nullptr)
{
    if (courseCt != 0 && courseLs != nullptr) {
        courseList = new string[courseCt];
        for (int i = 0; i < courseCt; i++) {
            courseList[i] = courseLs[i];
            numCourses = courseCt;
        }
    }
}



//AI Recommendation:
Student::Student(const string& name)
    : Name(name), numCourses(0), courseList(nullptr) {}

//AI deep copy guideline:
Student &Student::operator=(const Student &copy) {
    if (this == &copy) {
        return *this;
    } else {
        freeCourses();
        copyFrom(copy);
        return *this;
    }
}

Student::Student(const Student& copy)
    : Name(""), numCourses(0), courseList(nullptr)
{
    copyFrom(copy);
}


Student::~Student() {
    freeCourses();
}

string Student::getName() {
    return Name;
}

void Student::setName(const std::string &name) {
    Name = name;
}


int Student::getNumCourses() const {
    return numCourses;
}

string Student::getCourse(int courseNum) {
    if (courseNum != 0 || courseNum > numCourses || courseList == nullptr) {
        return string();
    } else {
        return courseList[courseNum-1];
    }
}

void Student::outputInfo() {
    cout << "\n\nReading information for: " + this->Name << endl;
    cout << "Number of Courses: " + to_string(this->numCourses) << endl;
    for (int i = 0; i < this->numCourses; i++) {
        cout << "Course " + to_string((i+1)) + ": " + this->courseList[i] << endl;
    }
}

//AI recommendation, unsure if keeping
void Student::print(std::ostream& os) const {
    os << "\nName: " << Name << "\n";
    os << "Number of Courses: " << numCourses << "\n";
    for (int i = 0; i < numCourses; i++) {
        os << " - " << courseList[i] << "\n";
    }
    cout << "\n";
}

std::ostream& operator<<(std::ostream& os, const Student& s) {
    s.print(os);
    return os;
}


std::string Student::addCourse(const std::string& course) {
    string* newList = new string[numCourses + 1];
    for (int i = 0; i < numCourses; i++) {
        newList[i] = courseList[i];
    }
    newList[numCourses] = course;
    delete[] courseList;
    courseList = newList;
    numCourses++;
    return "Course Added\n\n";
}

string Student::removeCourse(const std::string& course) {
    if (numCourses == 0 || courseList == nullptr) return "No Courses Present\n\n";

    int location = -1;
    for (int i = 0; i < numCourses; i++) {
        if (courseList[i] == course) {
            location = i;
            break;
        }
    }
    if (location == -1) return "Course Not Present\n\n";

    string* newList = nullptr;
    if (numCourses -1 > 0) {
        newList = new string[numCourses -1];
        for (int i = 0, j = 0; i < numCourses; i++) {
            if (i == location) continue;
            newList[j++] = courseList[i];
        }
    }
    delete[] courseList;
    courseList = newList;
    --numCourses;
    return "Course Removed\n\n";
}



//Private methods:

void Student::freeCourses() {
    if (courseList != nullptr) {
        delete[] courseList;
        courseList = nullptr;
    }
    numCourses = 0;
}

void Student::copyFrom(const Student& copy) {
    Name = copy.Name;
    if (copy.numCourses > 0 && copy.courseList != nullptr) {
        courseList = new string[copy.numCourses];
        for (int i = 0; i < copy.numCourses; i++) {
            courseList[i] = copy.courseList[i];
        }
        numCourses = copy.numCourses;
    }
    else {
        courseList = nullptr;
        numCourses = 0;
    }
}




