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

//#include "RegistrationSystem.h"
#include "SLL.h"
#include "SNode.h"
#include "DLL.h"
#include "DNode.h"
#include "Student.h"
#include "Course.h"
#include <string>
#include <iostream>
#include <cstddef>
#include <functional>

using namespace std;

//public:
RegistrationSystem::RegistrationSystem(){
    this->students = new DLL<Student>();
}
RegistrationSystem::~RegistrationSystem(){
    DNode<Student>* currNode = reinterpret_cast<DNode<Student>*>(this->students);
    while(currNode != NULL){
        DNode<Student>* nextNode = reinterpret_cast<DNode<Student>*>(currNode->next);
        delete currNode;
        currNode = nextNode;
    }
    delete this->students;
}
//If student id is non positive integer or it already exists we should display a warning msg and not add the student
void RegistrationSystem::addStudent(const int studentId, const string firstName, const string lastName){
    DNode<Student>* currNode = reinterpret_cast<DNode<Student>*>(this->students->head);
    if(currNode == NULL || this->studentsCount == 0){ // !!!!! YOU MIGHT WANT TO REMOVE THE SECOND CONDITION OF THE IF !!!!!
        //first student is going to be added
        DNode<Student>* newNode = new DNode<Student>();
        Student* givenStudent = new Student(studentId, firstName, lastName, *this);
        newNode->data = givenStudent;
        this->students->head = newNode;
        this->incrementStudentCount();
        cout << "Student " << studentId << " has been added" << endl;
        return;
    }
    Student* currStudent = currNode->data;

    while(currNode != NULL){
        currStudent = currNode->data;
        int currId = currStudent->getId();
        if(studentId <= 0 || currId == studentId){
            cout << "Student " << studentId << " already exists" << endl;
            return;
        }
        currNode = reinterpret_cast<DNode<Student>*>(currNode->next);
    }
    DNode<Student>* initialHead = reinterpret_cast<DNode<Student>*>(this->students->head);
    Student* givenStudent = new Student(studentId, firstName, lastName, *this);
    DNode<Student>* givenNode = new DNode<Student>();
    givenNode->data = givenStudent;
    //add the given student at the correct position
    currNode = reinterpret_cast<DNode<Student>*>(this->students->head);
    currStudent = currNode->data;

    DNode<Student>* prevNode = nullptr;
    Student* prevStudent = nullptr;

    while(currNode != NULL){
        currStudent = reinterpret_cast<Student*>(currNode->data);
        if(currStudent->getId() > studentId){
            if(prevStudent == NULL){
                //insert at the beginning
                givenNode->next = this->students->head;
                this->students->head->prev = givenNode;
                this->students->head = givenNode;
                this->incrementStudentCount();
                cout << "Student " << studentId << " has been added" << endl;
                return;
            }
            else{
                //insert regularly
                prevNode->next = givenNode;
                givenNode->prev = prevNode;
                givenNode->next = currNode;
                currNode->prev = givenNode;
                this->incrementStudentCount();
                cout << "Student " << studentId << " has been added" << endl;
                return;
            }
        }
        prevNode = currNode;
        prevStudent = currStudent;
        currNode = reinterpret_cast<DNode<Student>*>(currNode->next);
    }
    //If we haven't added anything and left the loop, then we must insert at the end or at the very beginning
    if(prevStudent == NULL){
        this->students->head = givenNode;
    }
    else{
        prevNode->next = givenNode;
        givenNode->prev = prevNode;
    }
    this->incrementStudentCount();
    cout << "Student " << studentId << " has been added" << endl;
}
void RegistrationSystem::deleteStudent(const int studentId){
    //traverse the whole dll to check whether we have the desired student
    Student* currStudent = nullptr;//reinterpret_cast<Student*>(this->students->head->data);
    DNode<Student>* currNode = reinterpret_cast<DNode<Student>*>(this->students->head);
    Student* prevStudent = nullptr;
    DNode<Student>* prevNode = nullptr;

    while(currNode != NULL){
        currStudent = reinterpret_cast<Student*>(currNode->data);
        int currId = currStudent->getId();
        bool isDeleted = false;
        if(currId == studentId){
            if(prevStudent == NULL){
                //removal of the first element
                DNode<Student>* nextNode = reinterpret_cast<DNode<Student>*>(currNode->next);
                if(nextNode != NULL){
                    //we have only one node and it's the head node (currNode).
                    //Student* nextStudent = reinterpret_cast<Student*>(nextNode->data);
                    isDeleted = true;
                    delete currNode;
                    this->decrementStudentCount();
                    cout << "Student " << studentId << " has been deleted" << endl;
                    this->students->head = nextNode;
                    return;
                }
                else{
                    isDeleted = true;
                    delete currNode;
                    this->decrementStudentCount();
                    this->students->head = nullptr;
                    cout << "Student " << studentId << " has been deleted" << endl;
                    return;
                }

            }
            else{
                DNode<Student>* nextNode = reinterpret_cast<DNode<Student>*>(currNode->next);
                Student* nextStudent = reinterpret_cast<Student*>(nextNode->data);
                if(nextStudent == NULL){
                    //deletion of the last student
                    prevNode->next = nullptr;
                    delete currNode;
                    this->decrementStudentCount();
                    isDeleted = true;
                    cout << "Student " << studentId << " has been deleted" << endl;
                }
                else{
                    //regular deletion
                    //DNode<Student*> nextNode = reinterpret_cast<DNode<Student>*>(currNode->next);
                    prevNode->next = nextNode;
                    nextNode->prev = prevNode;
                    delete currNode;
                    this->decrementStudentCount();
                    isDeleted = true;
                    cout << "Student " << studentId << " has been deleted" << endl;
                }
                return;
            }
        }
        prevNode = currNode;
        prevStudent = currStudent;
        currNode = reinterpret_cast<DNode<Student>*>(currNode->next);
    }
    //If we have finished this loop without returning this implies that the given student does not exist
    cout << "Student " << studentId << " does not exist" << endl;
}
void RegistrationSystem::addCourse(const int studentId, const int courseId, const string courseName){
    //Check whether the course exists
    if(this->courseExists(studentId, courseId)){
        cout << "Student " << studentId << " is already enrolled in course " << courseId << endl;
        return;
    }
    //find the student with the given id
    Student* givenStudent = this->getStudent(studentId);
    if(givenStudent == NULL){
        cout << "Student " << studentId << " does not exist" << endl;
    }
    else{
        //both the student and the course exists proceed accordingly
        bool isAdded = givenStudent->addCourse(courseId, courseName); // we expect this method to return true but we will double check anyways
        if(isAdded){
            cout << "Course " << courseId << " has been added to student " << studentId << endl;
        }
        else{
            cout << "Student " << studentId << " is already enrolled in course" << courseId << endl; //?????
        }
    }
}

void RegistrationSystem::withdrawCourse ( const int studentId , const int courseId ){
    //if(this->courseExists(studentId, courseId)){
        Student* student = this->getStudent(studentId);
        if(student == NULL){
            cout << "Student " << studentId << " does not exist" << endl;
            return;
        }
        bool isWithdrawn = student->withdrawCourse(courseId);
        if(isWithdrawn){
            cout << "Student " << studentId << " has been withdrawn from course " << courseId << endl;
        }
        else{
            //Student is not enrolled in this course ?????
            cout << "Student " << studentId << " is not enrolled in course " << courseId << endl;
        }
    //}
    /*else{
        cout << "Student " << studentId << " is not enrolled in course " << courseId << endl;
    }*/
}
void RegistrationSystem::cancelCourse(const int courseId){
    //check whether the course exists in the currStudent and if so remove the course
    DNode<Student>* currStudentNode = reinterpret_cast<DNode<Student>*>(this->students->head);
    Student* currStudent = nullptr;
    if(currStudentNode != NULL){
        currStudent = reinterpret_cast<Student*>(currStudentNode->data);
    }
    bool isCancelled = false;
    while(currStudentNode != NULL){
        if(currStudent->courseExists(courseId)){
            //we must remove the course and also delete the retrieved node
            currStudent->withdrawCourse(courseId);
            isCancelled = true;
        }
        currStudentNode = reinterpret_cast<DNode<Student>*>(currStudentNode->next);
        if(currStudentNode != NULL){
            currStudent = reinterpret_cast<Student*>(currStudentNode->data);
        }
    }
    if(isCancelled){
        cout << "Course " << courseId << " has been cancelled" << endl;
    }
    else{
        cout << "Course " << std::to_string(courseId) << " does not exist" << endl;
    }
}
inline void RegistrationSystem::incrementStudentCount(){
    this->studentsCount++;
}
inline void RegistrationSystem::decrementStudentCount(){
    if(this->studentsCount > 0)
        this->studentsCount--;
}
inline int RegistrationSystem::getStudentCount() const{
    return this->studentsCount;
}
bool RegistrationSystem::studentExists(const int studentId) const{
    DNode<Student>* currNode = reinterpret_cast<DNode<Student>*>(this->students->head);
    Student* currStudent = reinterpret_cast<Student*>(currNode->data);

    while(currStudent != NULL){
        if(currStudent->getId() == studentId){
            return true;
        }
        currNode = reinterpret_cast<DNode<Student>*>(currNode->next);
        currStudent = reinterpret_cast<Student*>(currNode->data);
    }
    return false;
}
bool RegistrationSystem::courseExists(const int studentId, const int courseId) const{
    DNode<Student>* currNode = reinterpret_cast<DNode<Student>*>(this->students->head);
    Student* currStudent = reinterpret_cast<Student*>(currNode->data);

    while(currStudent != NULL && currNode != NULL){
        if(currStudent->getId() == studentId){
            //if the student exists then we must check its enrolled courses to verify the existence of the given course
            bool doesExist = currStudent->courseExists(courseId);
            return doesExist;

        }
        currNode = reinterpret_cast<DNode<Student>*>(currNode->next);
        if(currNode != NULL)
            currStudent = reinterpret_cast<Student*>(currNode->data);
    }
    return false;
}
//Returns the student by id if it exists, if not returns nullptr
Student* RegistrationSystem::getStudent(const int studentId) const{
    DNode<Student>* currNode = reinterpret_cast<DNode<Student>*>(this->students->head);
    Student* currStudent = reinterpret_cast<Student*>(currNode->data);

    while(currNode != NULL){
        int currId = currStudent->getId();
        if(currId == studentId){
            return currStudent;
        }
        currNode = reinterpret_cast<DNode<Student>*>(currNode->next);
        if(currNode != NULL)
            currStudent = reinterpret_cast<Student*>(currNode->data);
    }
    return nullptr;
}
DLL<Student>* RegistrationSystem::getStudents() const{
    return this->students;
}
void RegistrationSystem::showAllStudents() const{
    if(this->studentsCount == 0){
        cout << "There are no students in the system" << endl;
        return;
    }
    DNode<Student>* currNode = reinterpret_cast<DNode<Student>*>(this->students->head);
    Student* currStudent = nullptr;
    cout << "Student id First name Last name" << endl;
    while(currNode != NULL){
        currStudent = reinterpret_cast<Student*>(currNode->data);
        cout << currStudent->to_string();
        currNode = reinterpret_cast<DNode<Student>*>(currNode->next);
    }
}
void RegistrationSystem::showCourse(const int courseId) const{
    //first check whether the course exists in any of the students
    DNode<Student>* currNode = reinterpret_cast<DNode<Student>*>(this->students->head);
    Student* currStudent = nullptr;
    bool courseFound = false;
    Course* course = nullptr;
    while(currNode != NULL){
        currStudent = reinterpret_cast<Student*>(currNode->data);
        if(currStudent->courseExists(courseId)){
            courseFound = true;
            course = currStudent->getCourse(courseId);
            break;
        }
        currNode = reinterpret_cast<DNode<Student>*>(currNode->next);
    }
    if(courseFound){
        cout << "Course id Course Name" << endl;
        cout << courseId << course->getCourseName() << endl;
        cout << "Student id First name Last name" << endl;

        currNode = reinterpret_cast<DNode<Student>*>(this->students->head);
        currStudent = nullptr;
        while(currNode != NULL){
            currStudent = reinterpret_cast<Student*>(currNode->data);
            //recall that sorted property is already satisfied in the student dll
            if(currStudent->courseExists(courseId)){
                cout << currStudent->getId() << " " << currStudent->getFirstName() << " " << currStudent->getLastName() << endl;
            }
            currNode = reinterpret_cast<DNode<Student>*>(currNode->next);
        }
    }
    else{
        cout << "Course " << courseId << " does not exist" << endl;
    }
}
//show the contents of the specified student if it exists, if not display a warning message
void RegistrationSystem::showStudent(const int studentId) const{
    DNode<Student>* currNode = reinterpret_cast<DNode<Student>*>(this->students->head);
    Student* givenStudent = nullptr;
    Student* currStudent = nullptr;

    while(currNode != nullptr){
        currStudent = reinterpret_cast<Student*>(currNode->data);
        if(currStudent->getId() == studentId){
            givenStudent = currStudent;
            break;
        }
        currNode = reinterpret_cast<DNode<Student>*>(currNode->next);
    }
    if(givenStudent != NULL){
        cout << "Student id First name Last name" << endl;
        //we have found the specified student
        cout << givenStudent->to_string();
    }
    else{
        cout << "Student " << studentId << " does not exist" << endl;
    }
}

