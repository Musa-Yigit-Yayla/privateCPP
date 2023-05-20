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
    Student();
    Student(RegistrationSystem& rs);
    Student(const int studentId, const string firstName, const string lastName, RegistrationSystem& rs);
    ~Student();
    int getId() const;
    void setFirstName(const string firstName);
    string getFirstName() const;
    void setLastName(const string lastName);
    string getLastName() const;
    void incrementCoursesLength();
    void decrementCoursesLength();
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
    SLL<Course>* courses = new SLL<Course>();
    int coursesLength = 0;
    RegistrationSystem* rs;
};

#endif // STUDENT_H


#include "RegistrationSystem.h"
#include "SNode.h"
#include <string>

using namespace std;
//public:
Student::Student(){

}
Student::Student(RegistrationSystem& rs){
    this->rs = &rs;
}
Student::Student(const int studentId, const string firstName, const string lastName, RegistrationSystem& rs){
    this->studentId = studentId;
    this->firstName = firstName;
    this->lastName = lastName;
    this->rs = &rs;
}
Student::~Student(){
    //delete the courses which do not exist in other students
    /*DNode<Student>* students = this->rs.getStudents();
    SNode<Course>* currNode = reinterpret_cast<SNode<Course>*>(this->courses);
    Course* currCourse = reinterpret_cast<Course*>(currNode->data);

    while(currCourse != NULL){
        DNode<Student>* currStudentNode = students;
        Student* currStudent = reinterpret_cast<Student*>(currStudentNode->data);

        bool isDeletable = true;//check whether the current course is deletable
        while(currStudent != NULL){
            if(currStudent->courseExists(courseId)){
                //we should not be deleting this course from our original student, hence we must break the inner loop
                isDeletable = false;
                break;
            }
            currStudentNode = reinterpret_cast<DNode<Student>*>(currStudentNode->next);
            currStudent = currStudentNode->data;
        }
        if(isDeletable){
            SNode<Course>* nextNode = reinterpret_cast<SNode<Course>*>(currNode->next);
            currCourse = reinterpret_cast<Course*>(nextNode->data);
            delete currNode;
            currNode = nextNode;
        }
        else{
            currNode = reinterpret_cast<SNode<Course>*>(currNode->next);
            currCourse = reinterpret_cast<Course*>(currNode->data);
        }
    }*/
    SNode<Course>* currNode = reinterpret_cast<SNode<Course>*>(this->courses->head);
    Course* currCourse = reinterpret_cast<Course*>(currNode->data);

    while(currNode != NULL){
        SNode<Course>* nextNode = reinterpret_cast<SNode<Course>*>(currNode->next);
        //Course* nextCourse = reinterpret_cast<Course*>(nextNode->data);

        delete currNode;
        currNode = nextNode;
        //currCourse = nextCourse;
    }
}
//This method has a precondition that the student object is not already enrolled in the given student
//Instantiates a new course when adding to the student
//Returns true if the insertion is successful
//Maintains the sorted property of the sll after having added the course
bool Student::addCourse(const int courseId, const string courseName){
    SNode<Course>* currNode = reinterpret_cast<SNode<Course>*>(this->courses->head);
    Course* currCourse = nullptr;

    if(currNode != NULL){
        currCourse = reinterpret_cast<Course*>(currNode->data);
    }

    SNode<Course>* prevNode = nullptr;
    Course* prevCourse = nullptr;

    while(currNode != NULL){
        if(currCourse->getCourseId() == courseId){
            return false; //course already exists
        }
        else if(currCourse->getCourseId() > courseId){
            //insert the course right before the currCourse
            SNode<Course>* givenNode = new SNode<Course>();
            Course* givenCourse = new Course(courseId, courseName);
            givenNode->data = givenCourse;
            if(prevCourse == NULL){
                //insert at the very beginning

                this->courses->head = givenNode; // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! MIGHT BE PROBLEMATIC HERE ?????
                givenNode->next = currNode;
                this->coursesLength++;
                return true;
            }
            else{
                //regular insertion
                prevNode->next = givenNode;
                givenNode->next = currNode;
                this->coursesLength++;
                return true;
            }
        }
        prevNode = currNode;
        prevCourse = currCourse;
        currNode = reinterpret_cast<SNode<Course>*>(currNode->next);
        if(currNode != NULL){
            currCourse = reinterpret_cast<Course*>(currNode->data);
        }
    }
    //If we have left this loop without insertion this implies that we must add the course to the very end by the help of prevNode pointer
    SNode<Course>* givenNode = new SNode<Course>();
    Course* givenCourse = new Course(courseId, courseName);
    givenNode->data = givenCourse;
    if(prevNode == NULL){
        //insert at the very beginning
        this->courses->head = givenNode;
    }
    else{
        prevNode->next = givenNode;
    }
    this->coursesLength++;
    return true;
}
//returns true if the course with the given id is withdrawn successfully
//THERE MIGHT BE MEMORY LEAK IN A STUDENT OBJECT'S COURSES SLL, YOU MUST CHECK IT CAREFULLY!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
bool Student::withdrawCourse(const int courseId){
    SNode<Course>* currNode = reinterpret_cast<SNode<Course>*>(this->courses->head);
    Course* currCourse = nullptr;
    if(currNode != NULL){
        currCourse = reinterpret_cast<Course*>(currNode->data);
    }
    SNode<Course>* prevNode = nullptr;
    Course* prevCourse = nullptr;
    int counter = 0;

    while(currNode != NULL && counter < this->coursesLength){
        int currId = currCourse->getCourseId();
        if(courseId == currId){
            //we have to remove the currCourse by adjusting the pointers then deleting the currCourse afterwards
            SNode<Course>* nextNode = reinterpret_cast<SNode<Course>*>(currNode->next);
            Course* nextCourse = nullptr;
            if(prevCourse == NULL){
                //we are about to remove the very first node of the linked list
                if(nextNode != NULL){
                    //nextCourse exists
                    nextCourse = reinterpret_cast<Course*>(nextNode->data);
                    delete currNode;
                    this->courses->head = nextNode;
                }
                else{
                    //this is the one and only one node
                    delete currNode;
                    this->courses->head = nullptr;
                }
            }
            else{
                //regular removal of the course
                if(nextNode != NULL){
                    nextCourse = reinterpret_cast<Course*>(nextNode->data);
                    prevNode->next = nextNode;
                    delete currNode;
                }
                else{
                    delete currNode;
                }
            }
            this->coursesLength--;
            return true;
        }
        prevNode = currNode;
        prevCourse = reinterpret_cast<Course*>(prevNode->data);
        currNode = reinterpret_cast<SNode<Course>*>(currNode->next);
        if(currNode != NULL){
            currCourse = reinterpret_cast<Course*>(currNode->data);
        }
        counter++;
    }
    return false;
}
bool Student::courseExists(const int courseId) const{
    SNode<Course>* currNode = reinterpret_cast<SNode<Course>*>(this->courses->head);
    Course* currCourse = nullptr;

    int counter = 0;
    while(currNode != NULL && counter < this->coursesLength){
        currCourse = reinterpret_cast<Course*>(currNode->data);
        if(currCourse->getCourseId() == courseId){
            return true;
        }
        currNode = reinterpret_cast<SNode<Course>*>(currNode->next);
        counter++;
    }
    return false;
}
//If the course with the given id exists, returns a pointer to it, else returns nullptr
Course* Student::getCourse(const int courseId) const{
    SNode<Course>* currNode = reinterpret_cast<SNode<Course>*>(this->courses->head);
    Course* currCourse = nullptr;

    while(currNode != NULL){
        currCourse = reinterpret_cast<Course*>(currNode->data);
        if(currCourse->getCourseId() == courseId){
            break;
        }
    }
    return currCourse;
}
string Student::getFirstName() const{
    return this->firstName;
}
string Student::getLastName() const{
    return this->lastName;
}
void Student::setFirstName(string firstName){
    this->firstName = firstName;
}
void Student::setLastName(string lastName){
    this->lastName = lastName;
}
int Student::getId() const{
    return this->studentId;
}
void Student::incrementCoursesLength(){
    this->coursesLength++;
}
void Student::decrementCoursesLength(){
    if(this->coursesLength > 0)
        this->coursesLength--;
}
string Student::to_string() const{
    string result = "";

    result += std::to_string(this->getId()) + " " + this->getFirstName() + " " + this->getLastName() + "\n";

    SNode<Course>* currNode = reinterpret_cast<SNode<Course>*>(this->courses->head);
    Course* currCourse = nullptr;

    int counter = 0;
    while(currNode != NULL){
        if(counter == 0){
            result += "Course id Course name\n";
        }
        currCourse = reinterpret_cast<Course*>(currNode->data);
        result += std::to_string(currCourse->getCourseId()) + " " + currCourse->getCourseName() + "\n";
        counter++;
        currNode = reinterpret_cast<SNode<Course>*>(currNode->next);
    }
    return result;
}
