#ifndef Course_h
#define Course_h
#pragma once

class Course{
public:
    Course();
    ~Course();

    void setCourseId(const int courseId);
    int getCourseId() const;

private:
    int courseId;

};
#endif // Course_h
