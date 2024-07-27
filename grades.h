#pragma once
#include "categories.h"
#include "assignments.h"
#include <vector>
#include <iostream>
#include <ostream>
#include <iomanip>
#include <fstream>

/*
[ ] __Grade Calculator__
    [ ] Vector of categories
        [ ] Name of category
        [ ] Weight
        [ ] Grade
    [ ] Return grade of all categories for current/future grade
*/
class Grades
{
private:
    std::vector<Category> categories;
    double finalGrade, predictedGrade;
    int allAssignmentsRemaining;

public:
    std::vector<Category> getCategories() const;
    void addCategory(std::string name, double weight);
    int howManyCompletedAssignments() const;
    double getCurrentGrade() const;
    int howManyAssignmentsLeft() const;
    double getProjectedGradeForLeftovers() const;
    double getProjectedGradeForClass() const;
    friend std::ostream &operator<<(std::ostream &strm, const Grades &obj);
};