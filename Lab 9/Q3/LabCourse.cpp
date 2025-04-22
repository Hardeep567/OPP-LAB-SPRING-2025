#include "LabCourse.h"
#include <iostream>
using namespace std;

LabCourse::LabCourse(string code, int cr, float lab, float project) : Course(code, cr), labWorkScore(lab), projectScore(project) {}

void LabCourse::calculateGrade() {
    float finalGrade = (labWorkScore * 0.6) + (projectScore * 0.4);
    cout << "Final Lab Grade: " << finalGrade << endl;
}

void LabCourse::displayInfo() {
    cout << "Lab Course: " << courseCode << endl;
    cout << " Credits: " << credits << endl;
}
