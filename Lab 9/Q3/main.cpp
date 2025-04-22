#include <iostream>
#include "LectureCourse.h"
#include "LabCourse.h"
using namespace std;

int main() {
    Course* courses[2];

    courses[0] = new LectureCourse("CS101", 3, 85.0f, 90.0f);
    courses[1] = new LabCourse("CS102L", 1, 88.0f, 92.0f);

    for (int i = 0; i < 2; ++i) {
        courses[i]->displayInfo();
        courses[i]->calculateGrade();
    }

    for(int i=0;i<2;i++){
        delete courses[i];
    }
    return 0;
}
