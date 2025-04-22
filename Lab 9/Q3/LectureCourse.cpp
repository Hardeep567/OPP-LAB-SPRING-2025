#include "LectureCourse.h"
#include <iostream>
using namespace std;

LectureCourse::LectureCourse(string code, int cr, float exam, float assignment) : Course(code, cr), examScore(exam), assignmentScore(assignment) {}

void LectureCourse::calculateGrade() {
    float finalGrade = (examScore * 0.8) + (assignmentScore * 0.2);
    cout << "Final Lecture Grade: " << finalGrade << std::endl;
}

void LectureCourse::displayInfo() {
    cout << "Lecture Course: " << courseCode << endl;
    cout << " Credits: " << credits << endl;
}
