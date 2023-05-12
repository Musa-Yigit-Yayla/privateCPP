#ifndef STUDENT_H
#define STUDENT_H
#pragma once

#include <string>
#include "DLL.h"

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

private:
    int studentId;
    string firstName;
    string lastName;
    DLL<Course> courses;
};

#endif // STUDENT_H
