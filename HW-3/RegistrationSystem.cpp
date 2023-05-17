#include "RegistrationSystem.h"
#include "SLL.h"
#include "SNode.h"
#include "DLL.h"
#include "DNode.h"
#include "Student.h"
#include "Course.h"
#include <string>
#include <iostream>
#include <cstddef>

using namespace std;

//public:
RegistrationSystem::RegistrationSystem(){

}
RegistrationSystem::~RegistrationSystem(){
    DNode<Student>* currNode = reinterpret_cast<DNode<Student>*>(this->students);
    while(currNode != NULL){
        DNode<Student>* nextNode = reinterpret_cast<DNode<Student>*>(currNode->next);
        delete currNode;
        currNode = nextNode;
    }
}
//If student id is non positive integer or it already exists we should display a warning msg and not add the student
void RegistrationSystem::addStudent(const int studentId, const string firstName, const string lastName){
    DNode<Student>* currNode = reinterpret_cast<DNode<Student>*>(this->students);
    if(currNode == NULL){
        //first student is going to be added
        DNode<Student>* newNode = new DNode<Student>();
        Student* givenStudent = new Student(studentId, firstName, lastName, this);
        newNode->data = givenStudent;
        cout << "Student " << studentId << " has been added" << endl;
        this->incrementStudentCount();
        return;
    }
    Student* currStudent = currNode->data;

    while(currStudent != NULL){
        int currId = currStudent->getId();
        if(studentId <= 0 || currId == studentId){
            cout << "Student " << studentId << " already exists" << endl;
        }
        return;
    }
    DNode<Student>* initialHead = reinterpret_cast<DNode<Student>*>(this->students->head);
    Student* givenStudent = new Student(studentId, firstName, lastName, this);
    DNode<Student>* givenNode = new DNode<Student>();
    givenNode->data = givenStudent;
    //add the given student at the correct position
    currNode = reinterpret_cast<DNode<Student>*>(this->students);
    currStudent = currNode->data;

    DNode<Student>* prevNode = nullptr;
    Student* prevStudent = nullptr;

    while(currStudent != NULL){
        if(currStudent->getId() > studentId){
            if(prevStudent == NULL){
                //insert at the beginning
                givenNode->next = this->students->head;
                this->students->head->prev = givenNode;
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
        currStudent = reinterpret_cast<Student*>(currNode->data);
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
    Student* currStudent = reinterpret_cast<Student*>(this->students->head->data);
    DNode<Student>* currNode = reinterpret_cast<DNode<Student>*>(this->students->head);
    Student* prevStudent = nullptr;
    DNode<Student>* prevNode = nullptr;

    while(currStudent != NULL){
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
                    cout << "Student " << studentId << " has been deleted" << endl;
                    return;
                }

            }
            else{
                DNode<Student*> nextNode = reinterpret_cast<DNode<Student>*>(currNode->next);
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
        currStudent = reinterpret_cast<Student*>(currNode->data);
    }
}
void RegistrationSystem::addCourse(const int studentId, const int courseId, const string courseName){
    //Check whether the course exists
    if(this->courseExists(studentId)){
        cout << "Course " << courseId << " already exists ?" << endl;
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
            cout << "Course " << courseId << " already exists ?" << endl;
        }
    }
}

void RegistrationSystem::withdrawCourse ( const int studentId , const int courseId ){
    if(this->courseExists(studentId, courseId)){
        Student* student = this->getStudent(studentId);
        bool isWithdrawn = student->withdrawCourse(courseId);
        if(isWithdrawn){
            cout << "Student " << studentId << " has been withdrawn from course " << courseId << endl;
        }
        else{
            //Student is not enrolled in this course ?????
            cout << "Student " << studentId << " is not enrolled in course " << courseId << endl;
        }
    }
    else{
        cout << "Student " << studentId << " is not enrolled in course " << courseId << endl;
    }
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
        "Course " << courseId << " does not exist" << endl;
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
            if(doesExist){
                return true;
            }

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
    DNode<Student>* currNode = reinterpret_cast<DNode<Student>*>(this->students->head);
    Student* currStudent = nullptr;

    while(currNode != NULL){
        currStudent = reinterpret_cast<Student*>(currNode->data);
        cout << currStudent->to_string() << endl;

        currNode = reinterpret_cast<DNode<Student>*>(currNode->next);
    }
}
