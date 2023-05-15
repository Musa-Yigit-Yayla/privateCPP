#include "Student.h"
#include "RegistrationSystem.h"
#include <string>

using namespace std;
//public:
Student::Student(RegistrationSystem& rs){
    this->rs = rs;
}
Student::Student(const int studentId, const string firstName, const string lastName, RegistrationSystem& rs){
    this->studentId = studentId;
    this->firstName = firstName;
    this->lastName = lastName;
    this->rs = rs;
}
Student::~Student(){
    //delete the courses which do not exist in other students
    SNode<Student>* students = this->rs->getStudents();
    SNode<Course>* currNode = reinterpret_cast<DNode<Course>*>(this->courses);
    Course* currCourse = reinterpret_cast<Course*>(currNode->data);

    while(currCourse != NULL){
        SNode<Student>* currStudentNode = students;
        Student* currStudent = reinterpret_cast<Student*>(currStudentNode->data);

        bool isDeletable = true;//check whether the current course is deletable
        while(currStudent != NULL){
            if(currStudent->courseExists(courseId)){
                //we should not be deleting this course from our original student, hence we must break the inner loop
                isDeletable = false;
                break;
            }
            currStudentNode = reinterpret_cast<SNode<Student>*>(currStudentNode->next);
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

    }
}

bool Student::courseExists(const int courseId) const{
    SNode<Course>* currNode = reinterpret_cast<DNode<Course>*>(this->courses);
    Course* currCourse = reinterpret_cast<Course*>(currNode->data);

    while(currCourse != NULL){
        if(currCourse->getCourseId() == courseId){
            return true;
        }
        currNode = reinterpret_cast<DNode<Course>*>(currNode->next);
        currCourse = reinterpret_cast<Course*>(currNode->data);
    }
    return false;
}
