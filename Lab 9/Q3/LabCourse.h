#ifndef LABCOURSE
#define LABCOURSE

#include "Course.h"
using namespace std;

class LabCourse : public Course {
private:
    float labWorkScore, projectScore;
public:
    LabCourse(string code, int cr, float lab, float project);
    void calculateGrade() ;
    void displayInfo() ;
};

#endif
