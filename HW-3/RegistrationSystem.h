#ifndef REGISTRATIONSYSTEM_H
#define REGISTRATIONSYSTEM_H
#pragma once

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
    void showStudent ( const int studentId );
    void showCourse ( const int courseId );
    void showAllStudents ();
};
#endif // REGISTRATIONSYSTEM_H

