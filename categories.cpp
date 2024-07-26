#include "categories.h"
#include <iostream>
#include <ostream>
#include <fstream>
#include <vector>

Category::Category(std::string name) : nameOfCategory(name) {}
void Category::addAssignment(Assignment newAssignment)
{
    assignments.push_back(newAssignment);
}
void Category::addAssignment(const std::string &filename)
{
    Assignment newAssignment(filename);
    assignments.push_back(newAssignment);
}
double Category::changeWeightOfCategory(double numCategory)
{
    weightOfCategory = numCategory;
}
double Category::totalGrade()
{
    double gradeEarned = 0.0;
    double totalPoints = 0.0;

    for (const auto &assignment : assignments)
    {
        gradeEarned += assignment.getGradeEarned();
        totalPoints += assignment.getGradePossible();
    }
    return (gradeEarned / totalPoints);
}
std::vector<Assignment> Category::getAssignments() const
{
    return assignments;
}
std::ostream &operator<<(std::ostream &strm, const Category &obj)
{
    strm
}