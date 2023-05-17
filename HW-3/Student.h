#ifndef STUDENT_H
#define STUDENT_H
#pragma once

#include <string>
#include "DLL.h"
#include "SLL.h"
#include "Course.h"
#include "RegistrationSystem.h"

class RegistrationSystem; //forward declaration

using namespace std;
class Student{
public:
    Student(RegistrationSystem& rs);
    Student(const int studentId, const string firstName, const string lastName, RegistrationSystem& rs);
    ~Student();
    int getId() const;
    void setFirstName(const string firstName);
    string getFirstName() const;
    void setLastName(const string lastName);
    string getLastName() const;
    void incrementCoursesLength();
    int getCoursesLength() const;
    Course* getCourse(const int courseId) const;
    bool addCourse(const int courseId, const string courseName);
    bool withdrawCourse(const int courseId);
    bool courseExists(const int courseId) const;
    string to_string() const;
private:
    int studentId;
    string firstName;
    string lastName;
    SLL<Course>* courses;
    int coursesLength = 0;
    RegistrationSystem* rs;
};

#endif // STUDENT_H
