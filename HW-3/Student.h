#ifndef STUDENT_H
#define STUDENT_H
#pragma once

#include <string>
#include "DLL.h"
#include "Course.h"

using namespace std;
class Student{
public:
    Student();
    Student(const int studentId, const string firstName, const string lastName);
    ~Student();
    int getId() const;
    void setFirstName(const string firstName);
    string getFirstName() const;
    void setLastName(const string lastName);
    string getLastName() const;
    void incrementCoursesLength();
    int getCoursesLength() const;
    void addCourse(const int courseId, const string courseName);
    bool withdrawCourse(const int courseId);

    string to_string() const;
private:
    int studentId;
    string firstName;
    string lastName;
    DLL<Course> courses;
    int coursesLength = 0;
};

#endif // STUDENT_H
