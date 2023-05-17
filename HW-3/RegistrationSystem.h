#ifndef REGISTRATIONSYSTEM_H
#define REGISTRATIONSYSTEM_H
#pragma once

#include "DLL.h"
#include "DNode.h"
#include <string>
#include "Student.h"
#include <functional>

class Student;

using namespace std;
class RegistrationSystem {
public :
    RegistrationSystem ();
    ~ RegistrationSystem ();
    void addStudent ( const int studentId , const string firstName , const string
    lastName );
    void deleteStudent ( const int studentId );
    void addCourse ( const int studentId , const int courseId , const string
    courseName );
    void withdrawCourse ( const int studentId , const int courseId );
    void cancelCourse ( const int courseId );
    inline void incrementStudentCount();
    inline void decrementStudentCount();
    inline int getStudentCount() const;
    bool studentExists(const int studentId) const;
    bool courseExists(const int studentId, const int courseId) const;
    Student* getStudent(const int studentId) const;
    DLL<Student>* getStudents() const; // returns the head pointer of the DLL of students
    void showStudent ( const int studentId ) const;
    void showCourse ( const int courseId ) const;
    void showAllStudents () const;
private:
    DLL<Student>* students = nullptr;
    int studentsCount = 0;
};
#endif // REGISTRATIONSYSTEM_H

