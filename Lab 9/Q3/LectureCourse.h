#ifndef LECTURECOURSE
#define LECTURECOURSE

#include "Course.h"
using namespace std;

class LectureCourse : public Course {
private:
    float examScore, assignmentScore;
public:
    LectureCourse(string code, int cr, float exam, float assignment);
    void calculateGrade() ;
    void displayInfo() ;
};

#endif
