#include "assignments.h"
#include <iostream>
#include <fstream>

Assignment::Assignment(std::string n, double gEarned, double gPossible, bool isCompleted) : name(n), gradeEarned(gEarned), gradePossible(gPossible), complete(isCompleted) {}
std::string Assignment::getName() const
{
    return name;
}
double Assignment::getGradeEarned() const
{
    return gradeEarned;
}
bool Assignment::isCompleted() const
{
    return complete;
}
double Assignment::getGradePossible() const
{
    return gradePossible;
}

std::ostream &operator<<(std::ostream &strm, const Assignment &obj)
{
    strm << "Assignment name: " << obj.getName();
    return strm;
}