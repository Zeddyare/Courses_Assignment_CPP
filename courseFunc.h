//
// Created by zdrol on 2025-10-27.
//

#ifndef COURSES_COURSEFUNC_H
#define COURSES_COURSEFUNC_H

#include <string>



class Student {

public:
    //Constructors
    Student();
    Student(std::string name, int courseCt, std::string* courseLs);
    explicit Student(const std::string& name);
    Student(const Student& copy);
    Student& operator = (const Student& copy);

    //"Print" Function for output of student information
    void outputInfo();

    //Mutators
    void addCourse(const std::string& course);
    void removeCourse(const std::string& course);
    void setName(const std::string& name);

    //Accessors
    std::string getName();
    int getNumCourses() const;
    std::string getCourse(int courseNum);

    //Destructor
    ~Student();

private:
    std::string Name;
    int numCourses;
    std::string* courseList;

    //Deep copy help
    void copyFrom(const Student& copy);
    void freeCourses();

};

#endif //COURSES_COURSEFUNC_H