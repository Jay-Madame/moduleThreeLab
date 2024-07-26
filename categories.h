#pragma once
#include "assignments.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <ostream>

/*
    [ ] __Category__
    [ ] Vector of assignments
        [ ] Name of assignment
        [ ] Grade/expected grade
        [ ] is it completed
    [ ] Weight of category
    [ ] Total grade of assignments
    [ ] Total potential points
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
    double changeWeightOfCategory(double numCategory);
    double totalGrade();
    std::vector<Assignment> getAssignments() const;
    friend std::ostream &operator<<(std::ostream &strm, const Category &obj);
};