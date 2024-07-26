#pragma once
#include "assignments.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <ostream>

/*
    [ ] __Category__
    [X] Vector of assignments
        [X] Name of assignment
        [X] Grade/expected grade
        [X] is it completed
    [X] Weight of category
    [X] Total grade of assignments
    [X] Total potential points
    [ ] Return final grade
*/

class Category
{
private:
    std::vector<Assignment> assignments;
    std::string nameOfCategory;
    double weightOfCategory, gradeFromAssignments, gradeTotal;

public:
    Category(std::string name);
    void addAssignment(Assignment newAssignment);
    void addAssignment(const std::string &filename);
    void changeWeightOfCategory(double numCategory);
    double getWeightOfCategory() const;
    int assignmentsCompleted() const;
    int assignmentsLeft() const;
    std::vector<Assignment> unfinishedAssignments() const;
    double totalPoints() const;
    double totalGrade() const;
    double currentGrade() const;
    double potentialGrade() const;
    std::string getName() const;
    std::vector<Assignment> getAssignments() const;
    friend std::ostream &operator<<(std::ostream &strm, const Category &obj);
};