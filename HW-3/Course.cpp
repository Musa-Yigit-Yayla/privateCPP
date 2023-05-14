#include "Course.h"

//public:

void Course::setCourseId(const int courseId){
    this->courseId = courseId;
}
int Course::getCourseId() const{
    return this->courseId;
}
