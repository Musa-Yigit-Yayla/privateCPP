#ifndef Course_h
#define Course_h
#pragma once
#include <string>

using namespace std;
class Course{
public:
    Course();
    Course(const int courseId, const string courseName);
    ~Course();

    void setCourseId(const int courseId);
    int getCourseId() const;
    void setCourseName(const string courseName);
    string getCourseName() const;

private:
    int courseId;
    string courseName;
};
#endif // Course_h

#include <string>

using namespace std;
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
