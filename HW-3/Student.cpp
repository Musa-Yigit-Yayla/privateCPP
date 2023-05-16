#include "Student.h"
#include "RegistrationSystem.h"
#include "SNode.h"
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
        Course* nextCourse = reinterpret_cast<Course*>(nextNode->data);

        delete currNode;
        currNode = nextNode;
        currCourse = nextCourse;
    }
}
//This method has a precondition that the student object is not already enrolled in the given student
//Instantiates a new course when adding to the student
//Returns true if the insertion is successful
//Maintains the sorted property of the sll after having added the course
bool Student::addCourse(const int courseId, const string courseName){
    SNode<Course>* currNode = reinterpret_cast<SNode<Course>*>(this->courses);
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
            SNode<Course>* givenNode = new SNode();
            Course* givenCourse = new Course(courseId, courseName);
            givenNode->data = givenCourse;
            if(prevCourse == NULL){
                //insert at the very beginning

                this->courses->head = givenCourse;
                givenCourse->next = currCourse;
                this->coursesLength++;
                return true;
            }
            else{
                //regular insertion
                prevNode->next = givenNode;
                givenNode->next = currCourse;
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
    SNode<Course>* givenNode = new SNode();
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
