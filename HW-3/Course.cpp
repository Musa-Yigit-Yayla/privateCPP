#include "Course.h"

//public:

Course::Course(){

}
Course::Course(const int courseId, const string courseName){
    this->courseId = courseId;
    this->courseName = courseName;
}
Course::~Course(){

}
void Course::setCourseId(const int courseId){
    this->courseId = courseId;
}
int Course::getCourseId() const{
    return this->courseId;
}
void Course::setCourseName(const string courseName){
    this->courseName = courseName;
}
string Course::getCourseName() const{
    return this->courseName;
}
