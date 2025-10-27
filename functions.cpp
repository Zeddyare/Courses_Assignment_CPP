//
// Created by zdrol on 2025-10-27.
//

#include "../Courses/courseFunc.h"

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
    if (courseNum != 0 || courseNum >= numCourses || courseList == nullptr) {
        return string();
    } else {
        return courseList[courseNum];
    }
}

void Student::outputInfo() {

}

void Student::addCourse(const std::string& course) {

}
void Student::removeCourse(const std::string& course) {

}
void Student::setName(const std::string& name) {

}


//Private methods:

void Student::freeCourses() {

}

void Student::copyFrom(const Student& copy) {

}




