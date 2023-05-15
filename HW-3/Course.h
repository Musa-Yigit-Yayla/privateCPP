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
